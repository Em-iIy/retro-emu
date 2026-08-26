/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#pragma once

#include "CPU/CPU.hpp"
#include "Cartridge/Cartridge.hpp"
#include "Memory/MemoryBus.hpp"
#include "Memory/WRAM.hpp"
#include "Memory/HRAM.hpp"

#include <memory>

class GameBoy
{
	public:
		GameBoy();
		~GameBoy();

		void						loadCartridge(std::shared_ptr<Cartridge> inCartridge);

	private:
		CPU							cpu;
		MemoryBus					bus;
		std::shared_ptr<Cartridge>	cartridge = nullptr;
		WRAM						wram;
		HRAM						hram;
};
