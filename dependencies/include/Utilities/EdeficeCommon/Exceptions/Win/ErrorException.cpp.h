#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define NOGDI
#define NOKERNEL
#define NONLS
#define NOUSER
#define NOSERVICE
#define NOMMX
#define NOIME
#include <windows.h>
#include "../../SalFix.h"

namespace myid
{

/// No error number supplied, use GetLastError()
ErrorException::ErrorException(
	_In_ Localisation const& location,	///< localisation information
	_In_ std::wstring const& info)		///< description of the error
	: StackDump()
	, inherited(location, info)
	, m_fullReporting(true)
{
	m_errorReason = GetLastError();
}

/// Translate error number to error text
std::wstring ErrorException::GetErrorText(_In_ unsigned long error)	///< error number
{
	std::wstring rtn;
	if (error != 0)
	{
		LPWSTR MessageBuffer = NULL;
		DWORD dwBufferLength = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_IGNORE_INSERTS |
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL, // == system
			error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
			(LPWSTR)&MessageBuffer,
			0,
			NULL
			);

		if (dwBufferLength > 0)
		{
			// if a readable message exists, then output that also
			rtn = MessageBuffer;
			LocalFree(MessageBuffer);
		}
	}
	return rtn;
}

}
