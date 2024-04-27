#pragma once
#include "Instruction.h"

class JMPInstruction : public Instruction
{
public:
	JMPInstruction() {
		this->channel = LoadExecuteChannel::getInstance();
	}

	void execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize) override;

private:
	int getValueOfArgument(int src, int srcValue, vector<uint16_t>& registers);
};

