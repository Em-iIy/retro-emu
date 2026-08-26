/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#include "Cartridge/MBC/MBC5.hpp"

#include <iostream>

MBC5::MBC5(uint16_t romBankCount, uint16_t ramBankCount): MBC(romBankCount, ramBankCount)
{
}

MBC5::~MBC5() {};

uint8_t		MBC5::readROM(uint16_t address)
{
	return (rom.readByte(address));
}

void		MBC5::writeROM(uint16_t address, uint8_t value)
{
	handleRegisters(address, value);
}

uint8_t		MBC5::readRAM(uint16_t address)
{
	if (ramEnabled == false || hasRam == false)
		return (0xFF);
	return (ram.readByte(address));
}

void		MBC5::writeRAM(uint16_t address, uint8_t value)
{
	if (ramEnabled == false || hasRam == false)
		return ;
	ram.writeByte(address, value);
}

void		MBC5::handleRegisters(uint16_t address, uint8_t value)
{

	if (address >= RAM_ENABLE_START && address <= RAM_ENABLE_END)
	{
		if ((value & 0b1111) == 0xA)
			ramEnabled = true;
		else
			ramEnabled = false;
	}
	else if (address >= ROM_BANK_LOWER_NUMBER_START && address <= ROM_BANK_LOWER_NUMBER_END)
	{
		uint16_t	maskedValue = value & 0xFF;

		romBankNumber = (romBankNumber & ~0xFF) + maskedValue;
		rom.switchBank(romBankNumber);
	}
	else if (address >= ROM_BANK_UPPER_NUMBER_START && address <= ROM_BANK_UPPER_NUMBER_END)
	{
		uint16_t	maskedValue = value & 0b1;

		romBankNumber = (romBankNumber & 0xFF) + (maskedValue << 8);
		rom.switchBank(romBankNumber);
	}
	else if (address >= RAM_BANK_NUMBER_START && address <= RAM_BANK_NUMBER_END)
	{
		uint16_t	maskedValue = value & 0xF;

		ramBankNumber = maskedValue;
		ram.switchBank(ramBankNumber);
	}
}
