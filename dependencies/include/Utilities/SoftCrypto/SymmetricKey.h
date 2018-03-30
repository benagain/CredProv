#pragma once

#include "Key.h"
#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"

namespace MyCrypto
{
class SymmetricKeyGenerator : public KeyGenerator
{
public:
	virtual VectorOfBytePtr generate(_In_ unsigned long keySize) = 0;
};

class SymmetricKey : public Key
{
protected:
	/// Concrete implementation of encrypting one block of data
	virtual VectorOfByte encryptBlock(_In_ VectorOfByte const & block) = 0;

	/// Concrete implementation of encrypting one block of data
	virtual VectorOfByte decryptBlock(_In_ VectorOfByte const & block) = 0;
};
}