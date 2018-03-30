#pragma once

#include <string>

//helper functions for dealing with COM extended error info
namespace eError
{
// I have found cases where (especially cross apartment etc..) the ATL Error() function does not pass on the
// error details.
inline OKBOOL SetExtendedErrorInformation(_In_ _bstr_t bstrErrorInfo)
{
	bool bSucceeded(false);
	if (bstrErrorInfo.length())
	{
		ICreateErrorInfo *pcerrinfo = NULL;
		IErrorInfo *perrinfo = NULL;
		if (SUCCEEDED(CreateErrorInfo(&pcerrinfo)))
		{
			pcerrinfo->SetDescription(bstrErrorInfo);
			if (SUCCEEDED(pcerrinfo->QueryInterface(IID_IErrorInfo, (LPVOID FAR*) &perrinfo)))
			{
				if (SUCCEEDED(SetErrorInfo(0, perrinfo)))
					bSucceeded = true;
				perrinfo->Release();
			}
			pcerrinfo->Release();
		}
	}
	return bSucceeded;
}

// use this function where there is no _com_error exception thrown (e.g. using raw COM calls or CComPtr)
// note that if a _com_error is thrown, it clears the error info, and you must use e.Description() to
// retrieve the error
inline std::wstring GetExtendedErrorInfo()
{
	std::wstring wstrDescription;
	IErrorInfo *perrorinfo = NULL;
#pragma warning(suppress: 6031)
	GetErrorInfo(0, &perrorinfo);
	BSTR bstrDescription = NULL;
	if (perrorinfo != NULL)
	{
		perrorinfo->GetDescription(&bstrDescription);
		//GUID guid;
		//perrorinfo->GetGUID(&guid);
		if (::SysStringLen(bstrDescription))
			wstrDescription = bstrDescription;

		::SysFreeString(bstrDescription);
		perrorinfo->Release();
	}
	return wstrDescription;
}

inline std::wstring GetErrorText(_In_ DWORD dwError)
{
	DWORD dwFormatFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_FROM_SYSTEM;

	//
	// Call FormatMessage() to allow for message
	//  text to be acquired from the system
	LPTSTR MessageBuffer = NULL;

	DWORD dwBufferLength = FormatMessage(dwFormatFlags,
		NULL, // == system
		dwError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
		(LPTSTR)&MessageBuffer,
		0,
		NULL
		);


	std::wstring wstrMessageBuffer;
	if (dwBufferLength)
	{
		// if a readable message exists, then output that also
		USES_CONVERSION;
		wstrMessageBuffer = T2W(MessageBuffer);
		LocalFree(MessageBuffer);
	}

	return wstrMessageBuffer;
}

}

