/// \file SCards.h
/// Smart card readers interface

#pragma once

#include "SCard.h"
#include <list>
#include <boost/shared_ptr.hpp>

namespace scard
{

typedef boost::shared_ptr<sCardTransmit> sCardTransmitPtr;	/// smart pointer to sCardTransmit

/// Reader monitor interface
class Readers : private boost::noncopyable
{
public:
	static SCARDCONTEXT GlobalContext();

	// reader handling
	static scard::sCardTransmitPtr GetSCard(_In_ const std::wstring& reader, _In_ bool share = false);
	static StringList GetReaders(_In_ bool force = false);
	static std::wstring SelectReader(_In_ const std::wstring& title, _In_ const std::wstring& search, _Inout_opt_ std::wstring* name = NULL, _In_opt_ HWND owner = NULL);
	static void UnlockAll(void);
	static void UpdateStatus(void);

	// card monitor
	static void SetupMonitor(void);
	static void CancelMonitor(void);
	static void SuspendMonitor(_In_ bool suspend);
	static HANDLE GetMonitorEvent(_In_ sCardMonitor::MonitorResult state);
	static void ServiceError(_In_ LONG error);
	static const std::wstring& LastCardReaderEvent(void);
};

} // namespace scard
