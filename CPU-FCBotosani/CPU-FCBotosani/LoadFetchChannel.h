#pragma once
#include "LoadStoreUnit.h"
class LoadFetchChannel
{
private:
	static LoadFetchChannel* instance;
	LoadStoreUnit* loadStoreUnitInstance;

	LoadFetchChannel() {
		this->loadStoreUnitInstance = LoadStoreUnit::getInstance();
	}

public:
	static LoadFetchChannel* getInstance();

	uint16_t requestFromMemory(uint16_t requestedAddress);
};

