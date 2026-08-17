/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/08/2026
*/

#pragma once

#include "AMemoryAccessor.hpp"
#include "Bank.hpp"

#define HRAM_BANK_SIZE 0x007E
#define HRAM_START_ADDRESS 0xFF80

using HRAMBank = Bank<HRAM_BANK_SIZE>;

class HRAM: public AMemoryAccessor {
	public:
		HRAM();
		~HRAM();

		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

	private:

		HRAMBank	bank;
};
