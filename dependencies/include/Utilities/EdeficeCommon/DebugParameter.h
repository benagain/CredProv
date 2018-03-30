#pragma once

#include "Debug.h"
#include "StringList.h"

/// Debug class with support for tracing function parameters
class DebugParameter : public CDebug
{
	typedef CDebug inherited;

public:
	explicit DebugParameter(_In_z_ const char* MethodName);

	void AddParameter(_In_z_ const wchar_t* Name, _In_ int Value);
	void AddParameter(_In_z_ const wchar_t* Name, _In_ unsigned long Value);
	void AddParameter(_In_z_ const wchar_t* Name, _In_opt_z_ const char* Value);
	void AddParameter(_In_z_ const wchar_t* Name, _In_ const std::wstring& Value);

	void AddOutput(_In_z_ const wchar_t* Name, _In_ bool Value);
	void AddOutput(_In_z_ const wchar_t* Name, _In_ int Value);
	void AddOutput(_In_z_ const wchar_t* Name, _In_ unsigned long Value);
	void AddOutput(_In_z_ const wchar_t* Name, _In_ const std::wstring& Value);

	void AddReturn(_In_ unsigned long Value);

#ifndef MOBILE
	void AddParameter(_In_z_ const wchar_t* Name, _In_ const BSTR Value, _In_ bool Sensitive = false);
	void AddParameter(_In_z_ const wchar_t* Name, _In_ const VARIANT_BOOL& Value);
	void AddParameterXML(_In_z_ const wchar_t* Name, _In_ const BSTR Value, _In_ const StringList& SensitiveNodes);
	void AddOutput(_In_z_ const wchar_t* Name, _In_ const BSTR Value, _In_ bool Sensitive = false);
	void AddOutput(_In_z_ const wchar_t* Name, _In_ const VARIANT_BOOL& Value);
	void AddOutputXML(_In_z_ const wchar_t* Name, _In_ const BSTR Value, _In_ const StringList& SensitiveNodes);
#endif

protected:
	void RemoveSensitiveNodes(_Inout_ std::wstring& XML, _In_ const StringList& SensitiveNodes);
};




