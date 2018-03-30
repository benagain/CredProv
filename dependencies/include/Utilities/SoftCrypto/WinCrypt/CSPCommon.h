#pragma once
#include "../CommonKey.h"

namespace CspCrypt
{
class CspCommon : public MyCrypto::KeyName
{
public:
	CspCommon();
	explicit CspCommon(_In_ const std::wstring& csp);

	void Provider(_In_ const std::wstring& csp);
	std::wstring Provider(void) const;

	virtual DWORD LastError() const;

protected:
	OKBOOL Acquire(_Out_ HCRYPTPROV* hProv, _In_ DWORD dwFlags) const;

	std::wstring m_csp;				///< CSP name
	DWORD m_provType;				///< CSP provider type
	mutable DWORD m_error;			///< last CSP error code
};
} // namespace CspCrypt
