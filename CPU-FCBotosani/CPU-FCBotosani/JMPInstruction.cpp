#include "JMPInstruction.h"

void JMPInstruction::execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	int src1 = instructionArguments[1];
	int src1Value = instructionArguments[3];

	int newIP = this->getValueOfArgument(src1, src1Value, registers);

	instructionPointer = newIP;
}

int JMPInstruction::getValueOfArgument(int src, int srcValue, vector<uint16_t>& registers)
{
	cout << "=================================" << endl;
	cout << src << " " << srcValue << endl;
	if (src >= 8 && src <= 15)
		return registers[src - 8];

	else if (src == 0x01)
		return srcValue;

	else if (src == 0x02)
		return this->channel->loadFromMemory(srcValue);

	return this->channel->loadFromMemory(registers[srcValue]);
}
