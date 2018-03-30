#pragma once

#include "../CertificateData.h"
#include <openssl/x509v3.h>

namespace Certificate
{

/// Certificate related conversions from OpenSSL
namespace Conv
{
void To(_Out_ VectorOfByte& cert, _In_ const X509* x509cert);
void To(_Out_ VectorOfBytePtr& cert, _In_ const X509* x509cert);
X509* To(_In_ const VectorOfByte& cert);

void To(_Inout_ Exts& extension, _In_opt_ X509_EXTENSIONS* extensions, bool add = false);
bool To(_Inout_ Name& name, _In_opt_ const X509_NAME* x509name, bool add = false);
bool To(_Inout_ GeneralName& name, _In_opt_ const GENERAL_NAME* x509name, bool add = false);
bool To(_Inout_ GeneralNames& names, _In_opt_ const GENERAL_NAMES* x509name, bool add = false);
bool To(_Inout_ CrlDistPoints& ext, _In_opt_ const CRL_DIST_POINTS* point, bool add = false);
bool To(_Inout_ AuthKey& ext, _In_opt_ const AUTHORITY_KEYID* akid, bool add = false);
bool To(_Inout_ Policies& ext, _In_opt_ const CERTIFICATEPOLICIES* pols, bool add = false);
bool To(_Inout_ AccessDescriptions& ext, _In_opt_ const AUTHORITY_INFO_ACCESS* auths, bool add = false);
bool To(_Inout_ PolicyConstraints& ext, _In_opt_ const POLICY_CONSTRAINTS* auths, bool add = false);
bool To(_Inout_ BasicConstraints& ext, _In_opt_ const BASIC_CONSTRAINTS* auths, bool add = false);
bool To(_Inout_ NameConstraints::GeneralSubtrees& ext, _In_opt_ const STACK_OF(GENERAL_SUBTREE)* trees, bool add = false);
bool To(_Inout_ NameConstraints& ext, _In_opt_ const NAME_CONSTRAINTS* nc, bool add = false);
bool To(_Inout_ PolicyMappings& ext, _In_opt_ const POLICY_MAPPINGS* pmaps, bool add = false);
bool To(_Inout_ RevokedList& revoked, _In_opt_ const STACK_OF(X509_REVOKED)* revs, _In_ bool decodeFullDetails, bool add = false);
bool To(_Inout_ Attribute& attribute, _In_opt_ const X509_ATTRIBUTE* x509attribute, bool add = false);
bool To(_Inout_ CrlNumber& attribute, _In_opt_ const ASN1_INTEGER* asn1, bool add = false);
}

/// Certificate data loader and processor using OpenSSL
class Loader : public Data
{
	typedef Data inherited;

public:
	Loader();
	Loader(_In_ const std::wstring& reference, _In_ const VectorOfBytePtr& data, _In_ bool decodeFullDetails = false);
	Loader(_In_ const std::wstring& reference, _In_ const VectorOfByte& data, _In_ bool decodeFullDetails = false);
	Loader(_In_ const std::wstring& reference, _In_ const X509* data, _In_ bool decodeFullDetails = false);

	void Load(_In_ const std::wstring& reference, _In_ const VectorOfBytePtr& data, _In_ bool decodeFullDetails);
	void Load(_In_ const std::wstring& reference, _In_ const VectorOfByte& data, _In_ bool decodeFullDetails);
	void Load(_In_ const std::wstring& reference, _In_ const X509* data, _In_ bool decodeFullDetails);

	bool operator==(_In_ const Loader& rhs) const;
	bool operator==(_In_ const std::wstring& rhs) const;
	operator std::wstring(void) const;

protected:
	void load(_In_ bool decodeFullDetails);
	operator X509* (void) const;
};

class CrlLoader : public Crl
{
	typedef Crl inherited;

public:
	CrlLoader();
	CrlLoader(_In_ const VectorOfBytePtr& data, _In_ bool decodeFullDetails = false);
	CrlLoader(_In_ const VectorOfByte& data, _In_ bool decodeFullDetails = false);

	void Load(_In_ const VectorOfBytePtr& data, _In_ bool decodeFullDetails);
	void Load(_In_ const VectorOfByte& data, _In_ bool decodeFullDetails);
	void Load(_In_ const X509_CRL* data, _In_ bool decodeFullDetails);

protected:
	void load(_In_ bool decodeFullDetails);
	operator X509_CRL* (void) const;
};

} // namespace Certificate
