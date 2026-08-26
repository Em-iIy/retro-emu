/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#pragma once

#include "Bank.hpp"

#include <vector>

#define EXT_RAM_BANK_SIZE 0x2000
#define EXT_RAM_START_ADDRESS 0xA000

using ExtRAMBank = Bank<EXT_RAM_BANK_SIZE>;

class ExtRAM {
	public:
		ExtRAM();
		~ExtRAM();

		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		void					initBanks(uint16_t count);
		void					switchBank(uint16_t number);

	private:

		ExtRAMBank				&getCurrentBank();

		std::vector<ExtRAMBank>	banks;
		uint16_t				bankCount = 0;
		uint16_t				currentBank = 1;
};
