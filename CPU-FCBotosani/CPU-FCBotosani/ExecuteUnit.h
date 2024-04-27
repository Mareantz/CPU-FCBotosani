#pragma once
#include <vector>
using namespace std;

class ExecuteUnit
{
private:
	ExecuteUnit() {
	}

	static ExecuteUnit* instance;

public:
	static ExecuteUnit* getInstance();
	void executeInstruction(vector<uint16_t> cmdArgs, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize);
};

