/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#pragma once

#include "MBC.hpp"

#define RAM_ENABLE_START			0x0000
#define RAM_ENABLE_END				0x1FFF

#define ROM_BANK_NUMBER_START		0x2000
#define ROM_BANK_NUMBER_END			0x3FFF

#define RAM_BANK_NUMBER_START		0x4000
#define RAM_BANK_NUMBER_END			0x5FFF

#define BANKING_MODE_SELECT_START	0x6000
#define BANKING_MODE_SELECT_END		0x7FFF

class MBC1 : public MBC
{
	public:
		MBC1(uint16_t romBankCount, uint16_t ramBankCount);
		~MBC1();

		uint8_t		readROM(uint16_t address);
		void		writeROM(uint16_t address, uint8_t value);
		uint8_t		readRAM(uint16_t address);
		void		writeRAM(uint16_t address, uint8_t value);
	
	private:
		void		handleRegisters(uint16_t address, uint8_t value);
		uint8_t		bankingMode = 0;
};
