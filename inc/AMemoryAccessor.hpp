/*
Created by: Emily (Em_iIy) Winnink
Created on: 15/04/2026
*/

#pragma once

#include <cstdint>

class AMemoryAccessor {
	public:
		AMemoryAccessor() = delete;
		AMemoryAccessor(uint16_t rangeStart, uint16_t rangeEnd);
		virtual ~AMemoryAccessor() {};

		virtual uint8_t	readByte(uint16_t address) = 0;
		virtual void	writeByte(uint16_t address, uint8_t value) = 0;

		bool	inRange(uint16_t address);

	private:
		uint16_t		_rangeStart;
		uint16_t		_rangeEnd;
};
