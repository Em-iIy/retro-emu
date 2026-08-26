/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#include "Cartridge/ROM.hpp"
#include "Bank.hpp"

#include <fcntl.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <cassert>

#include <iostream>

ROM::ROM()
{
	banks.resize(bankCount);
}

ROM::~ROM()
{
}

uint8_t					ROM::readByte(uint16_t address)
{
	uint16_t	romAddress = address - ROM_START_ADDRESS;

	// Check whether taking rom bank 00 or 01-XX
	if (romAddress < ROM_BANK_SIZE)
		return (banks.front().readByte(romAddress));
	return (getCurrentBank().readByte(romAddress - ROM_BANK_SIZE));
}

void					ROM::writeByte(uint16_t address, uint8_t value)
{
	std::cout << "ROM::writeByte() Soon deprecated" << std::endl;
	uint16_t	romAddress = address - ROM_START_ADDRESS;
	if (romAddress >= 0x2000 && romAddress <= 0x3FFF)
	{
		currentBank = value & 0b00011111;
		std::cout << "Selected ROM bank: " << currentBank << std::endl;
	}
}

void					ROM::initBanks(uint16_t count)
{
	std::cout << "initializing " << count << " ROM banks" << std::endl;
	bankCount = count;
	banks.resize(count);
}

void					ROM::switchBank(uint16_t number)
{
	assert(number < bankCount);
	currentBank = number;
}

void					ROM::fill(std::vector<uint8_t> &data)
{
	for (uint32_t i = 0; i < banks.size(); i++)
		banks[i].load(data, i * ROM_BANK_SIZE, (i + 1) * ROM_BANK_SIZE);
}

ROMBank					&ROM::getCurrentBank()
{
	assert(currentBank < bankCount);
	return (banks[currentBank]);
}
