/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/
/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#include "WRAM.hpp"
#include "Bank.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <cassert>

#include <iostream>

WRAM::WRAM(): AMemoryAccessor(0xC000, 0xDFFF)
{
	_banks.resize(_bankCount);
}

WRAM::~WRAM()
{
}

uint8_t					WRAM::readByte(uint16_t address)
{
	uint16_t	wramAddress = address - WRAM_START_ADDRESS;
	if (wramAddress < WRAM_BANK_SIZE)
		return (_banks.front().readByte(wramAddress));
	return (_getCurrentBank().readByte(wramAddress - WRAM_BANK_SIZE));
}

void					WRAM::writeByte(uint16_t address, uint8_t value)
{
	uint16_t	wramAddress = address - WRAM_START_ADDRESS;
	if (wramAddress < WRAM_BANK_SIZE)
		_banks.front().writeByte(wramAddress, value);
	_getCurrentBank().writeByte(wramAddress - WRAM_BANK_SIZE, value);
}

void					WRAM::initBanks(uint16_t count)
{
	std::cout << "initializing " << count << " WRAM banks" << std::endl;
	_bankCount = count;
	_banks.resize(count);
}

void					WRAM::fill(std::vector<uint8_t> &data)
{
	for (uint32_t i = 0; i < _banks.size(); i++)
		_banks[i].load(data, i * WRAM_BANK_SIZE, (i + 1) * WRAM_BANK_SIZE);
}

WRAMBank					&WRAM::_getCurrentBank()
{
	assert(_currentBank < _bankCount);
	return (_banks[_currentBank]);
}
