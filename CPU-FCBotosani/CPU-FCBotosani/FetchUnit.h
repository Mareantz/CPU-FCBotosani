#pragma once
#include "LoadFetchChannel.h"

class FetchUnit
{
private:
	FetchUnit() {
		this->loadFetchChannelInstance = LoadFetchChannel::getInstance();
	}

	static FetchUnit* instance;
	LoadFetchChannel* loadFetchChannelInstance;

public:
	static FetchUnit* getInstance();

	uint16_t fetchInstruction(uint16_t& requestedAddress);
	uint16_t fetchOperand(uint16_t& requestedAddress);
};

