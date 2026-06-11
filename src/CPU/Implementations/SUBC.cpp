/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::SUBC_A_R8(uint8_t &rb)
{
	uint8_t		&ra = AF.reg8b.hi;
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra - rbc;
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rbc, 3));
	setFlag(Flag::C, (rbc > ra));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::SUBC_A_IM8()
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = fetchImmediateByte();
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra - rbc;
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rbc, 3));
	setFlag(Flag::C, (rbc > ra));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::SUBC_A_PR16(uint16_t &pRb)
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = _bus.readByte(pRb);
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra - rbc;
	setFlag(Flag::N);
	setFlag(Flag::H, checkBorrow(ra, rbc, 3));
	setFlag(Flag::C, (rbc > ra));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}
