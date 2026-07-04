/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#include "CPU/CPU.hpp"

uint8_t		CPU::CALL_IM16()
{
	uint16_t	data = fetchImmediate2Bytes();
	PUSH_R16(PC.reg16b);
	PC.setValue(data);
	return (1);
}

uint8_t		CPU::CALL_FLAG_IM16(Flag flag)
{
	uint16_t	data = fetchImmediate2Bytes();
	if (checkFlag(flag))
	{
		PUSH_R16(PC.reg16b);
		PC.setValue(data);
	}
	return (1);
}

uint8_t		CPU::CALL_NFLAG_IM16(Flag flag)
{
	uint16_t	data = fetchImmediate2Bytes();
	if (!checkFlag(flag))
	{
		PUSH_R16(PC.reg16b);
		PC.setValue(data);
	}
	return (1);
}
