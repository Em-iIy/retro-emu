/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/08/2026
*/

#include "CPU/CPU.hpp"

void	CPU::setState(const State &state)
{
	// If the state of the 16 register is 0x0000:
	//	Either the 8 bit registers should be set
	//	Or it should be 0x0000, in which case the 8 bit registers will set it to 0x0000 as well
	if (state.AF != 0x0000)
	{
		AF.setValue(state.AF);
	}
	else
	{
		AF.setHi(state.A);
		AF.setLo(state.F);
	}
	if (state.BC != 0x0000)
	{
		BC.setValue(state.BC);
	}
	else
	{
		BC.setHi(state.B);
		BC.setLo(state.C);
	}
	if (state.DE != 0x0000)
	{
		DE.setValue(state.DE);
	}
	else
	{
		DE.setHi(state.D);
		DE.setLo(state.E);
	}
	if (state.HL != 0x0000)
	{
		HL.setValue(state.HL);
	}
	else
	{
		HL.setHi(state.H);
		HL.setLo(state.L);
	}
	SP.setValue(state.SP);
	PC.setValue(state.PC);

	// if (state.readAddress != 0x0000)
	// {
	// 	if (state.readValue8bit != 0x00)
	// 	{
	// 		_bus.writeByte(state.readAddress, state.readValue8bit);
	// 	}
	// 	else
	// 	{
	// 		_bus.writeByte(state.readAddress, state.readValue8bit);
	// 		_bus.writeByte(state.readAddress + 1, state.readValue8bit);
	// 	}
	// }
}

bool	CPU::checkState(const State &state)
{
	bool result = true;
	if (state.AF != 0x0000)
	{
		if (state.AF != AF.getValue())
			result = false;
	}
	else
	{
		if (state.A != AF.getHi())
			result = false;
		if (state.F != AF.getLo())
			result = false;
	}
	if (state.BC != 0x0000)
	{
		if (state.BC != BC.getValue())
			result = false;
	}
	else
	{
		if (state.B != BC.getHi())
			result = false;
		if (state.C != BC.getLo())
			result = false;
	}
	if (state.DE != 0x0000)
	{
		if (state.DE != DE.getValue())
			result = false;
	}
	else
	{
		if (state.D != DE.getHi())
			result = false;
		if (state.E != DE.getLo())
			result = false;
	}
	if (state.HL != 0x0000)
	{
		if (state.HL != HL.getValue())
			result = false;
	}
	else
	{
		if (state.H != HL.getHi())
			result = false;
		if (state.L != HL.getLo())
			result = false;
	}
	if (state.HL != HL.getValue())
		result = false;
	if (state.HL != HL.getValue())
		result = false;
	return (result);
}
