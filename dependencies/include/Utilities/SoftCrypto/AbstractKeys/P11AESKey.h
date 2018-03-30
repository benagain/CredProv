#pragma once

#include ".\AbstractKey.h"
#include ".\P11SessionKeyFactory.h"
#include ".\P11Key.h"
#include ".\P11SymmetricKey.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{


class P11AESKey :	public P11SymmetricKey,
					public AESKey,
					public boost::enable_shared_from_this<P11AESKey> 
{
public:
	virtual void SetSymmetricMechanism(SymmetricCryptParameters &param, CK_MECHANISM &mechanism, bool bCombinePadding=false);

	virtual VectorOfBytePtr Sign(const VectorOfByte &vecUnsigned,
							CryptParameters &signParameters);

	virtual bool Verify(const VectorOfByte &vecData,
						const VectorOfByte &vecSignature,
						CryptParameters &verifyParams);

protected:
	// concept of parity correction does not exist for AES (because there are no parity bits)
	P11AESKey(P11SessionKeyFactory &factory) : P11SymmetricKey(factory, familyAES, /*bImportParityCorrectionSupported=*/false) {} // must be instantiated via a KeyFactory object

	virtual CK_MECHANISM_TYPE GetKeyGenMechanism(const SymmetricKeyParameters &symKeyParams, int &nCKA_VALUE_LEN) const;
	virtual CK_KEY_TYPE CryptoAlgorithmToP11KeyType(const SymmetricKeyParameters &symKeyParameters) const;

	virtual AbstractKeyPtr GenerateTemporaryKey(AbstractKeyFactory &keyFactory, KeyParametersPtr &params);
	virtual void GetKeyTypeCurrentlyLoaded(SymmetricKeyParameters &keyParams);
	virtual void SetKeyParametersByEncryptedDataLength(const unsigned long nKeyDataLength, const SymmetricCryptParameters &unwrapParams, SymmetricKeyParameters &keyParams, const AbstractKeyPtr pEncryptionKey) const;

	friend class P11SessionKeyFactory;
};

}