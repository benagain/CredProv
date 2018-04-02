#pragma once
#include "VscProvider.h"

namespace Monitor
{

/// Provides monitoring of SCardSvr, and generates a credential update once it starts
class Service
{
public:
	Service() = default;
	Service(const Service&) = delete;
	Service& operator=(const Service&) = delete;
	~Service();

	void SetupMonitor(_In_ VscProvider* provider);
	void CancelMonitor(void);
	bool Running(void) const;

	static Service& Instance(void);

protected:
	void RunMonitorThread();
	void CloseEvent();

	VscProvider*		m_provider{};			///< provider to call
	std::thread			m_hMonitorThread;		///< monitor thread handle
	HANDLE				m_event[2]{};			///< \li 0 Cancel thread event
												///< \li 1 Scard access event
	std::atomic_bool	m_running;				///< whether SCardSvr is running
};

} // namespace Monitor
