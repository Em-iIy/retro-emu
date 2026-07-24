/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#pragma once

#include <iostream>

enum class OpCodesExt
{
	RLC_B = 0x00,
	RLC_C = 0x01,
	RLC_D = 0x02,
	RLC_E = 0x03,
	RLC_H = 0x04,
	RLC_L = 0x05,
	RLC_HL = 0x06,
	RLC_A = 0x07,
	RRC_B = 0x08,
	RRC_C = 0x09,
	RRC_D = 0x0A,
	RRC_E = 0x0B,
	RRC_H = 0x0C,
	RRC_L = 0x0D,
	RRC_HL = 0x0E,
	RRC_A = 0x0F,
	RL_B = 0x10,
	RL_C = 0x11,
	RL_D = 0x12,
	RL_E = 0x13,
	RL_H = 0x14,
	RL_L = 0x15,
	RL_HL = 0x16,
	RL_A = 0x17,
	RR_B = 0x18,
	RR_C = 0x19,
	RR_D = 0x1A,
	RR_E = 0x1B,
	RR_H = 0x1C,
	RR_L = 0x1D,
	RR_HL = 0x1E,
	RR_A = 0x1F,
	SLA_B = 0x20,
	SLA_C = 0x21,
	SLA_D = 0x22,
	SLA_E = 0x23,
	SLA_H = 0x24,
	SLA_L = 0x25,
	SLA_HL = 0x26,
	SLA_A = 0x27,
	SRA_B = 0x28,
	SRA_C = 0x29,
	SRA_D = 0x2A,
	SRA_E = 0x2B,
	SRA_H = 0x2C,
	SRA_L = 0x2D,
	SRA_HL = 0x2E,
	SRA_A = 0x2F,
	SWAP_B = 0x30,
	SWAP_C = 0x31,
	SWAP_D = 0x32,
	SWAP_E = 0x33,
	SWAP_H = 0x34,
	SWAP_L = 0x35,
	SWAP_HL = 0x36,
	SWAP_A = 0x37,
	SRL_B = 0x38,
	SRL_C = 0x39,
	SRL_D = 0x3A,
	SRL_E = 0x3B,
	SRL_H = 0x3C,
	SRL_L = 0x3D,
	SRL_HL = 0x3E,
	SRL_A = 0x3F,
	BIT_0_B = 0x40,
	BIT_0_C = 0x41,
	BIT_0_D = 0x42,
	BIT_0_E = 0x43,
	BIT_0_H = 0x44,
	BIT_0_L = 0x45,
	BIT_0_HL = 0x46,
	BIT_0_A = 0x47,
	BIT_1_B = 0x48,
	BIT_1_C = 0x49,
	BIT_1_D = 0x4A,
	BIT_1_E = 0x4B,
	BIT_1_H = 0x4C,
	BIT_1_L = 0x4D,
	BIT_1_HL = 0x4E,
	BIT_1_A = 0x4F,
	BIT_2_B = 0x50,
	BIT_2_C = 0x51,
	BIT_2_D = 0x52,
	BIT_2_E = 0x53,
	BIT_2_H = 0x54,
	BIT_2_L = 0x55,
	BIT_2_HL = 0x56,
	BIT_2_A = 0x57,
	BIT_3_B = 0x58,
	BIT_3_C = 0x59,
	BIT_3_D = 0x5A,
	BIT_3_E = 0x5B,
	BIT_3_H = 0x5C,
	BIT_3_L = 0x5D,
	BIT_3_HL = 0x5E,
	BIT_3_A = 0x5F,
	BIT_4_B = 0x60,
	BIT_4_C = 0x61,
	BIT_4_D = 0x62,
	BIT_4_E = 0x63,
	BIT_4_H = 0x64,
	BIT_4_L = 0x65,
	BIT_4_HL = 0x66,
	BIT_4_A = 0x67,
	BIT_5_B = 0x68,
	BIT_5_C = 0x69,
	BIT_5_D = 0x6A,
	BIT_5_E = 0x6B,
	BIT_5_H = 0x6C,
	BIT_5_L = 0x6D,
	BIT_5_HL = 0x6E,
	BIT_5_A = 0x6F,
	BIT_6_B = 0x70,
	BIT_6_C = 0x71,
	BIT_6_D = 0x72,
	BIT_6_E = 0x73,
	BIT_6_H = 0x74,
	BIT_6_L = 0x75,
	BIT_6_HL = 0x76,
	BIT_6_A = 0x77,
	BIT_7_B = 0x78,
	BIT_7_C = 0x79,
	BIT_7_D = 0x7A,
	BIT_7_E = 0x7B,
	BIT_7_H = 0x7C,
	BIT_7_L = 0x7D,
	BIT_7_HL = 0x7E,
	BIT_7_A = 0x7F,
	RES_0_B = 0x80,
	RES_0_C = 0x81,
	RES_0_D = 0x82,
	RES_0_E = 0x83,
	RES_0_H = 0x84,
	RES_0_L = 0x85,
	RES_0_HL = 0x86,
	RES_0_A = 0x87,
	RES_1_B = 0x88,
	RES_1_C = 0x89,
	RES_1_D = 0x8A,
	RES_1_E = 0x8B,
	RES_1_H = 0x8C,
	RES_1_L = 0x8D,
	RES_1_HL = 0x8E,
	RES_1_A = 0x8F,
	RES_2_B = 0x90,
	RES_2_C = 0x91,
	RES_2_D = 0x92,
	RES_2_E = 0x93,
	RES_2_H = 0x94,
	RES_2_L = 0x95,
	RES_2_HL = 0x96,
	RES_2_A = 0x97,
	RES_3_B = 0x98,
	RES_3_C = 0x99,
	RES_3_D = 0x9A,
	RES_3_E = 0x9B,
	RES_3_H = 0x9C,
	RES_3_L = 0x9D,
	RES_3_HL = 0x9E,
	RES_3_A = 0x9F,
	RES_4_B = 0xA0,
	RES_4_C = 0xA1,
	RES_4_D = 0xA2,
	RES_4_E = 0xA3,
	RES_4_H = 0xA4,
	RES_4_L = 0xA5,
	RES_4_HL = 0xA6,
	RES_4_A = 0xA7,
	RES_5_B = 0xA8,
	RES_5_C = 0xA9,
	RES_5_D = 0xAA,
	RES_5_E = 0xAB,
	RES_5_H = 0xAC,
	RES_5_L = 0xAD,
	RES_5_HL = 0xAE,
	RES_5_A = 0xAF,
	RES_6_B = 0xB0,
	RES_6_C = 0xB1,
	RES_6_D = 0xB2,
	RES_6_E = 0xB3,
	RES_6_H = 0xB4,
	RES_6_L = 0xB5,
	RES_6_HL = 0xB6,
	RES_6_A = 0xB7,
	RES_7_B = 0xB8,
	RES_7_C = 0xB9,
	RES_7_D = 0xBA,
	RES_7_E = 0xBB,
	RES_7_H = 0xBC,
	RES_7_L = 0xBD,
	RES_7_HL = 0xBE,
	RES_7_A = 0xBF,
	SET_0_B = 0xC0,
	SET_0_C = 0xC1,
	SET_0_D = 0xC2,
	SET_0_E = 0xC3,
	SET_0_H = 0xC4,
	SET_0_L = 0xC5,
	SET_0_HL = 0xC6,
	SET_0_A = 0xC7,
	SET_1_B = 0xC8,
	SET_1_C = 0xC9,
	SET_1_D = 0xCA,
	SET_1_E = 0xCB,
	SET_1_H = 0xCC,
	SET_1_L = 0xCD,
	SET_1_HL = 0xCE,
	SET_1_A = 0xCF,
	SET_2_B = 0xD0,
	SET_2_C = 0xD1,
	SET_2_D = 0xD2,
	SET_2_E = 0xD3,
	SET_2_H = 0xD4,
	SET_2_L = 0xD5,
	SET_2_HL = 0xD6,
	SET_2_A = 0xD7,
	SET_3_B = 0xD8,
	SET_3_C = 0xD9,
	SET_3_D = 0xDA,
	SET_3_E = 0xDB,
	SET_3_H = 0xDC,
	SET_3_L = 0xDD,
	SET_3_HL = 0xDE,
	SET_3_A = 0xDF,
	SET_4_B = 0xE0,
	SET_4_C = 0xE1,
	SET_4_D = 0xE2,
	SET_4_E = 0xE3,
	SET_4_H = 0xE4,
	SET_4_L = 0xE5,
	SET_4_HL = 0xE6,
	SET_4_A = 0xE7,
	SET_5_B = 0xE8,
	SET_5_C = 0xE9,
	SET_5_D = 0xEA,
	SET_5_E = 0xEB,
	SET_5_H = 0xEC,
	SET_5_L = 0xED,
	SET_5_HL = 0xEE,
	SET_5_A = 0xEF,
	SET_6_B = 0xF0,
	SET_6_C = 0xF1,
	SET_6_D = 0xF2,
	SET_6_E = 0xF3,
	SET_6_H = 0xF4,
	SET_6_L = 0xF5,
	SET_6_HL = 0xF6,
	SET_6_A = 0xF7,
	SET_7_B = 0xF8,
	SET_7_C = 0xF9,
	SET_7_D = 0xFA,
	SET_7_E = 0xFB,
	SET_7_H = 0xFC,
	SET_7_L = 0xFD,
	SET_7_HL = 0xFE,
	SET_7_A = 0xFF
};

inline std::ostream &operator<<(std::ostream &o, const OpCodesExt code)
{
	switch (code)
	{
	case OpCodesExt::RLC_B:
		o << "0x00: RLC_B"; break ;
	case OpCodesExt::RLC_C:
		o << "0x01: RLC_C"; break ;
	case OpCodesExt::RLC_D:
		o << "0x02: RLC_D"; break ;
	case OpCodesExt::RLC_E:
		o << "0x03: RLC_E"; break ;
	case OpCodesExt::RLC_H:
		o << "0x04: RLC_H"; break ;
	case OpCodesExt::RLC_L:
		o << "0x05: RLC_L"; break ;
	case OpCodesExt::RLC_HL:
		o << "0x06: RLC_HL"; break ;
	case OpCodesExt::RLC_A:
		o << "0x07: RLC_A"; break ;
	case OpCodesExt::RRC_B:
		o << "0x08: RRC_B"; break ;
	case OpCodesExt::RRC_C:
		o << "0x09: RRC_C"; break ;
	case OpCodesExt::RRC_D:
		o << "0x0A: RRC_D"; break ;
	case OpCodesExt::RRC_E:
		o << "0x0B: RRC_E"; break ;
	case OpCodesExt::RRC_H:
		o << "0x0C: RRC_H"; break ;
	case OpCodesExt::RRC_L:
		o << "0x0D: RRC_L"; break ;
	case OpCodesExt::RRC_HL:
		o << "0x0E: RRC_HL"; break ;
	case OpCodesExt::RRC_A:
		o << "0x0F: RRC_A"; break ;
	case OpCodesExt::RL_B:
		o << "0x10: RL_B"; break ;
	case OpCodesExt::RL_C:
		o << "0x11: RL_C"; break ;
	case OpCodesExt::RL_D:
		o << "0x12: RL_D"; break ;
	case OpCodesExt::RL_E:
		o << "0x13: RL_E"; break ;
	case OpCodesExt::RL_H:
		o << "0x14: RL_H"; break ;
	case OpCodesExt::RL_L:
		o << "0x15: RL_L"; break ;
	case OpCodesExt::RL_HL:
		o << "0x16: RL_HL"; break ;
	case OpCodesExt::RL_A:
		o << "0x17: RL_A"; break ;
	case OpCodesExt::RR_B:
		o << "0x18: RR_B"; break ;
	case OpCodesExt::RR_C:
		o << "0x19: RR_C"; break ;
	case OpCodesExt::RR_D:
		o << "0x1A: RR_D"; break ;
	case OpCodesExt::RR_E:
		o << "0x1B: RR_E"; break ;
	case OpCodesExt::RR_H:
		o << "0x1C: RR_H"; break ;
	case OpCodesExt::RR_L:
		o << "0x1D: RR_L"; break ;
	case OpCodesExt::RR_HL:
		o << "0x1E: RR_HL"; break ;
	case OpCodesExt::RR_A:
		o << "0x1F: RR_A"; break ;
	case OpCodesExt::SLA_B:
		o << "0x20: SLA_B"; break ;
	case OpCodesExt::SLA_C:
		o << "0x21: SLA_C"; break ;
	case OpCodesExt::SLA_D:
		o << "0x22: SLA_D"; break ;
	case OpCodesExt::SLA_E:
		o << "0x23: SLA_E"; break ;
	case OpCodesExt::SLA_H:
		o << "0x24: SLA_H"; break ;
	case OpCodesExt::SLA_L:
		o << "0x25: SLA_L"; break ;
	case OpCodesExt::SLA_HL:
		o << "0x26: SLA_HL"; break ;
	case OpCodesExt::SLA_A:
		o << "0x27: SLA_A"; break ;
	case OpCodesExt::SRA_B:
		o << "0x28: SRA_B"; break ;
	case OpCodesExt::SRA_C:
		o << "0x29: SRA_C"; break ;
	case OpCodesExt::SRA_D:
		o << "0x2A: SRA_D"; break ;
	case OpCodesExt::SRA_E:
		o << "0x2B: SRA_E"; break ;
	case OpCodesExt::SRA_H:
		o << "0x2C: SRA_H"; break ;
	case OpCodesExt::SRA_L:
		o << "0x2D: SRA_L"; break ;
	case OpCodesExt::SRA_HL:
		o << "0x2E: SRA_HL"; break ;
	case OpCodesExt::SRA_A:
		o << "0x2F: SRA_A"; break ;
	case OpCodesExt::SWAP_B:
		o << "0x30: SWAP_B"; break ;
	case OpCodesExt::SWAP_C:
		o << "0x31: SWAP_C"; break ;
	case OpCodesExt::SWAP_D:
		o << "0x32: SWAP_D"; break ;
	case OpCodesExt::SWAP_E:
		o << "0x33: SWAP_E"; break ;
	case OpCodesExt::SWAP_H:
		o << "0x34: SWAP_H"; break ;
	case OpCodesExt::SWAP_L:
		o << "0x35: SWAP_L"; break ;
	case OpCodesExt::SWAP_HL:
		o << "0x36: SWAP_HL"; break ;
	case OpCodesExt::SWAP_A:
		o << "0x37: SWAP_A"; break ;
	case OpCodesExt::SRL_B:
		o << "0x38: SRL_B"; break ;
	case OpCodesExt::SRL_C:
		o << "0x39: SRL_C"; break ;
	case OpCodesExt::SRL_D:
		o << "0x3A: SRL_D"; break ;
	case OpCodesExt::SRL_E:
		o << "0x3B: SRL_E"; break ;
	case OpCodesExt::SRL_H:
		o << "0x3C: SRL_H"; break ;
	case OpCodesExt::SRL_L:
		o << "0x3D: SRL_L"; break ;
	case OpCodesExt::SRL_HL:
		o << "0x3E: SRL_HL"; break ;
	case OpCodesExt::SRL_A:
		o << "0x3F: SRL_A"; break ;
	case OpCodesExt::BIT_0_B:
		o << "0x40: BIT_0_B"; break ;
	case OpCodesExt::BIT_0_C:
		o << "0x41: BIT_0_C"; break ;
	case OpCodesExt::BIT_0_D:
		o << "0x42: BIT_0_D"; break ;
	case OpCodesExt::BIT_0_E:
		o << "0x43: BIT_0_E"; break ;
	case OpCodesExt::BIT_0_H:
		o << "0x44: BIT_0_H"; break ;
	case OpCodesExt::BIT_0_L:
		o << "0x45: BIT_0_L"; break ;
	case OpCodesExt::BIT_0_HL:
		o << "0x46: BIT_0_HL"; break ;
	case OpCodesExt::BIT_0_A:
		o << "0x47: BIT_0_A"; break ;
	case OpCodesExt::BIT_1_B:
		o << "0x48: BIT_1_B"; break ;
	case OpCodesExt::BIT_1_C:
		o << "0x49: BIT_1_C"; break ;
	case OpCodesExt::BIT_1_D:
		o << "0x4A: BIT_1_D"; break ;
	case OpCodesExt::BIT_1_E:
		o << "0x4B: BIT_1_E"; break ;
	case OpCodesExt::BIT_1_H:
		o << "0x4C: BIT_1_H"; break ;
	case OpCodesExt::BIT_1_L:
		o << "0x4D: BIT_1_L"; break ;
	case OpCodesExt::BIT_1_HL:
		o << "0x4E: BIT_1_HL"; break ;
	case OpCodesExt::BIT_1_A:
		o << "0x4F: BIT_1_A"; break ;
	case OpCodesExt::BIT_2_B:
		o << "0x50: BIT_2_B"; break ;
	case OpCodesExt::BIT_2_C:
		o << "0x51: BIT_2_C"; break ;
	case OpCodesExt::BIT_2_D:
		o << "0x52: BIT_2_D"; break ;
	case OpCodesExt::BIT_2_E:
		o << "0x53: BIT_2_E"; break ;
	case OpCodesExt::BIT_2_H:
		o << "0x54: BIT_2_H"; break ;
	case OpCodesExt::BIT_2_L:
		o << "0x55: BIT_2_L"; break ;
	case OpCodesExt::BIT_2_HL:
		o << "0x56: BIT_2_HL"; break ;
	case OpCodesExt::BIT_2_A:
		o << "0x57: BIT_2_A"; break ;
	case OpCodesExt::BIT_3_B:
		o << "0x58: BIT_3_B"; break ;
	case OpCodesExt::BIT_3_C:
		o << "0x59: BIT_3_C"; break ;
	case OpCodesExt::BIT_3_D:
		o << "0x5A: BIT_3_D"; break ;
	case OpCodesExt::BIT_3_E:
		o << "0x5B: BIT_3_E"; break ;
	case OpCodesExt::BIT_3_H:
		o << "0x5C: BIT_3_H"; break ;
	case OpCodesExt::BIT_3_L:
		o << "0x5D: BIT_3_L"; break ;
	case OpCodesExt::BIT_3_HL:
		o << "0x5E: BIT_3_HL"; break ;
	case OpCodesExt::BIT_3_A:
		o << "0x5F: BIT_3_A"; break ;
	case OpCodesExt::BIT_4_B:
		o << "0x60: BIT_4_B"; break ;
	case OpCodesExt::BIT_4_C:
		o << "0x61: BIT_4_C"; break ;
	case OpCodesExt::BIT_4_D:
		o << "0x62: BIT_4_D"; break ;
	case OpCodesExt::BIT_4_E:
		o << "0x63: BIT_4_E"; break ;
	case OpCodesExt::BIT_4_H:
		o << "0x64: BIT_4_H"; break ;
	case OpCodesExt::BIT_4_L:
		o << "0x65: BIT_4_L"; break ;
	case OpCodesExt::BIT_4_HL:
		o << "0x66: BIT_4_HL"; break ;
	case OpCodesExt::BIT_4_A:
		o << "0x67: BIT_4_A"; break ;
	case OpCodesExt::BIT_5_B:
		o << "0x68: BIT_5_B"; break ;
	case OpCodesExt::BIT_5_C:
		o << "0x69: BIT_5_C"; break ;
	case OpCodesExt::BIT_5_D:
		o << "0x6A: BIT_5_D"; break ;
	case OpCodesExt::BIT_5_E:
		o << "0x6B: BIT_5_E"; break ;
	case OpCodesExt::BIT_5_H:
		o << "0x6C: BIT_5_H"; break ;
	case OpCodesExt::BIT_5_L:
		o << "0x6D: BIT_5_L"; break ;
	case OpCodesExt::BIT_5_HL:
		o << "0x6E: BIT_5_HL"; break ;
	case OpCodesExt::BIT_5_A:
		o << "0x6F: BIT_5_A"; break ;
	case OpCodesExt::BIT_6_B:
		o << "0x70: BIT_6_B"; break ;
	case OpCodesExt::BIT_6_C:
		o << "0x71: BIT_6_C"; break ;
	case OpCodesExt::BIT_6_D:
		o << "0x72: BIT_6_D"; break ;
	case OpCodesExt::BIT_6_E:
		o << "0x73: BIT_6_E"; break ;
	case OpCodesExt::BIT_6_H:
		o << "0x74: BIT_6_H"; break ;
	case OpCodesExt::BIT_6_L:
		o << "0x75: BIT_6_L"; break ;
	case OpCodesExt::BIT_6_HL:
		o << "0x76: BIT_6_HL"; break ;
	case OpCodesExt::BIT_6_A:
		o << "0x77: BIT_6_A"; break ;
	case OpCodesExt::BIT_7_B:
		o << "0x78: BIT_7_B"; break ;
	case OpCodesExt::BIT_7_C:
		o << "0x79: BIT_7_C"; break ;
	case OpCodesExt::BIT_7_D:
		o << "0x7A: BIT_7_D"; break ;
	case OpCodesExt::BIT_7_E:
		o << "0x7B: BIT_7_E"; break ;
	case OpCodesExt::BIT_7_H:
		o << "0x7C: BIT_7_H"; break ;
	case OpCodesExt::BIT_7_L:
		o << "0x7D: BIT_7_L"; break ;
	case OpCodesExt::BIT_7_HL:
		o << "0x7E: BIT_7_HL"; break ;
	case OpCodesExt::BIT_7_A:
		o << "0x7F: BIT_7_A"; break ;
	case OpCodesExt::RES_0_B:
		o << "0x80: RES_0_B"; break ;
	case OpCodesExt::RES_0_C:
		o << "0x81: RES_0_C"; break ;
	case OpCodesExt::RES_0_D:
		o << "0x82: RES_0_D"; break ;
	case OpCodesExt::RES_0_E:
		o << "0x83: RES_0_E"; break ;
	case OpCodesExt::RES_0_H:
		o << "0x84: RES_0_H"; break ;
	case OpCodesExt::RES_0_L:
		o << "0x85: RES_0_L"; break ;
	case OpCodesExt::RES_0_HL:
		o << "0x86: RES_0_HL"; break ;
	case OpCodesExt::RES_0_A:
		o << "0x87: RES_0_A"; break ;
	case OpCodesExt::RES_1_B:
		o << "0x88: RES_1_B"; break ;
	case OpCodesExt::RES_1_C:
		o << "0x89: RES_1_C"; break ;
	case OpCodesExt::RES_1_D:
		o << "0x8A: RES_1_D"; break ;
	case OpCodesExt::RES_1_E:
		o << "0x8B: RES_1_E"; break ;
	case OpCodesExt::RES_1_H:
		o << "0x8C: RES_1_H"; break ;
	case OpCodesExt::RES_1_L:
		o << "0x8D: RES_1_L"; break ;
	case OpCodesExt::RES_1_HL:
		o << "0x8E: RES_1_HL"; break ;
	case OpCodesExt::RES_1_A:
		o << "0x8F: RES_1_A"; break ;
	case OpCodesExt::RES_2_B:
		o << "0x90: RES_2_B"; break ;
	case OpCodesExt::RES_2_C:
		o << "0x91: RES_2_C"; break ;
	case OpCodesExt::RES_2_D:
		o << "0x92: RES_2_D"; break ;
	case OpCodesExt::RES_2_E:
		o << "0x93: RES_2_E"; break ;
	case OpCodesExt::RES_2_H:
		o << "0x94: RES_2_H"; break ;
	case OpCodesExt::RES_2_L:
		o << "0x95: RES_2_L"; break ;
	case OpCodesExt::RES_2_HL:
		o << "0x96: RES_2_HL"; break ;
	case OpCodesExt::RES_2_A:
		o << "0x97: RES_2_A"; break ;
	case OpCodesExt::RES_3_B:
		o << "0x98: RES_3_B"; break ;
	case OpCodesExt::RES_3_C:
		o << "0x99: RES_3_C"; break ;
	case OpCodesExt::RES_3_D:
		o << "0x9A: RES_3_D"; break ;
	case OpCodesExt::RES_3_E:
		o << "0x9B: RES_3_E"; break ;
	case OpCodesExt::RES_3_H:
		o << "0x9C: RES_3_H"; break ;
	case OpCodesExt::RES_3_L:
		o << "0x9D: RES_3_L"; break ;
	case OpCodesExt::RES_3_HL:
		o << "0x9E: RES_3_HL"; break ;
	case OpCodesExt::RES_3_A:
		o << "0x9F: RES_3_A"; break ;
	case OpCodesExt::RES_4_B:
		o << "0xA0: RES_4_B"; break ;
	case OpCodesExt::RES_4_C:
		o << "0xA1: RES_4_C"; break ;
	case OpCodesExt::RES_4_D:
		o << "0xA2: RES_4_D"; break ;
	case OpCodesExt::RES_4_E:
		o << "0xA3: RES_4_E"; break ;
	case OpCodesExt::RES_4_H:
		o << "0xA4: RES_4_H"; break ;
	case OpCodesExt::RES_4_L:
		o << "0xA5: RES_4_L"; break ;
	case OpCodesExt::RES_4_HL:
		o << "0xA6: RES_4_HL"; break ;
	case OpCodesExt::RES_4_A:
		o << "0xA7: RES_4_A"; break ;
	case OpCodesExt::RES_5_B:
		o << "0xA8: RES_5_B"; break ;
	case OpCodesExt::RES_5_C:
		o << "0xA9: RES_5_C"; break ;
	case OpCodesExt::RES_5_D:
		o << "0xAA: RES_5_D"; break ;
	case OpCodesExt::RES_5_E:
		o << "0xAB: RES_5_E"; break ;
	case OpCodesExt::RES_5_H:
		o << "0xAC: RES_5_H"; break ;
	case OpCodesExt::RES_5_L:
		o << "0xAD: RES_5_L"; break ;
	case OpCodesExt::RES_5_HL:
		o << "0xAE: RES_5_HL"; break ;
	case OpCodesExt::RES_5_A:
		o << "0xAF: RES_5_A"; break ;
	case OpCodesExt::RES_6_B:
		o << "0xB0: RES_6_B"; break ;
	case OpCodesExt::RES_6_C:
		o << "0xB1: RES_6_C"; break ;
	case OpCodesExt::RES_6_D:
		o << "0xB2: RES_6_D"; break ;
	case OpCodesExt::RES_6_E:
		o << "0xB3: RES_6_E"; break ;
	case OpCodesExt::RES_6_H:
		o << "0xB4: RES_6_H"; break ;
	case OpCodesExt::RES_6_L:
		o << "0xB5: RES_6_L"; break ;
	case OpCodesExt::RES_6_HL:
		o << "0xB6: RES_6_HL"; break ;
	case OpCodesExt::RES_6_A:
		o << "0xB7: RES_6_A"; break ;
	case OpCodesExt::RES_7_B:
		o << "0xB8: RES_7_B"; break ;
	case OpCodesExt::RES_7_C:
		o << "0xB9: RES_7_C"; break ;
	case OpCodesExt::RES_7_D:
		o << "0xBA: RES_7_D"; break ;
	case OpCodesExt::RES_7_E:
		o << "0xBB: RES_7_E"; break ;
	case OpCodesExt::RES_7_H:
		o << "0xBC: RES_7_H"; break ;
	case OpCodesExt::RES_7_L:
		o << "0xBD: RES_7_L"; break ;
	case OpCodesExt::RES_7_HL:
		o << "0xBE: RES_7_HL"; break ;
	case OpCodesExt::RES_7_A:
		o << "0xBF: RES_7_A"; break ;
	case OpCodesExt::SET_0_B:
		o << "0xC0: SET_0_B"; break ;
	case OpCodesExt::SET_0_C:
		o << "0xC1: SET_0_C"; break ;
	case OpCodesExt::SET_0_D:
		o << "0xC2: SET_0_D"; break ;
	case OpCodesExt::SET_0_E:
		o << "0xC3: SET_0_E"; break ;
	case OpCodesExt::SET_0_H:
		o << "0xC4: SET_0_H"; break ;
	case OpCodesExt::SET_0_L:
		o << "0xC5: SET_0_L"; break ;
	case OpCodesExt::SET_0_HL:
		o << "0xC6: SET_0_HL"; break ;
	case OpCodesExt::SET_0_A:
		o << "0xC7: SET_0_A"; break ;
	case OpCodesExt::SET_1_B:
		o << "0xC8: SET_1_B"; break ;
	case OpCodesExt::SET_1_C:
		o << "0xC9: SET_1_C"; break ;
	case OpCodesExt::SET_1_D:
		o << "0xCA: SET_1_D"; break ;
	case OpCodesExt::SET_1_E:
		o << "0xCB: SET_1_E"; break ;
	case OpCodesExt::SET_1_H:
		o << "0xCC: SET_1_H"; break ;
	case OpCodesExt::SET_1_L:
		o << "0xCD: SET_1_L"; break ;
	case OpCodesExt::SET_1_HL:
		o << "0xCE: SET_1_HL"; break ;
	case OpCodesExt::SET_1_A:
		o << "0xCF: SET_1_A"; break ;
	case OpCodesExt::SET_2_B:
		o << "0xD0: SET_2_B"; break ;
	case OpCodesExt::SET_2_C:
		o << "0xD1: SET_2_C"; break ;
	case OpCodesExt::SET_2_D:
		o << "0xD2: SET_2_D"; break ;
	case OpCodesExt::SET_2_E:
		o << "0xD3: SET_2_E"; break ;
	case OpCodesExt::SET_2_H:
		o << "0xD4: SET_2_H"; break ;
	case OpCodesExt::SET_2_L:
		o << "0xD5: SET_2_L"; break ;
	case OpCodesExt::SET_2_HL:
		o << "0xD6: SET_2_HL"; break ;
	case OpCodesExt::SET_2_A:
		o << "0xD7: SET_2_A"; break ;
	case OpCodesExt::SET_3_B:
		o << "0xD8: SET_3_B"; break ;
	case OpCodesExt::SET_3_C:
		o << "0xD9: SET_3_C"; break ;
	case OpCodesExt::SET_3_D:
		o << "0xDA: SET_3_D"; break ;
	case OpCodesExt::SET_3_E:
		o << "0xDB: SET_3_E"; break ;
	case OpCodesExt::SET_3_H:
		o << "0xDC: SET_3_H"; break ;
	case OpCodesExt::SET_3_L:
		o << "0xDD: SET_3_L"; break ;
	case OpCodesExt::SET_3_HL:
		o << "0xDE: SET_3_HL"; break ;
	case OpCodesExt::SET_3_A:
		o << "0xDF: SET_3_A"; break ;
	case OpCodesExt::SET_4_B:
		o << "0xE0: SET_4_B"; break ;
	case OpCodesExt::SET_4_C:
		o << "0xE1: SET_4_C"; break ;
	case OpCodesExt::SET_4_D:
		o << "0xE2: SET_4_D"; break ;
	case OpCodesExt::SET_4_E:
		o << "0xE3: SET_4_E"; break ;
	case OpCodesExt::SET_4_H:
		o << "0xE4: SET_4_H"; break ;
	case OpCodesExt::SET_4_L:
		o << "0xE5: SET_4_L"; break ;
	case OpCodesExt::SET_4_HL:
		o << "0xE6: SET_4_HL"; break ;
	case OpCodesExt::SET_4_A:
		o << "0xE7: SET_4_A"; break ;
	case OpCodesExt::SET_5_B:
		o << "0xE8: SET_5_B"; break ;
	case OpCodesExt::SET_5_C:
		o << "0xE9: SET_5_C"; break ;
	case OpCodesExt::SET_5_D:
		o << "0xEA: SET_5_D"; break ;
	case OpCodesExt::SET_5_E:
		o << "0xEB: SET_5_E"; break ;
	case OpCodesExt::SET_5_H:
		o << "0xEC: SET_5_H"; break ;
	case OpCodesExt::SET_5_L:
		o << "0xED: SET_5_L"; break ;
	case OpCodesExt::SET_5_HL:
		o << "0xEE: SET_5_HL"; break ;
	case OpCodesExt::SET_5_A:
		o << "0xEF: SET_5_A"; break ;
	case OpCodesExt::SET_6_B:
		o << "0xF0: SET_6_B"; break ;
	case OpCodesExt::SET_6_C:
		o << "0xF1: SET_6_C"; break ;
	case OpCodesExt::SET_6_D:
		o << "0xF2: SET_6_D"; break ;
	case OpCodesExt::SET_6_E:
		o << "0xF3: SET_6_E"; break ;
	case OpCodesExt::SET_6_H:
		o << "0xF4: SET_6_H"; break ;
	case OpCodesExt::SET_6_L:
		o << "0xF5: SET_6_L"; break ;
	case OpCodesExt::SET_6_HL:
		o << "0xF6: SET_6_HL"; break ;
	case OpCodesExt::SET_6_A:
		o << "0xF7: SET_6_A"; break ;
	case OpCodesExt::SET_7_B:
		o << "0xF8: SET_7_B"; break ;
	case OpCodesExt::SET_7_C:
		o << "0xF9: SET_7_C"; break ;
	case OpCodesExt::SET_7_D:
		o << "0xFA: SET_7_D"; break ;
	case OpCodesExt::SET_7_E:
		o << "0xFB: SET_7_E"; break ;
	case OpCodesExt::SET_7_H:
		o << "0xFC: SET_7_H"; break ;
	case OpCodesExt::SET_7_L:
		o << "0xFD: SET_7_L"; break ;
	case OpCodesExt::SET_7_HL:
		o << "0xFE: SET_7_HL"; break ;
	case OpCodesExt::SET_7_A:
		o << "0xFF: SET_7_A"; break ;
	}
	return (o);
}