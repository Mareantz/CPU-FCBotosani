#include "LoadStoreUnit.h"

LoadStoreUnit* LoadStoreUnit::instance = nullptr;

LoadStoreUnit* LoadStoreUnit::getInstance()
{
	if (instance == nullptr)
		instance = new LoadStoreUnit();
	
	return instance;
}

uint16_t LoadStoreUnit::requestToMemory(uint16_t requestedAddress)
{
	return memoryRequestsChannelInstance->requestMemory(requestedAddress);
}

void LoadStoreUnit::requestToMemory(uint16_t requestedAddress, uint16_t newValue)
{
	memoryRequestsChannelInstance->requestMemory(requestedAddress, newValue);
}

uint16_t LoadStoreUnit::receiveFromMemory(uint16_t requestedAddress)
{
	return this->requestToMemory(requestedAddress);
}
