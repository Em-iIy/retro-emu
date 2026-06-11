/*
Created by: Emily (Em_iIy) Winnink
Created on: 24/04/2026
*/

#pragma once

#include <iostream>

enum class CartridgeType {
	ROM_ONLY = 0x00,
	MBC1 = 0x01,
	MBC1_RAM = 0x02,
	MBC1_RAM_BATTERY = 0x03,
	MBC2 = 0x05,
	MBC2_BATTERY = 0x06,
	ROM_RAM_11 = 0x08,
	ROM_RAM_BATTERY_11 = 0x09,
	MMM01 = 0x0B,
	MMM01_RAM = 0x0C,
	MMM01_RAM_BATTERY = 0x0D,
	MBC3_TIMER_BATTERY = 0x0F,
	MBC3_TIMER_RAM_BATTERY_12 = 0x10,
	MBC3 = 0x11,
	MBC3_RAM_12 = 0x12,
	MBC3_RAM_BATTERY_12 = 0x13,
	MBC5 = 0x19,
	MBC5_RAM = 0x1A,
	MBC5_RAM_BATTERY = 0x1B,
	MBC5_RUMBLE = 0x1C,
	MBC5_RUMBLE_RAM = 0x1D,
	MBC5_RUMBLE_RAM_BATTERY = 0x1E,
	MBC6 = 0x20,
	MBC7_SENSOR_RUMBLE_RAM_BATTERY = 0x22,
	POCKET_CAMERA = 0xFC,
	BANDAI_TAMA5 = 0xFD,
	HuC3 = 0xFE,
	HuC1_RAM_BATTERY = 0xFF,
};

inline std::ostream &operator<<(std::ostream &o, const CartridgeType type)
{
	switch (type)
	{
	case CartridgeType::ROM_ONLY:
		o << "ROM_ONLY"; break ;
	case CartridgeType::MBC1:
		o << "MBC1"; break ;
	case CartridgeType::MBC1_RAM:
		o << "MBC1_RAM"; break ;
	case CartridgeType::MBC1_RAM_BATTERY:
		o << "MBC1_RAM_BATTERY"; break ;
	case CartridgeType::MBC2:
		o << "MBC2"; break ;
	case CartridgeType::MBC2_BATTERY:
		o << "MBC2_BATTERY"; break ;
	case CartridgeType::ROM_RAM_11:
		o << "ROM_RAM_11"; break ;
	case CartridgeType::ROM_RAM_BATTERY_11:
		o << "ROM_RAM_BATTERY_11"; break ;
	case CartridgeType::MMM01:
		o << "MMM01"; break ;
	case CartridgeType::MMM01_RAM:
		o << "MMM01_RAM"; break ;
	case CartridgeType::MMM01_RAM_BATTERY:
		o << "MMM01_RAM_BATTERY"; break ;
	case CartridgeType::MBC3_TIMER_BATTERY:
		o << "MBC3_TIMER_BATTERY"; break ;
	case CartridgeType::MBC3_TIMER_RAM_BATTERY_12:
		o << "MBC3_TIMER_RAM_BATTERY_12"; break ;
	case CartridgeType::MBC3:
		o << "MBC3"; break ;
	case CartridgeType::MBC3_RAM_12:
		o << "MBC3_RAM_12"; break ;
	case CartridgeType::MBC3_RAM_BATTERY_12:
		o << "MBC3_RAM_BATTERY_12"; break ;
	case CartridgeType::MBC5:
		o << "MBC5"; break ;
	case CartridgeType::MBC5_RAM:
		o << "MBC5_RAM"; break ;
	case CartridgeType::MBC5_RAM_BATTERY:
		o << "MBC5_RAM_BATTERY"; break ;
	case CartridgeType::MBC5_RUMBLE:
		o << "MBC5_RUMBLE"; break ;
	case CartridgeType::MBC5_RUMBLE_RAM:
		o << "MBC5_RUMBLE_RAM"; break ;
	case CartridgeType::MBC5_RUMBLE_RAM_BATTERY:
		o << "MBC5_RUMBLE_RAM_BATTERY"; break ;
	case CartridgeType::MBC6:
		o << "MBC6"; break ;
	case CartridgeType::MBC7_SENSOR_RUMBLE_RAM_BATTERY:
		o << "MBC7_SENSOR_RUMBLE_RAM_BATTERY"; break ;
	case CartridgeType::POCKET_CAMERA:
		o << "POCKET_CAMERA"; break ;
	case CartridgeType::BANDAI_TAMA5:
		o << "BANDAI_TAMA5"; break ;
	case CartridgeType::HuC3:
		o << "HuC3"; break ;
	case CartridgeType::HuC1_RAM_BATTERY:
		o << "HuC1_RAM_BATTERY"; break ;
	default:
		break;
	}
	return (o);
}
