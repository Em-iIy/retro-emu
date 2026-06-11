/*
Created by: Emily (Em_iIy) Winnink
Created on: 09/04/2026
*/

#pragma once

#include <cstdint>

class Register {
	public:
		uint16_t	getValue() const;
		uint8_t		getHi() const;
		uint8_t		getLo() const;

		void		setValue(uint16_t val);
		void		setHi(uint8_t val);
		void		setLo(uint8_t val);

		void		incValue();
		void		incHi();
		void		incLo();

		void		decValue();
		void		decHi();
		void		decLo();

		uint16_t	&getRef();
		uint8_t		&getHiRef();
		uint8_t		&getLoRef();

		union
		{
			struct
			{
				uint8_t	hi;
				uint8_t	lo;
			}			reg8b;
			uint16_t	reg16b;
		};
};
