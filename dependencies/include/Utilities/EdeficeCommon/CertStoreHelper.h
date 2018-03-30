#pragma once

#include "Utilities\EdeficeCommon\Exceptions\LocalisedException.h"

class CertStoreHelper 
{
public:
	CertStoreHelper(){};
	~CertStoreHelper(){};

	/** 
		Removes a certificate from the given certificate store based on a container name and provider name.
		@param containerName The container name associated with the certificate
		@param provName The CSP provider associated with the certificate
		@param hStoreHandle The certificate store to search
	*/
	void RemoveCertificateFromStore(const std::wstring &containerName, const std::wstring &provName, const HANDLE &hStoreHandle);

	/**
		Gets the certificate context of a certificate based on a container name and provider name.
		@param containerName The container name associated with the certificate
		@param provName The CSP provider associated with the certificate
		@param hStoreHandle The certificate store to search
		@return The certificate context. NULL is returned if the certificate can not be found
	*/
	PCCERT_CONTEXT GetCertificateContextFromContainerName(const std::wstring &containerName, const std::wstring &provName, const HANDLE &hStoreHandle);
};

