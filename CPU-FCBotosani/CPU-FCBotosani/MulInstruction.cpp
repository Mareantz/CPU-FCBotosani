#include "MulInstruction.h"
#include "Constants.h"

void MulInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	uint16_t src1 = instructionArguments[1];
	uint16_t src2 = instructionArguments[2];
	uint16_t src1Value = instructionArguments[3];
	uint16_t src2Value = instructionArguments[4];

	int result = 0;

	if (src1 >= 8 && src1 <= 15 && src2 >= 8 && src2 <= 15)
		result = registers[src1 - 1] * registers[src2 - 1];

	else if (src1 == 0x01 && src2 == 0x01)
		result = src1Value * src2Value;

	else if (src1 >= 8 && src1 <= 15)
	{
		if (src2 == 0x01)
			result = registers[src1 - 1] * src2Value;

		else if (src2 == 0x02)
		{
			int valueToAdd = this->channel->loadFromMemory(src2Value);

			result = registers[src1 - 1] * valueToAdd;
		}

		else if (src2 >= 24)
		{
			int valueToAdd = this->channel->loadFromMemory(registers[src2Value - 1]);
			result = registers[src1 - 1] * valueToAdd;
		}
	}

	else
	{
		int addressFromMemory;

		if (src1 == 0x02)
			addressFromMemory = src1Value;
		else
			addressFromMemory = registers[src1Value - 1];

		if (src2 >= 8 && src2 <= 15)
			result = this->channel->loadFromMemory(addressFromMemory) * registers[src2Value - 1];

		else if (src2 == 0x01)
			result = this->channel->loadFromMemory(addressFromMemory) * src2Value;

		if (src2 == 0x02)
			result = this->channel->loadFromMemory(addressFromMemory) * this->channel->loadFromMemory(src2Value);

		if (src2 >= 24)
			result = this->channel->loadFromMemory(addressFromMemory) * this->channel->loadFromMemory(registers[src2Value - 1]);
	}

	flags[ZERO_FLAG] = result == 0;

	registers[1] = result & 0xFFFF;
	registers[0] = (result >> 16) & 0xFFFF;
}
