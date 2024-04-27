#pragma once

#include <vector>
using namespace std;

class CPU
{
private:
	vector<uint16_t> registers, flags;
	uint16_t instructionPointer;
	uint16_t stackPointer;
	uint16_t stackBase;
	uint16_t stackSize;

public:
	CPU();

	void reset();

	uint16_t getRegisterValue(uint16_t registerIndex);
	void setRegisterValue(uint16_t registerIndex, uint16_t newValue);

	uint16_t fetch(uint16_t requestedAddress);
	void decode(uint16_t instruction);
	void execute(uint16_t instruction);
};

