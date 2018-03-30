#pragma once
#include "../CommonKey.h"

/// CNG .NET interface
namespace NetCrypt
{

/// Random number generation
class Random : public MyCrypto::Random
{
public:
	static VectorOfByte Generate(_In_ int bytes);
	static VectorOfByte Generate(_In_ const VectorOfByte& entropy, _In_ int bytes);

	virtual void Seed() const;
	virtual VectorOfByte Bytes(_In_ int bytes) const;
	virtual VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes) const;
};

} // namespace NetCrypt
