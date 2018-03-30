#pragma once

#include "AbstractKey.h"
#include "SoftwareKeyFactory.h"
#include "../CommonKey.h"

namespace AbstractKeys
{

class SoftwareECCKey
	: public AbstractKey
	, public SoftwareAbstractKey
	, public ECCKey
{
public:
	virtual ~SoftwareECCKey(void);

	virtual void Generate(_In_ KeyParametersPtr pKeyParameters);

	virtual VectorOfBytePtr Encrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters);
	virtual VectorOfBytePtr Sign(_In_ const VectorOfByte &data, _In_ CryptParameters &cryptParams);
	virtual bool Verify(_In_ const VectorOfByte &data, _In_ const VectorOfByte &signature, _In_ CryptParameters &cryptParams);

	virtual void Import(_In_ const std::wstring &wstrKeyData, _In_ const KeyFormat &format, _In_ CryptParameters &unwrapParameters, _In_ KeyParametersPtr importedKeyParameters, _In_ AbstractKeyPtr &UnwrappingKey);
	virtual std::wstring Export(_In_ const KeyFormat &format, _In_ CryptParameters &wrapParameters, _In_ AbstractKeyPtr &WrappingKey);

	virtual bool DestroyKey();
	virtual AbstractKeyPtr DeriveKey(_In_ const VectorOfByte &vecDerivationData, _In_ CryptParameters &deriveParams, _In_ KeyParametersPtr &newKeyParameters);
	virtual KeyParametersPtr GetKeyParameters() const;

	virtual void ImportEx(_In_ const VectorOfByte &vecKeyData, _In_ const KeyFormat &format, _In_ CryptParameters &unwrapParameters, _In_ KeyParametersPtr importedKeyParameters, _In_ AbstractKeyPtr &UnwrappingKey);
	virtual VectorOfBytePtr ExportEx(_In_ const KeyFormat &format, _In_ CryptParameters &wrapParameters, _In_ AbstractKeyPtr &WrappingKey);

protected:
	explicit SoftwareECCKey(_In_ SoftwareKeyFactory &factory);
	SoftwareECCKey(_In_ SoftwareKeyFactory &factory, _In_ const MyCrypto::KeyFactoryPtr& keyFactory, _In_ const MyCrypto::KeyFactoryPtr& hashFactory);

	KeyParametersPtr		m_pKeyParameters;
	MyCrypto::EccKeyPtr		m_key;
	MyCrypto::HashPtr		m_hash;

	friend class SoftwareKeyFactory;
};


}