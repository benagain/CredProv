#pragma once

#include "Debug.h"
#include <list>

/// Obtains high precision timing events and reports to the standard debug output
class DebugTimer : public CDebug
{
	typedef CDebug inherited;

public:
	DebugTimer();
	explicit DebugTimer(_In_opt_z_ const char* methodName);
	explicit DebugTimer(_In_ unsigned int decimals);
	explicit DebugTimer(_In_ ComponentName const & name);

	void Resolution(_In_ unsigned int decimals);
	void Start(_In_opt_z_ const wchar_t* description = NULL);
	void End(_In_opt_z_ const wchar_t* description = NULL);
	void Mark(_In_opt_z_ const wchar_t* description = NULL);
	void Report(_In_ bool delta = true, _In_ bool description = true);

protected:
	void Setup(void);
	std::wstring Value(_In_ __int64 v) const;
	class timed
	{
	public:
		timed(__int64 time, const std::wstring& desc);

		__int64			m_Time;		///< time of event
		std::wstring	m_Desc;		///< description of event
	};
	typedef std::list<timed> timedList;

	bool		m_available;		///< feature is available
	bool		m_running;			///< timer is running
	long		m_resolution;		///< report resolution
	__int64		m_freq;				///< frequency
	timedList	m_event;			///< timer events
};

class DebugTimerConsole : public DebugTimer
{
	typedef DebugTimer inherited;

public:
	DebugTimerConsole();
	explicit DebugTimerConsole(_In_ unsigned int decimals);

protected:
	void timerSetup();
};
