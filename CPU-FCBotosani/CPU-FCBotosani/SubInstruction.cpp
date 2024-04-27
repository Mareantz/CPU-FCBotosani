#include "SubInstruction.h"
#include "Constants.h"

#include <iostream>
using namespace std;

void SubInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{

	int src1 = instructionArguments[1];
	int src2 = instructionArguments[2];
	int src1Value = instructionArguments[3];
	int src2Value = instructionArguments[4];

	cout<<src1<<" "<<src2<<" "<<src1Value<<" "<<src2Value<<endl;

	if (src1 == 0x01)
		throw std::exception("In sub instruction src1 can't be immediate!");

	if (src1 >= 8 && src1 <= 15 && src2 >= 8 && src2 <= 15)
	{
		registers[src1 - 8] -= registers[src2 - 8];

		flags[ZERO_FLAG] = registers[src1 - 8] == 0;
	}

	else if (src1 >= 8 && src1 <= 15)
	{
		if (src2 == 0x01)
			registers[src1 - 8] -= src2Value;

		else if (src2 == 0x02)
		{
			int valueToAdd = this->channel->loadFromMemory(src2Value);

			registers[src1 - 8] -= valueToAdd;
		}

		else if (src2 >= 24)
		{
			int valueToAdd = this->channel->loadFromMemory(registers[src2Value]);
			registers[src1 - 8] -= valueToAdd;
		}

		flags[ZERO_FLAG] = registers[src1 - 8] == 0;
	}

	else
	{
		int addressFromMemory;

		if (src1 == 0x02)
			addressFromMemory = src1Value;
		else
			addressFromMemory = registers[src1Value];

		if (src2 >= 8 && src2 <= 15)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) - registers[src2Value];
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		else if (src2 == 0x01)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) - src2Value;
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 == 0x02)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) - this->channel->loadFromMemory(src2Value);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		if (src2 >= 24)
		{
			int newValue = this->channel->loadFromMemory(addressFromMemory) - this->channel->loadFromMemory(registers[src2Value]);
			this->channel->storeToMemory(addressFromMemory, newValue);
		}

		flags[ZERO_FLAG] = this->channel->loadFromMemory(addressFromMemory) == 0;
	}
}


