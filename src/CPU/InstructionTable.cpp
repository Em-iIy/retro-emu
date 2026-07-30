/*
Created by: Emily (Em_iIy) Winnink
Created on: 01/06/2026
*/

#include "CPU/CPU.hpp"

#define REG_A CPU::AF.reg8b.hi
#define REG_F CPU::AF.reg8b.lo
#define REG_B CPU::BC.reg8b.hi
#define REG_C CPU::BC.reg8b.lo
#define REG_D CPU::DE.reg8b.hi
#define REG_E CPU::DE.reg8b.lo
#define REG_H CPU::HL.reg8b.hi
#define REG_L CPU::HL.reg8b.lo

#define REG_AF CPU::AF.reg16b
#define REG_BC CPU::BC.reg16b
#define REG_DE CPU::DE.reg16b
#define REG_HL CPU::HL.reg16b
#define REG_SP CPU::SP.reg16b
#define REG_PC CPU::PC.reg16b

static void	setCallback(CPU::InstructionTable &table, OpCodes code, CPU::InstructionCallback cb)
{
	table.at(static_cast<uint8_t>(code)) = cb;
}

void		CPU::initInstructionTable()
{
	InstructionCallback	notImpl = std::bind(&CPU::notImplemented, this);
	table.fill(notImpl);

	setCallback(table, OpCodes::NOP, std::bind(&CPU::NOP, this));
	setCallback(table, OpCodes::LD_BC_d16, std::bind(&CPU::LOAD_R16_IM16, this, REG_BC));
	setCallback(table, OpCodes::LD_DREF_BC_A, std::bind(&CPU::LOAD_PR16_R8, this, REG_BC, REG_A));
	setCallback(table, OpCodes::INC_BC, std::bind(&CPU::INC_R16, this, REG_BC));
	setCallback(table, OpCodes::INC_B, std::bind(&CPU::INC_R8, this, REG_B));
	setCallback(table, OpCodes::DEC_B, std::bind(&CPU::DEC_R8, this, REG_B));
	setCallback(table, OpCodes::LD_B_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_B));
	setCallback(table, OpCodes::RLCA, std::bind(&CPU::RLCA, this));
	setCallback(table, OpCodes::LD_DREF_a16_SP, std::bind(&CPU::LOAD_PIM16_R16, this, REG_SP));
	setCallback(table, OpCodes::ADD_HL_BC, std::bind(&CPU::ADD_R16_R16, this, REG_HL, REG_BC));
	setCallback(table, OpCodes::LD_A_DREF_BC, std::bind(&CPU::LOAD_R8_PR16, this, REG_A, REG_BC));
	setCallback(table, OpCodes::DEC_BC, std::bind(&CPU::DEC_R16, this, REG_BC));
	setCallback(table, OpCodes::INC_C, std::bind(&CPU::INC_R8, this, REG_C));
	setCallback(table, OpCodes::DEC_C, std::bind(&CPU::DEC_R8, this, REG_C));
	setCallback(table, OpCodes::LD_C_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_C));
	setCallback(table, OpCodes::RRCA, std::bind(&CPU::RRCA, this));

	// setCallback(table, OpCodes::STOP, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::LD_DE_d16, std::bind(&CPU::LOAD_R16_IM16, this, REG_DE));
	setCallback(table, OpCodes::LD_DREF_DE_A, std::bind(&CPU::LOAD_PR16_R8, this, REG_DE, REG_A));
	setCallback(table, OpCodes::INC_DE, std::bind(&CPU::INC_R16, this, REG_DE));
	setCallback(table, OpCodes::INC_D, std::bind(&CPU::INC_R8, this, REG_D));
	setCallback(table, OpCodes::DEC_D, std::bind(&CPU::DEC_R8, this, REG_D));
	setCallback(table, OpCodes::LD_D_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_D));
	setCallback(table, OpCodes::RLA, std::bind(&CPU::RLA, this));
	setCallback(table, OpCodes::JR_s8, std::bind(&CPU::JUMP_RELATIVE_IM8, this));
	setCallback(table, OpCodes::ADD_HL_DE, std::bind(&CPU::ADD_R16_R16, this, REG_HL, REG_DE));
	setCallback(table, OpCodes::LD_A_DREF_DE, std::bind(&CPU::LOAD_R8_PR16, this, REG_A, REG_DE));
	setCallback(table, OpCodes::DEC_DE, std::bind(&CPU::DEC_R16, this, REG_DE));
	setCallback(table, OpCodes::INC_E, std::bind(&CPU::INC_R8, this, REG_E));
	setCallback(table, OpCodes::DEC_E, std::bind(&CPU::DEC_R8, this, REG_E));
	setCallback(table, OpCodes::LD_E_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_E));
	setCallback(table, OpCodes::RRA, std::bind(&CPU::RRA, this));

	setCallback(table, OpCodes::JR_NZ_s8, std::bind(&CPU::JUMP_RELATIVE_NFLAG_IM8, this, Flag::Z));
	setCallback(table, OpCodes::LD_HL_d16, std::bind(&CPU::LOAD_R16_IM16, this, REG_HL));
	setCallback(table, OpCodes::LD_DREF_HLI_A, std::bind(&CPU::LOAD_PHLI_R8, this, REG_A));
	setCallback(table, OpCodes::INC_HL, std::bind(&CPU::INC_R16, this, REG_HL));
	setCallback(table, OpCodes::INC_H, std::bind(&CPU::INC_R8, this, REG_H));
	setCallback(table, OpCodes::DEC_H, std::bind(&CPU::DEC_R8, this, REG_H));
	setCallback(table, OpCodes::LD_H_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_H));
	// setCallback(table, OpCodes::DAA, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::JR_Z_s8, std::bind(&CPU::JUMP_RELATIVE_FLAG_IM8, this, Flag::Z));
	setCallback(table, OpCodes::ADD_HL_HL, std::bind(&CPU::ADD_R16_R16, this, REG_HL, REG_HL));
	setCallback(table, OpCodes::LD_A_DREF_HLI, std::bind(&CPU::LOAD_R8_PHLI, this, REG_A));
	setCallback(table, OpCodes::DEC_HL, std::bind(&CPU::DEC_R16, this, REG_HL));
	setCallback(table, OpCodes::INC_L, std::bind(&CPU::INC_R8, this, REG_L));
	setCallback(table, OpCodes::DEC_L, std::bind(&CPU::DEC_R8, this, REG_L));
	setCallback(table, OpCodes::LD_L_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_L));
	setCallback(table, OpCodes::CPL, std::bind(&CPU::CPL, this));

	setCallback(table, OpCodes::JR_NC_s8, std::bind(&CPU::JUMP_RELATIVE_NFLAG_IM8, this, Flag::C));
	setCallback(table, OpCodes::LD_SP_d16, std::bind(&CPU::LOAD_R16_IM16, this, REG_SP));
	setCallback(table, OpCodes::LD_DREF_HLD_A, std::bind(&CPU::LOAD_PHLD_R8, this, REG_A));
	setCallback(table, OpCodes::INC_SP, std::bind(&CPU::INC_R16, this, REG_SP));
	setCallback(table, OpCodes::INC_DREF_HL, std::bind(&CPU::INC_PR16, this, REG_HL));
	setCallback(table, OpCodes::DEC_DREF_HL, std::bind(&CPU::DEC_PR16, this, REG_HL));
	setCallback(table, OpCodes::LD_DREF_HL_d8, std::bind(&CPU::LOAD_PR16_IM8, this, REG_HL));
	// setCallback(table, OpCodes::SCF, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::JR_C_s8, std::bind(&CPU::JUMP_RELATIVE_FLAG_IM8, this, Flag::C));
	setCallback(table, OpCodes::ADD_HL_SP, std::bind(&CPU::ADD_R16_R16, this, REG_HL, REG_SP));
	setCallback(table, OpCodes::LD_A_DREF_HLD, std::bind(&CPU::LOAD_R8_PHLD, this, REG_A));
	setCallback(table, OpCodes::DEC_SP, std::bind(&CPU::DEC_R16, this, REG_SP));
	setCallback(table, OpCodes::INC_A, std::bind(&CPU::INC_R8, this, REG_A));
	setCallback(table, OpCodes::DEC_A, std::bind(&CPU::DEC_R8, this, REG_A));
	setCallback(table, OpCodes::LD_A_d8, std::bind(&CPU::LOAD_R8_IM8, this, REG_A));
	// setCallback(table, OpCodes::CCF, std::bind(&CPU::notImplemented, this));

	setCallback(table, OpCodes::LD_B_B, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_B));
	setCallback(table, OpCodes::LD_B_C, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_C));
	setCallback(table, OpCodes::LD_B_D, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_D));
	setCallback(table, OpCodes::LD_B_E, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_E));
	setCallback(table, OpCodes::LD_B_H, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_H));
	setCallback(table, OpCodes::LD_B_L, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_L));
	setCallback(table, OpCodes::LD_B_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_C, REG_HL));
	setCallback(table, OpCodes::LD_B_A, std::bind(&CPU::LOAD_R8_R8, this, REG_B, REG_A));

	setCallback(table, OpCodes::LD_C_B, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_B));
	setCallback(table, OpCodes::LD_C_C, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_C));
	setCallback(table, OpCodes::LD_C_D, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_D));
	setCallback(table, OpCodes::LD_C_E, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_E));
	setCallback(table, OpCodes::LD_C_H, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_H));
	setCallback(table, OpCodes::LD_C_L, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_L));
	setCallback(table, OpCodes::LD_C_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_C, REG_HL));
	setCallback(table, OpCodes::LD_C_A, std::bind(&CPU::LOAD_R8_R8, this, REG_C, REG_A));

	setCallback(table, OpCodes::LD_D_B, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_B));
	setCallback(table, OpCodes::LD_D_C, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_C));
	setCallback(table, OpCodes::LD_D_D, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_D));
	setCallback(table, OpCodes::LD_D_E, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_E));
	setCallback(table, OpCodes::LD_D_H, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_H));
	setCallback(table, OpCodes::LD_D_L, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_L));
	setCallback(table, OpCodes::LD_D_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_D, REG_HL));
	setCallback(table, OpCodes::LD_D_A, std::bind(&CPU::LOAD_R8_R8, this, REG_D, REG_A));

	setCallback(table, OpCodes::LD_E_B, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_B));
	setCallback(table, OpCodes::LD_E_C, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_C));
	setCallback(table, OpCodes::LD_E_D, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_D));
	setCallback(table, OpCodes::LD_E_E, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_E));
	setCallback(table, OpCodes::LD_E_H, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_H));
	setCallback(table, OpCodes::LD_E_L, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_L));
	setCallback(table, OpCodes::LD_E_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_E, REG_HL));
	setCallback(table, OpCodes::LD_E_A, std::bind(&CPU::LOAD_R8_R8, this, REG_E, REG_A));

	setCallback(table, OpCodes::LD_H_B, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_B));
	setCallback(table, OpCodes::LD_H_C, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_C));
	setCallback(table, OpCodes::LD_H_D, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_D));
	setCallback(table, OpCodes::LD_H_E, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_E));
	setCallback(table, OpCodes::LD_H_H, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_H));
	setCallback(table, OpCodes::LD_H_L, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_L));
	setCallback(table, OpCodes::LD_H_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_H, REG_HL));
	setCallback(table, OpCodes::LD_H_A, std::bind(&CPU::LOAD_R8_R8, this, REG_H, REG_A));

	setCallback(table, OpCodes::LD_L_B, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_B));
	setCallback(table, OpCodes::LD_L_C, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_C));
	setCallback(table, OpCodes::LD_L_D, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_D));
	setCallback(table, OpCodes::LD_L_E, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_E));
	setCallback(table, OpCodes::LD_L_H, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_H));
	setCallback(table, OpCodes::LD_L_L, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_L));
	setCallback(table, OpCodes::LD_L_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_L, REG_HL));
	setCallback(table, OpCodes::LD_L_A, std::bind(&CPU::LOAD_R8_R8, this, REG_L, REG_A));

	setCallback(table, OpCodes::LD_DREF_HL_B, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_B));
	setCallback(table, OpCodes::LD_DREF_HL_C, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_C));
	setCallback(table, OpCodes::LD_DREF_HL_D, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_D));
	setCallback(table, OpCodes::LD_DREF_HL_E, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_E));
	setCallback(table, OpCodes::LD_DREF_HL_H, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_H));
	setCallback(table, OpCodes::LD_DREF_HL_L, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_L));

	// setCallback(table, OpCodes::HALT, std::bind(&CPU::notImplemented, this));

	setCallback(table, OpCodes::LD_DREF_HL_A, std::bind(&CPU::LOAD_PR16_R8, this, REG_HL, REG_A));

	setCallback(table, OpCodes::LD_A_B, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_B));
	setCallback(table, OpCodes::LD_A_C, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_C));
	setCallback(table, OpCodes::LD_A_D, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_D));
	setCallback(table, OpCodes::LD_A_E, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_E));
	setCallback(table, OpCodes::LD_A_H, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_H));
	setCallback(table, OpCodes::LD_A_L, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_L));
	setCallback(table, OpCodes::LD_A_DREF_HL, std::bind(&CPU::LOAD_R8_PR16, this, REG_A, REG_HL));
	setCallback(table, OpCodes::LD_A_A, std::bind(&CPU::LOAD_R8_R8, this, REG_A, REG_A));

	setCallback(table, OpCodes::ADD_A_B, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_B));
	setCallback(table, OpCodes::ADD_A_C, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_C));
	setCallback(table, OpCodes::ADD_A_D, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_D));
	setCallback(table, OpCodes::ADD_A_E, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_E));
	setCallback(table, OpCodes::ADD_A_H, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_H));
	setCallback(table, OpCodes::ADD_A_L, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_L));
	setCallback(table, OpCodes::ADD_A_DREF_HL, std::bind(&CPU::ADD_R8_PR16, this, REG_A, REG_HL));
	setCallback(table, OpCodes::ADD_A_A, std::bind(&CPU::ADD_R8_R8, this, REG_A, REG_A));

	setCallback(table, OpCodes::ADC_A_B, std::bind(&CPU::ADDC_A_R8, this, REG_B));
	setCallback(table, OpCodes::ADC_A_C, std::bind(&CPU::ADDC_A_R8, this, REG_C));
	setCallback(table, OpCodes::ADC_A_D, std::bind(&CPU::ADDC_A_R8, this, REG_D));
	setCallback(table, OpCodes::ADC_A_E, std::bind(&CPU::ADDC_A_R8, this, REG_E));
	setCallback(table, OpCodes::ADC_A_H, std::bind(&CPU::ADDC_A_R8, this, REG_H));
	setCallback(table, OpCodes::ADC_A_L, std::bind(&CPU::ADDC_A_R8, this, REG_L));
	setCallback(table, OpCodes::ADC_A_DREF_HL, std::bind(&CPU::ADDC_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::ADC_A_A, std::bind(&CPU::ADDC_A_R8, this, REG_A));

	setCallback(table, OpCodes::SUB_B, std::bind(&CPU::SUB_A_R8, this, REG_B));
	setCallback(table, OpCodes::SUB_C, std::bind(&CPU::SUB_A_R8, this, REG_C));
	setCallback(table, OpCodes::SUB_D, std::bind(&CPU::SUB_A_R8, this, REG_D));
	setCallback(table, OpCodes::SUB_E, std::bind(&CPU::SUB_A_R8, this, REG_E));
	setCallback(table, OpCodes::SUB_H, std::bind(&CPU::SUB_A_R8, this, REG_H));
	setCallback(table, OpCodes::SUB_L, std::bind(&CPU::SUB_A_R8, this, REG_L));
	setCallback(table, OpCodes::SUB_DREF_HL, std::bind(&CPU::SUB_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::SUB_A, std::bind(&CPU::SUB_A_R8, this, REG_A));

	setCallback(table, OpCodes::SBC_A_B, std::bind(&CPU::SUBC_A_R8, this, REG_B));
	setCallback(table, OpCodes::SBC_A_C, std::bind(&CPU::SUBC_A_R8, this, REG_C));
	setCallback(table, OpCodes::SBC_A_D, std::bind(&CPU::SUBC_A_R8, this, REG_D));
	setCallback(table, OpCodes::SBC_A_E, std::bind(&CPU::SUBC_A_R8, this, REG_E));
	setCallback(table, OpCodes::SBC_A_H, std::bind(&CPU::SUBC_A_R8, this, REG_H));
	setCallback(table, OpCodes::SBC_A_L, std::bind(&CPU::SUBC_A_R8, this, REG_L));
	setCallback(table, OpCodes::SBC_A_DREF_HL, std::bind(&CPU::SUBC_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::SBC_A_A, std::bind(&CPU::SUBC_A_R8, this, REG_A));

	setCallback(table, OpCodes::AND_B, std::bind(&CPU::AND_A_R8, this, REG_B));
	setCallback(table, OpCodes::AND_C, std::bind(&CPU::AND_A_R8, this, REG_C));
	setCallback(table, OpCodes::AND_D, std::bind(&CPU::AND_A_R8, this, REG_D));
	setCallback(table, OpCodes::AND_E, std::bind(&CPU::AND_A_R8, this, REG_E));
	setCallback(table, OpCodes::AND_H, std::bind(&CPU::AND_A_R8, this, REG_H));
	setCallback(table, OpCodes::AND_L, std::bind(&CPU::AND_A_R8, this, REG_L));
	setCallback(table, OpCodes::AND_DREF_HL, std::bind(&CPU::AND_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::AND_A, std::bind(&CPU::AND_A_R8, this, REG_A));

	setCallback(table, OpCodes::XOR_B, std::bind(&CPU::XOR_A_R8, this, REG_B));
	setCallback(table, OpCodes::XOR_C, std::bind(&CPU::XOR_A_R8, this, REG_C));
	setCallback(table, OpCodes::XOR_D, std::bind(&CPU::XOR_A_R8, this, REG_D));
	setCallback(table, OpCodes::XOR_E, std::bind(&CPU::XOR_A_R8, this, REG_E));
	setCallback(table, OpCodes::XOR_H, std::bind(&CPU::XOR_A_R8, this, REG_H));
	setCallback(table, OpCodes::XOR_L, std::bind(&CPU::XOR_A_R8, this, REG_L));
	setCallback(table, OpCodes::XOR_DREF_HL, std::bind(&CPU::XOR_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::XOR_A, std::bind(&CPU::XOR_A_R8, this, REG_A));

	setCallback(table, OpCodes::OR_B, std::bind(&CPU::OR_A_R8, this, REG_B));
	setCallback(table, OpCodes::OR_C, std::bind(&CPU::OR_A_R8, this, REG_C));
	setCallback(table, OpCodes::OR_D, std::bind(&CPU::OR_A_R8, this, REG_D));
	setCallback(table, OpCodes::OR_E, std::bind(&CPU::OR_A_R8, this, REG_E));
	setCallback(table, OpCodes::OR_H, std::bind(&CPU::OR_A_R8, this, REG_H));
	setCallback(table, OpCodes::OR_L, std::bind(&CPU::OR_A_R8, this, REG_L));
	setCallback(table, OpCodes::OR_DREF_HL, std::bind(&CPU::OR_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::OR_A, std::bind(&CPU::OR_A_R8, this, REG_A));

	setCallback(table, OpCodes::CP_B, std::bind(&CPU::COMPARE_A_R8, this, REG_B));
	setCallback(table, OpCodes::CP_C, std::bind(&CPU::COMPARE_A_R8, this, REG_C));
	setCallback(table, OpCodes::CP_D, std::bind(&CPU::COMPARE_A_R8, this, REG_D));
	setCallback(table, OpCodes::CP_E, std::bind(&CPU::COMPARE_A_R8, this, REG_E));
	setCallback(table, OpCodes::CP_H, std::bind(&CPU::COMPARE_A_R8, this, REG_H));
	setCallback(table, OpCodes::CP_L, std::bind(&CPU::COMPARE_A_R8, this, REG_L));
	setCallback(table, OpCodes::CP_DREF_HL, std::bind(&CPU::COMPARE_A_PR16, this, REG_HL));
	setCallback(table, OpCodes::CP_A, std::bind(&CPU::COMPARE_A_R8, this, REG_A));

	setCallback(table, OpCodes::RET_NZ, std::bind(&CPU::RET_NFLAG, this, Flag::Z));
	setCallback(table, OpCodes::POP_BC, std::bind(&CPU::POP_R16, this, REG_BC));
	setCallback(table, OpCodes::JP_NZ_a16, std::bind(&CPU::JUMP_RELATIVE_NFLAG_IM8, this, Flag::Z));
	setCallback(table, OpCodes::JP_a16, std::bind(&CPU::JUMP_IM16, this));
	setCallback(table, OpCodes::CALL_NZ_a16, std::bind(&CPU::CALL_NFLAG_IM16, this, Flag::Z));
	setCallback(table, OpCodes::PUSH_BC, std::bind(&CPU::PUSH_R16, this, REG_BC));
	setCallback(table, OpCodes::ADD_A_d8, std::bind(&CPU::ADD_R8_IM8, this, REG_A));
	// setCallback(table, OpCodes::RST_0, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::RET_Z, std::bind(&CPU::RET_FLAG, this, Flag::Z));
	setCallback(table, OpCodes::RET, std::bind(&CPU::RET, this));
	setCallback(table, OpCodes::JP_Z_a16, std::bind(&CPU::JUMP_RELATIVE_FLAG_IM8, this, Flag::Z));
	// setCallback(table, OpCodes::EXTENDED, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::CALL_Z_a16, std::bind(&CPU::CALL_FLAG_IM16, this, Flag::Z));
	setCallback(table, OpCodes::CALL_a16, std::bind(&CPU::CALL_IM16, this));
	setCallback(table, OpCodes::ADC_A_d8, std::bind(&CPU::ADDC_A_IM8, this));
	// setCallback(table, OpCodes::RST_1, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::RET_NC, std::bind(&CPU::RET_NFLAG, this, Flag::C));
	setCallback(table, OpCodes::POP_DE, std::bind(&CPU::POP_R16, this, REG_DE));
	setCallback(table, OpCodes::JP_NC_a16, std::bind(&CPU::JUMP_RELATIVE_NFLAG_IM8, this, Flag::C));
	setCallback(table, OpCodes::CALL_NC_a16, std::bind(&CPU::CALL_NFLAG_IM16, this, Flag::C));
	setCallback(table, OpCodes::PUSH_DE, std::bind(&CPU::PUSH_R16, this, REG_DE));
	setCallback(table, OpCodes::SUB_d8, std::bind(&CPU::SUB_A_IM8, this));
	// setCallback(table, OpCodes::RST_2, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::RET_C, std::bind(&CPU::RET_FLAG, this, Flag::C));
	setCallback(table, OpCodes::RETI, std::bind(&CPU::RETI, this));
	setCallback(table, OpCodes::JP_C_a16, std::bind(&CPU::JUMP_RELATIVE_FLAG_IM8, this, Flag::C));
	setCallback(table, OpCodes::CALL_C_a16, std::bind(&CPU::CALL_FLAG_IM16, this, Flag::C));
	setCallback(table, OpCodes::SBC_A_d8, std::bind(&CPU::SUBC_A_IM8, this));
	// setCallback(table, OpCodes::RST_3, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::LD_DREF_a8_A, std::bind(&CPU::LOAD_PIM8_R8, this, REG_A));
	setCallback(table, OpCodes::POP_HL, std::bind(&CPU::POP_R16, this, REG_HL));
	// setCallback(table, OpCodes::LD_DREF_C_A, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::PUSH_HL, std::bind(&CPU::PUSH_R16, this, REG_HL));
	setCallback(table, OpCodes::AND_d8, std::bind(&CPU::AND_A_IM8, this));
	// setCallback(table, OpCodes::RST_4, std::bind(&CPU::notImplemented, this));
	// setCallback(table, OpCodes::ADD_SP_s8, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::JP_HL, std::bind(&CPU::JUMP_R16, this, REG_HL));
	setCallback(table, OpCodes::LD_DREF_a16_A, std::bind(&CPU::LOAD_PIM16_R8, this, REG_A));
	setCallback(table, OpCodes::XOR_d8, std::bind(&CPU::XOR_A_IM8, this));
	// setCallback(table, OpCodes::RST_5, std::bind(&CPU::notImplemented, this));
	// setCallback(table, OpCodes::LD_A_DREF_a8, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::POP_AF, std::bind(&CPU::POP_R16, this, REG_AF));
	// setCallback(table, OpCodes::LD_A_DREF_C, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::DI, std::bind(&CPU::DI, this));
	setCallback(table, OpCodes::PUSH_AF, std::bind(&CPU::PUSH_R16, this, REG_AF));
	setCallback(table, OpCodes::OR_d8, std::bind(&CPU::OR_A_IM8, this));
	// setCallback(table, OpCodes::RST_6, std::bind(&CPU::notImplemented, this));
	// setCallback(table, OpCodes::LD_HL_SP_PLUS_s8, std::bind(&CPU::notImplemented, this));
	setCallback(table, OpCodes::LD_SP_HL, std::bind(&CPU::ADD_R16_R16, this, REG_SP, REG_HL));
	setCallback(table, OpCodes::LD_A_DREF_a16, std::bind(&CPU::LOAD_R8_PIM16, this, REG_A));
	setCallback(table, OpCodes::EI, std::bind(&CPU::EI, this));
	setCallback(table, OpCodes::CP_d8, std::bind(&CPU::COMPARE_A_IM8, this));
	// setCallback(table, OpCodes::RST_7, std::bind(&CPU::notImplemented, this));
}
