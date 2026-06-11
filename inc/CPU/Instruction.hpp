/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/04/2026
*/

#pragma once

#include <cstdint>
#include "enums/OpCodes.hpp"

class Instruction
{
	public:
		Instruction();
		Instruction(OpCodes code);
		~Instruction();

		bool	checkExtended();
		void	setExtension(uint8_t extension);

		OpCodes	opCode;
		uint8_t	ext;
};
