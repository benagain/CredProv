#include "stdafx.h"
#include "CardMonitor.h"
#include "Utilities\EdeficeCommon\ThreadName.h"

namespace Monitor
{

Card::~Card()
{
	CancelMonitor();
}

void Card::SetupMonitor(_In_ VscProvider* provider)
{
	CancelMonitor();

	m_provider = provider;

	m_CardMonitor.SetupMonitor();

	RunMonitorThread();
}

/// Triggers thread close
void Card::CancelMonitor(void)
{
	try
	{
		m_provider = nullptr;

		m_CardMonitor.CancelMonitor();

		if (m_hMonitorThread.joinable())
			m_hMonitorThread.join();
	}
	catch (...)
	{
	}
}

/// Wait for reader or card state changes
void Card::RunMonitorThread()
{
	m_hMonitorThread = std::thread([&]()
	{
		bool wait = true;
		while (wait)
		{
			scard::sCardMonitor::MonitorData result = m_CardMonitor.Monitor();

			switch (result.result)
			{
			case scard::sCardMonitor::TERMINATED:
				wait = false;
				break;
			case scard::sCardMonitor::READER_CHANGE:
			case scard::sCardMonitor::CARD_INSERTED:
			case scard::sCardMonitor::CARD_REMOVED:
				if (m_provider)
					m_provider->OnCredentialsChanged();
				break;
			}
		}
	});
	myid::SetThreadName(m_hMonitorThread, "Card monitor");
}

/// atomic get instance
Card& Card::Instance(void)
{
	return *myid::Instance<Card>();
}

} // namespace Monitor
