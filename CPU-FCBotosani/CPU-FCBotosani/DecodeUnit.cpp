#include "DecodeUnit.h"
#include "AddInstruction.h"
#include "SubInstruction.h"
#include "MulInstruction.h"
#include "DivInstruction.h"
#include "CmpInstruction.h"
#include "MovInstruction.h"
#include "JMPInstruction.h"
#include "JEInstruction.h"
#include "JZInstruction.h"
#include "JLInstruction.h"
#include "JGInstruction.h"

DecodeUnit* DecodeUnit::instance = nullptr;

DecodeUnit* DecodeUnit::getInstance()
{
    if (instance == nullptr)
		instance = new DecodeUnit();

    return instance;
}

vector<uint16_t> DecodeUnit::decodeInstruction(uint16_t instruction, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	vector<uint16_t> cmdArgs(5);

	uint16_t opCode = instruction >> 10;
	uint16_t src1 = (instruction >> 5);
	src1 = src1 & 0x1F;
	uint16_t src2 = instruction & 0x1F;

	cmdArgs[0] = opCode;
	cmdArgs[1] = src1;
	cmdArgs[2] = src2;

	if (!(src1 >= 8 && src1 <= 15))
	{
		uint16_t src1Value = this->fetchDecodeChannelInstance->fetchOperand(instructionPointer);
		cmdArgs[3] = src1Value;
	}

	else
	{
		cmdArgs[3] = 0;
	}

	if (!(src2 >= 8 && src2 <= 15))
	{
		uint16_t src2Value = this->fetchDecodeChannelInstance->fetchOperand(instructionPointer);
		cmdArgs[4] = src2Value;
	}

	else
	{
		cmdArgs[4] = 0;
	}

	/*if (src1 == 0x01 && cmdArgs[3] % 2 == 1)
		throw std::exception("Misalign access!");*/

	if (src1 == 0x02 && registers[cmdArgs[3]] % 2 == 1)
		throw std::exception("Misalign access!");

	/*if (src2 == 0x01 && cmdArgs[4] % 2 == 1)
		throw std::exception("Misalign access!");*/

	if (src2 == 0x02 && registers[cmdArgs[4]] % 2 == 1)
		throw std::exception("Misalign access!");

	if (src1 == 0x01 && src2 != 0x0)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Write in memory at address %xh\n\n", cmdArgs[3]);
		changeConsoleColor(15);
	}

	else if (src1 >= 24 && src2 != 0x0)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Write in memory at address %xh\n\n", registers[cmdArgs[3] - 1]);
		changeConsoleColor(15);
	}

	if (src2 == 0x02)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Read from memory at address %xh\n\n", cmdArgs[4]);
		changeConsoleColor(15);
	}

	if (src2 >= 24)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Read from memory at address %xh\n\n", registers[cmdArgs[4] - 1]);
		changeConsoleColor(15);
	}

	return cmdArgs;
}

//Instruction* DecodeUnit::convertToInstruction(vector<uint16_t> cmdArgs, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
//{
//	switch (cmdArgs[0])
//	{
//	case 1:
//		return new AddInstruction(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
//		break;
//
//	case 2:
//		return new SubInstruction(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
//		break;
//	}
//}
