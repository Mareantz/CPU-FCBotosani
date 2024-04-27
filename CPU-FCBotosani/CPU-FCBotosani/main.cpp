#include <iostream>
#include "Memory.h"

using namespace std;
int main()
{
	Memory* memory = Memory::getInstance("memory.txt");

	memory->printMemory();

	return 0;
}