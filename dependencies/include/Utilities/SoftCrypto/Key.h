#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"
#include <string>
#include <boost/shared_ptr.hpp>

namespace MyCrypto
{
class Padder;

/// Interface base class for options related to key generation
class CreationOptions
{
public:
	virtual ~CreationOptions() {};
	virtual std::wstring const & name() const = 0;

	virtual unsigned long keySize() const = 0;
};


/// Interface base class for key generators
class KeyGenerator
{
public:
	virtual ~KeyGenerator()
	{}
};
typedef boost::shared_ptr<KeyGenerator> KeyGeneratorPtr;


/// This is a key that is used for cryptography purposes
class Key
{
public:
	virtual ~Key() {}

	virtual void generate(_In_ CreationOptions const & options, _In_ KeyGeneratorPtr generator) = 0;

	virtual VectorOfBytePtr encrypt(_In_ VectorOfByte const & data, _In_ Padder const & padder) = 0;
	virtual VectorOfBytePtr decrypt(_In_ VectorOfByte const & data, _In_ Padder const & padder) = 0;
};
}

