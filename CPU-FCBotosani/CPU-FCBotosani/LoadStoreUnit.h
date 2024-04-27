#pragma once
#include "MemoryRequestsChannel.h"
class LoadStoreUnit
{
private:
	LoadStoreUnit() {
		this->memoryRequestsChannelInstance = MemoryRequestsChannel::getInstance();
	}

	static LoadStoreUnit* instance;
	MemoryRequestsChannel* memoryRequestsChannelInstance;

public:
	static LoadStoreUnit* getInstance();

	uint16_t requestToMemory(uint16_t requestedAddress);
	void requestToMemory(uint16_t requestedAddress, uint16_t newValue);

	uint16_t receiveFromMemory(uint16_t requestedAddress);
};

