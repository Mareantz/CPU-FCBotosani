#include "EndSimInstruction.h"

void EndSimInstruction::execute(vector<uint16_t> cmdArgs, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	system("pause");
	exit(0);
}
