#include "JGInstruction.h"
#include "Constants.h"

#include "JMPInstruction.h"

void JGInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	if (flags[GREATER_FLAG] == 0)
		return;

	JMPInstruction jmpInstruction;
	jmpInstruction.execute(instructionArguments, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
}
