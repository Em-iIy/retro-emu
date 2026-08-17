/*
Created by: Emily (Em_iIy) Winnink
Created on: 13/04/2026
*/

#pragma once

#include "Cartridge/Cartridge.hpp"

#include <memory>

class CPU;
class WRAM;
class HRAM;

class MemoryBus: public AMemoryAccessor {
	public:
		MemoryBus();
		MemoryBus(CPU *cpu, WRAM *wram, HRAM *hram);
		~MemoryBus();
	
		uint8_t	readByte(uint16_t address);
		void	writeByte(uint16_t address, uint8_t value);

		void	loadCartridge(std::shared_ptr<Cartridge> cartridge);

	private:
		ROM		*_rom;
		// RAM	*_vram; // Video RAM
		// RAM	*_eram; // External RAM
		WRAM	*_wram; // Work RAM
		HRAM	*_hram; // High RAM
		CPU		*_cpu;
};
