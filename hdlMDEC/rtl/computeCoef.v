/*
	This unit takes the decoded stream of coefficent with scale and specific setup
	and does the pre IDCT multiplication of the coefficient based on the mode :
	
	Standard Mode :
	- Item 0 : Coef x   1.0 x QuantMatrix[0]    -> Coef x     8 x QuantMatrix[0] / 8
	- Item x : Coef x Scale x QuantMatrix[x]/8  -> Coef x Scale x QuantMatrix[x] / 8 
	
	Full Uncompressed Matrix Mode :
	- Item 0 : Coef x   2.0                     -> Coef x    16 x              1 / 8
	- Item x : Coef x   2.0						-> Coef x    16 x              1 / 8
	
	No$PSX specs says that +4 is added BEFORE DIVISION by 8.
	
	[Coef : 10 Bit]x[Scale : 6 Bit]x[Quantization : 7 Bit] = [22:0] BIT / 8 = BIT[19:0]
	
	And pass pipelined the important information such as :
	- HiRes (4/8/16/24 bit output for YUV->RGB Conversion unit)
	- Block Number
	- Of course strict necessary information for storage in IDCT.
 */
 
module computeCoef (
	input					i_clk,
	input					i_nrst,

	// Loading Side
	input					i_dataWrt,
	input	signed[9:0]		i_dataIn,
	input	[5:0]			i_scale,
	input					i_isDC,
	input	[5:0]			i_index,			// Linear or Zagzig order.
	input	[5:0]			i_linearIndex,		// Needed because Quant table is read in linear order, avoid i_index.
	input					i_fullBlockType,
	input	[2:0]			i_blockNum,
	input					i_matrixComplete,

	// IDCT Busy side
	input					i_freezePipe,

	// Quant Table Loading
	input					i_quantWrt,
	input	[27:0]			i_quantValue,
	input	[3:0]			i_quantAdr,
	input					i_quantTblSelect,
	
//	output	[23:0]			debug,
	
	// Write output (2 cycle latency from loading)
	output					o_write,
	output	[5:0]			o_writeIdx,
	output	[2:0]			o_blockNum,
	output	signed [11:0]	o_coefValue,
	output          		o_matrixComplete
);
	// ----- Data Pipelining Management ----------------------------------
	//
	// IDCT can suddenly decide to be full and STOP the FIFO from feeding.
	// But in this case, we may have valid data in flight due to a 1 cycle
	// pipeline (which we can NOT avoid because of the Quantization table read).
	// So we handle the freezing and unfreezing of the pipeline.
	//
	// Transition over time : {pipedfreezePipe,freezePipe} => [00] [01] [11] [10] 
	// ----
	//
	// Values over time (output of reg for register):
	//     Input    Reg1    Reg2 (Backup)                                    Reg1W   Reg2W  StoreQuantV
	// 00    C       B B'    A" 			Output B (Acceptd by IDCT)        1       X       1                    Use Reg
	// 01    D       C C'    B"				Output C (Refused by IDCT)        1       1       1                    Dont care -> Use Reg
	// 11    X       D D'    C"				Output D (Refused by IDCT)        0       0		  1                    Dont care -> Use Reg
	// 11    X       D X'    C"				Output D (Refused by IDCT)        0       0		  0                    Dont care -> Use Reg
	// 11    X       D X'    C"				Output D (Refused by IDCT)        0       0		  0                    Dont care -> Use Reg
	// 10    X       D X'	 C"				Output C (Acceptd by IDCT)        0       1		  0                    Use Reg2
	// 00    E       D X'    #"				Output D (Acceptd by IDCT)        1       X  	  0                    Use Reg
	// 00    F       E E'    
	//
	// x' are value from the Quantization Table read.
	// x" are value stored using x' and x values if we do not handle 
	//
	// We notice thate there is a discrepancy if we just pipeline the values, but
	// do not manager the output of the table.
	//
	// => Store the Quant Table result on pipe(True when 01 transition)
	// => Use stored result (TRUE) on 10 transition (non piped !)
	//
	always @(posedge i_clk) begin
		pFreeze 		<= i_freezePipe;
	end

	always @(posedge i_clk) begin
		storeQuantVal <= Reg1W;
		useQuantStore <= useReg2;
	end
	
	reg		pFreeze;
	reg		storeQuantVal;
	reg		useQuantStore;
	wire	Reg1W   		= (!pFreeze)					| (!i_nrst);	// We also make sure we invalidate data in the pipe if RESET.
	wire	Reg2W   		= (!pFreeze &  i_freezePipe)	| (!i_nrst);	// We also make sure we invalidate data in the pipe if RESET.
	wire	useReg2 		= ( pFreeze & !i_freezePipe);
	/*
	reg		Reg2W;
	reg		useReg2;
	always @(*)
	begin
		// TODO Reg1W / Reg2W use i_nrst;
		case ({pFreeze,i_freezePipe})
		2'b00:
		begin
			// Value is processed, mul occurs as needed at the next cycle.
			Reg2W   		= 0;
			useReg2			= 0;
		end
		2'b01:
		begin
			// Value is STORED, Reg1 does NOT have multiplied result.
			Reg2W   		= 1;	// Need to save previous value.
			useReg2			= 0;
		end
		2'b11:
		begin
			Reg2W   		= 0;
			useReg2			= 0;
		end
		2'b10:
		begin
			Reg2W   		= 0;	// Don't change internal.
			useReg2			= 1;	
		end
		endcase
	end
	*/
	// -------------------------------------------------------------------

	// -------------------------------------------------------------------
	//   Embedded Quantization Table RAM
	// -------------------------------------------------------------------
	// INPUT : [We read continuously from the Quant table]
	//
	//    Read from computeCoef
	//    ----------------------
	//             storeQuantVal
	//             selectTable
	//       [5:0] quantReadIdx
	//
	//    Setup from outside
	//    ----------------------
	//				i_quantWrt,
	//		[27:0]	i_quantValue,
	//		[ 3:0]	i_quantAdr,
	//				i_quantTblSelect,
	//
	// OUTPUT
	reg  [6:0] valueQuant;
	reg  [6:0] storedQuant;
	// -------------------------------------------------------------------
	// Internal stuff
	reg  [27:0] QuantTbl[31:0];
	reg   [4:0] quantAdr_reg;
	wire  [4:0] writeAdr = {i_quantTblSelect,i_quantAdr};
	reg   [1:0] pipeQuantReadIdx;

	// [Quantization Table READ/WRITE]
	always @ (posedge i_clk)
	begin
		// Write
		if (i_quantWrt)
		begin
			QuantTbl[writeAdr] <= i_quantValue;
		end

		// Read
		quantAdr_reg <= {selectTable,quantReadIdx[5:2]};
		// Read
		pipeQuantReadIdx <= quantReadIdx[1:0];
	end
	wire [27:0] fullValueQuant = QuantTbl[quantAdr_reg]; 

	// [Select the correct 7 bit from 28 bit record]
	always @ (*)	
	begin
		case (pipeQuantReadIdx)
		0       : valueQuant = fullValueQuant[ 6: 0];
		1       : valueQuant = fullValueQuant[13: 7];
		2       : valueQuant = fullValueQuant[20:14];
		default : valueQuant = fullValueQuant[27:21];
		endcase
	end

	// [Storage of valueQuant if we can't use it (pipeline freeze)
	always @ (posedge i_clk)
	begin
		if (storeQuantVal) begin
			storedQuant <= valueQuant;
		end
	end
	// -------------------------------------------------------------------
	
	
	// -------------------------------------------------------------------
	//   Stage 0 : Compute data (1st multiplication) while we request
	//             the quantization factor
	// -------------------------------------------------------------------
	// 
	// Cycle 0 :	- Drive SRAM Read for quantization block.
	//				- Compute Scale * Coef => Temporary Coef
	//
	wire 		selectTable			= i_blockNum[1] | i_blockNum[2];
	wire [5:0]	quantReadIdx		= i_linearIndex;

	reg			pWrite;
	reg  [5:0]	pIndex;
	reg  [2:0]	pBlk;
	reg			pMatrixComplete;
	reg			pFullBlkType;

	//
	// Save values needed for stage 1 (pipeline to match SRAM latency)
	//
	wire signed [16:0] multF;
	reg  signed [15:0] pMultF;
	
	wire signed [6:0]  signedScale = {1'b0,i_scale}; // Verilog authorize wire signed a = ua; and generate one more bit, but Verilator is not. And I prefer explicit anyway.
	
	assign multF = i_dataIn * signedScale; // 10x7 -> 17 bit, but range is from [-512*63..511*63] (-32256,32193)

	always @(posedge i_clk)
	begin
		if (Reg1W) begin
			pWrite			<= i_dataWrt & i_nrst;
			pIndex			<= i_index;
			pBlk			<= i_blockNum;
			pMatrixComplete	<= i_matrixComplete & i_nrst;
			pFullBlkType	<= i_fullBlockType;
			pMultF          <= multF[15:0];
		end
	end
	
	// -------------------------------------------------------------------
	//   Stage 1 : Compute data (2nd multiplication) with the arrived
	//             the quantization factor
	// -------------------------------------------------------------------
	//   Compute :
	//	 Temporary Coef * Quantization Value => Output
	//                  * 1.0 if fullblockType
	//
	wire signed [23:0] outCalc;
	reg  signed [11:0] pOutCalc;
	wire         [6:0] LocalQuantValue	= useQuantStore ? storedQuant : valueQuant;
	wire signed [ 7:0] quant			= pFullBlkType  ? 8'd1 : { 1'b0, LocalQuantValue };

	// Spec says in No$PSX => (signed10bit(n AND 3FFh)*qt[k]*q_scale+4)/8
	
	//--------------------------------------------------------------------------------------------
	// First we do qt[k]*(q_scale*value)
	assign outCalc = (pMultF * quant); // 16x8 = 24 bit.	// Consider MUL to take 1 cycle, implement accordingly.

	roundDiv8AndClamp inst_roundDiv8AndClamp(
		.valueIn	(outCalc),
		.valueOut	(roundedOddTowardZeroExceptMinus1)
	);
	
	wire [11:0] roundedOddTowardZeroExceptMinus1;
	
	reg       ppWrite;
	reg [5:0] ppIndex;
	reg [2:0] ppBlk;
	reg       ppMatrixComplete;

	always @(posedge i_clk)
	begin
		if (Reg2W) begin
			ppWrite				<= pWrite & i_nrst;
			ppIndex				<= pIndex;
			ppBlk   			<= pBlk;
			ppMatrixComplete	<= pMatrixComplete & i_nrst;
			pOutCalc			<= roundedOddTowardZeroExceptMinus1;
		end
	end
	
	wire      	outWrite			= useReg2 ? ppWrite 			: pWrite;
	wire [5:0]	outIndex			= useReg2 ? ppIndex 			: pIndex;
	wire [2:0]	outBlk				= useReg2 ? ppBlk				: pBlk;
	wire      	outMatrixComplete	= useReg2 ? ppMatrixComplete	: pMatrixComplete;
	wire [11:0] outSelCalc 			= useReg2 ? pOutCalc			: roundedOddTowardZeroExceptMinus1;

	assign o_write    		= outWrite & i_nrst & (!i_freezePipe);
	assign o_writeIdx 		= outIndex;
	assign o_blockNum 		= outBlk;
	// 12 bit : -2048..+2047
	assign o_coefValue		= outSelCalc;
	assign o_matrixComplete = outMatrixComplete;	
endmodule
