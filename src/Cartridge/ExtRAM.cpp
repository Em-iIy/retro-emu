/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/08/2026
*/

#include "Cartridge/ExtRAM.hpp"

#include <iostream>

ExtRAM::ExtRAM(): AMemoryAccessor(EXT_RAM_START_ADDRESS, EXT_RAM_START_ADDRESS + EXT_RAM_BANK_SIZE)
{
}

ExtRAM::~ExtRAM()
{
}

uint8_t					ExtRAM::readByte(uint16_t address)
{
	uint16_t	extRamAddress = address - EXT_RAM_START_ADDRESS;
		
	assert(extRamAddress < EXT_RAM_BANK_SIZE);
	return (getCurrentBank().readByte(address));
}

void					ExtRAM::writeByte(uint16_t address, uint8_t value)
{
	uint16_t	extRamAddress = address - EXT_RAM_START_ADDRESS;
	assert(extRamAddress < EXT_RAM_BANK_SIZE);
	getCurrentBank().writeByte(extRamAddress, value);
}

void					ExtRAM::initBanks(uint16_t count)
{
	std::cout << "initializing " << count << " External RAM banks" << std::endl;
	bankCount = count;
	banks.resize(count);
}

void					ExtRAM::switchBank(uint16_t number)
{
	assert(number < bankCount);
	currentBank = number;
}

ExtRAMBank				&ExtRAM::getCurrentBank()
{
	assert(currentBank < bankCount);
	return (banks[currentBank]);
}
