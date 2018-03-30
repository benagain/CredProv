#pragma once
#include "SymmetricKey.h"

namespace MyCrypto
{
class Padder;

enum KeyLength
{
	bits_128 = 128, 
	bits_192 = 192,
	bits_256 = 256,
	bits_512 = 512
};


class AesKeyCreationOptions : public CreationOptions
{
public:
	AesKeyCreationOptions(_In_ KeyLength length, _In_ std::wstring const & name = std::wstring());

	virtual unsigned long keySize() const
	{
		return m_keySize;
	}

	virtual std::wstring const & name() const
	{
		return m_desiredName;
	}

	unsigned long m_keySize;
	std::wstring m_desiredName;
};



class Win32SymmetricKeyGenerator : public SymmetricKeyGenerator
{
public:
	virtual VectorOfBytePtr generate(_In_ unsigned long keySize);
};

typedef boost::shared_ptr<SymmetricKeyGenerator> SymmetricKeyGeneratorPtr;



class AesSoftKey : public SymmetricKey
{
public:
	typedef VectorOfByte (AesSoftKey::*CryptoOperationPtr)(VectorOfByte const &);

	AesSoftKey();
	explicit AesSoftKey(_In_ VectorOfByte const & key);

	virtual void generate(_In_ CreationOptions const & options, _In_ KeyGeneratorPtr generator);
	virtual void generate(_In_ CreationOptions const & options);

	operator bool() const;

	VectorOfByte const & exportKey() const;

	std::wstring const & name() const;

	VectorOfBytePtr encrypt(_In_ VectorOfByte const & data, _In_ Padder const & padder);
	VectorOfBytePtr decrypt(_In_ VectorOfByte const & data, _In_ Padder const & padder);

protected:
	VectorOfBytePtr operateOnBlocks(_In_ VectorOfByte const & data, _In_ CryptoOperationPtr pp);

	virtual VectorOfByte encryptBlock(_In_ VectorOfByte const & block16Bytes);
	virtual VectorOfByte decryptBlock(_In_ VectorOfByte const & block16Bytes);

protected:
	VectorOfByte m_bytes;
	std::wstring m_name;
};
}