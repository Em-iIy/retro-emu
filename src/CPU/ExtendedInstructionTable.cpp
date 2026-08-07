/*
Created by: Emily (Em_iIy) Winnink
Created on: 04/07/2026
*/

#include "CPU/CPU.hpp"

#define REG_A std::ref(CPU::AF.reg8b.hi)
#define REG_F std::ref(CPU::AF.reg8b.lo)
#define REG_B std::ref(CPU::BC.reg8b.hi)
#define REG_C std::ref(CPU::BC.reg8b.lo)
#define REG_D std::ref(CPU::DE.reg8b.hi)
#define REG_E std::ref(CPU::DE.reg8b.lo)
#define REG_H std::ref(CPU::HL.reg8b.hi)
#define REG_L std::ref(CPU::HL.reg8b.lo)

#define REG_AF std::ref(CPU::AF.reg16b)
#define REG_BC std::ref(CPU::BC.reg16b)
#define REG_DE std::ref(CPU::DE.reg16b)
#define REG_HL std::ref(CPU::HL.reg16b)
#define REG_SP std::ref(CPU::SP.reg16b)
#define REG_PC std::ref(CPU::PC.reg16b)


static void	setCallback(CPU::InstructionTable &table, OpCodesExt code, CPU::InstructionCallback cb)
{
	table.at(static_cast<uint8_t>(code)) = cb;
}

void		CPU::initExtendedInstructionTable()
{
	InstructionCallback	notImpl = std::bind(&CPU::notImplemented, this);
	extendedTable.fill(notImpl);

	setCallback(extendedTable, OpCodesExt::RLC_B, std::bind(&CPU::RLC_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::RLC_C, std::bind(&CPU::RLC_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::RLC_D, std::bind(&CPU::RLC_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::RLC_E, std::bind(&CPU::RLC_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::RLC_H, std::bind(&CPU::RLC_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::RLC_L, std::bind(&CPU::RLC_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::RLC_HL, std::bind(&CPU::RLC_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::RLC_A, std::bind(&CPU::RLC_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::RRC_B, std::bind(&CPU::RRC_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::RRC_C, std::bind(&CPU::RRC_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::RRC_D, std::bind(&CPU::RRC_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::RRC_E, std::bind(&CPU::RRC_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::RRC_H, std::bind(&CPU::RRC_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::RRC_L, std::bind(&CPU::RRC_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::RRC_HL, std::bind(&CPU::RRC_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::RRC_A, std::bind(&CPU::RRC_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::RL_B, std::bind(&CPU::RL_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::RL_C, std::bind(&CPU::RL_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::RL_D, std::bind(&CPU::RL_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::RL_E, std::bind(&CPU::RL_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::RL_H, std::bind(&CPU::RL_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::RL_L, std::bind(&CPU::RL_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::RL_HL, std::bind(&CPU::RL_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::RL_A, std::bind(&CPU::RL_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::RR_B, std::bind(&CPU::RR_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::RR_C, std::bind(&CPU::RR_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::RR_D, std::bind(&CPU::RR_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::RR_E, std::bind(&CPU::RR_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::RR_H, std::bind(&CPU::RR_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::RR_L, std::bind(&CPU::RR_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::RR_HL, std::bind(&CPU::RR_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::RR_A, std::bind(&CPU::RR_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::SLA_B, std::bind(&CPU::SLA_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::SLA_C, std::bind(&CPU::SLA_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::SLA_D, std::bind(&CPU::SLA_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::SLA_E, std::bind(&CPU::SLA_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::SLA_H, std::bind(&CPU::SLA_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::SLA_L, std::bind(&CPU::SLA_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::SLA_HL, std::bind(&CPU::SLA_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::SLA_A, std::bind(&CPU::SLA_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::SRA_B, std::bind(&CPU::SRA_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::SRA_C, std::bind(&CPU::SRA_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::SRA_D, std::bind(&CPU::SRA_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::SRA_E, std::bind(&CPU::SRA_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::SRA_H, std::bind(&CPU::SRA_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::SRA_L, std::bind(&CPU::SRA_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::SRA_HL, std::bind(&CPU::SRA_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::SRA_A, std::bind(&CPU::SRA_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::SWAP_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SWAP_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SRL_B, std::bind(&CPU::SRL_R8, this, REG_B));
	setCallback(extendedTable, OpCodesExt::SRL_C, std::bind(&CPU::SRL_R8, this, REG_C));
	setCallback(extendedTable, OpCodesExt::SRL_D, std::bind(&CPU::SRL_R8, this, REG_D));
	setCallback(extendedTable, OpCodesExt::SRL_E, std::bind(&CPU::SRL_R8, this, REG_E));
	setCallback(extendedTable, OpCodesExt::SRL_H, std::bind(&CPU::SRL_R8, this, REG_H));
	setCallback(extendedTable, OpCodesExt::SRL_L, std::bind(&CPU::SRL_R8, this, REG_L));
	setCallback(extendedTable, OpCodesExt::SRL_HL, std::bind(&CPU::SRL_PR16, this, REG_HL));
	setCallback(extendedTable, OpCodesExt::SRL_A, std::bind(&CPU::SRL_R8, this, REG_A));

	setCallback(extendedTable, OpCodesExt::BIT_0_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_0_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_1_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_1_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_2_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_2_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_3_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_3_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_4_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_4_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_5_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_5_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_6_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_6_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::BIT_7_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::BIT_7_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_0_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_0_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_1_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_1_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_2_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_2_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_3_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_3_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_4_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_4_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_5_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_5_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_6_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_6_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::RES_7_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::RES_7_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_0_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_0_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_1_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_1_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_2_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_2_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_3_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_3_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_4_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_4_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_5_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_5_A, std::bind(&CPU::notImplemented, this));

	setCallback(extendedTable, OpCodesExt::SET_6_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_6_A, std::bind(&CPU::notImplemented, this));
	
	setCallback(extendedTable, OpCodesExt::SET_7_B, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_C, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_D, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_E, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_H, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_L, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_HL, std::bind(&CPU::notImplemented, this));
	setCallback(extendedTable, OpCodesExt::SET_7_A, std::bind(&CPU::notImplemented, this));
}
