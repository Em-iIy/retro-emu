/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "GameBoy.hpp"

GameBoy::GameBoy(): _cpu(_bus), _bus(&_cpu)
{
}

GameBoy::~GameBoy()
{
}

void	GameBoy::loadCartridge(std::shared_ptr<Cartridge> cartridge)
{
	_cartridge = cartridge;
	_bus.loadCartridge(cartridge);
	while (_cpu.cycle()){};
}
