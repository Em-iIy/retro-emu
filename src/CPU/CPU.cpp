/*
Created by: Emily (Em_iIy) Winnink
Created on: 28/04/2026
*/

#include "CPU/CPU.hpp"
#include "CPU/enums/OpCodes.hpp"

#include <iostream>

CPU::CPU(MemoryBus &bus): _bus(bus)
{
	initInstructionTable();
	initExtendedInstructionTable();
	flushRegisters();
	PC.setValue(0x100);
	SP.setValue(0xFFFE);
}

CPU::~CPU()
{
}

bool	CPU::cycle()
{
	currentInstructionData.clear();

	uint16_t	pcState = PC.getValue();
	Instruction	currentInstruction = getInstruction();
	std::cout << std::hex << pcState << " -> ";
	auto instructionCB = table.at(static_cast<uint8_t>(currentInstruction.opCode));
	uint8_t	result = instructionCB();

	logInstructionData();

	if (result == 0)
		return (false);
	return (true);
}

void	CPU::setIME(bool val)
{
	IME = val;
}

void	CPU::flushRegisters()
{
	AF.setValue(0x0);
	BC.setValue(0x0);
	DE.setValue(0x0);
	HL.setValue(0x0);
	SP.setValue(0x0);
	PC.setValue(0x0);
}

uint8_t		&CPU::get8BitRegister(RegisterName name)
{
	switch (name)
	{
	case RegisterName::REG_A:
		return (AF.getHiRef());
	case RegisterName::REG_F:
		return (AF.getLoRef());
	case RegisterName::REG_B:
		return (BC.getHiRef());
	case RegisterName::REG_C:
		return (BC.getLoRef());
	case RegisterName::REG_D:
		return (DE.getHiRef());
	case RegisterName::REG_E:
		return (DE.getLoRef());
	case RegisterName::REG_H:
		return (HL.getHiRef());
	case RegisterName::REG_L:
		return (HL.getLoRef());
	default:
		break ;
	}
	return (AF.getHiRef());
}

uint16_t	&CPU::get16BitRegister(RegisterName name)
{
	switch (name)
	{
	case RegisterName::REG_AF:
		return (AF.getRef());
	case RegisterName::REG_BC:
		return (BC.getRef());
	case RegisterName::REG_DE:
		return (DE.getRef());
	case RegisterName::REG_HL:
		return (HL.getRef());
	case RegisterName::REG_SP:
		return (SP.getRef());
	case RegisterName::REG_PC:
		return (PC.getRef());
	default:
		break ;
	}
	return (AF.getRef());
}

uint8_t		CPU::fetchByte()
{
	uint8_t	ret = _bus.readByte(PC.getValue());
	PC.incValue();
	return (ret);
}

uint8_t	CPU::fetchImmediateByte()
{
	
	uint8_t	ret = fetchByte();

	// For debugging immediate data
	currentInstructionData.push_back(ret);
	return (ret);
}

uint16_t	CPU::fetchImmediate2Bytes()
{
	uint8_t		byte1 = fetchByte();
	uint8_t		byte2 = fetchByte();
	uint16_t	ret = byte1 | (byte2 << 8); // Little endian

	// For debugging immediate data
	currentInstructionData.push_back(ret);
	return (ret);
}

Instruction	CPU::getInstruction()
{
	Instruction ret(static_cast<OpCodes>(fetchImmediateByte()));
	if (ret.checkExtended())
		ret.setExtension(static_cast<OpCodesExt>(fetchImmediateByte()));
	return (ret);
}

void	CPU::logInstructionData()
{
	OpCodes code = static_cast<OpCodes>(currentInstructionData.front());
	std::cout << code << "\t";
	for (uint8_t i = 1; i < currentInstructionData.size(); i++)
		std::cout << "(" << std::hex << currentInstructionData.at(i) << ") ";
	std::cout << std::endl;
}

void	CPU::setFlag(CPU::Flag flag, bool value)
{
	if (value == true)
		setFlag(flag);
	else
		unsetFlag(flag);
}

void	CPU::setFlag(CPU::Flag flag)
{
	AF.reg8b.lo |= (1 << (uint8_t)flag);
}

void	CPU::unsetFlag(CPU::Flag flag)
{
	AF.reg8b.lo &= ~(1 << (uint8_t)flag);
}

bool	CPU::checkFlag(CPU::Flag flag)
{
	return (AF.reg8b.lo & (1 << (uint8_t)flag));
}

uint8_t		CPU::notImplemented()
{
	std::cout << "Not implemented" << std::endl;
	return (0);
}

uint8_t	CPU::NOP()
{
	return (1);
}

uint8_t	CPU::DI()
{
	setIME(false);
	return (1);
}

uint8_t	CPU::EI()
{
	setIME(true);
	return (1);
}

uint8_t	CPU::CPL()
{
	AF.reg8b.hi = ~AF.reg8b.hi;
	setFlag(Flag::N);
	setFlag(Flag::H);
	return (1);
}
