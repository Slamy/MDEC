6'h0 : retAdr = 9'd0; // NOP
6'h1 : retAdr = 9'd230; // RTPS
6'h2 : retAdr = 9'd285; // MVMVA_Buggy
6'h6 : retAdr = 9'd314; // NCLIP
6'hc : retAdr = 9'd308; // OP
6'h10 : retAdr = 9'd188; // DPCS
6'h11 : retAdr = 9'd222; // INTPL
6'h12 : retAdr = 9'd277; // MVMVA
6'h13 : retAdr = 9'd1; // NCDS
6'h14 : retAdr = 9'd175; // CDP
6'h16 : retAdr = 9'd20; // NCDT
6'h1b : retAdr = 9'd108; // NCCS
6'h1c : retAdr = 9'd164; // CC
6'h1e : retAdr = 9'd64; // NCS
6'h20 : retAdr = 9'd78; // NCT
6'h28 : retAdr = 9'd303; // SQR
6'h29 : retAdr = 9'd214; // DPCL
6'h2a : retAdr = 9'd196; // DPCT
6'h2d : retAdr = 9'd266; // AVSZ3
6'h2e : retAdr = 9'd271; // AVSZ4
6'h30 : retAdr = 9'd244; // RTPT
6'h3d : retAdr = 9'd298; // GPF
6'h3e : retAdr = 9'd293; // GPL
6'h3f : retAdr = 9'd125; // NCCT
default: retAdr = 9'd0; // UNDEF -> MAP TO NOP
