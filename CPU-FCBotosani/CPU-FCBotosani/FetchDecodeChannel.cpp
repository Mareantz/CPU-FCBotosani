#include "FetchDecodeChannel.h"

FetchDecodeChannel* FetchDecodeChannel::instance = nullptr;

FetchDecodeChannel* FetchDecodeChannel::getInstance()
{
    if (instance == nullptr)
		instance = new FetchDecodeChannel();

	return instance;
}

uint16_t FetchDecodeChannel::fetchInstruction(uint16_t& requestedAddress)
{
	return this->fetchUnitInstance->fetchInstruction(requestedAddress);
}

uint16_t FetchDecodeChannel::fetchOperand(uint16_t& requestedAddress)
{
	return this->fetchUnitInstance->fetchOperand(requestedAddress);
}
