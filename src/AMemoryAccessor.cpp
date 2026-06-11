	/*
Created by: Emily (Em_iIy) Winnink
Created on: 15/04/2026
*/

#include "AMemoryAccessor.hpp"

AMemoryAccessor::AMemoryAccessor(uint16_t rangeStart, uint16_t rangeEnd):
	_rangeStart(rangeStart), _rangeEnd(rangeEnd)
{}

bool	AMemoryAccessor::inRange(uint16_t address)
{
	return (address >= _rangeStart && address <= _rangeEnd);
}
