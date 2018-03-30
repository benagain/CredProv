#pragma once

#include <string>

/** Purpose of heartbeat is for server components/services to output small files.
These files will signify that the service in question is alive. This is not a logging system - the file will never build
up a history of trace - its purpose is for an observer or tool to examine the filename, and datemodified timestamp to
determine the state of process/threads within a process.
The files created shall have the format:
ProcessName.PID.ThreadName.TID.STATE
e.g
	  CertSvr.234.Request.567.Active

where PID=ProcessID, TID=ThreadID
STATE=Active or Stopped
*/
class CHeartbeat
{
public:
	CHeartbeat();
	~CHeartbeat(void);

	bool DoHeartbeat(_In_ const std::wstring &wstrThreadName, _In_ const std::wstring &wstrContent = L"", _In_ const std::wstring &wstrState = L"Active");
private:
	bool Enabled();
	std::wstring GetProcessName();
	std::wstring GetFilePath();;
	std::wstring BuildOutputFileName(_In_ const std::wstring &wstrThreadName, _In_ const std::wstring &wstrState);

	std::wstring m_wstrProcessName;
	std::wstring m_wstrFilePath;
	ATL::CComAutoCriticalSection m_csLock;
};
