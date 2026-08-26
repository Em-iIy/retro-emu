/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#pragma once

#include "CPU/CPU.hpp"
#include "Cartridge/Cartridge.hpp"
#include "MemoryBus.hpp"
#include "WRAM.hpp"
#include "HRAM.hpp"

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
