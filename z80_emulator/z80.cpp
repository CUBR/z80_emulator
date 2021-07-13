#include "z80.h"

void Z80::Reset() {
	PC = 0x0000;
	//interrupt mode 0
	//interrupt disable
	I = 0x00;
	R = 0x00;
}

void Z80::Init() {
	SP = PC = IX = IY = 0x0000;
	A = B = C = D = E = H = L = I = R = 0x00;
	F.S = F.Z = F.F5 = F.H = F.F3 = F.PV = F.C = 0;
}