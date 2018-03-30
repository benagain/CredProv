#include "stdafx.h"
#include "Debug.h"
#include "Msg\EventLog.h"
#include "Utilities\EdeficeCommon\Conversions\HexBinConversion.h"
#include "Utilities\EdeficeCommon\Exceptions\ErrorException.h"

namespace Support
{

Debug::Debug(_In_ const std::wstring& instance)
	: m_instance(instance)
{
	m_nLevelFlag = LevelFlag::ENABLED | LevelFlag::TIMER;

	if (!m_instance.empty())
		m_instance.push_back(' ');
}

void Debug::Instance(_In_ const std::wstring& instance)
{
	m_instance = instance;
	if (!m_instance.empty())
		m_instance.push_back(' ');
}

std::wstringstream& Debug::WsIns(void)
{
	std::wstringstream& stream = GetWStream();
	stream << m_instance;
	return stream;
}

void Debug::Log(_In_ const std::wstring& desc)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc;
		Write(w);
	}
}

void Debug::LogOK(_In_ const std::wstring& desc)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc << L" OK";
		Write(w);
	}
}

void Debug::Log(_In_ const std::wstring& desc, _In_ DWORD value)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc << L" 0x" << myid::ToHex(value);
		Write(w);
	}
}

void Debug::LogError(_In_ const std::wstring& desc, _In_ DWORD error)
{
	if (operator bool() && (error != 0))
	{
		std::wstring w;
		w << m_instance << desc << L" 0x" << myid::ToHex(error) << L" " << myid::ErrorException::GetErrorText(error);
		Write(w);
	}
}

void Debug::LogLastError(_In_ const std::wstring& desc)
{
	LogError(desc, GetLastError());
}

void Debug::Log(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc1 << L" " << desc2;
		Write(w);
	}
}

void Debug::LogOK(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc1 << L" " << desc2 << L" OK";
		Write(w);
	}
}

void Debug::Log(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2, _In_ DWORD value)
{
	if (operator bool())
	{
		std::wstring w;
		w << m_instance << desc1 << L" " << desc2 << L" 0x" << myid::ToHex(value);
		Write(w);
	}
}

void Debug::LogError(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2, _In_ DWORD error)
{
	if (operator bool() && (error != 0))
	{
		std::wstring w;
		w << m_instance << desc1 << L" " << desc2 << L" 0x" << myid::ToHex(error) << L" " << myid::ErrorException::GetErrorText(error);
		Write(w);
	}
}

void Debug::LogLastError(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2)
{
	LogError(desc1, desc2, GetLastError());
}

void Debug::LogException(_In_ const std::wstring& desc1, _In_ const std::wstring& desc2)
{
	Support::LogEvent(MYID_EXCEPTION, myid::StringList{m_instance, desc1, desc2});
	Log(desc1, desc2 + L"exception");
}

//===================================================================================================================
//===================================================================================================================

void LogEvent(_In_ int id, _In_ const myid::StringList& messages, _In_z_ const wchar_t* source) throw()
{
	HANDLE hEventSource = RegisterEventSource(nullptr, source);
	if (hEventSource != nullptr)
	{
		std::vector<LPCWSTR> msg;
		msg.reserve(messages.size());
		for (const auto& m : messages)
		{
			msg.push_back(m.c_str());
		}

		WORD type;
		switch ((id >> 30) & 0x3)
		{
		case STATUS_SEVERITY_SUCCESS:
		default:
			type = EVENTLOG_SUCCESS;
			break;
		case STATUS_SEVERITY_INFORMATIONAL:
			type = EVENTLOG_INFORMATION_TYPE;
			break;
		case STATUS_SEVERITY_WARNING:
			type = EVENTLOG_WARNING_TYPE;
			break;
		case STATUS_SEVERITY_ERROR:
			type = EVENTLOG_ERROR_TYPE;
			break;
		}

		ReportEvent(hEventSource, type, 0, id, nullptr, (WORD)messages.size(), 0, (messages.empty() ? nullptr : &msg.front()), nullptr);
		DeregisterEventSource(hEventSource);
	}
}

std::wstring ObjectName(HANDLE handle)
{
	std::wstring name;
	DWORD len(0);
	GetUserObjectInformation(handle, UOI_NAME, nullptr, 0, &len);
	name.resize((len / 2) - 1);
	if (!GetUserObjectInformation(handle, UOI_NAME, (PVOID)name.c_str(), len, &len))
	{
		name.clear();
	}

	return name;
}

} // namespace Support
