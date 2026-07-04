/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::POP_R16(uint16_t &reg)
{
	Register	&reg16 = reinterpret_cast<Register &>(reg);
	uint16_t	spValue = SP.getValue();

	reg16.setLo(_bus.readByte(spValue));
	reg16.setHi(_bus.readByte(spValue + 1));

	SP.setValue(spValue + 2);
	return (1);
}
