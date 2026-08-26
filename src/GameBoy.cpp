/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "GameBoy.hpp"

#include "utils/printTypes.hpp"

#define DEBUG false

GameBoy::GameBoy(): cpu(bus), bus(&cpu, &wram, &hram)
{
}

GameBoy::~GameBoy()
{
}

void	GameBoy::loadCartridge(std::shared_ptr<Cartridge> inCartridge)
{
	cartridge = inCartridge;
	bus.loadMBC(cartridge->getMBC());

	// cpu.setState({.A = 0x1, .B = 0xF});
	// if (cpu.checkState({.A = 0x1, .B = 0xF}) == false)
	// {
	// 	std::cout << "WTFFFF" << std::endl;
	// 	return;
	// }
	// else
	// {
	// 	std::cout << "passed" << std::endl;
	// }

	do
	{
		std::string input;
		if (!DEBUG)
		{
			cpu.printflags();
			cpu.printRegisters();
			std::cout << std::endl;
			continue ;
		}
		std::getline(std::cin, input);

		if (input == "s")
		{
			cpu.printflags();
			cpu.printRegisters();
			std::cout << std::endl;
		}
		else if (input == "help")
		{
			std::cout << "Press enter for next instruction" << std::endl;
			std::cout << "`s` = state of registers" << std::endl;
			std::cout << "`help` = this message" << std::endl;
		}
	}
	while (cpu.cycle());
}
