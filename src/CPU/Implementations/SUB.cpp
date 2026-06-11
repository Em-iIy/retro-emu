/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::SUB_A_R8(uint8_t &rb)
{
	uint8_t	&ra = AF.reg8b.hi;
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rb, 3));
	setFlag(Flag::C, (rb > ra));

	ra -= rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::SUB_A_IM8()
{
	uint8_t	&ra = AF.reg8b.hi;
	uint8_t	rb = fetchImmediateByte();
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rb, 3));
	setFlag(Flag::C, (rb > ra));

	ra -= rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::SUB_A_PR16(uint16_t &pRb)
{
	uint8_t	&ra = AF.reg8b.hi;
	uint8_t	rb = _bus.readByte(pRb);
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rb, 3));
	setFlag(Flag::C, (rb > ra));

	ra -= rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}
