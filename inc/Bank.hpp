/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/04/2026
*/

#pragma once

#include "AMemoryAccessor.hpp"

#include <array>
#include <vector>
#include <cassert>

template<std::size_t n>
class Bank {
	public:
		Bank() {};
		~Bank() {};

		uint8_t					readByte(uint16_t address)
		{
			return (_data[address]);
		}

		void					writeByte(uint16_t address, uint8_t value)
		{
			_data[address] = value;
		}

		constexpr std::size_t	size() const
		{
			return (n);
		}

		std::array<uint8_t, n> &getArray()
		{
			return (_data);
		}

		void					load(std::vector<uint8_t> &in, std::size_t start, std::size_t end)
		{
			assert(in.size() >= end);
			assert(end - start <= _data.size());

			auto	it = in.begin() + start;
			auto	ite = in.begin() + end;

			std::copy(it, ite, _data.begin());
		}

	private:
		std::array<uint8_t, n>	_data;
};
