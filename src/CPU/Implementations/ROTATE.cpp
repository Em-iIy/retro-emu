/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::RLCA()
{
	uint8_t	&ra = AF.getHiRef();
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | carry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RLA()
{
	uint8_t	&ra = AF.getHiRef();
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | prevCarry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RRCA()
{
	uint8_t	&ra = AF.getHiRef();
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (carry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RRA()
{
	uint8_t	&ra = AF.getHiRef();
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (prevCarry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RLC_R8(uint8_t &ra)
{
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | carry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RLC_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | carry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}

uint8_t		CPU::RL_R8(uint8_t &ra)
{
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | prevCarry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RL_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b10000000;
	ra = (ra << 1) | prevCarry;
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}

uint8_t		CPU::RRC_R8(uint8_t &ra)
{
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (carry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RRC_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (carry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}

uint8_t		CPU::RR_R8(uint8_t &ra)
{
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (prevCarry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	return (1);
}

uint8_t		CPU::RR_PR16(uint16_t &pRa)
{
	uint8_t	ra = _bus.readByte(pRa);
	bool	prevCarry = checkFlag(Flag::C);
	bool	carry;

	carry = ra & 0b00000001;
	ra = (ra >> 1) | (prevCarry << 7);
	setFlag(Flag::C, carry);
	setFlag(Flag::Z, (ra == 0x0));
	_bus.writeByte(pRa, ra);
	return (1);
}
