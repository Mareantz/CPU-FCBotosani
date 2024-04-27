#include "CPU.h"
#include "Constants.h"

CPU::CPU()
{
	this->registers = vector<uint16_t>(8);
	this->flags = vector<uint16_t>(3);

	this->reset();

	this->decodeUnit = DecodeUnit::getInstance();
	this->executeUnit = ExecuteUnit::getInstance();
	this->fetchUnit = FetchUnit::getInstance();
	this->loadStoreUnit = LoadStoreUnit::getInstance();
}

void CPU::reset()
{
	for (int i = 0; i < 8; i++)
		this->registers[i] = 0;

	this->flags[ZERO_FLAG] = this->flags[EQUAL_FLAG] = this->flags[GREATER_FLAG] = 0;
	this->stackBase = 10000;
	this->stackSize = 1000;

	this->instructionPointer = 0xfff0;
}

uint16_t CPU::getRegisterValue(uint16_t registerIndex)
{
	return this->registers[registerIndex];
}

void CPU::setRegisterValue(uint16_t registerIndex, uint16_t newValue)
{
	this->registers[registerIndex] = newValue;
}

uint16_t CPU::fetch(uint16_t& requestedAddress)
{
	return this->fetchUnit->fetchInstruction(requestedAddress);
}

uint16_t& CPU::getInstructionPointer()
{
	return this->instructionPointer;
}

vector<uint16_t> CPU::decode(uint16_t instruction)
{
	return this->decodeUnit->decodeInstruction(instruction, this->registers, this->flags, this->instructionPointer, this->stackPointer, this->stackBase, this->stackSize);
}

void CPU::printCPUState(CPU cpuBeforeExecution)
{
	printf("Registers:\n");
	for (int i = 0; i < 8; i++)
	{
		if (registers[i] != cpuBeforeExecution.registers[i])
			changeConsoleColor(FOREGROUND_GREEN);

		printf("Register %d: %xh\n", i, this->registers[i]);

		changeConsoleColor(15);
	}

	if (this->instructionPointer != cpuBeforeExecution.instructionPointer)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Register IP: %xh\n", this->instructionPointer);
		changeConsoleColor(15);
	}

	else
		printf("Register IP: %xh\n", this->instructionPointer);


	if (this->stackPointer != cpuBeforeExecution.stackPointer)
	{
		changeConsoleColor(FOREGROUND_GREEN);
		printf("Register SP: %xh\n", this->stackPointer);
		changeConsoleColor(15);
	}

	else
		printf("Register SP: %xh\n", this->stackPointer);


	printf("\nFlags:\n");
	printf("Zero Flag: %d\n", flags[ZERO_FLAG]);
	printf("Equal Flag: %d\n", flags[EQUAL_FLAG]);
	printf("Greater Flag: %d\n", flags[GREATER_FLAG]);
	printf("\n");
}

void CPU::execute(vector<uint16_t> instructionArguments)
{
	this->executeUnit->executeInstruction(instructionArguments, this->registers, this->flags, this->instructionPointer, this->stackPointer, this->stackBase, this->stackSize);
}