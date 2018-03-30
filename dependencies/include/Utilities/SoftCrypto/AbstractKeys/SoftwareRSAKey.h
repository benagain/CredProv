#pragma once

#include "AbstractKey.h"
#include "..\WinCrypt\RSAKeyHelperCSP.h"
#include ".\Softwarekeyfactory.h"

namespace AbstractKeys
{

class SoftwareRSAKey : public AbstractKey,
						public RSAKey
{
public:
	virtual ~SoftwareRSAKey(void);


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

	/// derive (and return) a new key object, based on supplied derivation data and derivation parameters (e.g. specifying ECB). The new key returned will have the specified newKeyParameters (if supplied)
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
	SoftwareRSAKey(SoftwareKeyFactory &factory);

	/*!
	* Internal implementation of ImportEx after the key has been unwrapped (if an unwrapping key
	* was provided). This is separated out to improve code maintainability.
	*
	* \param[in] vecKeyData
	*   Binary public or private key data
	* \param[in] format
	*   The format of the data in vecKeyData
	* \param[in] importedKeyParameters
	*   The key parameters to apply to the key once it has been imported
	*/
	virtual void ImportKey(const VectorOfByte &vecKeyData,
		const KeyFormat &format,
		KeyParametersPtr importedKeyParameters);

	void ImportHexRSA_CSPPublic(const VectorOfByte &vecKeyData);

	void ImportHexRSA_PKCS1Public(const VectorOfByte &vecKeyData);

	/*!
	* Given a set of key parameters with a missing key length value this method determines the size
	* of the key which was imported and updates the key parameters with the length
	*
	* \pre
	*   A key has been imported successfully
	*/
	void ImportKey_ExtractKeyLength(KeyParametersPtr importedKeyParameters);

	virtual bool VerifyASN1(const VectorOfByte &vecData,
		const VectorOfByte &vecSignature,
		CryptParameters &verifyParams);

	/*!
	* Helper method for VerifyASN1 to convert an OID into a hash algorithm name. The verification
	* of the supported algorithms (based on crypt parameters) is also performed and the crypt
	* parameters will be updated with the actual OID that was found (if supported)
	*/
	bool VerifyASN1_AlgorithmFromOID(const std::wstring& OID, CryptParameters &verifyParams, std::wstring& algorithm);

	virtual VectorOfBytePtr PublicEncrypt(const VectorOfByte &vecData);

	SoftwareKeyFactory &m_Factory;
	KeyParametersPtr m_pKeyParameters;

	CRSAKeyHelperCSP m_RSAHelper;

	friend class SoftwareKeyFactory;
};


}