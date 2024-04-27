#include "JLInstruction.h"

#include "Constants.h"

void JLInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	if (flags[GREATER_FLAG] == 1)
		return;

	JMPInstruction jmpInstruction;
	jmpInstruction.execute(instructionArguments, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
}	
