#pragma once

#include ".\abstractkey.h"
#include ".\Softwarekeyfactory.h"


#include "..\SoftCrypto.h"
#include "OpenSSL\aes.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{

class SoftwareAESKey :	public AbstractKey,
						public AESKey,
						public boost::enable_shared_from_this<SoftwareAESKey> // because for modeSP800_38B_CMAC we need to feed an AbstractKeyPtr(this) to another class
{
public:
	virtual ~SoftwareAESKey(void);

	virtual void Generate(KeyParametersPtr pKeyParameters);

	virtual VectorOfBytePtr Encrypt(const VectorOfByte &data, CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(const VectorOfByte &data, CryptParameters &Parameters);

	/// Import wstrKeyData (unwrapping with UnwrappingKey) into this object
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

	virtual VectorOfBytePtr Sign(const VectorOfByte &vecUnsigned,
							CryptParameters &signParameters);

	virtual bool Verify(const VectorOfByte &vecData,
						const VectorOfByte &vecSignature,
						CryptParameters &verifyParams);

protected:
	SoftwareAESKey(SoftwareKeyFactory &factory);

	void GetKeyCheckValue();

	void ImportHexSymmetricBlob(const VectorOfByte &vecKeyData, 
									CryptParameters &unwrapParameters,
									KeyParametersPtr importedKeyParameters,
									AbstractKeyPtr &UnwrappingKey);

	SoftwareKeyFactory &m_Factory;
	KeyParametersPtr m_pKeyParameters;

	friend class SoftwareKeyFactory;

private:
	void SetKeySchedule();

	VectorOfByte m_vecKeyData;
	// for some reason OpenSSL has different key schedule objects for encrypt and decrypt
	bool m_bKeySet;
	AES_KEY m_keySchedEncrypt;
	AES_KEY m_keySchedDecrypt;
};


}
