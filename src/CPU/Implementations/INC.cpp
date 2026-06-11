/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::INC_R8(uint8_t &reg)
{
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(reg, 1, 3));
	reg++;
	setFlag(Flag::Z, (reg == 0x00));
	return (1);
}

uint8_t		CPU::INC_R16(uint16_t &reg)
{
	reg++;
	return (1);
}

uint8_t		CPU::INC_PR16(uint16_t &pDst)
{
	uint8_t value = _bus.readByte(pDst);
	INC_R8(value);
	_bus.writeByte(pDst, value);
	return (1);
}
