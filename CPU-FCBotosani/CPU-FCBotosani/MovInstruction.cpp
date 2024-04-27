#include "MovInstruction.h"
#include "Constants.h"

void MovInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	uint16_t src1 = instructionArguments[1];
	uint16_t src2 = instructionArguments[2];
	uint16_t src1Value = instructionArguments[3];
	uint16_t src2Value = instructionArguments[4];

	if (src1 == 0x10)
		throw std::exception("destination can't be immediate!");

	if (src1 < 0x10 && src2 < 0x10)
		registers[src1 - 1] = registers[src2 - 1];

	else if (src1 < 0x10)
	{
		if (src2 == 0x10)
			registers[src1 - 1] = src2Value;

		else if (src2 == 0x11)
		{
			int valueToAdd = this->channel->loadFromMemory(src2Value);
			registers[src1 - 1] = valueToAdd;
		}

		else if (src2 == 0x12)
		{
			int valueToAdd = this->channel->loadFromMemory(registers[src2Value - 1]);
			registers[src1 - 1] = valueToAdd;
		}
	}

	else
	{
		int addressFromMemory;

		if (src1 == 0x11)
			addressFromMemory = src1Value;
		else
			addressFromMemory = registers[src1Value - 1];

		if (src2 < 0x10)
		{
			int newValue = registers[src2Value - 1];
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x10)
		{
			int newValue = src2Value;
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x11)
		{
			int newValue = this->channel->loadFromMemory(src2Value);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x12)
		{
			int newValue = this->channel->loadFromMemory(registers[src2Value - 1]);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}
	}
}