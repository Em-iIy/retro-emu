/*
Created by: Emily (Em_iIy) Winnink
Created on: 09/04/2026
*/

#pragma once

#include <iostream>

enum class OpCodes
{
	NOP 				= 0x00,		// 0x00: NOP
	LD_BC_d16			= 0x01,		// 0x01: LD BC, d16
	LD_DREF_BC_A		= 0x02,		// 0x02: LD (BC), A
	INC_BC	 			= 0x03,		// 0x03: INC BC
	INC_B 				= 0x04,		// 0x04: INC B
	DEC_B 				= 0x05,		// 0x05: DEC B
	LD_B_d8 			= 0x06,		// 0x06: LD B, d8
	RLCA 				= 0x07,		// 0x07: RLCA
	LD_DREF_a16_SP 		= 0x08,		// 0x08: LD (a16), SP
	ADD_HL_BC 			= 0x09,		// 0x09: ADD HL, BC
	LD_A_DREF_BC 		= 0x0A,		// 0x0A: LD A, (BC)
	DEC_BC 				= 0x0B,		// 0x0B: DEC BC
	INC_C 				= 0x0C,		// 0x0C: INC C
	DEC_C 				= 0x0D,		// 0x0D: DEC C
	LD_C_d8 			= 0x0E,		// 0x0E: LD C, d8
	RRCA 				= 0x0F,		// 0x0F: RRCA
	STOP 				= 0x10,		// 0x1000: STOP
	LD_DE_d16 			= 0x11,		// 0x11: LD DE, d16
	LD_DREF_DE_A 		= 0x12,		// 0x12: LD (DE), A
	INC_DE	 			= 0x13,		// 0x13: INC DE
	INC_D 				= 0x14,		// 0x14: INC D
	DEC_D 				= 0x15,		// 0x15: DEC D
	LD_D_d8 			= 0x16,		// 0x16: LD D, d8
	RLA 				= 0x17,		// 0x17: RLA
	JR_s8 				= 0x18,		// 0x18: JR s8
	ADD_HL_DE 			= 0x19,		// 0x19: ADD HL, DE
	LD_A_DREF_DE 		= 0x1A,		// 0x1A: LD A, (DE)
	DEC_DE 				= 0x1B,		// 0x1B: DEC DE
	INC_E 				= 0x1C,		// 0x1C: INC E
	DEC_E 				= 0x1D,		// 0x1D: DEC E
	LD_E_d8 			= 0x1E,		// 0x1E: LD E, d8
	RRA 				= 0x1F,		// 0x1F: RRA
	JR_NZ_s8 			= 0x20,		// 0x20: JR NZ, s8
	LD_HL_d16 			= 0x21,		// 0x21: LD HL, d16
	LD_DREF_HLI_A		= 0x22,		// 0x22: LD (HL+), A
	INC_HL	 			= 0x23,		// 0x23: INC HL
	INC_H 				= 0x24,		// 0x24: INC H
	DEC_H 				= 0x25,		// 0x25: DEC H
	LD_H_d8 			= 0x26,		// 0x26: LD H, d8
	DAA 				= 0x27,		// 0x27: DAA
	JR_Z_s8 			= 0x28,		// 0x28: JR Z, s8
	ADD_HL_HL 			= 0x29,		// 0x29: ADD HL, HL
	LD_A_DREF_HLI		= 0x2A,		// 0x2A: LD A, (HL+)
	DEC_HL 				= 0x2B,		// 0x2B: DEC HL
	INC_L 				= 0x2C,		// 0x2C: INC L
	DEC_L 				= 0x2D,		// 0x2D: DEC L
	LD_L_d8 			= 0x2E,		// 0x2E: LD L, d8
	CPL 				= 0x2F,		// 0x2F: CPL
	JR_NC_s8 			= 0x30,		// 0x30: JR NC, s8
	LD_SP_d16 			= 0x31,		// 0x31: LD SP, d16
	LD_DREF_HLD_A		= 0x32,		// 0x32: LD (HL-), A
	INC_SP	 			= 0x33,		// 0x33: INC SP
	INC_DREF_HL			= 0x34,		// 0x34: INC (HL)
	DEC_DREF_HL			= 0x35,		// 0x35: DEC (HL)
	LD_DREF_HL_d8		= 0x36,		// 0x36: LD (HL), d8
	SCF 				= 0x37,		// 0x37: SCF
	JR_C_s8 			= 0x38,		// 0x38: JR C, s8
	ADD_HL_SP 			= 0x39,		// 0x39: ADD HL, SP
	LD_A_DREF_HLD		= 0x3A,		// 0x3A: LD A, (HL-)
	DEC_SP 				= 0x3B,		// 0x3B: DEC SP
	INC_A 				= 0x3C,		// 0x3C: INC A
	DEC_A 				= 0x3D,		// 0x3D: DEC A
	LD_A_d8 			= 0x3E,		// 0x3E: LD A, d8
	CCF 				= 0x3F,		// 0x3F: CCF
	LD_B_B 				= 0x40,		// 0x40: LD B, B
	LD_B_C 				= 0x41,		// 0x41: LD B, C
	LD_B_D 				= 0x42,		// 0x42: LD B, D
	LD_B_E 				= 0x43,		// 0x43: LD B, E
	LD_B_H 				= 0x44,		// 0x44: LD B, H
	LD_B_L 				= 0x45,		// 0x45: LD B, L
	LD_B_DREF_HL		= 0x46,		// 0x46: LD B, (HL)
	LD_B_A 				= 0x47,		// 0x47: LD B, A
	LD_C_B 				= 0x48,		// 0x48: LD C, B
	LD_C_C 				= 0x49,		// 0x49: LD C, C
	LD_C_D 				= 0x4A,		// 0x4A: LD C, D
	LD_C_E 				= 0x4B,		// 0x4B: LD C, E
	LD_C_H 				= 0x4C,		// 0x4C: LD C, H
	LD_C_L 				= 0x4D,		// 0x4D: LD C, L
	LD_C_DREF_HL		= 0x4E,		// 0x4E: LD C, (HL)
	LD_C_A 				= 0x4F,		// 0x4F: LD C, A
	LD_D_B 				= 0x50,		// 0x50: LD D, B
	LD_D_C 				= 0x51,		// 0x51: LD D, C
	LD_D_D 				= 0x52,		// 0x52: LD D, D
	LD_D_E 				= 0x53,		// 0x53: LD D, E
	LD_D_H 				= 0x54,		// 0x54: LD D, H
	LD_D_L 				= 0x55,		// 0x55: LD D, L
	LD_D_DREF_HL		= 0x56,		// 0x56: LD D, (HL)
	LD_D_A 				= 0x57,		// 0x57: LD D, A
	LD_E_B 				= 0x58,		// 0x58: LD E, B
	LD_E_C 				= 0x59,		// 0x59: LD E, C
	LD_E_D 				= 0x5A,		// 0x5A: LD E, D
	LD_E_E 				= 0x5B,		// 0x5B: LD E, E
	LD_E_H 				= 0x5C,		// 0x5C: LD E, H
	LD_E_L 				= 0x5D,		// 0x5D: LD E, L
	LD_E_DREF_HL		= 0x5E,		// 0x5E: LD E, (HL)
	LD_E_A 				= 0x5F,		// 0x5F: LD E, A
	LD_H_B 				= 0x60,		// 0x60: LD H, B
	LD_H_C 				= 0x61,		// 0x61: LD H, C
	LD_H_D 				= 0x62,		// 0x62: LD H, D
	LD_H_E 				= 0x63,		// 0x63: LD H, E
	LD_H_H 				= 0x64,		// 0x64: LD H, H
	LD_H_L 				= 0x65,		// 0x65: LD H, L
	LD_H_DREF_HL		= 0x66,		// 0x66: LD H, (HL)
	LD_H_A 				= 0x67,		// 0x67: LD H, A
	LD_L_B 				= 0x68,		// 0x68: LD L, B
	LD_L_C 				= 0x69,		// 0x69: LD L, C
	LD_L_D 				= 0x6A,		// 0x6A: LD L, D
	LD_L_E 				= 0x6B,		// 0x6B: LD L, E
	LD_L_H 				= 0x6C,		// 0x6C: LD L, H
	LD_L_L 				= 0x6D,		// 0x6D: LD L, L
	LD_L_DREF_HL		= 0x6E,		// 0x6E: LD L, (HL)
	LD_L_A 				= 0x6F,		// 0x6F: LD L, A
	LD_DREF_HL_B		= 0x70,		// 0x70: LD (HL), B
	LD_DREF_HL_C		= 0x71,		// 0x71: LD (HL), C
	LD_DREF_HL_D		= 0x72,		// 0x72: LD (HL), D
	LD_DREF_HL_E		= 0x73,		// 0x73: LD (HL), E
	LD_DREF_HL_H		= 0x74,		// 0x74: LD (HL), H
	LD_DREF_HL_L		= 0x75,		// 0x75: LD (HL), L
	HALT 				= 0x76,		// 0x76: HALT
	LD_DREF_HL_A		= 0x77,		// 0x77: LD (HL), A
	LD_A_B 				= 0x78,		// 0x78: LD A, B
	LD_A_C 				= 0x79,		// 0x79: LD A, C
	LD_A_D 				= 0x7A,		// 0x7A: LD A, D
	LD_A_E 				= 0x7B,		// 0x7B: LD A, E
	LD_A_H 				= 0x7C,		// 0x7C: LD A, H
	LD_A_L 				= 0x7D,		// 0x7D: LD A, L
	LD_A_DREF_HL		= 0x7E,		// 0x7E: LD A, (HL)
	LD_A_A 				= 0x7F,		// 0x7F: LD A, A
	ADD_A_B 			= 0x80,		// 0x80: ADD A, B
	ADD_A_C 			= 0x81,		// 0x81: ADD A, C
	ADD_A_D 			= 0x82,		// 0x82: ADD A, D
	ADD_A_E 			= 0x83,		// 0x83: ADD A, E
	ADD_A_H 			= 0x84,		// 0x84: ADD A, H
	ADD_A_L 			= 0x85,		// 0x85: ADD A, L
	ADD_A_DREF_HL		= 0x86,		// 0x86: ADD A, (HL)
	ADD_A_A 			= 0x87,		// 0x87: ADD A, A
	ADC_A_B 			= 0x88,		// 0x88: ADC A, B
	ADC_A_C 			= 0x89,		// 0x89: ADC A, C
	ADC_A_D 			= 0x8A,		// 0x8A: ADC A, D
	ADC_A_E 			= 0x8B,		// 0x8B: ADC A, E
	ADC_A_H 			= 0x8C,		// 0x8C: ADC A, H
	ADC_A_L 			= 0x8D,		// 0x8D: ADC A, L
	ADC_A_DREF_HL		= 0x8E,		// 0x8E: ADC A, (HL)
	ADC_A_A 			= 0x8F,		// 0x8F: ADC A, A
	SUB_B 				= 0x90,		// 0x90: SUB B
	SUB_C 				= 0x91,		// 0x91: SUB C
	SUB_D 				= 0x92,		// 0x92: SUB D
	SUB_E 				= 0x93,		// 0x93: SUB E
	SUB_H 				= 0x94,		// 0x94: SUB H
	SUB_L 				= 0x95,		// 0x95: SUB L
	SUB_DREF_HL			= 0x96,		// 0x96: SUB (HL)
	SUB_A 				= 0x97,		// 0x97: SUB A
	SBC_A_B 			= 0x98,		// 0x98: SBC A, B
	SBC_A_C 			= 0x99,		// 0x99: SBC A, C
	SBC_A_D 			= 0x9A,		// 0x9A: SBC A, D
	SBC_A_E 			= 0x9B,		// 0x9B: SBC A, E
	SBC_A_H 			= 0x9C,		// 0x9C: SBC A, H
	SBC_A_L 			= 0x9D,		// 0x9D: SBC A, L
	SBC_A_DREF_HL		= 0x9E,		// 0x9E: SBC A, (HL)
	SBC_A_A 			= 0x9F,		// 0x9F: SBC A, A
	AND_B 				= 0xA0,		// 0xA0: AND B
	AND_C 				= 0xA1,		// 0xA1: AND C
	AND_D 				= 0xA2,		// 0xA2: AND D
	AND_E 				= 0xA3,		// 0xA3: AND E
	AND_H 				= 0xA4,		// 0xA4: AND H
	AND_L 				= 0xA5,		// 0xA5: AND L
	AND_DREF_HL			= 0xA6,		// 0xA6: AND (HL)
	AND_A 				= 0xA7,		// 0xA7: AND A
	XOR_B 				= 0xA8,		// 0xA8: XOR B
	XOR_C 				= 0xA9,		// 0xA9: XOR C
	XOR_D 				= 0xAA,		// 0xAA: XOR D
	XOR_E 				= 0xAB,		// 0xAB: XOR E
	XOR_H 				= 0xAC,		// 0xAC: XOR H
	XOR_L 				= 0xAD,		// 0xAD: XOR L
	XOR_DREF_HL			= 0xAE,		// 0xAE: XOR (HL)
	XOR_A 				= 0xAF,		// 0xAF: XOR A
	OR_B 				= 0xB0,		// 0xB0: OR B
	OR_C 				= 0xB1,		// 0xB1: OR C
	OR_D 				= 0xB2,		// 0xB2: OR D
	OR_E 				= 0xB3,		// 0xB3: OR E
	OR_H 				= 0xB4,		// 0xB4: OR H
	OR_L 				= 0xB5,		// 0xB5: OR L
	OR_DREF_HL 			= 0xB6,		// 0xB6: OR (HL)
	OR_A 				= 0xB7,		// 0xB7: OR A
	CP_B 				= 0xB8,		// 0xB8: CP B
	CP_C 				= 0xB9,		// 0xB9: CP C
	CP_D 				= 0xBA,		// 0xBA: CP D
	CP_E 				= 0xBB,		// 0xBB: CP E
	CP_H 				= 0xBC,		// 0xBC: CP H
	CP_L 				= 0xBD,		// 0xBD: CP L
	CP_DREF_HL 			= 0xBE,		// 0xBE: CP (HL)
	CP_A 				= 0xBF,		// 0xBF: CP A
	RET_NZ 				= 0xC0,		// 0xC0: RET NZ
	POP_BC 				= 0xC1,		// 0xC1: POP BC
	JP_NZ_a16 			= 0xC2,		// 0xC2: JP NZ, a16
	JP_a16 				= 0xC3,		// 0xC3: JP a16
	CALL_NZ_a16			= 0xC4,		// 0xC4: CALL NZ, a16
	PUSH_BC 			= 0xC5,		// 0xC5: PUSH BC
	ADD_A_d8 			= 0xC6,		// 0xC6: ADD A, d8
	RST_0 				= 0xC7,		// 0xC7: RST 0
	RET_Z 				= 0xC8,		// 0xC8: RET Z
	RET 				= 0xC9,		// 0xC9: RET
	JP_Z_a16 			= 0xCA,		// 0xCA: JP Z, a16
	EXTENDED			= 0xCB,		// 0xCB: EXTENDED
	CALL_Z_a16 			= 0xCC,		// 0xCC: CALL Z, a16
	CALL_a16 			= 0xCD,		// 0xCD: CALL a16
	ADC_A_d8 			= 0xCE,		// 0xCE: ADC A, d8
	RST_1 				= 0xCF,		// 0xCF: RST 1
	RET_NC 				= 0xD0,		// 0xD0: RET NC
	POP_DE 				= 0xD1,		// 0xD1: POP DE
	JP_NC_a16 			= 0xD2,		// 0xD2: JP NC, a16
	CALL_NC_a16			= 0xD4,		// 0xD4: CALL NC, a16
	PUSH_DE 			= 0xD5,		// 0xD5: PUSH DE
	SUB_d8 				= 0xD6,		// 0xD6: SUB d8
	RST_2 				= 0xD7,		// 0xD7: RST 2
	RET_C 				= 0xD8,		// 0xD8: RET C
	RETI 				= 0xD9,		// 0xD9: RETI
	JP_C_a16 			= 0xDA,		// 0xDA: JP C, a16
	CALL_C_a16 			= 0xDC,		// 0xDC: CALL C, a16
	SBC_A_d8 			= 0xDE,		// 0xDE: SBC A, d8
	RST_3 				= 0xDF,		// 0xDF: RST 3
	LD_DREF_a8_A		= 0xE0,		// 0xE0: LD (a8), A
	POP_HL 				= 0xE1,		// 0xE1: POP HL
	LD_DREF_C_A			= 0xE2,		// 0xE2: LD (C), A
	PUSH_HL 			= 0xE5,		// 0xE5: PUSH HL
	AND_d8 				= 0xE6,		// 0xE6: AND d8
	RST_4 				= 0xE7,		// 0xE7: RST 4
	ADD_SP_s8 			= 0xE8,		// 0xE8: ADD SP, s8
	JP_HL 				= 0xE9,		// 0xE9: JP HL
	LD_DREF_a16_A 		= 0xEA,		// 0xEA: LD (a16), A
	XOR_d8 				= 0xEE,		// 0xEE: XOR d8
	RST_5 				= 0xEF,		// 0xEF: RST 5
	LD_A_DREF_a8		= 0xF0,		// 0xF0: LD A, (a8)
	POP_AF 				= 0xF1,		// 0xF1: POP AF
	LD_A_DREF_C			= 0xF2,		// 0xF2: LD A, (C)
	DI 					= 0xF3,		// 0xF3: DI
	PUSH_AF 			= 0xF5,		// 0xF5: PUSH AF
	OR_d8 				= 0xF6,		// 0xF6: OR d8
	RST_6 				= 0xF7,		// 0xF7: RST 6
	LD_HL_SP_PLUS_s8	= 0xF8,		// 0xF8: LD HL, SP+s8
	LD_SP_HL 			= 0xF9,		// 0xF9: LD SP, HL
	LD_A_DREF_a16 		= 0xFA,		// 0xFA: LD A, (a16)
	EI 					= 0xFB,		// 0xFB: EI
	CP_d8 				= 0xFE,		// 0xFE: CP d8
	RST_7 				= 0xFF		// 0xFF: RST 7
};

inline std::ostream &operator<<(std::ostream &o, const OpCodes code)
{
	switch (code)
	{
	case OpCodes::NOP:
		o << "0x00: NOP"; break ;
	case OpCodes::LD_BC_d16:
		o << "0x01: LD BC, d16"; break ;
	case OpCodes::LD_DREF_BC_A:
		o << "0x02: LD (BC), A"; break ;
	case OpCodes::INC_BC:
		o << "0x03: INC BC"; break ;
	case OpCodes::INC_B:
		o << "0x04: INC B"; break ;
	case OpCodes::DEC_B:
		o << "0x05: DEC B"; break ;
	case OpCodes::LD_B_d8:
		o << "0x06: LD B, d8"; break ;
	case OpCodes::RLCA:
		o << "0x07: RLCA"; break ;
	case OpCodes::LD_DREF_a16_SP:
		o << "0x08: LD (a16), SP"; break ;
	case OpCodes::ADD_HL_BC:
		o << "0x09: ADD HL, BC"; break ;
	case OpCodes::LD_A_DREF_BC:
		o << "0x0A: LD A, (BC)"; break ;
	case OpCodes::DEC_BC:
		o << "0x0B: DEC BC"; break ;
	case OpCodes::INC_C:
		o << "0x0C: INC C"; break ;
	case OpCodes::DEC_C:
		o << "0x0D: DEC C"; break ;
	case OpCodes::LD_C_d8:
		o << "0x0E: LD C, d8"; break ;
	case OpCodes::RRCA:
		o << "0x0F: RRCA"; break ;
	case OpCodes::STOP:
		o << "0x1000: STOP"; break ;
	case OpCodes::LD_DE_d16:
		o << "0x11: LD DE, d16"; break ;
	case OpCodes::LD_DREF_DE_A:
		o << "0x12: LD (DE), A"; break ;
	case OpCodes::INC_DE:
		o << "0x13: INC DE"; break ;
	case OpCodes::INC_D:
		o << "0x14: INC D"; break ;
	case OpCodes::DEC_D:
		o << "0x15: DEC D"; break ;
	case OpCodes::LD_D_d8:
		o << "0x16: LD D, d8"; break ;
	case OpCodes::RLA:
		o << "0x17: RLA"; break ;
	case OpCodes::JR_s8:
		o << "0x18: JR s8"; break ;
	case OpCodes::ADD_HL_DE:
		o << "0x19: ADD HL, DE"; break ;
	case OpCodes::LD_A_DREF_DE:
		o << "0x1A: LD A, (DE)"; break ;
	case OpCodes::DEC_DE:
		o << "0x1B: DEC DE"; break ;
	case OpCodes::INC_E:
		o << "0x1C: INC E"; break ;
	case OpCodes::DEC_E:
		o << "0x1D: DEC E"; break ;
	case OpCodes::LD_E_d8:
		o << "0x1E: LD E, d8"; break ;
	case OpCodes::RRA:
		o << "0x1F: RRA"; break ;
	case OpCodes::JR_NZ_s8:
		o << "0x20: JR NZ, s8"; break ;
	case OpCodes::LD_HL_d16:
		o << "0x21: LD HL, d16"; break ;
	case OpCodes::LD_DREF_HLI_A:
		o << "0x22: LD (HL+), A"; break ;
	case OpCodes::INC_HL:
		o << "0x23: INC HL"; break ;
	case OpCodes::INC_H:
		o << "0x24: INC H"; break ;
	case OpCodes::DEC_H:
		o << "0x25: DEC H"; break ;
	case OpCodes::LD_H_d8:
		o << "0x26: LD H, d8"; break ;
	case OpCodes::DAA:
		o << "0x27: DAA"; break ;
	case OpCodes::JR_Z_s8:
		o << "0x28: JR Z, s8"; break ;
	case OpCodes::ADD_HL_HL:
		o << "0x29: ADD HL, HL"; break ;
	case OpCodes::LD_A_DREF_HLI:
		o << "0x2A: LD A, (HL+)"; break ;
	case OpCodes::DEC_HL:
		o << "0x2B: DEC HL"; break ;
	case OpCodes::INC_L:
		o << "0x2C: INC L"; break ;
	case OpCodes::DEC_L:
		o << "0x2D: DEC L"; break ;
	case OpCodes::LD_L_d8:
		o << "0x2E: LD L, d8"; break ;
	case OpCodes::CPL:
		o << "0x2F: CPL"; break ;
	case OpCodes::JR_NC_s8:
		o << "0x30: JR NC, s8"; break ;
	case OpCodes::LD_SP_d16:
		o << "0x31: LD SP, d16"; break ;
	case OpCodes::LD_DREF_HLD_A:
		o << "0x32: LD (HL-), A"; break ;
	case OpCodes::INC_SP:
		o << "0x33: INC SP"; break ;
	case OpCodes::INC_DREF_HL:
		o << "0x34: INC (HL)"; break ;
	case OpCodes::DEC_DREF_HL:
		o << "0x35: DEC (HL)"; break ;
	case OpCodes::LD_DREF_HL_d8:
		o << "0x36: LD (HL), d8"; break ;
	case OpCodes::SCF:
		o << "0x37: SCF"; break ;
	case OpCodes::JR_C_s8:
		o << "0x38: JR C, s8"; break ;
	case OpCodes::ADD_HL_SP:
		o << "0x39: ADD HL, SP"; break ;
	case OpCodes::LD_A_DREF_HLD:
		o << "0x3A: LD A, (HL-)"; break ;
	case OpCodes::DEC_SP:
		o << "0x3B: DEC SP"; break ;
	case OpCodes::INC_A:
		o << "0x3C: INC A"; break ;
	case OpCodes::DEC_A:
		o << "0x3D: DEC A"; break ;
	case OpCodes::LD_A_d8:
		o << "0x3E: LD A, d8"; break ;
	case OpCodes::CCF:
		o << "0x3F: CCF"; break ;
	case OpCodes::LD_B_B:
		o << "0x40: LD B, B"; break ;
	case OpCodes::LD_B_C:
		o << "0x41: LD B, C"; break ;
	case OpCodes::LD_B_D:
		o << "0x42: LD B, D"; break ;
	case OpCodes::LD_B_E:
		o << "0x43: LD B, E"; break ;
	case OpCodes::LD_B_H:
		o << "0x44: LD B, H"; break ;
	case OpCodes::LD_B_L:
		o << "0x45: LD B, L"; break ;
	case OpCodes::LD_B_DREF_HL:
		o << "0x46: LD B, (HL)"; break ;
	case OpCodes::LD_B_A:
		o << "0x47: LD B, A"; break ;
	case OpCodes::LD_C_B:
		o << "0x48: LD C, B"; break ;
	case OpCodes::LD_C_C:
		o << "0x49: LD C, C"; break ;
	case OpCodes::LD_C_D:
		o << "0x4A: LD C, D"; break ;
	case OpCodes::LD_C_E:
		o << "0x4B: LD C, E"; break ;
	case OpCodes::LD_C_H:
		o << "0x4C: LD C, H"; break ;
	case OpCodes::LD_C_L:
		o << "0x4D: LD C, L"; break ;
	case OpCodes::LD_C_DREF_HL:
		o << "0x4E: LD C, (HL)"; break ;
	case OpCodes::LD_C_A:
		o << "0x4F: LD C, A"; break ;
	case OpCodes::LD_D_B:
		o << "0x50: LD D, B"; break ;
	case OpCodes::LD_D_C:
		o << "0x51: LD D, C"; break ;
	case OpCodes::LD_D_D:
		o << "0x52: LD D, D"; break ;
	case OpCodes::LD_D_E:
		o << "0x53: LD D, E"; break ;
	case OpCodes::LD_D_H:
		o << "0x54: LD D, H"; break ;
	case OpCodes::LD_D_L:
		o << "0x55: LD D, L"; break ;
	case OpCodes::LD_D_DREF_HL:
		o << "0x56: LD D, (HL)"; break ;
	case OpCodes::LD_D_A:
		o << "0x57: LD D, A"; break ;
	case OpCodes::LD_E_B:
		o << "0x58: LD E, B"; break ;
	case OpCodes::LD_E_C:
		o << "0x59: LD E, C"; break ;
	case OpCodes::LD_E_D:
		o << "0x5A: LD E, D"; break ;
	case OpCodes::LD_E_E:
		o << "0x5B: LD E, E"; break ;
	case OpCodes::LD_E_H:
		o << "0x5C: LD E, H"; break ;
	case OpCodes::LD_E_L:
		o << "0x5D: LD E, L"; break ;
	case OpCodes::LD_E_DREF_HL:
		o << "0x5E: LD E, (HL)"; break ;
	case OpCodes::LD_E_A:
		o << "0x5F: LD E, A"; break ;
	case OpCodes::LD_H_B:
		o << "0x60: LD H, B"; break ;
	case OpCodes::LD_H_C:
		o << "0x61: LD H, C"; break ;
	case OpCodes::LD_H_D:
		o << "0x62: LD H, D"; break ;
	case OpCodes::LD_H_E:
		o << "0x63: LD H, E"; break ;
	case OpCodes::LD_H_H:
		o << "0x64: LD H, H"; break ;
	case OpCodes::LD_H_L:
		o << "0x65: LD H, L"; break ;
	case OpCodes::LD_H_DREF_HL:
		o << "0x66: LD H, (HL)"; break ;
	case OpCodes::LD_H_A:
		o << "0x67: LD H, A"; break ;
	case OpCodes::LD_L_B:
		o << "0x68: LD L, B"; break ;
	case OpCodes::LD_L_C:
		o << "0x69: LD L, C"; break ;
	case OpCodes::LD_L_D:
		o << "0x6A: LD L, D"; break ;
	case OpCodes::LD_L_E:
		o << "0x6B: LD L, E"; break ;
	case OpCodes::LD_L_H:
		o << "0x6C: LD L, H"; break ;
	case OpCodes::LD_L_L:
		o << "0x6D: LD L, L"; break ;
	case OpCodes::LD_L_DREF_HL:
		o << "0x6E: LD L, (HL)"; break ;
	case OpCodes::LD_L_A:
		o << "0x6F: LD L, A"; break ;
	case OpCodes::LD_DREF_HL_B:
		o << "0x70: LD (HL), B"; break ;
	case OpCodes::LD_DREF_HL_C:
		o << "0x71: LD (HL), C"; break ;
	case OpCodes::LD_DREF_HL_D:
		o << "0x72: LD (HL), D"; break ;
	case OpCodes::LD_DREF_HL_E:
		o << "0x73: LD (HL), E"; break ;
	case OpCodes::LD_DREF_HL_H:
		o << "0x74: LD (HL), H"; break ;
	case OpCodes::LD_DREF_HL_L:
		o << "0x75: LD (HL), L"; break ;
	case OpCodes::HALT:
		o << "0x76: HALT"; break ;
	case OpCodes::LD_DREF_HL_A:
		o << "0x77: LD (HL), A"; break ;
	case OpCodes::LD_A_B:
		o << "0x78: LD A, B"; break ;
	case OpCodes::LD_A_C:
		o << "0x79: LD A, C"; break ;
	case OpCodes::LD_A_D:
		o << "0x7A: LD A, D"; break ;
	case OpCodes::LD_A_E:
		o << "0x7B: LD A, E"; break ;
	case OpCodes::LD_A_H:
		o << "0x7C: LD A, H"; break ;
	case OpCodes::LD_A_L:
		o << "0x7D: LD A, L"; break ;
	case OpCodes::LD_A_DREF_HL:
		o << "0x7E: LD A, (HL)"; break ;
	case OpCodes::LD_A_A:
		o << "0x7F: LD A, A"; break ;
	case OpCodes::ADD_A_B:
		o << "0x80: ADD A, B"; break ;
	case OpCodes::ADD_A_C:
		o << "0x81: ADD A, C"; break ;
	case OpCodes::ADD_A_D:
		o << "0x82: ADD A, D"; break ;
	case OpCodes::ADD_A_E:
		o << "0x83: ADD A, E"; break ;
	case OpCodes::ADD_A_H:
		o << "0x84: ADD A, H"; break ;
	case OpCodes::ADD_A_L:
		o << "0x85: ADD A, L"; break ;
	case OpCodes::ADD_A_DREF_HL:
		o << "0x86: ADD A, (HL)"; break ;
	case OpCodes::ADD_A_A:
		o << "0x87: ADD A, A"; break ;
	case OpCodes::ADC_A_B:
		o << "0x88: ADC A, B"; break ;
	case OpCodes::ADC_A_C:
		o << "0x89: ADC A, C"; break ;
	case OpCodes::ADC_A_D:
		o << "0x8A: ADC A, D"; break ;
	case OpCodes::ADC_A_E:
		o << "0x8B: ADC A, E"; break ;
	case OpCodes::ADC_A_H:
		o << "0x8C: ADC A, H"; break ;
	case OpCodes::ADC_A_L:
		o << "0x8D: ADC A, L"; break ;
	case OpCodes::ADC_A_DREF_HL:
		o << "0x8E: ADC A, (HL)"; break ;
	case OpCodes::ADC_A_A:
		o << "0x8F: ADC A, A"; break ;
	case OpCodes::SUB_B:
		o << "0x90: SUB B"; break ;
	case OpCodes::SUB_C:
		o << "0x91: SUB C"; break ;
	case OpCodes::SUB_D:
		o << "0x92: SUB D"; break ;
	case OpCodes::SUB_E:
		o << "0x93: SUB E"; break ;
	case OpCodes::SUB_H:
		o << "0x94: SUB H"; break ;
	case OpCodes::SUB_L:
		o << "0x95: SUB L"; break ;
	case OpCodes::SUB_DREF_HL:
		o << "0x96: SUB (HL)"; break ;
	case OpCodes::SUB_A:
		o << "0x97: SUB A"; break ;
	case OpCodes::SBC_A_B:
		o << "0x98: SBC A, B"; break ;
	case OpCodes::SBC_A_C:
		o << "0x99: SBC A, C"; break ;
	case OpCodes::SBC_A_D:
		o << "0x9A: SBC A, D"; break ;
	case OpCodes::SBC_A_E:
		o << "0x9B: SBC A, E"; break ;
	case OpCodes::SBC_A_H:
		o << "0x9C: SBC A, H"; break ;
	case OpCodes::SBC_A_L:
		o << "0x9D: SBC A, L"; break ;
	case OpCodes::SBC_A_DREF_HL:
		o << "0x9E: SBC A, (HL)"; break ;
	case OpCodes::SBC_A_A:
		o << "0x9F: SBC A, A"; break ;
	case OpCodes::AND_B:
		o << "0xA0: AND B"; break ;
	case OpCodes::AND_C:
		o << "0xA1: AND C"; break ;
	case OpCodes::AND_D:
		o << "0xA2: AND D"; break ;
	case OpCodes::AND_E:
		o << "0xA3: AND E"; break ;
	case OpCodes::AND_H:
		o << "0xA4: AND H"; break ;
	case OpCodes::AND_L:
		o << "0xA5: AND L"; break ;
	case OpCodes::AND_DREF_HL:
		o << "0xA6: AND (HL)"; break ;
	case OpCodes::AND_A:
		o << "0xA7: AND A"; break ;
	case OpCodes::XOR_B:
		o << "0xA8: XOR B"; break ;
	case OpCodes::XOR_C:
		o << "0xA9: XOR C"; break ;
	case OpCodes::XOR_D:
		o << "0xAA: XOR D"; break ;
	case OpCodes::XOR_E:
		o << "0xAB: XOR E"; break ;
	case OpCodes::XOR_H:
		o << "0xAC: XOR H"; break ;
	case OpCodes::XOR_L:
		o << "0xAD: XOR L"; break ;
	case OpCodes::XOR_DREF_HL:
		o << "0xAE: XOR (HL)"; break ;
	case OpCodes::XOR_A:
		o << "0xAF: XOR A"; break ;
	case OpCodes::OR_B:
		o << "0xB0: OR B"; break ;
	case OpCodes::OR_C:
		o << "0xB1: OR C"; break ;
	case OpCodes::OR_D:
		o << "0xB2: OR D"; break ;
	case OpCodes::OR_E:
		o << "0xB3: OR E"; break ;
	case OpCodes::OR_H:
		o << "0xB4: OR H"; break ;
	case OpCodes::OR_L:
		o << "0xB5: OR L"; break ;
	case OpCodes::OR_DREF_HL:
		o << "0xB6: OR (HL)"; break ;
	case OpCodes::OR_A:
		o << "0xB7: OR A"; break ;
	case OpCodes::CP_B:
		o << "0xB8: CP B"; break ;
	case OpCodes::CP_C:
		o << "0xB9: CP C"; break ;
	case OpCodes::CP_D:
		o << "0xBA: CP D"; break ;
	case OpCodes::CP_E:
		o << "0xBB: CP E"; break ;
	case OpCodes::CP_H:
		o << "0xBC: CP H"; break ;
	case OpCodes::CP_L:
		o << "0xBD: CP L"; break ;
	case OpCodes::CP_DREF_HL:
		o << "0xBE: CP (HL)"; break ;
	case OpCodes::CP_A:
		o << "0xBF: CP A"; break ;
	case OpCodes::RET_NZ:
		o << "0xC0: RET NZ"; break ;
	case OpCodes::POP_BC:
		o << "0xC1: POP BC"; break ;
	case OpCodes::JP_NZ_a16:
		o << "0xC2: JP NZ, a16"; break ;
	case OpCodes::JP_a16:
		o << "0xC3: JP a16"; break ;
	case OpCodes::CALL_NZ_a16:
		o << "0xC4: CALL NZ, a16"; break ;
	case OpCodes::PUSH_BC:
		o << "0xC5: PUSH BC"; break ;
	case OpCodes::ADD_A_d8:
		o << "0xC6: ADD A, d8"; break ;
	case OpCodes::RST_0:
		o << "0xC7: RST 0"; break ;
	case OpCodes::RET_Z:
		o << "0xC8: RET Z"; break ;
	case OpCodes::RET:
		o << "0xC9: RET"; break ;
	case OpCodes::JP_Z_a16:
		o << "0xCA: JP Z, a16"; break ;
	case OpCodes::EXTENDED:
		o << "0xCB: EXTENDED"; break ;
	case OpCodes::CALL_Z_a16:
		o << "0xCC: CALL Z, a16"; break ;
	case OpCodes::CALL_a16:
		o << "0xCD: CALL a16"; break ;
	case OpCodes::ADC_A_d8:
		o << "0xCE: ADC A, d8"; break ;
	case OpCodes::RST_1:
		o << "0xCF: RST 1"; break ;
	case OpCodes::RET_NC:
		o << "0xD0: RET NC"; break ;
	case OpCodes::POP_DE:
		o << "0xD1: POP DE"; break ;
	case OpCodes::JP_NC_a16:
		o << "0xD2: JP NC, a16"; break ;
	case OpCodes::CALL_NC_a16:
		o << "0xD4: CALL NC, a16"; break ;
	case OpCodes::PUSH_DE:
		o << "0xD5: PUSH DE"; break ;
	case OpCodes::SUB_d8:
		o << "0xD6: SUB d8"; break ;
	case OpCodes::RST_2:
		o << "0xD7: RST 2"; break ;
	case OpCodes::RET_C:
		o << "0xD8: RET C"; break ;
	case OpCodes::RETI:
		o << "0xD9: RETI"; break ;
	case OpCodes::JP_C_a16:
		o << "0xDA: JP C, a16"; break ;
	case OpCodes::CALL_C_a16:
		o << "0xDC: CALL C, a16"; break ;
	case OpCodes::SBC_A_d8:
		o << "0xDE: SBC A, d8"; break ;
	case OpCodes::RST_3:
		o << "0xDF: RST 3"; break ;
	case OpCodes::LD_DREF_a8_A:
		o << "0xE0: LD (a8), A"; break ;
	case OpCodes::POP_HL:
		o << "0xE1: POP HL"; break ;
	case OpCodes::LD_DREF_C_A:
		o << "0xE2: LD (C), A"; break ;
	case OpCodes::PUSH_HL:
		o << "0xE5: PUSH HL"; break ;
	case OpCodes::AND_d8:
		o << "0xE6: AND d8"; break ;
	case OpCodes::RST_4:
		o << "0xE7: RST 4"; break ;
	case OpCodes::ADD_SP_s8:
		o << "0xE8: ADD SP, s8"; break ;
	case OpCodes::JP_HL:
		o << "0xE9: JP HL"; break ;
	case OpCodes::LD_DREF_a16_A:
		o << "0xEA: LD (a16), A"; break ;
	case OpCodes::XOR_d8:
		o << "0xEE: XOR d8"; break ;
	case OpCodes::RST_5:
		o << "0xEF: RST 5"; break ;
	case OpCodes::LD_A_DREF_a8:
		o << "0xF0: LD A, (a8)"; break ;
	case OpCodes::POP_AF:
		o << "0xF1: POP AF"; break ;
	case OpCodes::LD_A_DREF_C:
		o << "0xF2: LD A, (C)"; break ;
	case OpCodes::DI:
		o << "0xF3: DI"; break ;
	case OpCodes::PUSH_AF:
		o << "0xF5: PUSH AF"; break ;
	case OpCodes::OR_d8:
		o << "0xF6: OR d8"; break ;
	case OpCodes::RST_6:
		o << "0xF7: RST 6"; break ;
	case OpCodes::LD_HL_SP_PLUS_s8:
		o << "0xF8: LD HL, SP+s8"; break ;
	case OpCodes::LD_SP_HL:
		o << "0xF9: LD SP, HL"; break ;
	case OpCodes::LD_A_DREF_a16:
		o << "0xFA: LD A, (a16)"; break ;
	case OpCodes::EI:
		o << "0xFB: EI"; break ;
	case OpCodes::CP_d8:
		o << "0xFE: CP d8"; break ;
	case OpCodes::RST_7:
		o << "0xFF: RST 7"; break ;
	default:
		break;
	}
	return (o);
}
