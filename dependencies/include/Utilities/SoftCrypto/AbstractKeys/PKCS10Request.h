#pragma once

#include "AbstractKey.h"
#include "Utilities\SoftCrypto\CertificateRequest\Pkcs10RequestEncoder\CertificateRequestSigner.h"
#include "Utilities\SoftCrypto\CertificateRequest\Pkcs10RequestEncoder\CertificateRequestEncoder.h"

namespace AbstractKeys
{

class PKCS10Request : public Pkcs10RequestSigner
{
public:
	PKCS10Request(void);
	~PKCS10Request(void);

	void SetReverseDN(_In_ bool reverseDN);

	void SetDN(_Out_ std::wstring& dn);

	virtual VectorOfBytePtr SignPkcs10Request(_In_ VectorOfByte const& data, _In_ std::wstring const& keyName);
	virtual VectorOfBytePtr SignPkcs10Request(_In_ VectorOfByte const& data, _In_ std::wstring const& keyName, _In_ long const signer);

	VectorOfBytePtr CreateRequest(_In_ AbstractKeyPtr pPrivateKey, _In_ KeyParametersPtr pKeyParameters);

protected:
	void ReverseDN(_Inout_ std::wstring& dn) const;

private:
	bool m_reverseDn;
	std::wstring m_dn;
	VectorOfBytePtr m_vecKey;

	AbstractKeyPtr m_pPrivateKey;
	Pkcs10RequestEncoder m_p10Encoder;
};

}