#pragma once

/** \file
 * Definition of CPKCS7Encoder
 */

#include <wincrypt.h>
#include "VectorOfByte.h"

#define szOID_OIWSEC_sha256 "2.16.840.1.101.3.4.2.1"
#define szOID_RSA_SHA256RSA "1.2.840.113549.1.1.11"

/// PKCS#7 ASN1 encoder
class CPKCS7Encoder
{
public:
	CPKCS7Encoder(void);
	virtual ~CPKCS7Encoder(void);

	void Sign(const VectorOfByte &vecDataToSign, const char* pszOID_DataContent, VectorOfByte &vecSignedData);

	void IncludeCertificateInSignature(const bool bInclude);
	void SetDetachedSignature(bool bDetachedSignature);

protected:
	virtual PCRYPT_ATTRIBUTE GetAuthenticatedAttributes(DWORD &dwNumberAttributes);
	virtual PCRYPT_ATTRIBUTE GetUnAuthenticatedAttributes(DWORD &dwNumberAttributes);
	virtual int GetVersion(void) const;
	virtual std::wstring GetAlgorithm(void);
	virtual void SetCryptContext(void) = 0;

	// these next two must be set by SetCryptContext()
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE m_hCryptProv;				///< crypt provider
	PCCERT_CONTEXT m_pCertContext;			///< certificate context

	DWORD m_dwKeySpec;						///< which key

	bool m_bIncludeCertificateInSignature;	///< is certificate included
	bool m_bDetachedSignature;				///< detached signature implies no data in content
};
