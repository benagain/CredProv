#pragma once

#include "LocalisedException.h"


namespace myid
{
/// This exception takes an HRESULT, or if not provided, it gets the error code from GetLastError().
/// It also displays the text for the error
class ErrorException : public myid::LocalisedException
{
	typedef myid::LocalisedException inherited;

public:
	ErrorException(_In_ unsigned long reason);
	ErrorException(_In_ unsigned long reason, _In_ std::wstring const& info);
	ErrorException(_In_ long reason);
	ErrorException(_In_ long reason, _In_ std::wstring const& info);

	ErrorException(_In_ myid::Localisation const& location, _In_ unsigned long reason);
	ErrorException(_In_ myid::Localisation const& location, _In_ unsigned long reason, _In_ std::wstring const& info);
	ErrorException(_In_ myid::Localisation const& location, _In_ long reason);
	ErrorException(_In_ myid::Localisation const& location, _In_ long reason, _In_ std::wstring const& info);

#ifndef MOBILE
	ErrorException(_In_ myid::Localisation const& location, _In_ std::wstring const& reason);
#endif

	virtual ~ErrorException() throw();

	virtual unsigned long getErrorNumber(void) const;
	bool FullReporting(void) const;

	static std::wstring GetErrorText(_In_ unsigned long error);
	static std::wstring GetErrorText(_In_ long error);

protected:
	struct errorItem
	{
		long m_errorNum;					///< error number
		const wchar_t* m_errorText;			///< error text
	};

	unsigned long  m_errorReason;			///< error code, usually an HRESULT
	bool m_fullReporting;					///< simple or full reporting

	virtual std::wstring buildErrorMessage() const;
	virtual std::wstring getErrorText(void) const;
	virtual std::wstring formatErrorNumber(void) const;
	std::wstring lookupErrorText(_In_ const errorItem*) const;
};

}
