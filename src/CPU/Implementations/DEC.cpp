/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::DEC_R8(uint8_t &reg)
{
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(reg, 1, 3));
	reg--;
	setFlag(Flag::Z, (reg == 0x00));
	return (1);
}

uint8_t		CPU::DEC_R16(uint16_t &reg)
{
	reg--;
	return (1);
}

uint8_t		CPU::DEC_PR16(uint16_t &pDst)
{
	uint8_t value = _bus.readByte(pDst);
	DEC_R8(value);
	_bus.writeByte(pDst, value);
	return (1);
}
