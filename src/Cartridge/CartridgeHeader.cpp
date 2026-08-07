/*
Created by: Emily (Em_iIy) Winnink
Created on: 15/04/2026
*/

#include "Cartridge/CartridgeHeader.hpp"

#include "utils/printTypes.hpp"

void		CartridgeHeader::fill(AMemoryAccessor &data)
{
	cartridgeType = static_cast<CartridgeType>(data.readByte(0x0147));
	romSize = data.readByte(0x0148);
	ramSize = data.readByte(0x0149);
	for (uint64_t i = 0x134; i < 0x143; i++)
		title += data.readByte(i);
	for (uint64_t i = 0x13F; i < 0x142; i++)
		manufacturerCode += data.readByte(i);
}

uint16_t	CartridgeHeader::getRamBankCount()
{
	switch (ramSize)
	{
	case 0x0:
	case 0x1:
		return (0);

	case 0x2:
		return (1);

	case 0x3:
		return (4);

	case 0x4:
		return (16);

	case 0x5:
		return (8);
	
	default:
		return (0);
	}
}

uint16_t	CartridgeHeader::getRomBankCount()
{
	return (2 << romSize);
}


std::ostream &operator<<(std::ostream &o, const CartridgeHeader &header)
{
	o << "Cart type:\t\t" << header.cartridgeType << std::endl;
	o << "ROM size:\t\t" << X8bit{header.romSize} << std::endl;
	o << "RAM size:\t\t" << X8bit{header.ramSize} << std::endl;
	o << "Title:\t\t\t"  << header.title << std::endl;
	o << "Manufacturer code:\t"  << header.manufacturerCode << std::endl;
	return (o);
}

