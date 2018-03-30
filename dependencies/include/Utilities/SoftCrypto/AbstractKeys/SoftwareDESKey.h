#pragma once

#include ".\abstractkey.h"
#include ".\Softwarekeyfactory.h"


#include "..\SoftCrypto.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{


/** Implementation of AbstractKey that utilises OpenSSL with software cryptography
for DES/2DES/3DES key types.
Since there is no hardware device, attribute checking is 'simulated' in software*/
class SoftwareDESKey :  public AbstractKey,
						public DESKey,
						protected SoftCryptoDES,
						public boost::enable_shared_from_this<SoftwareDESKey> // because for modeSP800_38B_CMAC we need to feed an AbstractKeyPtr(this) to another class
{
public:
	virtual ~SoftwareDESKey(void);

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

	virtual VectorOfByte RData(int const nSize);

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
	SoftwareDESKey(SoftwareKeyFactory &factory);
	DESKeyParameters &GetDESKeyParameters();

	const VectorOfByte &PadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
										VectorOfByte &vecPaddedData,
										const VectorOfByte &dataToPad);
	VectorOfBytePtr UnpadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
										VectorOfBytePtr vecData);

	void ImportHexSymmetricBlob(const VectorOfByte &vecKeyData, 
										CryptParameters &unwrapParameters,
										KeyParametersPtr importedKeyParameters,
										AbstractKeyPtr &UnwrappingKey);


	void GetKeyCheckValue();

	SoftwareKeyFactory &m_Factory;
	KeyParametersPtr m_pKeyParameters;

	friend class SoftwareKeyFactory;
};



}
