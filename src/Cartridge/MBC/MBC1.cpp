/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#include "Cartridge/MBC/MBC1.hpp"

#include <iostream>

MBC1::MBC1(uint16_t romBankCount, uint16_t ramBankCount): MBC(romBankCount, ramBankCount)
{
}

MBC1::~MBC1() {};

uint8_t		MBC1::readROM(uint16_t address)
{
	return (rom.readByte(address));
}

void		MBC1::writeROM(uint16_t address, uint8_t value)
{
	handleRegisters(address, value);
}

uint8_t		MBC1::readRAM(uint16_t address)
{
	if (ramEnabled == false || hasRam == false)
		return (0xFF);
	return (ram.readByte(address));
}

void		MBC1::writeRAM(uint16_t address, uint8_t value)
{
	if (ramEnabled == false || hasRam == false)
		return ;
	ram.writeByte(address, value);
}

void		MBC1::handleRegisters(uint16_t address, uint8_t value)
{

	if (address >= RAM_ENABLE_START && address <= RAM_ENABLE_END)
	{
		if ((value & 0b1111) == 0xA)
			ramEnabled = true;
		else
			ramEnabled = false;
	}
	else if (address >= ROM_BANK_NUMBER_START && address <= ROM_BANK_NUMBER_END)
	{
		uint16_t	maskedValue = value & 0b11111;

		if (maskedValue == 0x00)
			maskedValue = 0x01;
		romBankNumber = maskedValue;
		rom.switchBank(romBankNumber);
	}
	else if (address >= RAM_BANK_NUMBER_START && address <= RAM_BANK_NUMBER_END)
	{
		uint16_t	maskedValue = value & 0b11;

		ramBankNumber = maskedValue;
		ram.switchBank(ramBankNumber);
	}
	else if (address >= BANKING_MODE_SELECT_START && address <= BANKING_MODE_SELECT_END)
	{
		uint16_t	maskedValue = value & 0b1;

		bankingMode = maskedValue;
		std::cout << "MBC1 banking mode not implemented" << std::endl;
	}
}
