#pragma once
#include "Instruction.h"

class AddInstruction : public Instruction
{
public:
	AddInstruction() {
		this->channel = LoadExecuteChannel::getInstance();
	}

	void execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize) override;
};

