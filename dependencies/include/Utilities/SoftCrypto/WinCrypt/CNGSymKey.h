#pragma once

#include "CNGCrypt.h"
#include  "../CommonKey.h"
#include <boost/noncopyable.hpp>

#include <bcrypt.h>

namespace CngCrypt
{

/// Low level AES processing
/// \note This does not use padding, all data in must be one or more whole blocks
class SymKey : public MyCrypto::SymKey, private boost::noncopyable
{
public:
	virtual bool FIPS(void) const;
	virtual VectorOfByte exportKey(void) const;
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual bool hasKey(void) const;
	virtual OKBOOL generateKey(_In_ unsigned long keySize);
	virtual unsigned long blockSize(void) const;
	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_encrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_decrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;

protected:
	SymKey();
	explicit SymKey(_In_z_ const wchar_t* alg);
	virtual ~SymKey();

	void SetChainingMode() const;

	const CngCrypt::AlgHandle*	m_algECB;		///< ECB algorithm variant
	const CngCrypt::AlgHandle*	m_algCBC;		///< CBC algorithm variant

	CngCrypt::Key			m_handleECB;		///< ECB key handle
	CngCrypt::Key			m_handleCBC;		///< CBC key handle
};

/// AES symmetric key
/// \note One algorithm works for all AES lengths
class AES : public SymKey
{
public:
	AES();
};

/// Aggregator
/// \note CNG requires a separate algorithm for each DES length
/// The key length must match the algorithm type
class DES : public SymKey
{
	typedef SymKey inherited;

public:
	DES();

	virtual bool FIPS(void) const;
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual OKBOOL generateKey(_In_ unsigned long keySize);

protected:
	void allocate();

	unsigned long			m_keySize;			///< key size in bits
};

/// Password based key derivation
class PBKDF2 : public MyCrypto::PBKDF2
{
public:
	virtual VectorOfByte Derive(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ unsigned long length, _In_ int iterations = 2048) const;

protected:
	const CngCrypt::AlgHandle& alg(_In_ const AbstractKeys::CryptParameters::HashType hashType) const;
};

} // namespace CngCrypt
