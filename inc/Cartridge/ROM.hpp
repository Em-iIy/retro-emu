/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#pragma once

#include "AMemoryAccessor.hpp"
#include "Bank.hpp"

#include <string>
#include <vector>

#define ROM_BANK_SIZE 0x4000
#define ROM_START_ADDRESS 0x0000

using ROMBank = Bank<ROM_BANK_SIZE>;

class ROM: public AMemoryAccessor {
	public:
		ROM();
		~ROM();

		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		void					initBanks(uint16_t count);
		void					fill(std::vector<uint8_t> &data);

	private:

		ROMBank					&_getCurrentBank();

		std::vector<ROMBank>	_banks;

		uint16_t				_currentBank = 0x01;
		uint16_t				_bankCount = 2;

		
};
