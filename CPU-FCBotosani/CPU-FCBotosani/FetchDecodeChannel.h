#pragma once
#include "FetchUnit.h"

class FetchDecodeChannel
{
private:
	FetchDecodeChannel() {
		this->fetchUnitInstance = FetchUnit::getInstance();
	}

	static FetchDecodeChannel* instance;
	FetchUnit* fetchUnitInstance;

public:
	static FetchDecodeChannel* getInstance();

	uint16_t fetchInstruction(uint16_t& requestedAddress);
	uint16_t fetchOperand(uint16_t& requestedAddress);
};

