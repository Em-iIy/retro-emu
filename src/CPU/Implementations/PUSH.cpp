/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::PUSH_R16(uint16_t &reg)
{
	Register &reg16 = reinterpret_cast<Register &>(reg);
	uint16_t	spValue = SP.getValue();

	_bus.writeByte(spValue - 1, reg16.getHi());
	_bus.writeByte(spValue - 2, reg16.getLo());

	SP.setValue(spValue - 2);
	return (1);
}
