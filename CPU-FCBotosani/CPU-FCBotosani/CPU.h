#pragma once

#include <vector>

#include "FetchUnit.h"
#include "LoadStoreUnit.h"
#include "DecodeUnit.h"
#include "ExecuteUnit.h"

using namespace std;

class CPU
{
private:
	vector<uint16_t> registers, flags;
	uint16_t instructionPointer;
	uint16_t stackPointer;
	uint16_t stackBase;
	uint16_t stackSize;

	FetchUnit* fetchUnit;
	LoadStoreUnit* loadStoreUnit;
	DecodeUnit* decodeUnit;
	ExecuteUnit* executeUnit;

public:
	CPU();

	void reset();

	uint16_t getRegisterValue(uint16_t registerIndex);
	void setRegisterValue(uint16_t registerIndex, uint16_t newValue);

	uint16_t& getInstructionPointer();

	uint16_t fetch(uint16_t& requestedAddress);
	vector<uint16_t> decode(uint16_t instruction);
	void execute(vector<uint16_t> instructionArguments);

	void printCPUState(CPU cpuBeforeExecution);
};

