/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#pragma once

#include "AMemoryAccessor.hpp"
#include "Bank.hpp"

#include <string>
#include <vector>

#define WRAM_BANK_SIZE 0x1000
#define WRAM_START_ADDRESS 0xC000

using WRAMBank = Bank<WRAM_BANK_SIZE>;

class WRAM: public AMemoryAccessor {
	public:
		WRAM();
		~WRAM();

		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		void					initBanks(uint16_t count);
		void					fill(std::vector<uint8_t> &data);

	private:

		WRAMBank					&_getCurrentBank();

		std::vector<WRAMBank>	_banks;

		uint16_t				_currentBank = 0x01;
		uint16_t				_bankCount = 2;

		
};
