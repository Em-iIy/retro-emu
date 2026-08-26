/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#pragma once

#include "Bank.hpp"

#include <string>
#include <vector>

#define ROM_BANK_SIZE 0x4000
#define ROM_START_ADDRESS 0x0000

using ROMBank = Bank<ROM_BANK_SIZE>;

class ROM {
	public:
		ROM();
		~ROM();

		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		void					initBanks(uint16_t count);
		void					switchBank(uint16_t number);
		void					fill(std::vector<uint8_t> &data);

	private:

		ROMBank					&getCurrentBank();

		std::vector<ROMBank>	banks;

		uint16_t				currentBank = 0x01;
		uint16_t				bankCount = 2;

		
};
