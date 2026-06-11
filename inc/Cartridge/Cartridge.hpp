/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#pragma once

#include "ROM.hpp"
#include "CartridgeHeader.hpp"

#include <vector>

class Cartridge: public AMemoryAccessor {
	public:
		Cartridge(const std::string &cartFileName);
		~Cartridge();


		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		ROM						&getRom();

	private:
		void					load(const std::string &cartFileName);

		CartridgeHeader			_header;
		ROM						_rom;
		std::vector<uint8_t>	_data;
};
