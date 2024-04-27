#pragma once
#include "FetchDecodeChannel.h"
#include "Instruction.h"
#include "utils.h"

class DecodeUnit
{
private:
	DecodeUnit() {
		this->fetchDecodeChannelInstance = FetchDecodeChannel::getInstance();
	}

	static DecodeUnit* instance;
	FetchDecodeChannel* fetchDecodeChannelInstance;

public:
	static DecodeUnit* getInstance();
	vector<uint16_t> decodeInstruction(uint16_t instruction, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize);
};

