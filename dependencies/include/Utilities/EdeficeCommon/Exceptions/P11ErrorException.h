#pragma once

#include "ErrorException.h"

namespace myid
{

/// This exception takes the PKCS CK_RV return code
/// It also displays the text for the error
class P11ErrorException : public myid::ErrorException
{
	typedef myid::ErrorException inherited;

public:
	P11ErrorException(_In_ Localisation const& location, _In_ unsigned long int p11Error);
	P11ErrorException(_In_ Localisation const& location, _In_ unsigned long int p11Error, _In_ std::wstring const& info);

	P11ErrorException(_In_ Localisation const& location, _In_ long error, _In_ unsigned long int p11Error);
	P11ErrorException(_In_ Localisation const& location, _In_ long error, _In_ unsigned long int p11Error, _In_ std::wstring const& info);

	unsigned long int GetP11ErrorNumber() const
	{
		return m_P11Error;
	}

	static std::wstring GetPKCSErrorText(_In_ unsigned long int p11Error);

protected:
	virtual std::wstring getErrorText(void) const;

	unsigned long int m_P11Error;
};

}