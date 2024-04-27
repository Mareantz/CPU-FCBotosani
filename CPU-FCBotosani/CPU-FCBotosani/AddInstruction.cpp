#include "AddInstruction.h"

#include "Constants.h"

void AddInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	uint16_t src1 = instructionArguments[1];
	uint16_t src2 = instructionArguments[2];
	uint16_t src1Value = instructionArguments[3];
	uint16_t src2Value = instructionArguments[4];

	if (src1 == 0x01)
		throw std::exception("In add instruction src1 can't be immediate!");

	if (src1 >= 8 && src1 <= 15 && src2 >= 8 && src2 <= 15)
	{
		registers[src1 - 8] += registers[src2 - 8];

		flags[ZERO_FLAG] = registers[src1 - 8] == 0;
	}

	else if (src1 >= 8 && src1 <= 15)
	{
		if (src2 == 0x01)
			registers[src1 - 8] += src2Value;

		else if (src2 == 0x02)
		{
			int valueToAdd = this->channel->loadFromMemory(src2Value);

			registers[src1 - 8] += valueToAdd;
		}

		else if (src2 >= 24)
		{
			int valueToAdd = this->channel->loadFromMemory(registers[src2Value - 1]);
			registers[src1 - 1] += valueToAdd;
		}

		flags[ZERO_FLAG] = registers[src1 - 8] == 0;
	}

	else
	{
		int addressFromMemory;

		if (src1 == 0x02)
			addressFromMemory = src1Value;
		else
			addressFromMemory = registers[src1Value - 1];

		if (src2 >= 8 && src2 <= 15)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + registers[src2Value - 1];
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x01)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + src2Value;
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 == 0x02)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + this->channel->loadFromMemory(src2Value);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 >= 24)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) + this->channel->loadFromMemory(registers[src2Value - 1]);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		flags[ZERO_FLAG] = this->channel->loadFromMemory(addressFromMemory) == 0;
	}
}
