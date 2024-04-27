#include "AddInstruction.h"

#include "Constants.h"

void AddInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	uint16_t src1 = instructionArguments[1];
	uint16_t src2 = instructionArguments[2];
	uint16_t src1Value = instructionArguments[3];
	uint16_t src2Value = instructionArguments[4];

	if (src1 == 0x10)
		throw std::exception("In add instruction src1 can't be immediate!");

	if (src1 < 0x10 && src2 < 0x10)
	{
		registers[src1 - 1] += registers[src2 - 1];

		flags[ZERO_FLAG] = registers[src1 - 1] == 0;
	}

	else if (src1 < 0x10)
	{
		if (src2 == 0x10)
			registers[src1 - 1] += src2Value;

		else if (src2 == 0x11)
		{
			int valueToAdd = this->channel->loadFromMemory(src2Value);

			registers[src1 - 1] += valueToAdd;
		}

		else if (src2 == 0x12)
		{
			int valueToAdd = this->channel->loadFromMemory(registers[src2Value - 1]);
			registers[src1 - 1] += valueToAdd;
		}

		flags[ZERO_FLAG] = flags[src1 - 1] == 0;
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
			int newValue = this->channel->loadFromMemory(addressFromMemory) + registers[src2Value - 1];
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x10)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + src2Value;
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 == 0x11)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + this->channel->loadFromMemory(src2Value);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 == 0x12)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + this->channel->loadFromMemory(registers[src2Value - 1]);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		flags[ZERO_FLAG] = this->channel->loadFromMemory(addressFromMemory) == 0;
	}
}
