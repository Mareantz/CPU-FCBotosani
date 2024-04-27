#pragma once

#include <map>
#include <string>

using namespace std;

class Memory
{
	map<uint16_t, uint16_t> memoryArea;
	string fileName;

	static Memory* currentInstance;

	Memory() {
		this->fileName = "memory.txt";
	}

	Memory(string fileName) {
		this->fileName = fileName;
	}

public:
	Memory* getInstance(string fileName);

	void loadMemoryFromFile();

	uint16_t getByAddress(uint16_t requestedAddress);
	void setAtAddress(uint16_t requestedAddress, uint16_t newValue);

	void printMemory();
};
