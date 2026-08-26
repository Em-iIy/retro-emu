/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#include "Cartridge/MBC/MBC2.hpp"

#include <iostream>

MBC2::MBC2(uint16_t romBankCount, uint16_t ramBankCount): MBC(romBankCount, ramBankCount)
{
}

MBC2::~MBC2() {};

uint8_t		MBC2::readROM(uint16_t address)
{
	return (rom.readByte(address));
}

void		MBC2::writeROM(uint16_t address, uint8_t value)
{
	handleRegisters(address, value);
}

uint8_t		MBC2::readRAM(uint16_t address)
{
	if (ramEnabled == false)
		return (0xFF);
	uint16_t ramAddress = (address - EXT_RAM_START_ADDRESS) & 0x1FF;
	return (mbc2Ram.readByte(ramAddress));
}

void		MBC2::writeRAM(uint16_t address, uint8_t value)
{
	if (ramEnabled == false)
		return ;
	uint16_t ramAddress = (address - EXT_RAM_START_ADDRESS) & 0x1FF;
	mbc2Ram.writeByte(ramAddress, value);
}

void		MBC2::handleRegisters(uint16_t address, uint8_t value)
{

	if (address >= RAM_ENABLE_ROM_BANK_NUMBER_START && address <= RAM_ENABLE_ROM_BANK_NUMBER_END)
	{
		if ((address & 0x100) == 0)
		{
			if ((value & 0b1111) == 0xA)
				ramEnabled = true;
			else
				ramEnabled = false;
		}
		else
		{
			uint16_t	maskedValue = value & 0b1111;

			if (maskedValue == 0x00)
				maskedValue = 0x01;
			romBankNumber = maskedValue;
			rom.switchBank(romBankNumber);
		}
	}
}
