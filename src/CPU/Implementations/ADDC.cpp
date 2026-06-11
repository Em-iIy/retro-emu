/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::ADDC_A_R8(uint8_t &rb)
{
	uint8_t		&ra = AF.reg8b.hi;
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra + rbc;
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::ADDC_A_IM8()
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = fetchImmediateByte();
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra + rbc;
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}

uint8_t		CPU::ADDC_A_PR16(uint16_t &pRb)
{
	uint8_t		&ra = AF.reg8b.hi;
	uint8_t		rb = _bus.readByte(pRb);
	uint16_t	rbc = rb + checkFlag(Flag::C);
	uint16_t	result = ra + rbc;
	unsetFlag(Flag::N);
	setFlag(Flag::H, checkCarry(ra, rb, 3));
	setFlag(Flag::C, checkCarry(ra, rb, 7));

	ra = result & 0xFF;
	setFlag(Flag::Z, (ra == 0x00));
	return (1);
}
