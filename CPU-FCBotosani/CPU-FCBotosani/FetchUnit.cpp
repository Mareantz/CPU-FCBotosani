#include "FetchUnit.h"

FetchUnit* FetchUnit::instance = nullptr;

FetchUnit* FetchUnit::getInstance()
{
    if (instance == nullptr)
		instance = new FetchUnit();

	return instance;
}

uint16_t FetchUnit::fetchInstruction(uint16_t& requestedAddress)
{
	uint16_t result = this->loadFetchChannelInstance->requestFromMemory(requestedAddress);
	requestedAddress += 2;

	return result;
}

uint16_t FetchUnit::fetchOperand(uint16_t& requestedAddress)
{
	uint16_t result = this->loadFetchChannelInstance->requestFromMemory(requestedAddress);
	requestedAddress += 2;

	return result;
}
