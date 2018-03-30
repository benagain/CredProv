/** Implementation of key diversification algorithm for MPCOS applet.
	See \\filestore\FileStore\Professional_Services\Projects\DUC Kuwait\3. Implementation\GemAppletDocs\RM_MPCOS-Applet.pdf
	Section 4 - Key Diversification - page 38
*/

#pragma once
#include "abstractkey.h"
#include ".\P11SessionKeyFactory.h"
#include ".\P11Key.h"
#include "..\paddinghelper.h"

namespace AbstractKeys
{

class P112DES16Key:	public AbstractKey,
					public DESKey,
					public P11Key,
					protected CPaddingHelper
{
public:
	virtual ~P112DES16Key(void);

	virtual void Generate(KeyParametersPtr pKeyParameters);

	virtual VectorOfBytePtr Encrypt(const VectorOfByte &data, CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(const VectorOfByte &data, CryptParameters &Parameters); //< Doesn't make sense to decrypt with this.

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

	virtual CK_OBJECT_HANDLE GetKey(); // P11Key override

	virtual VectorOfByte RData(int const nSize); // CPaddingHelper override

protected:
	P112DES16Key(P11SessionKeyFactory &factory, const bool bImportParityCorrectionSupported=true); // must be instantiated via a KeyFactory object
	virtual std::wstring GenerateUniqueID() const;

	KeyParametersPtr m_pKeyParameters;

private:
	AbstractKeyPtr m_ptrLeftKey;
	AbstractKeyPtr m_ptrRightKey;
	P11SessionKeyFactory &m_Factory;


	friend class P11SessionKeyFactory;
};

}