#pragma once

#include "../CommonKey.h"
#include "../AbstractKeys/KeyStore.h"
#include "../AbstractKeys/AbstractKeyParameters.h"
#include "CNGKeyPair.h"

#include <bcrypt.h>

namespace CngCrypt
{
/// This is purely an ephemeral key
class RsaKey : public MyCrypto::RsaKey, public CngCrypt::KeyPair
{
public:
	static OKBOOL Create(_Out_ KeyStore::RSAPrivate& key, _In_ unsigned long size = 2048);

	RsaKey();

	virtual KeyStore::RSAPrivate exportPrivateKey(void) const;
	virtual KeyStore::RSAPublic exportPublicKey(void) const;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::RSAPrivate& key);
	virtual OKBOOL importPublicKey(_In_ const KeyStore::RSAPublic& key);
	virtual bool hasKey(void) const { return pairHasKey(); }
	virtual unsigned long blockSize(void) const { return pairBlockSize(); }

	virtual OKBOOL create(_In_ unsigned long size = 2048);
	virtual OKBOOL create(_In_ unsigned long size, _In_ unsigned long exponent);
	virtual OKBOOL create(_In_ unsigned long size, _In_ const VectorOfByte& exponent);
	virtual OKBOOL create(_In_ const AbstractKeys::RSAKeyParameters& keyParameters);

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual bool verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::RSACryptParameters& crypt);
};

/// use an RSA key in a store, usually hardware (HSM, TPM etc)
class StoreRsaKey : public MyCrypto::RsaKey, public StoreKeyPair
{
public:
	StoreRsaKey();
	explicit StoreRsaKey(_In_ const std::wstring& provider);

	virtual KeyStore::RSAPrivate exportPrivateKey(void) const;
	virtual KeyStore::RSAPublic exportPublicKey(void) const;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::RSAPrivate& key);
	virtual OKBOOL importPublicKey(_In_ const KeyStore::RSAPublic& key);
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::RSAPrivate& key, _In_ const AbstractKeys::KeyParameters& keyParameters);
	virtual bool hasKey(void) const { return pairHasKey(); }
	virtual unsigned long blockSize(void) const { return pairBlockSize(); }

	virtual OKBOOL create(_In_ unsigned long size = 2048);
	virtual OKBOOL create(_In_ const AbstractKeys::RSAKeyParameters& keyParameters);

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual bool verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::RSACryptParameters& crypt);
};
} // namespace CngCrypt
