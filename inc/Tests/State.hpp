/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/08/2026
*/

#pragma once

#include <cstdint>

struct State
{
	uint8_t		A	= 0x00;
	uint8_t		F	= 0x00;
	uint16_t	AF	= 0x0000;
	uint8_t		B	= 0x00;
	uint8_t		C	= 0x00;
	uint16_t	BC	= 0x0000;
	uint8_t		D	= 0x00;
	uint8_t		E	= 0x00;
	uint16_t	DE	= 0x0000;
	uint8_t		H	= 0x00;
	uint8_t		L	= 0x00;
	uint16_t	HL	= 0x0000;
	uint16_t	SP	= 0x0000;
	uint16_t	PC	= 0x0000;
	uint16_t	readAddress		= 0x0000;
	uint8_t		readValue8bit	= 0x00;
	uint16_t	readValue16bit	= 0x0000;
	uint16_t	writeAddress	= 0x0000;
	uint8_t		writeValue8bit	= 0x00;
	uint16_t	writeValue16bit	= 0x0000;
};
