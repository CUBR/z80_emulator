#pragma once
#include "Defines.h"
struct Mem32K {
	u8 Data[32 * 1024];
	u8 Read(u16 Addr);
	void Init();
};