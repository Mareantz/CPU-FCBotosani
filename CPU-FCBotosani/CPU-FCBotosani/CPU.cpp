#include "CPU.h"

CPU::CPU()
{
	this->reset();
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
