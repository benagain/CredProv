#pragma once
#include "VscProvider.h"
#include "Utilities\CardLib\SCard.h"

namespace Monitor
{

/// Provides monitoring of SCardSvr, and generates a credential update once it starts
class Card
{
public:
	Card() = default;
	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;
	~Card();

	void SetupMonitor(_In_ VscProvider* provider);
	void CancelMonitor(void);

	static Card& Instance(void);

protected:
	void RunMonitorThread();

	VscProvider*		m_provider{};			///< provider to call
	std::thread			m_hMonitorThread;		///< monitor thread handle
	scard::sCardMonitor	m_CardMonitor;			///< card monitor
};

} // namespace Monitor
