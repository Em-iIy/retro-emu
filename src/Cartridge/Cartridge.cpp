/*
Created by: Emily (Em_iIy) Winnink
Created on: 30/03/2026
*/

#include "Cartridge/Cartridge.hpp"
#include "Cartridge/MBC/MBC1.hpp"
#include "Cartridge/MBC/MBC2.hpp"
#include "Cartridge/MBC/MBC5.hpp"
#include "utils/readFile.hpp"

#include <iostream>

Cartridge::Cartridge(const std::string &cartFileName): AMemoryAccessor(0x0, 0xFFFF)
{
	load(cartFileName);
}

Cartridge::~Cartridge()
{
}

void	Cartridge::load(const std::string &cartFileName)
{
	data = readFile(cartFileName);
	header.fill(*this);

	std::cout << header << std::endl;

	initMBC();
	mbc->rom.fill(data);
}

void	Cartridge::initMBC()
{
	switch (header.cartridgeType)
	{
	case CartridgeType::ROM_ONLY:
		std::cout << header.cartridgeType << " Not implemented yet" << std::endl;
		break ;
	case CartridgeType::MBC1:
	case CartridgeType::MBC1_RAM:
	case CartridgeType::MBC1_RAM_BATTERY:
		mbc = std::make_shared<MBC1>(header.getRomBankCount(), header.getRamBankCount());
		break ;
	case CartridgeType::MBC2:
	case CartridgeType::MBC2_BATTERY:
		// std::cout << header.cartridgeType << " Not implemented yet" << std::endl;
		mbc = std::make_shared<MBC2>(header.getRomBankCount(), header.getRamBankCount());
		break ;
	case CartridgeType::MBC5:
	case CartridgeType::MBC5_RAM:
	case CartridgeType::MBC5_RAM_BATTERY:
	case CartridgeType::MBC5_RUMBLE:
	case CartridgeType::MBC5_RUMBLE_RAM:
	case CartridgeType::MBC5_RUMBLE_RAM_BATTERY:
		// std::cout << header.cartridgeType << " Not implemented yet" << std::endl;
		mbc = std::make_shared<MBC5>(header.getRomBankCount(), header.getRamBankCount());
		break ;
	case CartridgeType::ROM_RAM_11:
	case CartridgeType::ROM_RAM_BATTERY_11:
	case CartridgeType::MMM01:
	case CartridgeType::MMM01_RAM:
	case CartridgeType::MMM01_RAM_BATTERY:
	case CartridgeType::MBC3_TIMER_BATTERY:
	case CartridgeType::MBC3_TIMER_RAM_BATTERY_12:
	case CartridgeType::MBC3:
	case CartridgeType::MBC3_RAM_12:
	case CartridgeType::MBC3_RAM_BATTERY_12:
	case CartridgeType::MBC6:
	case CartridgeType::MBC7_SENSOR_RUMBLE_RAM_BATTERY:
	case CartridgeType::POCKET_CAMERA:
	case CartridgeType::BANDAI_TAMA5:
	case CartridgeType::HuC3:
	case CartridgeType::HuC1_RAM_BATTERY:
		std::cout << header.cartridgeType << " Not implemented and not supported" << std::endl;
	default:
		std::cout << "invalid cartridge type!" << std::endl;
		break;
	}
}

uint8_t	Cartridge::readByte(uint16_t address)
{
	return (data[address]);
}

void	Cartridge::writeByte(uint16_t address, uint8_t value)
{
	data[address] = value;
}

std::shared_ptr<MBC>	Cartridge::getMBC()
{
	return (mbc);
}

