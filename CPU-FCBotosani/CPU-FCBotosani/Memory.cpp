#include "Memory.h"

#include <fstream>
#include <iostream>

int stringToInt(string stringToConvert)
{
	for (int i = 0; i < stringToConvert.size(); i++)
		if (stringToConvert[i] >= 'A' && stringToConvert[i] <= 'Z')
			stringToConvert[i] = stringToConvert[i] - 'A' + 'a';

	int value = 0;

	for (int i = stringToConvert.size() - 1, power = 1; i >= 0; i--, power *= 16)
	{
		if (stringToConvert[i] >= '0' && stringToConvert[i] <= '9')
			value = value + (stringToConvert[i] - '0') * power;

		else
			value = value + (stringToConvert[i] - 'a' + 10) * power;
	}

	return value;
}

Memory* Memory::currentInstance = nullptr;

Memory* Memory::getInstance(string fileName)
{
	if (currentInstance == nullptr)
		currentInstance = new Memory(fileName);

	return currentInstance;
}

void Memory::loadMemoryFromFile()
{
	ifstream inputFile(this->fileName);

	int currentAddress = 0;

	if (!inputFile.good())
		throw std::exception("Memory not loaded!");

	string currentLine;

	while (!inputFile.eof())
	{
		getline(inputFile, currentLine);

		if (currentLine == "")
			continue;

		if (currentLine[0] == '#')
			currentAddress = stringToInt(currentLine.substr(1));

		else
		{
			this->memoryArea[currentAddress] = stringToInt(currentLine);
			currentAddress += 2;
		}
	}
}

uint16_t Memory::getByAddress(uint16_t requestedAddress)
{

	if (this->memoryArea.find(requestedAddress) != this->memoryArea.end())
		return this->memoryArea[requestedAddress];

	return 0;
}


void Memory::setAtAddress(uint16_t requestedAddress, uint16_t newValue)
{
	this->memoryArea[requestedAddress] = newValue;
}

void Memory::printMemory()
{
	cout << "Printing memory:\n\n";
	for (auto it = this->memoryArea.begin(); it != this->memoryArea.end(); it++)
		cout << it->first << " " << it->second << "\n";
}
