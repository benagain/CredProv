#pragma once

#include "Utilities\EdeficeCommon\DebugTimer.h"
#include "Utilities\EdeficeCommon\StringList.h"

namespace Support
{

class Debug : public DebugTimer
{
public:
	Debug() = default;
	explicit Debug(_In_ const std::wstring& instance);

	void Instance(_In_ const std::wstring& instance);
	std::wstringstream& WsIns(void);

	void Log(_In_ const std::wstring& desc);
	void LogOK(_In_ const std::wstring& desc);
	void Log(_In_ const std::wstring& desc, _In_ DWORD value);
	void LogError(_In_ const std::wstring& desc, _In_ DWORD error);
	void LogLastError(_In_ const std::wstring& desc);

	void Log(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2);
	void LogOK(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2);
	void Log(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2, _In_ DWORD value);
	void LogError(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2, _In_ DWORD error);
	void LogLastError(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2);

	void LogException(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2 = L"unknown");

protected:
	std::wstring m_instance;
};

void LogEvent(_In_ int id, _In_ const myid::StringList& messages, _In_z_ const wchar_t* source = L"MyIDVscService") throw();
std::wstring ObjectName(HANDLE handle);

} // namespace Support
