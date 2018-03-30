#pragma once

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include "VectorOfByte.h"
#include "VectorOfBytePtr.h"

namespace myid
{
	/*
	 Forward declaration of CertificateContext class
	*/
	class CertificateContext;

	/*
	 Type definition of a smart pointer wrapper for CertificateContext
	*/
	typedef boost::shared_ptr<CertificateContext> CertificateContextPtr;

	/*
	 CertificateContext class declaration
	*/
	class CertificateContext : private boost::noncopyable
	{
	protected:
		CertificateContext(void);

	public:
		virtual ~CertificateContext(void);

		static CertificateContextPtr Create(const std::wstring& filename);

		static CertificateContextPtr CreateFromBase64(const std::wstring& base64);
		
		static CertificateContextPtr Create(const myid::VectorOfByte& vecBinaryCertificate);
		static CertificateContextPtr Create(const VectorOfBytePtr& pVecBinaryCertificate);

		PCCERT_CONTEXT m_pCertContext;

		HCRYPTPROV_OR_NCRYPT_KEY_HANDLE GetPrivateKeyHandle(DWORD& keySpec);

		VectorOfBytePtr GetSubjectBytes(void) const;

		std::wstring GetCertNameString(DWORD dwType) const;

		bool operator==(const CertificateContext& rhs) const;

		bool operator!=(const CertificateContext& rhs) const;

	private:
		void FreeCertificate(void);
		void FreePrivateKeyHandle(void);
		void ImportBinaryCertificate(const myid::VectorOfByte& vecBinaryCertificate);
		static bool RemovePEMHeaderAndFooter(std::wstring& data, const std::wstring& header);

		HCRYPTPROV_OR_NCRYPT_KEY_HANDLE m_CryptProv;
		DWORD m_KeySpec;
		BOOL m_FreeKey;
	};
}
