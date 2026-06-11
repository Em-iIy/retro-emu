/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "MemoryBus.hpp"
#include "CPU/CPU.hpp"


MemoryBus::MemoryBus(): AMemoryAccessor(0x0000, 0xFFFF), _rom(nullptr), _cpu(nullptr)
{
	_cpu = nullptr;
}

MemoryBus::MemoryBus(CPU *cpu): AMemoryAccessor(0x0000, 0xFFFF), _rom(nullptr), _cpu(cpu)
{
}

MemoryBus::~MemoryBus()
{
}

uint8_t	MemoryBus::readByte(uint16_t address)
{
	if (_rom->inRange(address))
		return (_rom->readByte(address));
	return (0x0 - 1);
}

void	MemoryBus::writeByte(uint16_t address, uint8_t value)
{
	if (_rom->inRange(address))
		_rom->writeByte(address, value);
	if (address == 0xFFFF)
		_cpu->setIME(value);
}

void	MemoryBus::loadCartridge(std::shared_ptr<Cartridge> cartridge)
{
	_rom = &cartridge->getRom();
}