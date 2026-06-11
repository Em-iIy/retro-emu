/*
Created by: Emily (Em_iIy) Winnink
Created on: 11/06/2026
*/

#include "CPU/CPU.hpp"

/*
	LOAD to 8 bit register
*/

uint8_t	CPU::LOAD_R8_R8(uint8_t &dst, uint8_t &src)
{
	dst = src;
	return (1);
}

uint8_t	CPU::LOAD_R8_IM8(uint8_t &dst)
{
	uint8_t	src = fetchImmediateByte();
	dst = src;
	return (1);
}


/*
	LOAD to 16 bit register
*/

uint8_t	CPU::LOAD_R16_R16(uint16_t &dst, uint16_t &src)
{
	dst = src;
	return (1);
}

uint8_t	CPU::LOAD_R16_IM16(uint16_t &dst)
{
	uint16_t	src = fetchImmediate2Bytes();
	dst = src;
	return (1);
}


/*
	LOAD from/to memory pointed to by 16 bit register
*/

uint8_t	CPU::LOAD_PR16_R8(uint16_t &pDst, uint8_t &src)
{
	_bus.writeByte(pDst, src);
	return (1);
}

uint8_t	CPU::LOAD_PR16_IM8(uint16_t &pDst)
{
	uint8_t	src = fetchImmediateByte();
	_bus.writeByte(pDst, src);
	return (1);
}

uint8_t	CPU::LOAD_R8_PR16(uint8_t &dst, uint16_t &pSrc)
{
	dst = _bus.readByte(pSrc);
	return (1);
}


/*
	LOAD from/to RAM or Register pointed to by 8 bit address
*/

uint8_t	CPU::LOAD_PIM8_R8(uint8_t &src)
{
	uint8_t		pDst = fetchImmediateByte();
	uint16_t	dstAddress = 0xFF00 + pDst;
	_bus.writeByte(dstAddress, src);
	return (1);
}

uint8_t	CPU::LOAD_PR8_R8(uint8_t &pDst, uint8_t &src)
{
	uint16_t	dstAddress = 0xFF00 + pDst;
	_bus.writeByte(dstAddress, src);
	return (1);
}

uint8_t	CPU::LOAD_R8_PIM8(uint8_t &dst)
{
	uint8_t		pSrc = fetchImmediateByte();
	uint16_t	srcAddress = 0xFF00 + pSrc;
	dst = _bus.readByte(srcAddress);
	return (1);
}

uint8_t	CPU::LOAD_R8_PR8(uint8_t &dst, uint8_t &pSrc)
{
	uint16_t	srcAddress = 0xFF00 + pSrc;
	dst = _bus.readByte(srcAddress);
	return (1);
}


/*
	LOAD from/to RAM or Register pointed to by 16 bit address
*/

uint8_t	CPU::LOAD_PIM16_R8(uint8_t &src)
{
	uint16_t	pDst = fetchImmediate2Bytes();
	_bus.writeByte(pDst, src);
	return (1);
}

uint8_t	CPU::LOAD_PIM16_R16(uint16_t &src)
{
	uint16_t	pDst = fetchImmediate2Bytes();
	_bus.writeByte(pDst, src & 0xFF);
	_bus.writeByte(pDst + 1, src >> 8);
	return (1);
}

uint8_t	CPU::LOAD_R8_PIM16(uint8_t &dst)
{
	uint16_t	pSrc = fetchImmediate2Bytes();
	dst = _bus.readByte(pSrc);
	return (1);
}


/*
	LOAD + INC or DEC HL
*/

uint8_t	CPU::LOAD_PHLI_R8(uint8_t &src)
{
	_bus.writeByte(HL.getValue(), src);
	HL.incValue();
	return (1);
}

uint8_t	CPU::LOAD_R8_PHLI(uint8_t &dst)
{
	dst = _bus.readByte(HL.getValue());
	HL.incValue();
	return (1);
}

uint8_t	CPU::LOAD_PHLD_R8(uint8_t &src)
{
	_bus.writeByte(HL.getValue(), src);
	HL.decValue();
	return (1);
}

uint8_t	CPU::LOAD_R8_PHLD(uint8_t &dst)
{
	dst = _bus.readByte(HL.getValue());
	HL.decValue();
	return (1);
}
