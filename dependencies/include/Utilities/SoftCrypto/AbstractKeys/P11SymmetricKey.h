#pragma once

#include ".\AbstractKey.h"
#include ".\P11SessionKeyFactory.h"
#include ".\P11Key.h"
#include "..\paddinghelper.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{

class P11SymmetricKey : public AbstractKey,
					public P11Key,
					public boost::enable_shared_from_this<P11SymmetricKey> // because for modeSP800_38B_CMAC we need to feed an AbstractKeyPtr(this) to another class
{
public:
	virtual ~P11SymmetricKey(void);

	virtual void Generate(KeyParametersPtr pKeyParameters);

	virtual VectorOfBytePtr Encrypt(const VectorOfByte &data, CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(const VectorOfByte &data, CryptParameters &Parameters);

	virtual void Import(const std::wstring &wstrKeyData, 
						const KeyFormat &format,
						CryptParameters &unwrapParameters,
						KeyParametersPtr importedKeyParameters, // Parameters (attributes) this key will have once imported
						AbstractKeyPtr &UnwrappingKey);

	virtual std::wstring Export(const KeyFormat &format,
						CryptParameters &wrapParameters,
						AbstractKeyPtr &WrappingKey);

	virtual bool DestroyKey();

	virtual AbstractKeyPtr DeriveKey (const VectorOfByte &vecDerivationData, CryptParameters &deriveParams, KeyParametersPtr &newKeyParameters);

	virtual KeyParametersPtr GetKeyParameters() const;

	/// Import vecKeyData (unwrapping with UnwrappingKey) into this object
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

	virtual void SetSymmetricMechanism(SymmetricCryptParameters &param, CK_MECHANISM &mechanism, bool bCombinePadding=false)=0;

protected:
	P11SymmetricKey(P11SessionKeyFactory &factory, const KeyFamily family, const bool bImportParityCorrectionSupported=true); // must be instantiated via derived class

	/// concrete class must override this
	virtual AbstractKeyPtr GenerateTemporaryKey(AbstractKeyFactory &keyFactory, KeyParametersPtr &params)=0;
	virtual CK_MECHANISM_TYPE GetKeyGenMechanism(const SymmetricKeyParameters &symKeyParams, int &nCKA_VALUE_LEN) const=0;
	virtual CK_KEY_TYPE CryptoAlgorithmToP11KeyType(const SymmetricKeyParameters &symKeyParameters) const=0;

	/// this must be overriden on a derived class to create a new key object of the relevant type
	virtual AbstractKeyPtr CreateUninitialisedKey(AbstractKeyFactory &keyFactory) const;

	const VectorOfByte &PadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
										VectorOfByte &vecPaddedData,
										const VectorOfByte &dataToPad);
	VectorOfBytePtr UnpadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
										VectorOfBytePtr vecData);

	virtual void GetKeyCheckValue();

	virtual std::wstring GenerateUniqueID() const;

	// find key
	virtual void FindPersistedKey(const std::wstring &wstrKeyData, KeyParametersPtr importedKeyParameters);
	virtual void GetKeyTypeCurrentlyLoaded(SymmetricKeyParameters &keyParams);

	// key import / export
	virtual bool ImportHexSymmetricBlob(const VectorOfByte &vecKeyData, CryptParameters &unwrapParameters, KeyParametersPtr &importedKeyParameters, AbstractKeyPtr &UnwrappingKey);
	virtual AbstractKeyPtr CreateUnwrappingKeyAndEncrypt(VectorOfBytePtr &pvecKeyToImport, SymmetricCryptParameters &unwrapParameters);
	virtual bool KeyBelongsToThisSession(AbstractKeyPtr &pKey);
	virtual bool ImportKeyParityCorrectionSupported();
	virtual VectorOfBytePtr ParityCorrectHexSymmetricKeyBlob(const VectorOfByte &vecKeyData, AbstractKeyPtr &UnwrappingKey, CryptParameters &unwrapParameters);
	AbstractKeyPtr ImportKeyIntoThisSession(AbstractKeyPtr &pKeyToImport);
	virtual void SetKeyParametersByEncryptedDataLength(const unsigned long nKeyDataLength, const SymmetricCryptParameters &unwrapParams, SymmetricKeyParameters &keyParams, const AbstractKeyPtr pEncryptionKey) const;
	size_t CalculateWrappedKeyLength(const KeyParameters &wrapKeyParams, const SymmetricCryptParameters &wrapParams) const;

	SymmetricKeyParameters &GetSymmetricKeyParameters();

	void RemoveKeyIfRequired(); //not virtual (called from destructor)

	const KeyFamily m_keyFamily; //DES or AES
	bool m_bImportParityCorrectionSupported;
	CK_OBJECT_HANDLE m_hKey;
	P11SessionKeyFactory &m_Factory;
	KeyParametersPtr m_pKeyParameters;

	friend class P11RSAKey;
};


}