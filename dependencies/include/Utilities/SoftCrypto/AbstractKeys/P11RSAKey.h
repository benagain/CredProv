#pragma once

#include ".\AbstractKey.h"
#include ".\P11SessionKeyFactory.h"
#include ".\P11Key.h"

#include <boost/enable_shared_from_this.hpp>


namespace AbstractKeys
{

class P11SymmetricKey;

class P11RSAKey :	public AbstractKey,
					public RSAKey,
					public P11Key,
					public boost::enable_shared_from_this<P11RSAKey> 
{
public:
	virtual ~P11RSAKey(void);

	virtual void Generate(KeyParametersPtr pKeyParameters);

	virtual VectorOfBytePtr Encrypt(const VectorOfByte &data, CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(const VectorOfByte &data, CryptParameters &Parameters);

	/// Import vecKeyData (unwrapping with UnwrappingKey) into this object
	virtual void Import(const std::wstring &wstrKeyData, 
						const KeyFormat &format,
						CryptParameters &unwrapParameters,
						KeyParametersPtr importedKeyParameters, // Parameters (attributes) this key will have once imported
						AbstractKeyPtr &UnwrappingKey);

	/// Export this key (wrapped by WrappingKey)
	virtual std::wstring Export(const KeyFormat &format,
						CryptParameters &wrapParameters,
						AbstractKeyPtr &WrappingKey);

	/// Destroy this key. If it is persisted (e.g. in HSM), key will be permanently destroyed. return true for success
	virtual bool DestroyKey();

	/// derive (and return) a new key object, based on supplied derivation data and derivation parameters (e.g. specifying ECB). The new key returned will have the specified newKeyParameters (if supplied)
	virtual AbstractKeyPtr DeriveKey (const VectorOfByte &vecDerivationData, CryptParameters &deriveParams, KeyParametersPtr &newKeyParameters);


	virtual KeyParametersPtr GetKeyParameters() const;

	/// Import wstrKeyData (unwrapping with UnwrappingKey) into this object
	virtual void ImportEx(const VectorOfByte &vecKeyData, 
		const KeyFormat &format,
		CryptParameters &unwrapParameters,
		KeyParametersPtr importedKeyParameters, // Parameters (attributes) this key will have once imported
		AbstractKeyPtr &UnwrappingKey);

	/// Export this key (wrapped by WrappingKey)
	virtual VectorOfBytePtr ExportEx(const KeyFormat &format,
		CryptParameters &wrapParameters,
		AbstractKeyPtr &WrappingKey);

	virtual CK_OBJECT_HANDLE GetKey(); // P11Key override


	virtual VectorOfBytePtr Sign(const VectorOfByte &vecUnsigned,
							CryptParameters &signParameters);

	virtual bool Verify(const VectorOfByte &vecData,
						const VectorOfByte &vecSignature,
						CryptParameters &verifyParams);

protected:
	P11RSAKey(P11SessionKeyFactory &factory);

	void RemoveKeyIfRequired();
	void ReadPublicKey(VectorOfByte &vecModulus, VectorOfByte &vecPubExp);
	bool WrappingKeyValidForThisSession(AbstractKeyPtr &pKey);
	AbstractKeyPtr ImportKeyIntoThisSession(AbstractKeyPtr &pKeyToImport);
	void ExtractAsPKCS8(AbstractKeys::P11SymmetricKey &wrapKey, SymmetricCryptParameters &wrapParams, VectorOfByte &vecPrivateKeyData);

	CK_OBJECT_HANDLE m_hKeyPublic;
	CK_OBJECT_HANDLE m_hKeyPrivate;
	P11SessionKeyFactory &m_Factory;
	KeyParametersPtr m_pKeyParameters;

	friend class P11SessionKeyFactory;
};

}
