/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/04/2026
*/

#pragma once

#include <cstdint>
#include "enums/OpCodes.hpp"
#include "enums/OpCodesExt.hpp"

class Instruction
{
	public:
		Instruction();
		Instruction(OpCodes code);
		~Instruction();

		bool	checkExtended();
		void	setExtension(OpCodesExt extension);

		OpCodes	opCode;
		OpCodesExt	ext;
};
