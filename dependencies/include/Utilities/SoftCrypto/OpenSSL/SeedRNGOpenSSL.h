#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include "../CommonKey.h"

/** OpenSSL needs seeding once per thread.
The constructor of this class will ensure that the RNG is seeded.
If it is not, then it will create the seed.
Just instantiate an instance of this class prior to using a function that uses
OpenSSL RNG functionality*/
class SeedRNGOpenSSL
{
public:
	SeedRNGOpenSSL(void);

	static void Seed(void);
	static VectorOfByte RData(_In_ int const nSize);
};

namespace OpenSSLCrypt
{
/// Random number generation
class Random : public MyCrypto::Random
{
public:
	virtual void Seed() const;
	virtual VectorOfByte Bytes(_In_ int bytes) const;
	virtual VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes) const;
};

}
