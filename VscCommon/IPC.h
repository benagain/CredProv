#pragma once
#include "Debug.h"

namespace Support
{

/// Various Inter Process Communication functions
class IPC
{
public:
	explicit IPC(_In_ Support::Debug& debug);
	IPC(const IPC&) = delete;
	IPC& operator=(const IPC&) = delete;

	void StartVscService(void) const;
	std::wstring ServicePath(void) const;
	HANDLE GetEvent(_In_z_ LPCWSTR name) const;
	HANDLE CreatePipe(_In_z_ LPCWSTR name, _In_ DWORD nMaxInstances, _In_ bool overlapped) const;
	bool EnablePrivilege(_In_ HANDLE token, _In_z_ LPCWSTR privilege) const;
	DWORD LastError() const;

protected:
	Support::Debug& m_debug;		///< debug output
	mutable DWORD m_error;			///< last error
};

} // namespace Support
