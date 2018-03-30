#pragma once

#include "../CommonKey.h"
#include "../AbstractKeys/KeyStore.h"
#include "../AbstractKeys/AbstractKeyParameters.h"

namespace NetCrypt
{
/// This is purely an ephemeral key
class EccKey : public MyCrypto::EccKey, public MyCrypto::KeyPair
{
public:
	static OKBOOL Create(_Out_ KeyStore::ECCPrivate& key, _In_ unsigned long size = 256, _In_ bool dsa = true);
	static OKBOOL Create(_Out_ KeyStore::ECCPrivate& key, _In_ const AbstractKeys::ECCKeyParameters& keyParameters);

	EccKey();

	virtual KeyStore::ECCPrivate exportPrivateKey(void) const;
	virtual KeyStore::ECCPublic exportPublicKey(void) const;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::ECCPrivate& key);
	virtual OKBOOL importPublicKey(_In_ const KeyStore::ECCPublic& key);
	virtual bool hasKey(void) const { return pairHasKey(); }
	virtual unsigned long blockSize(void) const { return pairBlockSize(); }

	virtual OKBOOL create(_In_ unsigned long size = 256, _In_ bool dsa = true);
	virtual OKBOOL create(_In_ const AbstractKeys::ECCKeyParameters& keyParameters);

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::ECCCryptParameters& crypt);
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::ECCCryptParameters& crypt);
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::ECCCryptParameters& crypt);
	virtual bool verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::ECCCryptParameters& crypt);

protected:
	virtual unsigned long pairBlockSize(void) const;

	KeyStore::ECCPrivate	m_key;			///< key
};

} // namespace NetCrypt
