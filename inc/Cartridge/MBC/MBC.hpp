/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#pragma once

#include <cstdint>

#include "../ROM.hpp"
#include "../ExtRAM.hpp"

class MBC
{
	public:
		MBC() = delete;
		MBC(uint16_t romBankCount, uint16_t ramBankCount)
		{
			rom.initBanks(romBankCount);
			ram.initBanks(ramBankCount);
			hasRam = (ramBankCount > 0);
		};
		virtual ~MBC() {};

		virtual uint8_t		readROM(uint16_t address) = 0;
		virtual void		writeROM(uint16_t address, uint8_t value) = 0;
		virtual uint8_t		readRAM(uint16_t address) = 0;
		virtual void		writeRAM(uint16_t address, uint8_t value) = 0;

		ROM			rom;
		ExtRAM		ram;

		bool		hasRam = false;
		bool		ramEnabled = false;
		uint32_t	romBankNumber = 1;
		uint32_t	ramBankNumber = 0;
};
