/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::SLA_R8(uint8_t &ra)
{
	bool	carry;

	carry = ra & 0b10000000;
	ra = ra << 1;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::SLA_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	carry;

	carry = ra & 0b10000000;
	ra = ra << 1;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}

uint8_t		CPU::SRA_R8(uint8_t &ra)
{
	bool	carry;
	uint8_t	result;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (ra & 0b10000000);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::SRA_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	carry;
	uint8_t	result;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (ra & 0b10000000);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}

uint8_t		CPU::SRL_R8(uint8_t &ra)
{
	bool	carry;
	uint8_t	result;

	carry = ra & 0b00000001;
	ra = (ra >> 1);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::SRL_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	carry;
	uint8_t	result;

	carry = ra & 0b00000001;
	ra = (ra >> 1);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}
