#pragma once

#include <vector>

#include "LoadExecuteChannel.h"

using namespace std;

class Instruction
{
protected:
	LoadExecuteChannel* channel;

public:
	virtual void execute(vector<uint16_t> instructionArguments, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize) = 0;
};

