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

		void						loadCartridge(std::shared_ptr<Cartridge> _cartridge);

	private:
		CPU							_cpu;
		MemoryBus					_bus;
		std::shared_ptr<Cartridge>	_cartridge = nullptr;
		WRAM						_wram;
		HRAM						_hram;
};
