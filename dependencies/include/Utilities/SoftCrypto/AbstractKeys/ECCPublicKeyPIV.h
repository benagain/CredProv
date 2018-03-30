#pragma once

#include "ECCPublicKey.h"

namespace AbstractKeys
{

namespace KeyEncoder
{
class ECCPublicKeyPIV : public ECCPublicKey
{
public:
	// IECCPublicKeyData - no overrides

	//IKeyEncoder - overrides
	virtual void GetEncodedData(VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(const VectorOfByte &vecEncodedKey);

private:
};

} //namespace KeyEncoder

} //namespace AbstractKeys
