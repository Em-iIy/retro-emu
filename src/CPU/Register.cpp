/*
Created by: Emily (Em_iIy) Winnink
Created on: 09/04/2026
*/

#include "CPU/Register.hpp"

uint16_t	Register::getValue() const
{
	return (reg16b);
}

uint8_t		Register::getHi() const
{
	return (reg8b.hi);
}

uint8_t		Register::getLo() const
{
	return (reg8b.lo);
}

void		Register::setValue(uint16_t val)
{
	reg16b = val;
}

void		Register::setHi(uint8_t val)
{
	reg8b.hi = val;
}

void		Register::setLo(uint8_t val)
{
	reg8b.lo = val;
}

void		Register::incValue()
{
	reg16b++;
}

void		Register::incHi()
{
	reg8b.hi++;
}

void		Register::incLo()
{
	reg8b.lo++;
}

void		Register::decValue()
{
	reg16b--;
}

void		Register::decHi()
{
	reg8b.hi--;
}

void		Register::decLo()
{
	reg8b.lo--;
}

uint16_t	&Register::getRef()
{
	return (reg16b);
}

uint8_t		&Register::getHiRef()
{
	return (reg8b.hi);
}

uint8_t		&Register::getLoRef()
{
	return (reg8b.lo);
}
