/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#pragma once

#include "MBC.hpp"

#define RAM_ENABLE_ROM_BANK_NUMBER_START	0x0000
#define RAM_ENABLE_ROM_BANK_NUMBER_END		0x3FFF

#define MBC2_RAM_SIZE						512

class MBC2 : public MBC
{
	public:
		MBC2(uint16_t romBankCount, uint16_t ramBankCount);
		~MBC2();

		uint8_t		readROM(uint16_t address);
		void		writeROM(uint16_t address, uint8_t value);
		uint8_t		readRAM(uint16_t address);
		void		writeRAM(uint16_t address, uint8_t value);
	
	private:
		void		handleRegisters(uint16_t address, uint8_t value);

		Bank<MBC2_RAM_SIZE>	mbc2Ram;
};
