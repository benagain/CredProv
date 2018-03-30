#pragma once
#if (_MSC_VER >= 1700)
#include <thread>
#endif

// This sets the thread name in the Visual Studio thread window
//
// Usage: SetThreadName (-1, "MainThread");
//
// Taken from MSDN

namespace myid
{

void SetThreadName(_In_ DWORD threadID, _In_z_ const char* name);
void SetThreadName(_In_opt_ HANDLE threadHandle, _In_z_ const char* name);
#if (_MSC_VER >= 1700)
void SetThreadName(_In_ std::thread& _thread, _In_z_ const char* name);
#endif

} // namespace myid
