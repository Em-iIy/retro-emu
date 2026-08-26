/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#pragma once

#include "ROM.hpp"
#include "CartridgeHeader.hpp"
#include "MBC/MBC.hpp"

#include <vector>
#include <memory>

class Cartridge {
	public:
		Cartridge(const std::string &cartFileName);
		~Cartridge();


		uint8_t					readByte(uint16_t address);
		void					writeByte(uint16_t address, uint8_t value);

		ROM						&getRom();
		std::shared_ptr<MBC>	getMBC();


	private:
		void					load(const std::string &cartFileName);
		void					initMBC();

		CartridgeHeader			header;
		std::shared_ptr<MBC>	mbc;
		std::vector<uint8_t>	data;
		
};
