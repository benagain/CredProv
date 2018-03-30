#include "../AesSoftKey.h"

#include <windows.h>
#include <wincrypt.h>

using namespace MyCrypto;

class FakeSymmetricKeyGenerator : public SymmetricKeyGenerator
{
public:
	virtual VectorOfBytePtr generate(size_t length)
	{
		VectorOfBytePtr bytes(new VectorOfByte);
		for(size_t i = 0; i < (length/8); ++i)
		{
			bytes->push_back(i);
		}

		return bytes;
	}
};