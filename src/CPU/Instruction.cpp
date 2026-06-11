/*
Created by: Emily (Em_iIy) Winnink
Created on: 01/06/2026
*/

#include "CPU/Instruction.hpp"


Instruction::Instruction(): opCode(OpCodes::NOP), ext(0x00)
{

}

Instruction::Instruction(OpCodes code): opCode(code), ext(0x00)
{

}

Instruction::~Instruction()
{

}

bool	Instruction::checkExtended()
{
	return (opCode == OpCodes::STOP || opCode == OpCodes::EXTENDED);
}

void	Instruction::setExtension(uint8_t extension)
{
	ext = extension;
}
