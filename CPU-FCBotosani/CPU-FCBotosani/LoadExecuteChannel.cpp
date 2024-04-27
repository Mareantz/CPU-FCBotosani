#include "LoadExecuteChannel.h"

LoadExecuteChannel* LoadExecuteChannel::instance = nullptr;

LoadExecuteChannel* LoadExecuteChannel::getInstance()
{
	if (instance == nullptr)
		instance = new LoadExecuteChannel();

	return instance;
}

uint16_t LoadExecuteChannel::loadFromMemory(uint16_t address)
{
	return this->loadStoreUnit->receiveFromMemory(address);
}

void LoadExecuteChannel::storeToMemory(uint16_t address, uint16_t value)
{
	this->loadStoreUnit->requestToMemory(address, value);
}
