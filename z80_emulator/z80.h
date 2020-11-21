#ifndef z80
#define z80
#include <stdint.h>
class z80 {

private:
//pins
	// input or output
	uint8_t DataBus;

	//output
	uint16_t AddressBus;

	bool MREQ = false; //memory request, indicates address bus holds a valid address
	bool IORQ = false; //io request, indicates lower half of address bus holds valid io address
	bool RD = false; //read, indicates cpu wants to read data from memory or io device
	bool WR = false; //write, indicates cpu wants to write data to memory or io device
	bool M1 = false; //machine cycle 1, w' mreq indicates opcode fetch cycle, w' ioreq indicates interupt acknowledge cycle
	bool RFRSH = false; //refresh, w' mreq indicates lower 7 bits of address bus can be used as refresh address for dynamic memories
	bool BUSACK = false; //bus acknowledge, indicates data, address, mreq, ioreq, rw and wr can be externally controlled

	//input
	bool HALT = false; //halt, cpu has hit halt instruction and is waiting for int or nmi to continue, executes nop's during this
	bool INT = false; //interupt request, will interupt if IFF=1
	bool NMI = false; //non masksable interrupt, forces an interupt regardless of IFF
	bool WAIT = false; //wait, indicates to cpu that memory or io devices are not ready for data transfer. enters wait state as long as is active
	bool BUSREQ = false; //bus request, forces busack

//internal registers
	//8 bit
	uint8_t A, B, C, D, E, H, L, I, R,
		A2, B2, C2, D2, E2, H2, L2, F, F2;
	//Accumulator 1, A-L general registers, Interupt vector, Refresh vector
	//Accumulator 2, A2-L2 general registers, flags 1, flags2
	//flags: sign, zero, half carry, parity, carry, additon/subtraction

	//16 bit
	uint16_t IX, IY, SP, PC;

	//interupts
	bool IFF1, IFF2, IMFa, IMFb;




public:
	void Init();

	void Clock();

	void Reset();

	void ReadMemory(uint16_t Address);

};

#endif // !z80
