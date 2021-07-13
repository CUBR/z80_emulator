#include "z80.h"
#include "Memory.h"
int main() {
	Z80 CPU;
	Mem32K MEM;
	CPU.Init();
	MEM.Init();
	CPU.Reset();
}
