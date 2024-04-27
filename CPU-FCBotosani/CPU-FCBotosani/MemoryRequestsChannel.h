#pragma once
#include <iostream>
#include "Memory.h"
using namespace std;

class MemoryRequestsChannel
{
private:
	MemoryRequestsChannel() {
		this->memoryInstance = Memory::getInstance("memory.txt");
	}
	static MemoryRequestsChannel* instance;
	Memory* memoryInstance;

public:
	static MemoryRequestsChannel* getInstance();

	uint16_t requestMemory(uint16_t requestedAddress);
	void requestMemory(uint16_t requestedAddress, uint16_t newValue);
};

