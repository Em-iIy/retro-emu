/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::RET()
{
	POP_R16(PC.reg16b);
	return (1);
}

uint8_t		CPU::RETI()
{
	POP_R16(PC.reg16b);
	setIME(true);
	return (1);
}

uint8_t		CPU::RET_FLAG(Flag flag)
{
	if (checkFlag(flag))
		POP_R16(PC.reg16b);
	return (1);
}

uint8_t		CPU::RET_NFLAG(Flag flag)
{
	if (!checkFlag(flag))
		POP_R16(PC.reg16b);
	return (1);
}
