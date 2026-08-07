/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/08/2026
*/

#include "CPU/CPU.hpp"

#include <array>

const std::array<uint8_t, 8> RST_TABLE = {0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38};


uint8_t		CPU::RST(uint8_t idx)
{
	uint16_t	spValue = SP.getValue();

	_bus.writeByte(spValue - 1, PC.getHi());
	_bus.writeByte(spValue - 2, PC.getLo());

	SP.setValue(spValue - 2);
	PC.setValue(RST_TABLE.at(idx));
	return (1);
}
