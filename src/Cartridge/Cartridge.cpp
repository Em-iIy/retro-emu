/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#include "Cartridge/Cartridge.hpp"
#include "utils/readFile.hpp"

#include <iostream>

Cartridge::Cartridge(const std::string &cartFileName): AMemoryAccessor(0x0, 0xFFFF)
{
	load(cartFileName);
}

Cartridge::~Cartridge()
{
}

void	Cartridge::load(const std::string &cartFileName)
{
	_data = readFile(cartFileName);
	_header.fill(*this);

	std::cout << _header << std::endl;

	_rom.initBanks(_header.getRomBankCount());
	_rom.fill(_data);
}

uint8_t	Cartridge::readByte(uint16_t address)
{
	return (_data[address]);
}

void	Cartridge::writeByte(uint16_t address, uint8_t value)
{
	_data[address] = value;
}

ROM		&Cartridge::getRom()
{
	return (_rom);
}
