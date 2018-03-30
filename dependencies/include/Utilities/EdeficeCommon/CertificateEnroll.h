/// Declares the classes used to integrate with the microsoft certificate enrollment libraries.
#pragma once

#include <xenroll.h>
#include <rpcsal.h>
#include <certenroll.h>

/// CEnrollAPI - A base class for microsoft enrolment libraries.
class CEnrollAPI
{
public:
	enum Protection				/// key protection
	{
		NO_PROTECTION,			///< None
		USE_PROTECTION,			///< usage
		HIGH_PROTECTION			///< high protection
	};

	CEnrollAPI(const std::wstring &CSPName, const std::wstring &ReaderName, const std::wstring &PIN);

	virtual void KeyLength(const long KeyLength);
	virtual void IsExchangeKey(const bool Exchange);
	virtual void IsArchivable(const bool Archivable);
	virtual void IsExportable(const bool Exportable);
	virtual void IsProtected(const bool Protected);
	virtual void IsProtected(const Protection Protected);
	virtual void IsSilent(const bool Silent);
	virtual bool CheckKeyLength() = 0;
	virtual std::wstring CreatePKCS10(const std::wstring &DNName, const std::wstring &Usage, std::wstring &ContainerName, const std::wstring &keyUsageXML, bool bCreateKey = true, bool bInline = false) = 0;
	virtual std::wstring CreateCMC(const std::wstring &DNName, const std::wstring &ArchiveCertificate, const std::wstring &RequesterName, const std::wstring &keyUsageXML, std::wstring &ContainerName, bool bCreateKey = true) = 0;
	virtual void AcceptCertificate(const std::wstring &PKCS7, const std::wstring &ContainerName) = 0;
	
	virtual std::wstring CreatePFX(const std::wstring &ContainerName) = 0;

protected:
	std::wstring FormatContainerName(const std::wstring &ContainerName);
	void RemoveCarriageReturns(std::wstring &PKCS10);

	std::wstring m_CSPName;		///< The name of the cryptographic provider being used.
	std::wstring m_ReaderName;	///< The name of the reader containing the smart card to be accessed.
	std::wstring m_PIN;			///< The smart card user PIN or the password used for the software certificate.
	long m_KeyLength;			///< The length of the required key, in bits.
	bool m_Archivable;			///< True if the key is to be archivable, otherwise false.
	bool m_Exportable;			///< True if the key is to be exportable, otherwise false.
	bool m_ExchangeKey;			///< True if the key is to be an exchange key, otherwise false.
	Protection m_Protected;		///< key protection level
	bool m_Silent;				///< True if silent logon is required
};


/// CXEnrollAPI - Manages certificate enrolment using the microsoft XEnroll libraries.
class CXEnrollAPI: public CEnrollAPI
{
public:
	CXEnrollAPI(const std::wstring &CSPName, const std::wstring &ReaderName, const std::wstring &PIN);
	~CXEnrollAPI();

	virtual void IsExchangeKey(const bool Exchange);
	virtual bool CheckKeyLength();
	virtual std::wstring CreatePKCS10(const std::wstring &DNName, const std::wstring &Usage, std::wstring &ContainerName, const std::wstring &keyUsageXML, bool bCreateKey = true, bool bInline = false);
	virtual std::wstring CreateCMC(const std::wstring &DNName, const std::wstring &ArchiveCertificate, const std::wstring &RequesterName, const std::wstring &keyUsageXML, std::wstring &ContainerName, bool bCreateKey = true);
	virtual void AcceptCertificate(const std::wstring &PKCS7, const std::wstring &ContainerName);
	virtual std::wstring CreatePFX(const std::wstring &ContainerName);

protected:
	void SetGenKeyFlags();
	void SetFormattedReaderName(std::wstring &ContainerName, bool bCreateKey = true);
	void Initialise();
private:
	ATL::CComPtr<ICEnroll4> m_pEnroll;	///< A pointer to the XEnroll library.
};


/// CCertEnrollAPI - Manages certificate enrolment using the microsoft CertEnroll libraries.
class CCertEnrollAPI: public CEnrollAPI
{
public:
	CCertEnrollAPI(const std::wstring &CSPName, const std::wstring &ReaderName, const std::wstring &PIN);
	~CCertEnrollAPI();

	virtual void IsExchangeKey(const bool Exchange);
	virtual bool CheckKeyLength();
	virtual std::wstring CreatePKCS10(const std::wstring &DNName, const std::wstring &Usage, std::wstring &ContainerName, const std::wstring &keyUsageXML, bool bCreateKey = true, bool bInline = false);
	virtual std::wstring CreateCMC(const std::wstring &DNName, const std::wstring &ArchiveCertificate, const std::wstring &RequesterName, const std::wstring &keyUsageXML, std::wstring &ContainerName, bool bCreateKey = true);
	virtual void AcceptCertificate(const std::wstring &PKCS7, const std::wstring &ContainerName);
	virtual std::wstring CreatePFX(const std::wstring &ContainerName);

protected:
	void Initialise();
	void PreparePrivateKey(std::wstring &ContainerName, bool bCreateKey = true);
	void PreparePKCS10(const std::wstring &DN, const std::wstring &keyUsageXML, IX509CertificateRequestPkcs10 *pPKCS10);
	std::wstring CreatePrivateKey();
	std::wstring CreatePKCS10Request(const std::wstring &DN, const std::wstring &keyUsageXML, const bool bInline);
	std::wstring CreateCMCRequest(const std::wstring &DN, const std::wstring &ArchiveCertificate, const std::wstring &RequesterName, const std::wstring &keyUsageXML);
private:
	ATL::CComPtr<IX509PrivateKey> m_pPrivateKey;				///< A pointer to the IX509PrivateKey interface of the CertEnroll library.
	ATL::CComPtr<IX509Enrollment> m_pX509Enrollment;			///< A pointer to the IX509Enrollment interface of the CertEnroll library.
};

/// CCertificateEnroll - a class to manage the selection of the microsoft enrollment library
class CCertificateEnroll
{
public:
	CCertificateEnroll(const std::wstring &CSPName, const std::wstring &ReaderName, const std::wstring &PIN);
	~CCertificateEnroll();

	CEnrollAPI* GetEnrollAPI();
	static bool IsVista();

protected:
	CEnrollAPI *m_pAPI;	///< a pointer to a microsoft enrolment API wrapper class.
private:
	void GetEnrolmentAPI(const std::wstring &CSPName, const std::wstring &ReaderName, const std::wstring &PIN);
};

int ParseX509KeyUsage(const std::wstring &keyUsageXML);

