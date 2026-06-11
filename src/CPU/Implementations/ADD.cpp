/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::ADD_R8_R8(uint8_t &ra, uint8_t &rb)
{
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra += rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::ADD_R8_IM8(uint8_t &ra)
{
	uint8_t	rb = fetchImmediateByte();
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra += rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::ADD_R8_PR16(uint8_t &ra, uint16_t &pRb)
{
	uint8_t	rb = _bus.readByte(pRb);
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra += rb;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::ADD_R16_R16(uint16_t &ra, uint16_t &rb)
{
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 11));
	setFlag(Flag::C, checkCarry(ra, rb, 15));

	ra += rb;
	return (1);
}
