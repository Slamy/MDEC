class VSPU_IF; // Help 

#include "../../../rtl/obj_dir/VSPU_IF.h"
#include "VCScanner.h"

#define MODULE mod
#define SCAN   pScan

// ----------
// TRICK WITH MACRO TO REGISTER THE MEMBERS OF THE VERILATED INSTANCE INTO MY VCD SCANNER...
// ----------

#undef VL_IN
#undef VL_OUT
#undef VL_SIG
#undef VL_SIGA
#undef VL_IN8
#undef VL_OUT8
#undef VL_SIG8
#undef VL_IN16
#undef VL_OUT16
#undef VL_SIG16
#undef VL_IN64
#undef VL_OUT64
#undef VL_SIG64
#undef VL_SIGW

#define VL_IN(NAME,size,s2)			SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_OUT(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIG(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIGA(NAME,size,s2,cnt)	SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_IN8(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_OUT8(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIG8(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_IN16(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_OUT16(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIG16(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_IN64(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_OUT64(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIG64(NAME,size,s2)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME );
#define VL_SIGW(NAME,size,s2,storageSize,depth)		SCAN->addMemberFullPath( VCScanner_PatchName(#NAME), WIRE, BIN,size+1,& MODULE ->## NAME,depth, (((u8*)& MODULE ->## NAME[1]) - ((u8*)& MODULE ->## NAME[0])));

void registerVerilatedMemberIntoScanner(VSPU_IF* mod, VCScanner* pScan) {
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(i_clk,0,0);
    VL_IN8(n_rst,0,0);
    VL_IN8(SPUCS,0,0);
    VL_IN8(SRD,0,0);
    VL_IN8(SWRO,0,0);
    VL_OUT8(dataOutValid,0,0);
    VL_OUT8(SPUINT,0,0);
    VL_IN8(SPUDACK,0,0);
    VL_OUT8(SPUDREQ,0,0);
    VL_IN8(inputL,0,0);
    VL_IN8(inputR,0,0);
    VL_OUT8(VALIDOUT,0,0);
    VL_IN16(addr,9,0);
    VL_IN16(dataIn,15,0);
    VL_OUT16(dataOut,15,0);
    VL_IN16(CDRomInL,15,0);
    VL_IN16(CDRomInR,15,0);
    VL_OUT16(AOUTL,15,0);
    VL_OUT16(AOUTR,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(SPU_IF__DOT__i_clk,0,0);
    VL_SIG8(SPU_IF__DOT__n_rst,0,0);
    VL_SIG8(SPU_IF__DOT__SPUCS,0,0);
    VL_SIG8(SPU_IF__DOT__SRD,0,0);
    VL_SIG8(SPU_IF__DOT__SWRO,0,0);
    VL_SIG8(SPU_IF__DOT__dataOutValid,0,0);
    VL_SIG8(SPU_IF__DOT__SPUINT,0,0);
    VL_SIG8(SPU_IF__DOT__SPUDACK,0,0);
    VL_SIG8(SPU_IF__DOT__SPUDREQ,0,0);
    VL_SIG8(SPU_IF__DOT__inputL,0,0);
    VL_SIG8(SPU_IF__DOT__inputR,0,0);
    VL_SIG8(SPU_IF__DOT__VALIDOUT,0,0);
    VL_SIG8(SPU_IF__DOT__o_dataReadRAM,0,0);
    VL_SIG8(SPU_IF__DOT__o_dataWriteRAM,0,0);
    VL_SIG8(SPU_IF__DOT__SPURAMByteSel,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_re,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_we,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_byteSelect,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__readByteSelect_reg,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__hig,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__low,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__readByteSelect_reg1,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__readByteSelect_reg2,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__readByteSelect_reg3,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__i_clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__n_rst,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SPUCS,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SRD,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SWRO,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__dataOutValid,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SPUINT,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SPUDREQ,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SPUDACK,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__o_dataReadRAM,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__o_dataWriteRAM,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__inputL,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__inputR,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__VALIDOUT,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SPUMemWRSel,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__writeSPURAM,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__readFIFO,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isFIFOFull,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__emptyFifo,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isFIFOHasData,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__fifo_level,5,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__internalWrite,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__internalRead,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_SPUEnable,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_SPUNotMuted,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_NoiseFrequShift,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_NoiseFrequStep,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_NoiseStepStore,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_ReverbEnable,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_SPUIRQEnable,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_SPUTransferMode,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_ExtReverbEnabled,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_CDAudioReverbEnabled,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_ExtEnabled,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_CDAudioEnabled,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_SPUIRQSet,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__negNoiseStep,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isD8,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isD80_DFF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isChannel,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__channelAdr,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isDMAXferWR,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isDMAXferRD,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__dataTransferBusy,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__dataTransferReadReq,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__dataTransferWriteReq,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__dataTransferRDReq,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__writeFIFO,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__updateVoiceADPCMAdr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__regIsLastADPCMBlk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reg_isRepeatADPCMFlag,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__internalReadPipe,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__incrXFerAdr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__currVoice6Bit,5,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__currVoice,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__voiceCounter,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isLastCycle,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ctrl44Khz,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__side22Khz,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__currV_shift,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__currV_filter,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__voiceIncrement,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__decodeSample,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__updatePrev,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__loadPrev,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__adpcmSubSample,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__check_Kevent,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__zeroIndex,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__idxBuff,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__setEndX,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__setAsStart,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isRepeatADPCMFlag,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isNotEndADPCMBlock,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__storePrevVxOut,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ctrlSendOut,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__clearSum,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__readSPU,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__updateVoiceADPCMPos,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__updateVoiceADPCMPrev,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isVoice1,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isVoice3,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reverbCnt,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__sideAReg,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__sideBReg,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__minus2,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__selB,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__accAdd,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isRight,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isFIFOWR,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__KON,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__PMON,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__EON,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__SgnS2U,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__pitchSel,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__GT4000,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__nGT4000,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__nextNewBlock,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__nextNewLine,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__isNullADSR,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__newSampleReady,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__launchInterpolator,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__validSampleStage2,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__readRingBuffAdr,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NON,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__AdsrState,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__EnvExponential,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__EnvDirection,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__EnvShift,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__EnvStep,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__computedNextAdsrState,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__cmpLevel,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__susLvl,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__tstState,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__shift2ExpIncr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__step2ExpDecr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__reachZero,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__tooBigLvl,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__tooLowLvl,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__changeADSRState,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__nextAdsrState,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__clearKON,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__PValidSample,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__rst,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__wr_en_i,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__rd_en_i,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__full_o,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__empty_o,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__write_pointer,5,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__read_pointer,5,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__empty_int,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__full_or_empty,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__raddr,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__pRaddr,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__pRd_en_i,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__overflowAdr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__i_Shift,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__i_Filter,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__samplePosition,1,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__shift,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__filter,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__filterPos,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__filterNeg,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__nibble,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__firstStageNibble,6,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__sgn,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__mySignedDivisionBy64__DOT__DivN,6,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__overF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__isOne,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__sgn,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__andV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__orV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__i_clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__i_we,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__i_clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__i_go,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__i_interpolator,7,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__i_newPos,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__o_readRingBuffAdr,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__o_validSample,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__regIdx,2,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__bufOff,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__bufAdrTmp,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__AdrHead,4,2);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__instanceInterpROM__DOT__clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__clk,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__i_nrst,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__i_ctrl44Khz,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__i_noiseShift,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__i_noiseStep,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__parityBit,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__i_EnvShift,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__i_EnvStep,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__i_shift2ExpIncr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__i_step2ExpDecr,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__sh,3,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__st1,4,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__st2,6,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ClampADSRVolume__DOT__isPos,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__ClampADSRVolume__DOT__overF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__overF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__isOne,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__sgn,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__andV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__orV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__overF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__isOne,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__sgn,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__andV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__orV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__overF,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__isOne,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__sgn,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__andV,0,0);
    VL_SIG8(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__orV,0,0);
    VL_SIG16(SPU_IF__DOT__addr,9,0);
    VL_SIG16(SPU_IF__DOT__dataIn,15,0);
    VL_SIG16(SPU_IF__DOT__dataOut,15,0);
    VL_SIG16(SPU_IF__DOT__CDRomInL,15,0);
    VL_SIG16(SPU_IF__DOT__CDRomInR,15,0);
    VL_SIG16(SPU_IF__DOT__AOUTL,15,0);
    VL_SIG16(SPU_IF__DOT__AOUTR,15,0);
    VL_SIG16(SPU_IF__DOT__i_dataInRAM,15,0);
    VL_SIG16(SPU_IF__DOT__o_dataOutRAM,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_data,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__o_q,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__data1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__data2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__data3,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__addr,9,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dataIn,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dataOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__i_dataInRAM,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__o_dataOutRAM,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CDRomInL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CDRomInR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__AOUTL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__AOUTR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__internal_dataOutRAM,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__regRingBufferIndex,8,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reverbWriteValue,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__fifoDataOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_mainVolLeft,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_mainVolRight,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_reverbVolLeft,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_reverbVolRight,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_mBase,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_ramIRQAddr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_dataTransferAddr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_CDVolumeL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_CDVolumeR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_ExtVolumeL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_ExtVolumeR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__regSoundRAMDataXFerCtrl,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dataOutw,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__pipeDataOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_sampleRate,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_startAddr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_repeatAddr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_adpcmCurrAdr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__sampleOutADPCMRAW,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dAPF1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dAPF2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vIIR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vCOMB1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vCOMB2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vCOMB3,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vCOMB4,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vWALL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vAPF1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vAPF2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLSAME,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRSAME,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__negvAPF1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__negvAPF2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLCOMB1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRCOMB1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLCOMB2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRCOMB2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dLSAME,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dRSAME,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLDIFF,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRDIFF,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLCOMB3,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRCOMB3,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLCOMB4,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRCOMB4,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dLDIFF,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__dRDIFF,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLAPF1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRAPF1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mLAPF2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mRAPF2,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vLIN,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vRIN,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mulA,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__mulB,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__lineIn,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__resMulAB16,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__addB,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__clampedAddC,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__accReverb,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__adrB,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__VxPitch,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__prevChannelVxOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__tmpRes,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__lowPart,13,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__sampleOutADPCM,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__voiceSample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ringBufferADR,9,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__readSample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__noiseLevel,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ChannelValue,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_VolumeL,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__currV_VolumeR,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__AdsrVol,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__AdsrLo,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__AdsrHi,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__EnvLevel,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__EnvSusLevel,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__adsrStep,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__nextAdsrVol,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__sAdsrVol,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__vxOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__PvxOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reverbApply,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_CDRomInL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__reg_CDRomInR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__volume,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__valueReverbFinal,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__regValueReverbLeft,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__regValueReverbRight,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CD_addL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CD_addR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CdSideL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__CdSideR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__cdReverbInput,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__volL,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__volR,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__outL,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__outR,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__wr_data_i,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__rd_data_o,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__outputCache,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InternalFifo__DOT__straight_rd_data_o,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__i_baseAdr,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__inputRAW,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__i_PrevSample0,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__i_PrevSample1,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__o_sample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__baseSample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__valueOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__orStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__andStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__i_data,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__i_wordAddr,9,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__o_q,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__InterRingBuffInstance__DOT__addr_reg,9,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__i_sample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__o_sample_c5,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__ratio,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__romAdr,8,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__src,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__cumulativeSample,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__instanceInterpROM__DOT__adr,8,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__instanceInterpROM__DOT__dataOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__instanceInterpROM__DOT__data,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__o_noiseOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__noiseLevel,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__shiftedNoiseAdd,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__Noise_Value,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__i_adsrLevel,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__o_AdsrStep,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__st3,10,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__adsrStepBeforeOptDiv,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__sAdsrLevel,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ClampADSRVolume__DOT__valueOut,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__ClampADSRVolume__DOT__andStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__valueOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__orStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__andStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__valueOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__orStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__andStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__valueOut,15,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__orStage,14,0);
    VL_SIG16(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__andStage,14,0);
    VL_SIG(SPU_IF__DOT__o_adrRAM,17,0);
    VL_SIG(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__i_wordAddr,17,0);
    VL_SIG(SPU_IF__DOT__SPU_RAM_FPGAInternal__DOT__addr_reg,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__o_adrRAM,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__debugCnt,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__internal_adrRAM,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reverbAdr,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_tmpAdpcmPrev,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_ignoreLoadRepeatAddress,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_kon,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_koff,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_kEvent,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_kMode,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_pmon,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_non,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_eon,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_endx,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reg_dataTransferAddrCurr,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__currV_adpcmPos,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__currV_adpcmPrev,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__adrRAM,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__resMulAB,30,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__addC,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reverbAdrPreRing,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reverb_CounterWord,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__pitchMul,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__nextPitch,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__nextADPCMPos,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__AdsrCycleCount,22,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__cycleCountStart,22,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__decAdsrCycle,22,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__nextAdsrCycle,22,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__tmpVolStep,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__tmpVxOut,30,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__applyLVol,30,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__applyRVol,30,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__sumL,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__sumR,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__sumReverb,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__valueReverb,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__tmpCDRomL,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__tmpCDRomR,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__reverbFull,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__CDAndReverbL,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__CDAndReverbR,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__postVolL,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__postVolR,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__i_offsetRegister,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__i_offsetCounter,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__o_reverbAdr,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__addressWord,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__addressWord2,19,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ReverbWrapAdrInst__DOT__rollAdr,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__p0,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__p1,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__t,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__div64,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__addBase,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__mySignedDivisionBy64__DOT__valueIn,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__mySignedDivisionBy64__DOT__valueOut,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__mySignedDivisionBy64__DOT__outCalcDiv,23,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADPCMDecoderUnit__DOT__myClampSRange__DOT__valueIn,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__acc,17,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__Interpolator_inst__DOT__res,31,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__noiseTimer,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__M4to7,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__inputTimer,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__offset,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__secondT,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__thirdT,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__finalT,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__NoiseUnit_inst__DOT__writeT,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__o_CycleCount,22,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__st4,18,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__stepE,29,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ADSRCycleCountInstance__DOT__newCycleCount,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__ClampADSRVolume__DOT__valueIn,16,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__Reverb_Clamp__DOT__valueIn,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__Left_Clamp__DOT__valueIn,20,0);
    VL_SIG(SPU_IF__DOT__SPU_instance__DOT__RightClamp__DOT__valueIn,20,0);
    VL_SIG64(SPU_IF__DOT__SPU_instance__DOT__mulPitch,32,0);
    VL_SIG64(SPU_IF__DOT__SPU_instance__DOT__sumPostVolL,35,0);
    VL_SIG64(SPU_IF__DOT__SPU_instance__DOT__sumPostVolR,35,0);
}

