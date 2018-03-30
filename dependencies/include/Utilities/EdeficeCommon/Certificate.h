#pragma once

#include <boost/noncopyable.hpp>
#include "CertAltNameEntry.h"
#include "Utilities/EdeficeCommon/TimeCommon.h"
#include "Utilities/EdeficeCommon/XMLnode.h"

namespace myid
{

class Certificate : private boost::noncopyable
{
public:
	explicit Certificate(std::wstring const & b64Cert);
	virtual ~Certificate(void);

	std::wstring EmailAddress() const;
	std::wstring DistinguishedName() const;
	bool HasUserPrincipalName() const;
	std::wstring UserPrincipalName() const;
	std::wstring IssuerName() const;
	std::wstring PublicKey() const;
	myid::Time ExpiryDate() const;
	myid::Time IssueDate() const;

	bool IsInDate();

	std::wstring Pkcs7InDatabaseFormat() const;
	std::wstring SerialNumber() const;

	std::wstring KeyLength() const;
	std::wstring KeyAlgorithm() const;

protected:

	void CreateContext();


	// wrapper around CryptDecodeObject - takes care of sizing the returned vector
	bool DecodeObject( LPCSTR lpszStructType, BYTE const * pbEncoded, DWORD cbEncoded, VectorOfByte & vecDecoded );

	void DecodeSubjectAltNames();

	myid::Time ParseTimeFromXML(std::wstring const & timeXPath) const;

	VectorOfCertAltNameEntry m_altNameEntries;
	bool m_altNameEntriesDecoded;

	eXML::IXMLDOMNodePtr m_certificate;

private:
	std::wstring EmailAddressFromDn() const;

	// decode the cert using CSPUtils
	void DecodeCertToXML();

	VectorOfByte m_certBytes;
	PCCERT_CONTEXT m_pCertContext;
	
};

} // namespace myid