/*
Created by: Emily (Em_iIy) Winnink
Created on: 15/04/2026
*/

#pragma once

#include "AMemoryAccessor.hpp"
#include "enums/CartridgeType.hpp"

#include <cstdint>
#include <string>
#include <vector>


/*
	0x0100-0x0103	Entry point
	0x0104-0x0133	Nintendo logo
	0x0134-0x0143	Title
	0x013F-0x0142	Manufacturer code
	0x0147			Cartridge type
	0x0148			ROM size
	0x0149			RAM size
*/
class CartridgeHeader {
	public:
		void			fill(AMemoryAccessor &data);

		uint16_t		getRomBankCount();
		uint16_t		getRamBankCount();

		std::string		title;
		std::string		manufacturerCode;
		CartridgeType	cartridgeType;
		uint8_t			romSize;
		uint8_t			ramSize;
};


std::ostream &operator<<(std::ostream &o, const CartridgeHeader &header);
