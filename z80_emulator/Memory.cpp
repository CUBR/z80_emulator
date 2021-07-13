#include "Memory.h"

u8 Mem32K::Read(u16 Addr)
{
    //Just returns data rn, will have if's for different sections of memory in future
    return Data[Addr];
}

void Mem32K::Init()
{
    u32 x = 32*1024;
    while (x >= 0) {
        Data[x] = 0x00;
    }
}
