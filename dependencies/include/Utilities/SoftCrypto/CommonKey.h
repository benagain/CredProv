#pragma once

// All these methods are intended to be private to the SoftCrypto library and SoftCrypto.Tests
// Instead use abstract keys or SoftCrypto.h

#include "AbstractKeys/KeyStore.h"
#include "AbstractKeys/AbstractKeyParameters.h"

namespace MyCrypto
{

/// Common random interface.
class Random
{
public:
	virtual void Seed() const = 0;
	virtual VectorOfByte Bytes(_In_ int bytes) const = 0;
	virtual VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes) const = 0;

	template< typename T >
	void Value(_In_ T& value) const
	{
		VectorOfByte vec(Bytes((int)sizeof(T)));
		value = *reinterpret_cast<const T*>(vec.ptr());
	}
};
typedef boost::shared_ptr<Random> RandomPtr;

class Hash
{
public:
	virtual VectorOfByte sha1(_In_ const VectorOfByte& data) = 0;
	virtual VectorOfByte sha256(_In_ const VectorOfByte& data) = 0;
	virtual VectorOfByte sha384(_In_ const VectorOfByte& data) = 0;
	virtual VectorOfByte sha512(_In_ const VectorOfByte& data) = 0;

	virtual VectorOfByte sha(_In_ const VectorOfByte& data, _In_ const AbstractKeys::CryptParameters::HashType hashType);
	virtual VectorOfByte sha(_In_ const VectorOfByte& data, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ int iterations);
};
typedef boost::shared_ptr<Hash> HashPtr;

class HMAC
{
public:
	virtual VectorOfByte sha1(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key) = 0;
	virtual VectorOfByte sha256(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key) = 0;
	virtual VectorOfByte sha384(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key) = 0;
	virtual VectorOfByte sha512(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key) = 0;

	virtual VectorOfByte sha(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key, _In_ const AbstractKeys::CryptParameters::HashType hashType);
};
typedef boost::shared_ptr<HMAC> HMACPtr;

/// Common low level key pair parent.
class KeyPair
{
protected:
	KeyPair();

	virtual bool pairHasKey(void) const;
	virtual unsigned long pairBlockSize(void) const = 0;

	enum keyType
	{
		INVALID,			///< not defined yet - not created or imported
		PUBLIC,				///< key is public, can only do encrypt and verify
		PRIVATE				///< key is private, can do all ops
	};

	keyType	m_valid;				///< key type
};

/// Common low level for classes with stored key names
class KeyName
{
public:
	virtual void Key(_In_ const std::wstring& name);
	virtual std::wstring Key(void) const;

protected:
	std::wstring m_keyName;			///< key (container) name
};

/// Common low level RSA key interface. Do not use child classes directly, use abstract keys instead
/// \note This does not use padding, all data in must be one or more whole blocks
class RsaKey
{
public:
	virtual KeyStore::RSAPrivate exportPrivateKey(void) const = 0;
	virtual KeyStore::RSAPublic exportPublicKey(void) const = 0;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::RSAPrivate& key) = 0;
	virtual OKBOOL importPublicKey(_In_ const KeyStore::RSAPublic& key) = 0;
	virtual bool hasKey(void) const = 0;
	virtual unsigned long blockSize(void) const = 0;

	virtual OKBOOL create(_In_ unsigned long size = 2048) = 0;
	virtual OKBOOL create(_In_ unsigned long size, _In_ unsigned long exponent) = 0;
	virtual OKBOOL create(_In_ unsigned long size, _In_ const VectorOfByte& exponent) = 0;
	virtual OKBOOL create(_In_ const AbstractKeys::RSAKeyParameters& keyParameters) = 0;

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt) = 0;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt) = 0;
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::RSACryptParameters& crypt) = 0;
	virtual OKBOOL verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::RSACryptParameters& crypt) = 0;

protected:
	RsaKey() {}
};
typedef boost::shared_ptr<RsaKey> RsaKeyPtr;

/// Common low level ECC key interface. Do not use child classes directly, use abstract keys instead
/// \note This does not use padding, all data in must be one or more whole blocks
class EccKey
{
public:
	virtual KeyStore::ECCPrivate exportPrivateKey(void) const = 0;
	virtual KeyStore::ECCPublic exportPublicKey(void) const = 0;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::ECCPrivate& key) = 0;
	virtual OKBOOL importPublicKey(_In_ const KeyStore::ECCPublic& key) = 0;
	virtual bool hasKey(void) const = 0;
	virtual unsigned long blockSize(void) const = 0;

	virtual OKBOOL create(_In_ unsigned long size = 256, _In_ bool dsa = true) = 0;
	virtual OKBOOL create(_In_ const AbstractKeys::ECCKeyParameters& keyParameters) = 0;

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::ECCCryptParameters& crypt) = 0;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::ECCCryptParameters& crypt) = 0;
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::ECCCryptParameters& crypt) = 0;
	virtual OKBOOL verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::ECCCryptParameters& crypt) = 0;

protected:
	EccKey() {}
};
typedef boost::shared_ptr<EccKey> EccKeyPtr;

/// Common low level symmetric key interface. Do not use child classes directly, use abstract keys instead
/// \note This does not use padding, all data in must be one or more whole blocks
class SymKey
{
public:
	virtual ~SymKey()
	{}

	virtual bool FIPS(void) const = 0;
	virtual VectorOfByte exportKey(void) const = 0;
	virtual OKBOOL importKey(_In_ const VectorOfByte& key) = 0;
	virtual bool hasKey(void) const = 0;
	virtual OKBOOL generateKey(_In_ unsigned long keySize) = 0;
	virtual unsigned long blockSize(void) const = 0;
	virtual VectorOfByte encrypt(_In_ VectorOfByte const & data) const = 0;
	virtual VectorOfByte ecb_encrypt(_In_ VectorOfByte const & data) const = 0;
	virtual VectorOfByte cbc_encrypt(_In_ VectorOfByte const & data, _Inout_ VectorOfByte & ivc) const = 0;
	virtual VectorOfByte decrypt(_In_ VectorOfByte const & data) const = 0;
	virtual VectorOfByte ecb_decrypt(_In_ VectorOfByte const & data) const = 0;
	virtual VectorOfByte cbc_decrypt(_In_ VectorOfByte const & data, _Inout_ VectorOfByte & ivc) const = 0;

protected:
	void check_ivc(_Inout_ VectorOfByte& ivc) const;
};
typedef boost::shared_ptr<SymKey> SymKeyPtr;

/// Password based key derivation as defined by RFC2898 and NIST SP800-132
class PBKDF2
{
public:
	virtual ~PBKDF2()
	{}

	virtual VectorOfByte Derive(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ unsigned long length, _In_ int iterations = 2048) const = 0;
	virtual VectorOfByte DerivePKCS5(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ unsigned long length, _In_ int iterations = 2048) const;
};
typedef boost::shared_ptr<PBKDF2> PBKDF2Ptr;

}
