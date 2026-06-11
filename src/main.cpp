/*
Created by: Emily (Em_iIy) Winnink
Created on: 27/03/2026
*/

#include "GameBoy.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	GameBoy						gameBoy;


	std::shared_ptr<Cartridge>	cart = std::make_shared<Cartridge>(argv[1]);
	gameBoy.loadCartridge(cart);
	return (0);
}
