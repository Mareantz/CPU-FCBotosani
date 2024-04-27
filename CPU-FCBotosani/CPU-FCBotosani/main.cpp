#include <iostream>
#include "Memory.h"
#include "CPU.h"

using namespace std;
int main()
{
	Memory* memory = Memory::getInstance("memory.txt");
	memory->printMemory();
	CPU* cpu = new CPU();
	cpu->reset();

	while (true) {
		CPU cpuBeforeExecution = *cpu;
		uint16_t instruction = cpu->fetch(cpu->getInstructionPointer());
		cout<<"instruction: " << instruction<<endl;
		vector<uint16_t> instructionArguments = cpu->decode(instruction);
		cpu->execute(instructionArguments);
		cpu->printCPUState(cpuBeforeExecution);
	}

	return 0;
}