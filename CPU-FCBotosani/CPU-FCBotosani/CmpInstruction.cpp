#include "CmpInstruction.h"
#include "Constants.h"

void CmpInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	uint16_t src1 = instructionArguments[1];
	uint16_t src2 = instructionArguments[2];
	uint16_t src1Value = instructionArguments[3];
	uint16_t src2Value = instructionArguments[4];

	int firstArg = 0, secondArg = 0;

	if (src1 < 0x10)
		firstArg = registers[src1 - 1];

	else if (src1 == 0x10)
		firstArg = src1Value;

	else if (src1 == 0x11)
		firstArg = this->channel->loadFromMemory(src1Value);

	else
		firstArg = this->channel->loadFromMemory(registers[src1Value - 1]);


	if (src2 < 0x10)
		secondArg = registers[src2 - 1];

	else if (src2 == 0x10)
		secondArg = src2Value;

	else if (src2 == 0x11)
		secondArg = this->channel->loadFromMemory(src2Value);

	else
		secondArg = this->channel->loadFromMemory(registers[src2Value - 1]);


	if (firstArg == secondArg)
		flags[EQUAL_FLAG] = 1;
	else
		flags[EQUAL_FLAG] = 0;

	if (firstArg == 0 && secondArg == firstArg)
		flags[ZERO_FLAG] = 1;
	else
		flags[ZERO_FLAG] = 0;

	if (firstArg > secondArg)
		flags[GREATER_FLAG] = 1;
	else
		flags[GREATER_FLAG] = 0;
}