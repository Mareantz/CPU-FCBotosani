#include "MemoryRequestsChannel.h"

MemoryRequestsChannel* MemoryRequestsChannel::instance = nullptr;

MemoryRequestsChannel* MemoryRequestsChannel::getInstance()
{
	if (instance == nullptr)
		instance = new MemoryRequestsChannel();

	return instance;
}

uint16_t MemoryRequestsChannel::requestMemory(uint16_t requestedAddress)
{
	return this->memoryInstance->getByAddress(requestedAddress);
}

void MemoryRequestsChannel::requestMemory(uint16_t requestedAddress, uint16_t newValue)
{
	this->memoryInstance->setAtAddress(requestedAddress, newValue);
}
