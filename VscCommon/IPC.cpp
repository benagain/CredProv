#include "stdafx.h"
#include <cguid.h>
#include <aclapi.h>
#include <sddl.h>
#include <Shlwapi.h>

#include "IPC.h"
#include "Utilities\EdeficeCommon\GlobalOperator.h"
#include "Utilities\EdeficeCommon\VectorOfByte.h"
#include "VscPipe.h"

namespace Support
{

IPC::IPC(_In_ Support::Debug& debug)
	: m_debug(debug)
	, m_error(ERROR_SUCCESS)
{}

/// Start the MyIDVscService service
void IPC::StartVscService(void) const
{
	SC_HANDLE hSCM = OpenSCManager(nullptr, SERVICES_ACTIVE_DATABASE, GENERIC_EXECUTE);
	if (hSCM != nullptr)
	{
		SC_HANDLE hService = OpenService(hSCM, L"MyIDVscService", SERVICE_START | SERVICE_QUERY_STATUS);
		if (hService != nullptr)
		{
			SERVICE_STATUS status;
			if (!QueryServiceStatus(hService, &status))
			{
				m_error = GetLastError();
				m_debug.LogError(L"QueryServiceStatus", m_error);
			}
			else if (status.dwCurrentState == SERVICE_STOPPED)
			{
				m_debug.Log(L"Starting service");
				if (!StartService(hService, 0, nullptr))
				{
					m_error = GetLastError();
					m_debug.LogError(L"StartService", m_error);
				}
			}
			CloseServiceHandle(hService);
		}

		CloseServiceHandle(hSCM);
	}
}

/// Get the path of the MyIDVscService service
std::wstring IPC::ServicePath(void) const
{
	static std::wstring path;

	if (path.empty())
	{
		SC_HANDLE hSCM = OpenSCManager(nullptr, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT);
		if (hSCM == nullptr)
		{
			m_error = GetLastError();
			m_debug.LogError(L"OpenSCManager", m_error);
		}
		else
		{
			SC_HANDLE hService = OpenService(hSCM, L"MyIDVscService", SERVICE_QUERY_CONFIG);
			if (hService == nullptr)
			{
				m_error = GetLastError();
				m_debug.LogError(L"OpenService", m_error);
			}
			else
			{
				DWORD bytesNeeded(0);
				if (!QueryServiceConfig(hService, nullptr, 0, &bytesNeeded) && (GetLastError() != ERROR_INSUFFICIENT_BUFFER))
				{
					m_error = GetLastError();
					m_debug.LogError(L"QueryServiceConfig", m_error);
				}
				else
				{
					VectorOfByte d(bytesNeeded);
					LPQUERY_SERVICE_CONFIG config = (LPQUERY_SERVICE_CONFIG)d.ptr();
					if (!QueryServiceConfig(hService, config, bytesNeeded, &bytesNeeded))
					{
						m_error = GetLastError();
						m_debug.LogError(L"QueryServiceConfig", m_error);
					}
					else
					{
						m_debug.Log(L"Service path", config->lpBinaryPathName);
						WCHAR name[MAX_PATH];
						wcscpy_s(name, config->lpBinaryPathName + 1);		// skip initial "
						PathRemoveFileSpec(name);
						path = name;
					}
				}
				CloseServiceHandle(hService);
			}

			CloseServiceHandle(hSCM);
		}
	}

	return path;
}

/// Get an event, create if required
HANDLE IPC::GetEvent(_In_z_ LPCWSTR name)				///< event name
const
{
	HANDLE handle = ::OpenEvent(EVENT_ALL_ACCESS, FALSE, name);
	if (handle == nullptr)
	{
		if (GetLastError() != ERROR_FILE_NOT_FOUND)
		{
			m_error = GetLastError();
			m_debug.LogError(name, L"OpenEvent", m_error);
		}

		SECURITY_ATTRIBUTES sa{};
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.bInheritHandle = FALSE;

		// Add LOCAL SYSTEM and LOCAL SERVICE to discretionary access control
		const wchar_t* des = L"D:(A;;GA;;;AU)(A;;GA;;;CO)(A;;GA;;;SY)(A;;GA;;;LS)";
		if (!ConvertStringSecurityDescriptorToSecurityDescriptor(des, SDDL_REVISION_1, &sa.lpSecurityDescriptor, nullptr))
		{
			m_error = GetLastError();
			m_debug.LogError(name, L"SecurityDescriptor", m_error);
		}
		else
		{
			handle = CreateEventEx(&sa, name, CREATE_EVENT_MANUAL_RESET, EVENT_ALL_ACCESS);
			if (handle == nullptr)
			{
				m_error = GetLastError();
				m_debug.LogError(name, L"CreateEventEx", m_error);
			}
			LocalFree(sa.lpSecurityDescriptor);
		}
	}

	return handle;
}

/// Create a named pipe. Permissions are also set
HANDLE IPC::CreatePipe(
	_In_z_ LPCWSTR name,			///< pipe name
	_In_ DWORD nMaxInstances,		///< max instances, usually 1 or PIPE_UNLIMITED_INSTANCES
	_In_ bool overlapped)			///< is overlapped
const
{
	DWORD dwOpenMode = PIPE_ACCESS_DUPLEX | WRITE_DAC;
	if (nMaxInstances == 1)
		dwOpenMode |= FILE_FLAG_FIRST_PIPE_INSTANCE;
	if (overlapped)
		dwOpenMode |= FILE_FLAG_OVERLAPPED;
	DWORD dwPipeMode = PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT | PIPE_REJECT_REMOTE_CLIENTS;

	HANDLE handle(INVALID_HANDLE_VALUE);
	HANDLE pipe = CreateNamedPipe(name, dwOpenMode, dwPipeMode, nMaxInstances, Pipe::SIZE, Pipe::SIZE, 5000, nullptr);
	if (pipe == INVALID_HANDLE_VALUE)
	{
		m_error = GetLastError();
		m_debug.LogError(name, L"CreateNamedPipe", m_error);
	}
	else
	{
		PACL oldDacl(nullptr);
		DWORD ret = GetSecurityInfo(pipe, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, nullptr, nullptr, &oldDacl, nullptr, nullptr);
		if (ret != ERROR_SUCCESS)
		{
			m_error = ret;
			m_debug.LogError(name, L"GetSecurityInfo", ret);
		}
		else
		{
			// Add LOCAL SERVICE and LOCAL SYSTEM to pipe permissions
			DWORD sidSizeLS(SECURITY_MAX_SID_SIZE);
			DWORD sidSizeSY(SECURITY_MAX_SID_SIZE);
			PSID sidLS = LocalAlloc(LMEM_FIXED, sidSizeLS);
			PSID sidSY = LocalAlloc(LMEM_FIXED, sidSizeSY);
			if (!CreateWellKnownSid(WELL_KNOWN_SID_TYPE::WinLocalServiceSid, NULL, sidLS, &sidSizeLS) ||
				!CreateWellKnownSid(WELL_KNOWN_SID_TYPE::WinLocalSystemSid, NULL, sidSY, &sidSizeSY) )
			{
				m_error = GetLastError();
				m_debug.LogError(name, L"CreateWellKnownSid", m_error);
			}
			else
			{
				EXPLICIT_ACCESS ea[2]{};
				ea[0].grfAccessPermissions = GENERIC_ALL | SYNCHRONIZE | FILE_CREATE_PIPE_INSTANCE;
				ea[0].grfAccessMode = SET_ACCESS;
				ea[0].grfInheritance = NO_INHERITANCE;
				ea[0].Trustee.TrusteeForm = TRUSTEE_IS_SID;
				ea[0].Trustee.TrusteeType = TRUSTEE_IS_USER;
				ea[0].Trustee.ptstrName = (LPWSTR)sidLS;

				ea[1].grfAccessPermissions = GENERIC_ALL| SYNCHRONIZE | FILE_CREATE_PIPE_INSTANCE;
				ea[1].grfAccessMode = SET_ACCESS;
				ea[1].grfInheritance = NO_INHERITANCE;
				ea[1].Trustee.TrusteeForm = TRUSTEE_IS_SID;
				ea[1].Trustee.TrusteeType = TRUSTEE_IS_USER;
				ea[1].Trustee.ptstrName = (LPWSTR)sidSY;

				PACL dacl(nullptr);
				ret = SetEntriesInAcl(2, ea, oldDacl, &dacl);
				if (ret != ERROR_SUCCESS)
				{
					m_error = ret;
					m_debug.LogError(name, L"SetEntriesInAcl", ret);
				}
				else
				{
					ret = SetSecurityInfo(pipe, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, nullptr, nullptr, dacl, nullptr);
					if (ret != ERROR_SUCCESS)
					{
						m_error = ret;
						m_debug.LogError(name, L"SetSecurityInfo", ret);
					}
					else
					{
						handle = pipe;
					}
					LocalFree(dacl);
				}
			}
			LocalFree(sidLS);
			LocalFree(sidSY);
		}
	}

	return handle;
}

/// Enable a privilege
bool IPC::EnablePrivilege(
	_In_ HANDLE token,				///< token handle to set privilege on
	_In_z_ LPCWSTR privilege)		///< privilege name
const
{
	TOKEN_PRIVILEGES	tp{};
	LUID				luid{};

	if (!LookupPrivilegeValue(nullptr, privilege, &luid))
	{
		m_error = GetLastError();
		m_debug.LogError(privilege, L"LookupPrivilegeValue", m_error);
		return false;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(token, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), nullptr, nullptr))
	{
		m_error = GetLastError();
		m_debug.LogError(privilege, L"AdjustTokenPrivileges", m_error);
		return false;
	}

	return true;
}

/// Return the last error code
DWORD IPC::LastError() const
{
	return m_error;
}

} // namespace Support
