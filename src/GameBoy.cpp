/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "GameBoy.hpp"

#define DEBUG false

GameBoy::GameBoy(): _cpu(_bus), _bus(&_cpu, &_wram)
{
}

GameBoy::~GameBoy()
{
}

void	GameBoy::loadCartridge(std::shared_ptr<Cartridge> cartridge)
{
	_cartridge = cartridge;
	_bus.loadCartridge(cartridge);
	do
	{
		std::string input;
		if (!DEBUG)
		{
			_cpu.printflags();
			_cpu.printRegisters();
			std::cout << std::endl;
			continue ;
		}
		std::getline(std::cin, input);

		if (input == "s")
		{
			_cpu.printflags();
			_cpu.printRegisters();
			std::cout << std::endl;
		}
		else if (input == "help")
		{
			std::cout << "Press enter for next instruction" << std::endl;
			std::cout << "`s` = state of registers" << std::endl;
			std::cout << "`help` = this message" << std::endl;
		}
	}
	while (_cpu.cycle());
}
