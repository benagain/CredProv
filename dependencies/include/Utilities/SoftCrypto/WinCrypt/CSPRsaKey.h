#pragma once

#include "../CommonKey.h"
#include "../AbstractKeys/KeyStore.h"
#include "../AbstractKeys/AbstractKeyParameters.h"
#include "CSPCommon.h"

namespace CspCrypt
{
class RsaKey : public MyCrypto::RsaKey, public MyCrypto::KeyPair, public CspCommon
{
public:
	static OKBOOL Create(_In_ KeyStore::RSAPrivate& key, _In_ unsigned long size = 2048);

	RsaKey();
	explicit RsaKey(_In_ const std::wstring& csp);

	void AlgID(_In_ ALG_ID algID);
	ALG_ID AlgID(void) const;

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

protected:
	virtual unsigned long pairBlockSize(void) const;

	ALG_ID m_algID;					///< AT_KEYEXCHANGE or AT_SIGNATURE
};

} // namespace CspCrypt
