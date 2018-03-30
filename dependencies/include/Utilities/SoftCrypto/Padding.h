#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"

namespace MyCrypto
{
class Padder
{
public:
	virtual ~Padder() {}
	virtual VectorOfBytePtr addPadding(_In_ VectorOfByte const & data) const = 0;
	virtual VectorOfBytePtr removePadding(_In_ VectorOfByte const & data) const = 0;
};

class NoPadder : public Padder
{
public:
	virtual VectorOfBytePtr addPadding(_In_ VectorOfByte const & data) const;
	virtual VectorOfBytePtr removePadding(_In_ VectorOfByte const & data) const;
};

class Pkcs7Padder : public Padder
{
public:
	virtual VectorOfBytePtr addPadding(_In_ VectorOfByte const & data) const;
	virtual VectorOfBytePtr removePadding(_In_ VectorOfByte const & data) const;
};

	size_t remainder(double dividend, double divisor);
}
