#pragma once
#include "Defines.h"

struct Z80 {
	u16 SP, PC, IX, IY; //16 bit registers
	u8 A, B, C, D, E, H, L, I, R; // 8 bit registers
	//registers such as AB are stored as two 8 bit variables and are temporarily combined for 16 bit operations
	//this may be changed depending on performance and use of combined registers (might store HL as 16 bit)

	//flag register bit field
	struct  Freg
	{u8 S:1, Z:1, F5:1, H:1, F3:1, PV:1, N:1, C:1;};
	Freg F;
	void Reset();

	void Init();
};



