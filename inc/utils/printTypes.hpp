/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/08/2026
*/

#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <bitset>

struct X8bit {uint8_t val;};
struct X16bit {uint16_t val;};

inline std::ostream &operator<<(std::ostream &o, const X8bit val)
{
	o << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(val.val);
	return (o);
}

inline std::ostream &operator<<(std::ostream &o, const X16bit val)
{
	o << std::hex << std::setw(4) << std::setfill('0') << static_cast<uint32_t>(val.val);
	return (o);
}

struct B8bit {uint8_t val;};
struct B16bit {uint16_t val;};

inline std::ostream &operator<<(std::ostream &o, const B8bit val)
{
	o << std::bitset<8>(val.val);
	return (o);
}

inline std::ostream &operator<<(std::ostream &o, const B16bit val)
{
	o << std::bitset<16>(val.val);
	return (o);
}

struct D8bit {uint8_t val;};
struct D16bit {uint16_t val;};

inline std::ostream &operator<<(std::ostream &o, const D8bit val)
{
	o << std::dec << std::setw(3) << std::setfill('0') << static_cast<uint32_t>(val.val);
	return (o);
}

inline std::ostream &operator<<(std::ostream &o, const D16bit val)
{
	o << std::dec << std::setw(5) << std::setfill('0') << static_cast<uint32_t>(val.val);
	return (o);
}

