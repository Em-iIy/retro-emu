/*
Created by: Emily (Em_iIy) Winnink
Created on: 13/04/2026
*/

#pragma once

#include "Cartridge/Cartridge.hpp"
#include "Cartridge/MBC/MBC.hpp"

#include <memory>

class CPU;
class WRAM;
class HRAM;

class MemoryBus: public AMemoryAccessor {
	public:
		MemoryBus();
		MemoryBus(CPU *inCpu, WRAM *inWram, HRAM *inHram);
		~MemoryBus();
	
		uint8_t	readByte(uint16_t address);
		void	writeByte(uint16_t address, uint8_t value);

		void	loadMBC(std::shared_ptr<MBC> inMbc);

	private:
		std::shared_ptr<MBC>	mbc;
		// RAM	*vram; // Video RAM
		WRAM	*wram; // Work RAM
		HRAM	*hram; // High RAM
		CPU		*cpu;
};
