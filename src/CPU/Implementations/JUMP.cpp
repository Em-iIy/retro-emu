/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

uint8_t	CPU::JUMP_IM16()
{
	PC.setValue(fetchImmediate2Bytes());
	return (1);
}

uint8_t		CPU::JUMP_RELATIVE_IM8()
{
	PC.setValue(PC.getValue() + fetchImmediateByte());
	return (1);
}

uint8_t		CPU::JUMP_RELATIVE_FLAG_IM8(Flag flag)
{
	uint8_t	data = fetchImmediateByte();
	if (checkFlag(flag))
		PC.setValue(PC.getValue() + data);
	return (1);
}
uint8_t		CPU::JUMP_RELATIVE_NFLAG_IM8(Flag flag)
{
	uint8_t	data = fetchImmediateByte();
	if (!checkFlag(flag))
		PC.setValue(PC.getValue() + data);
	return (1);
}
