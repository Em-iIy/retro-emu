/*
Created by: Emily (Em_iIy) Winnink
Created on: 01/06/2026
*/

#include "CPU/Instruction.hpp"


Instruction::Instruction(): opCode(OpCodes::NOP), ext(OpCodesExt::RLC_B)
{

}

Instruction::Instruction(OpCodes code): opCode(code), ext(OpCodesExt::RLC_B)
{

}

Instruction::~Instruction()
{

}

bool	Instruction::checkExtended()
{
	return (opCode == OpCodes::STOP || opCode == OpCodes::EXTENDED);
}

void	Instruction::setExtension(OpCodesExt extension)
{
	ext = extension;
}
