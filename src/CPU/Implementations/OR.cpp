/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::OR_A_R8(uint8_t &rb)
{
	uint8_t		&ra = AF.reg8b.hi;

	ra |= rb;
	setFlag(Flag::Z, (ra == 0x00));
	unsetFlag(Flag::N);
	unsetFlag(Flag::H);
	unsetFlag(Flag::C);
	return (1);
}

uint8_t		CPU::OR_A_IM8()
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = fetchImmediateByte();

	ra |= rb;
	setFlag(Flag::Z, (ra == 0x00));
	unsetFlag(Flag::N);
	unsetFlag(Flag::H);
	unsetFlag(Flag::C);
	return (1);
}

uint8_t		CPU::OR_A_PR16(uint16_t &pRb)
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = _bus.readByte(pRb);

	ra |= rb;
	setFlag(Flag::Z, (ra == 0x00));
	unsetFlag(Flag::N);
	unsetFlag(Flag::H);
	unsetFlag(Flag::C);
	return (1);
}
