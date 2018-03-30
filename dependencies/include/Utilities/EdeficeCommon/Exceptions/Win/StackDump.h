#pragma once

#include <string>
#include "../../SalFix.h"
#ifdef MYID_DEBUG
#include "Utilities\EdeficeCommon\LeanWindows.h"
#endif

#define INHERIT_STACK_DUMP myid::StackDump(),

namespace myid
{

/// Produces a stack dump
class StackDump
{
public:
	StackDump();
	explicit StackDump(_In_ const StackDump& rhs);
	virtual ~StackDump();

	StackDump& operator=(_In_ const StackDump& rhs);

	const wchar_t* GetStackTrace(void) const;
#ifdef MYID_DEBUG
	static std::wstring ResolveSymbol(_In_ DWORD64 address);
#endif
	static bool Enabled;				///< enable/disable stack dump (default true) (used by tests)

protected:
#ifdef MYID_DEBUG
	static bool ResolveSymbol(_In_ void* hProcess, _In_ DWORD64 address, _Inout_ std::wstringstream& str);
	static void Walk(_In_ HANDLE hProcess, _In_ HANDLE hThread, _In_ CONTEXT& threadContext, _Inout_ std::wstringstream& str);
	void StackTrace(void);
#endif
	std::wstring	m_stackTrace;					///< stack trace
};
}
