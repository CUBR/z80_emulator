#include "z80.h"

void z80::Init()
{
}

void z80::Clock()
{
	switch (cycle)
	{
	default:
		break;

	case 1:
		AddressBus = PC;
		MREQ = true;
		RD = true;
		break;
	case 2:

	}
}

void z80::Reset()
{
}

int z80::ReadMemory(uint16_t Address)
{
	MREQ = true;
	RD = true;
	WR = false;
	BUSACK = true;

	AddressBus = Address;

	return 0;
}

int z80::WriteMemory(uint16_t Address, uint8_t Data)
{
	MREQ = true;
	WR = true;
	RD = false;
	BUSACK = false;

	AddressBus = Address;
	DataBus = Data;
	return 0;
}

void OpcodeFetch() {
	
}
