#pragma once

#include "Certificate.h"

namespace Certificate
{

class Certificate : public Loader
{
	typedef Loader inherited;

public:
	Certificate();
	Certificate(_In_ const std::wstring& reference, _In_ const VectorOfBytePtr& data, _In_ bool decodeFullDetails = false);
	Certificate(_In_ const std::wstring& reference, _In_ const VectorOfByte& data, _In_ bool decodeFullDetails = false);
	Certificate(_In_ const std::wstring& reference, _In_ const X509* data, _In_ bool decodeFullDetails = false);
	virtual ~Certificate() { }

	VectorOfByte encrypt(_In_ const VectorOfByte& data);
	VectorOfByte verify(_In_ const VectorOfByte& data);
	bool verify(_In_ const VectorOfByte& data, _In_ const VectorOfByte& sign);
    VectorOfByte thumbprint_sha1() const;
};
typedef boost::shared_ptr<Certificate > CertificatePtr;
typedef std::vector< CertificatePtr > CertificateList;

} // namespace Certificate
