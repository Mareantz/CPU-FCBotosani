#include "ExecuteUnit.h"
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
#include "EndSimInstruction.h"

ExecuteUnit* ExecuteUnit::instance = nullptr;

ExecuteUnit* ExecuteUnit::getInstance()
{
	if (instance == nullptr)
		instance = new ExecuteUnit();

	return instance;
}

void ExecuteUnit::executeInstruction(vector<uint16_t> cmdArgs, vector<uint16_t>& registers, vector<uint16_t>& flags, uint16_t& instructionPointer, uint16_t& stackPointer, uint16_t stackBase, uint16_t stackSize)
{
	Instruction* instruction = nullptr;

	switch (cmdArgs[0])
	{
	case 1:
		instruction = new AddInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 2:
		instruction = new SubInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 3:
		instruction = new MovInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 4:
		instruction = new MulInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 5:
		instruction = new DivInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 6:
		instruction = new CmpInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 7:
		instruction = new JMPInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 9:
		instruction = new JEInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 10:
		instruction = new JLInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 11:
		instruction = new JGInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 12:
		instruction = new JZInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;

	case 15:
		instruction = new EndSimInstruction();
		instruction->execute(cmdArgs, registers, flags, instructionPointer, stackPointer, stackBase, stackSize);
		break;
	}
}
