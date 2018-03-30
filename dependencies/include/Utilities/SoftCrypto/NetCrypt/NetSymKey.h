#pragma once

#include  "../CommonKey.h"

namespace NetCrypt
{

/// Symmetric keys
/// \note This does not use padding, all data in must be one or more whole blocks
class SymKey : public MyCrypto::SymKey
{
public:
	SymKey();
	~SymKey();

	virtual bool FIPS(void) const;
	virtual VectorOfByte exportKey(void) const;
	virtual bool hasKey(void) const;
	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data) const;

protected:
	byte			m_key[32];					///< key data, max is AES256
	unsigned long	m_keySize;					///< key size in bits AES (128, 192, 256), DES (64, 128, 192)
	bool			m_valid;					///< key is valid
};

/// AES symmetric key
/// \note This does not use padding, all data in must be one or more whole blocks
class AES : public SymKey
{
public:
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual OKBOOL generateKey(_In_ unsigned long keySize);
	virtual unsigned long blockSize(void) const;
	virtual VectorOfByte ecb_encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_encrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
	virtual VectorOfByte ecb_decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_decrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
};

/// DES symmetric key
/// \note This does not use padding, all data in must be one or more whole blocks
class DES : public SymKey
{
public:
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual OKBOOL generateKey(_In_ unsigned long keySize);
	virtual unsigned long blockSize(void) const;
	virtual VectorOfByte ecb_encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_encrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
	virtual VectorOfByte ecb_decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_decrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
};

/// Password based key derivation
class PBKDF2 : public MyCrypto::PBKDF2
{
public:
	virtual VectorOfByte Derive(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ unsigned long length, _In_ int iterations = 2048) const;
};

} // namespace NetCrypt
