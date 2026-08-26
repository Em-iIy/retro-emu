/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "Memory/MemoryBus.hpp"
#include "Memory/WRAM.hpp"
#include "Memory/HRAM.hpp"
#include "CPU/CPU.hpp"

#include <utils/printTypes.hpp>

#define ROM_START 0x0000
#define ROM_END 0x7FFF

#define VRAM_START 0x8000
#define VRAM_END 0x9FFF

#define EXT_RAM_START 0xA000
#define EXT_RAM_END 0xBFFF

#define WRAM_START 0xC000
#define WRAM_END 0xDFFF

#define ECHO_RAM_START 0xE000
#define ECHO_RAM_END 0xFDFF

#define OAM_START 0xFE00
#define OAM_END 0xFE9F

#define IO_START 0xFF00
#define IO_END 0xFF7F

#define HRAM_START 0xFF80
#define HRAM_END 0xFFFE

#define IE_START 0xFFFF
#define IE_END 0xFFFF


MemoryBus::MemoryBus(): wram(nullptr), cpu(nullptr)
{
	cpu = nullptr;
}

MemoryBus::MemoryBus(CPU *inCpu, WRAM *inWram, HRAM *inHram): wram(inWram), hram(inHram), cpu(inCpu)
{
}

MemoryBus::~MemoryBus()
{
}

uint8_t	MemoryBus::readByte(uint16_t address)
{
	if (address >= ROM_START && address <= ROM_END)
	{
		// return (_rom->readByte(address));
		return (mbc->readROM(address));
	}
	else if (address >= VRAM_START && address <= VRAM_END)
	{
		std::cout << "vram not implemented" << std::endl;
	}
	else if (address >= EXT_RAM_START && address <= EXT_RAM_END)
	{
		return (mbc->readRAM(address));
		// std::cout << "external ram not implemented" << std::endl;
	}
	else if (address >= WRAM_START && address <= WRAM_END)
	{
		return (wram->readByte(address));
	}
	else if (address >= ECHO_RAM_START && address <= ECHO_RAM_END)
	{
		std::cout << "echo ram not implemented" << std::endl;
	}
	else if (address >= OAM_START && address <= OAM_END)
	{
		std::cout << "OAM not implemented" << std::endl;
	}
	else if (address >= IO_START && address <= IO_END)
	{
		std::cout << "I/O not implemented" << std::endl;
	}
	else if (address >= HRAM_START && address <= HRAM_END)
	{
		return (hram->readByte(address));
	}
	else if (address >= IE_START && address <= IE_END)
	{
		std::cout << "IE not implemented" << std::endl;
	}
	else
	{
		std::cout << "Invalid adress" << std::endl;
	}

	return (0x0 - 1);
}

void	MemoryBus::writeByte(uint16_t address, uint8_t value)
{
	std::cout << "BUS: write: " << X8bit{value} << " to " << X16bit{address} << std::endl;
	if (address >= ROM_START && address <= ROM_END)
	{
		mbc->writeROM(address, value);
		// _rom->writeByte(address, value);
	}
	else if (address >= VRAM_START && address <= VRAM_END)
	{
		std::cout << "vram not implemented" << std::endl;
	}
	else if (address >= EXT_RAM_START && address <= EXT_RAM_END)
	{
		mbc->writeRAM(address, value);
		// std::cout << "external ram not implemented" << std::endl;
	}
	else if (address >= WRAM_START && address <= WRAM_END)
	{
		wram->writeByte(address, value);
	}
	else if (address >= ECHO_RAM_START && address <= ECHO_RAM_END)
	{
		std::cout << "echo ram not implemented" << std::endl;
	}
	else if (address >= OAM_START && address <= OAM_END)
	{
		std::cout << "OAM not implemented" << std::endl;
	}
	else if (address >= IO_START && address <= IO_END)
	{
		std::cout << "I/O not implemented" << std::endl;
	}
	else if (address >= HRAM_START && address <= HRAM_END)
	{
		hram->writeByte(address, value);
	}
	else if (address >= IE_START && address <= IE_END)
	{
		cpu->setIME(value);
	}
	else
	{
		std::cout << "Invalid adress" << std::endl;
	}
}

void	MemoryBus::loadMBC(std::shared_ptr<MBC> inMbc)
{
	mbc = inMbc;
}