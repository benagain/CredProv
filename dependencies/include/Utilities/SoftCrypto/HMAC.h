#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"

class HMACImpl
{
public:
	VectorOfByte HMAC_SHA256(_In_ const VectorOfByte &vecKey, _In_ const VectorOfByte &vecData, _In_opt_ VectorOfByte * vecChainingVector = NULL);
	VectorOfByte HMAC_SHA1(_In_ const VectorOfByte &vecKey, _In_ const VectorOfByte &vecData);
};