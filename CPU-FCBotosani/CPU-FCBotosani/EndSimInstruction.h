#pragma once
#include "Instruction.h"

class EndSimInstruction : public Instruction
{
public:
	void execute(vector<uint16_t> cmdArgs, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize);
};

