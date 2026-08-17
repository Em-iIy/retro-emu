/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/08/2026
*/

#include "HRAM.hpp"
#include "Bank.hpp"

#include <fcntl.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <cassert>

#include <utils/printTypes.hpp>

HRAM::HRAM(): AMemoryAccessor(HRAM_START_ADDRESS, HRAM_START_ADDRESS + HRAM_BANK_SIZE)
{
}

HRAM::~HRAM()
{
}

uint8_t					HRAM::readByte(uint16_t address)
{
	uint16_t	hramAddress = address - HRAM_START_ADDRESS;
	return (bank.readByte(hramAddress));
}

void					HRAM::writeByte(uint16_t address, uint8_t value)
{
	uint16_t	hramAddress = address - HRAM_START_ADDRESS;
	bank.writeByte(hramAddress, value);
}
