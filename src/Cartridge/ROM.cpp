/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#include "Cartridge/ROM.hpp"
#include "Bank.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <cassert>

#include <iostream>

ROM::ROM(): AMemoryAccessor(0x0000, 0x7FFF)
{
	_banks.resize(_bankCount);
}

ROM::~ROM()
{
}

uint8_t					ROM::readByte(uint16_t address)
{
	uint16_t	romAddress = address - ROM_START_ADDRESS;
	if (romAddress < ROM_BANK_SIZE)
		return (_banks.front().readByte(romAddress));
	return (_getCurrentBank().readByte(romAddress - ROM_BANK_SIZE));
}

void					ROM::writeByte(uint16_t address, uint8_t value)
{
	uint16_t	romAddress = address - ROM_START_ADDRESS;
	if (romAddress >= 0x2000 && romAddress <= 0x3FFF)
	{
		_currentBank = value & 0b00011111;
		std::cout << "Selected ROM bank: " << _currentBank << std::endl;
	}
}

void					ROM::initBanks(uint16_t count)
{
	std::cout << "initializing " << count << " ROM banks" << std::endl;
	_bankCount = count;
	_banks.resize(count);
}

void					ROM::fill(std::vector<uint8_t> &data)
{
	for (uint32_t i = 0; i < _banks.size(); i++)
		_banks[i].load(data, i * ROM_BANK_SIZE, (i + 1) * ROM_BANK_SIZE);
}

ROMBank					&ROM::_getCurrentBank()
{
	assert(_currentBank < _bankCount);
	return (_banks[_currentBank]);
}
