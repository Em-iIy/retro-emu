/*
Created by: Emily (Em_iIy) Winnink
Created on: 09/04/2026
*/

#pragma once

#include "Register.hpp"
#include "enums/RegisterName.hpp"
#include "Instruction.hpp"
#include "MemoryBus.hpp"

#include <functional>
#include <array>

constexpr bool	checkCarry(uint16_t a, uint16_t b, uint8_t bit)
{
	return (((a & b) | ((a | b) & ~(a + b))) & (1 << bit));
}

constexpr bool	checkBorrow(uint16_t a, uint16_t b, uint8_t bit)
{
	return (((~a & b) | ((a ^ b) & ~(a - b))) & (1 << bit));
}


class CPU {
	public:
		enum class	Flag {
			Z = 7,
			N = 6,
			H = 5,
			C = 4
		};

		using	InstructionCallback = std::function<uint8_t()>;
		using	InstructionTable = std::array<InstructionCallback, 0x100>;

		CPU(MemoryBus &bus);
		~CPU();

		bool		cycle();

		void		setIME(bool val);

	private:
		MemoryBus	&_bus;

		/*
			Hi: A
			Lo: -
			Accumulator & Flags
		*/
		Register	AF;

		/*
			Hi: B
			Lo: C
		*/
		Register	BC;

		/*
			Hi: D
			Lo: E
		*/
		Register	DE;

		/*
			Hi: H
			Lo: L
		*/
		Register	HL;

		/*
			Stack Pointer
		*/
		Register	SP;

		/*
			Program Counter/Pointer
		*/
		Register	PC;

		/*
			Interrupt Master Enable flag
		*/
		bool		IME;

		InstructionTable table;
		InstructionTable extendedTable;

		std::vector<uint16_t>	currentInstructionData;

		void		initInstructionTable();
		void		initExtendedInstructionTable();

		void		flushRegisters();

		uint8_t		&get8BitRegister(RegisterName name);
		uint16_t	&get16BitRegister(RegisterName name);

		uint8_t		fetchByte();
		uint8_t		fetchImmediateByte();
		uint16_t	fetchImmediate2Bytes();

		Instruction	getInstruction();
		uint8_t		executeInstruction(Instruction &instruction);
		void		logInstructionData();

		void		setFlag(Flag flag, bool value);
		void		setFlag(Flag flag);
		void		unsetFlag(Flag flag);
		bool		checkFlag(Flag flag);

		uint8_t		notImplemented();

		/*	Core instructions	*/

		/*
			Misc / control instructions
		*/
		uint8_t		NOP();
		uint8_t		DI();
		uint8_t		EI();



		/*
			Definitions:
				- R8	= 8bit register
				- R16	= 16bit register
				- IM8	= 8 bits of immediate data
				- IM16	= 16 bits of immediate data
				- PR8	= Data at address pointed to by 8bit register
				- PR16	= Data at address pointed to by 16bit register
				- PIM8	= Data at address pointed to by 8bits of immediate data
				- PIM16	= Data at address pointed to by 16bit of immediate data
		*/

		
		/*	LOAD	*/
			/*	LOAD to 8 bit register	*/
		uint8_t		LOAD_R8_R8(uint8_t &dst, uint8_t &src); // ex: LD A, B
		uint8_t		LOAD_R8_IM8(uint8_t &dst); // ex: LD B, d8

			/*	LOAD to 16 bit register	*/
		uint8_t		LOAD_R16_R16(uint16_t &dst, uint16_t &src); // ex: LD SP, HL
		uint8_t		LOAD_R16_IM16(uint16_t &dst); // ex: LD BC, d16

			/*	LOAD from/to memory pointed to by 16 bit register	*/
		uint8_t		LOAD_PR16_R8(uint16_t &pDst, uint8_t &src); // ex: LD (BC), A
		uint8_t		LOAD_PR16_IM8(uint16_t &pDst); // ex: LD (HL), d8
		uint8_t		LOAD_R8_PR16(uint8_t &dst, uint16_t &pSrc); // ex: LD A, (BC)

			/*	LOAD from/to RAM or Register pointed to by 8 bit address	*/
		uint8_t		LOAD_PIM8_R8(uint8_t &src); // ex: LD (a8), A
		uint8_t		LOAD_PR8_R8(uint8_t &pDst, uint8_t &src); // ex: LD (C), A
		uint8_t		LOAD_R8_PIM8(uint8_t &dst); // ex: LD A, (a8)
		uint8_t		LOAD_R8_PR8(uint8_t &dst, uint8_t &pSrc); // ex: LD A, (C)

			/*	LOAD from/to RAM or Register pointed to by 16 bit address	*/
		uint8_t		LOAD_PIM16_R8(uint8_t &src); // ex: LD (a16), A
		uint8_t		LOAD_PIM16_R16(uint16_t &src); // ex: LD (a16), SP
		uint8_t		LOAD_R8_PIM16(uint8_t &dst); // ex: LD A, (a16)

			/*	LOAD + INC or DEC HL	*/
		uint8_t		LOAD_PHLI_R8(uint8_t &src); // ex: LD (HL+), A
		uint8_t		LOAD_R8_PHLI(uint8_t &dst); // ex: LD A, (HL+)
		uint8_t		LOAD_PHLD_R8(uint8_t &src); // ex: LD (HL-), A
		uint8_t		LOAD_R8_PHLD(uint8_t &dst); // ex: LD A, (HL-)

		/*	JUMP	*/
		uint8_t		JUMP_IM16(); // ex: JP a16
		uint8_t		JUMP_R16(uint16_t &reg); // ex: JP HL
			/*	JUMP RELATIVE	*/
		uint8_t		JUMP_RELATIVE_IM8(); // ex: JR s8
		uint8_t		JUMP_RELATIVE_FLAG_IM8(Flag flag); // ex: JR Z, s8
		uint8_t		JUMP_RELATIVE_NFLAG_IM8(Flag flag); // ex: JR NZ, s8

		/*	INC		*/
		uint8_t		INC_R8(uint8_t &reg); // ex: INC B
		uint8_t		INC_R16(uint16_t &reg); // ex: INC BC
		uint8_t		INC_PR16(uint16_t &pDst); // ex: INC (HL)

		/*	DEC		*/
		uint8_t		DEC_R8(uint8_t &reg); // ex: DEC B
		uint8_t		DEC_R16(uint16_t &reg); // ex: DEC BC
		uint8_t		DEC_PR16(uint16_t &pDst); // ex: INC (HL)

		/*	ADD		*/
		uint8_t		ADD_R8_R8(uint8_t &ra, uint8_t &rb);
		uint8_t		ADD_R8_IM8(uint8_t &ra);
		uint8_t		ADD_R8_PR16(uint8_t &ra, uint16_t &pRb);
		
		uint8_t		ADD_R16_R16(uint16_t &ra, uint16_t &rb);

		/*	ADD CARRY	*/
		uint8_t		ADDC_A_R8(uint8_t &rb);
		uint8_t		ADDC_A_IM8();
		uint8_t		ADDC_A_PR16(uint16_t &pRb);

		/*	SUB		*/
		uint8_t		SUB_A_R8(uint8_t &rb);
		uint8_t		SUB_A_IM8();
		uint8_t		SUB_A_PR16(uint16_t &pRb);

		/*	SUB CARRY	*/
		uint8_t		SUBC_A_R8(uint8_t &rb);
		uint8_t		SUBC_A_IM8();
		uint8_t		SUBC_A_PR16(uint16_t &pRb);

		/*	AND		*/
		uint8_t		AND_A_R8(uint8_t &rb); // ex: AND B
		uint8_t		AND_A_IM8(); // ex: AND d8
		uint8_t		AND_A_PR16(uint16_t &pRb); // ex: AND (HL)
		
		/*	XOR		*/
		uint8_t		XOR_A_R8(uint8_t &rb); // ex: XOR B
		uint8_t		XOR_A_IM8(); // ex: XOR d8
		uint8_t		XOR_A_PR16(uint16_t &pRb); // ex: XOR (HL)

		/*	OR		*/
		uint8_t		OR_A_R8(uint8_t &rb); // ex: OR B
		uint8_t		OR_A_IM8(); // ex: OR d8
		uint8_t		OR_A_PR16(uint16_t &pRb); // ex: OR (HL)

		/*	COMPARE	*/
		uint8_t		COMPARE_A_R8(uint8_t &rb); // ex: CP B
		uint8_t		COMPARE_A_IM8(); // ex: CP d8
		uint8_t		COMPARE_A_PR16(uint16_t &pRb); // ex: CP (HL)

		/*	POP	*/
		uint8_t		POP_R16(uint16_t &reg); // ex: POP BC

		/*	PUSH	*/
		uint8_t		PUSH_R16(uint16_t &reg); // ex: PUSH BC

		/*	RET	*/
		uint8_t		RET(); // ex: RET
		uint8_t		RETI(); // ex: RETI
		uint8_t		RET_FLAG(Flag flag); // ex: RET Z
		uint8_t		RET_NFLAG(Flag flag); // ex: RET NZ

		/*	CALL	*/
		uint8_t		CALL_IM16(); // ex: CALL a16
		uint8_t		CALL_FLAG_IM16(Flag flag); // ex: CALL Z, a16
		uint8_t		CALL_NFLAG_IM16(Flag flag); // ex: CALL NZ, a16

		/*	ROTATE	*/
		uint8_t		RLC_R8(uint8_t &rb); // ex: RLC B
		uint8_t		RLC_PR16(uint16_t &pRb); // ex: RLC (HL)
		uint8_t		RL_R8(uint8_t &rb); // ex: RL B
		uint8_t		RL_PR16(uint16_t &pRb); // ex: RL (HL)

		uint8_t		RRC_R8(uint8_t &rb); // ex: RRC B
		uint8_t		RRC_PR16(uint16_t &pRb); // ex: RRC (HL)
		uint8_t		RR_R8(uint8_t &rb); // ex: RR B
		uint8_t		RR_PR16(uint16_t &pRb); // ex: RR (HL)

		/*	MISC	*/
		uint8_t		CPL(); // ex: CPL
};
