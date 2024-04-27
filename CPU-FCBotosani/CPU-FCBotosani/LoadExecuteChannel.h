#pragma once

#include "LoadStoreUnit.h"

class LoadExecuteChannel
{
private:
	LoadStoreUnit* loadStoreUnit;
	static LoadExecuteChannel* instance;

	LoadExecuteChannel()
	{
		loadStoreUnit = LoadStoreUnit::getInstance();
	}

public:
	static LoadExecuteChannel* getInstance();

	uint16_t loadFromMemory(uint16_t address);
	void storeToMemory(uint16_t address, uint16_t value);
};

