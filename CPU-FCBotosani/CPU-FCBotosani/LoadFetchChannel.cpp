#include "LoadFetchChannel.h"

LoadFetchChannel* LoadFetchChannel::instance = nullptr;

LoadFetchChannel* LoadFetchChannel::getInstance()
{
	if (instance == nullptr)
		instance = new LoadFetchChannel();

	return instance;
}

uint16_t LoadFetchChannel::requestFromMemory(uint16_t requestedAddress)
{
	return loadStoreUnitInstance->requestToMemory(requestedAddress);
}
