#include "FetchUnit.h"

FetchUnit* FetchUnit::instance = nullptr;

FetchUnit* FetchUnit::getInstance()
{
    if (instance == nullptr)
		instance = new FetchUnit();

	return instance;
}

uint16_t FetchUnit::fetchInstruction(uint16_t requestedAddress)
{
	return this->loadFetchChannelInstance->requestFromMemory(requestedAddress);
}

uint16_t FetchUnit::fetchOperand(uint16_t requestedAddress)
{
	return this->loadFetchChannelInstance->requestFromMemory(requestedAddress);
}
