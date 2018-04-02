#include "stdafx.h"
#include "ServiceMonitor.h"
#include "Utilities\EdeficeCommon\ThreadName.h"

#include <winscard.h>

namespace Monitor
{

Service::~Service()
{
	CancelMonitor();
	CloseEvent();
}

void Service::SetupMonitor(_In_ VscProvider* provider)
{
	CancelMonitor();
	CloseEvent();

	m_provider = provider;

	m_event[1] = SCardAccessStartedEvent();
	if (m_event[1] == nullptr)
		return;

	if (WaitForSingleObject(m_event[1], 0) != WAIT_OBJECT_0)
	{
		m_running = false;

		m_event[0] = CreateEvent(nullptr, FALSE, FALSE, L"CancelService");

		// smart card service is not running, wait for it to start
		RunMonitorThread();
	}
	else
	{
		m_running = true;

		// smart card service is running, all OK
		SCardReleaseStartedEvent();
		m_event[1] = nullptr;
	}
}

/// Triggers thread close
void Service::CancelMonitor(void)
{
	try
	{
		m_provider = nullptr;

		if (m_event[0])
			SetEvent(m_event[0]);

		if (m_event[1])
			SCardReleaseStartedEvent();

		if (m_hMonitorThread.joinable())
			m_hMonitorThread.join();
	}
	catch (...)
	{
	}
}

/// Wait for SCardSrv start or cancel event
void Service::RunMonitorThread()
{
	m_hMonitorThread = std::thread([&]()
	{
		bool wait = true;
		while (wait)
		{
			DWORD w = WaitForMultipleObjects(2, m_event, FALSE, INFINITE);

			switch (w)
			{
			case WAIT_OBJECT_0:
				// cancel thread event
				wait = false;
				break;

			case WAIT_OBJECT_0 + 1:
				// service is now running event
				m_running = true;
				if (m_provider)
					m_provider->OnCredentialsChanged();
				wait = false;
				break;

			case WAIT_FAILED:
				wait = false;
				break;
			}
		}

		CloseEvent();
	});
	myid::SetThreadName(m_hMonitorThread, "Service monitor");
}

void Service::CloseEvent()
{
	for (auto& h : m_event)
	{
		HANDLE handle = InterlockedExchangePointer(&h, nullptr);
		if (handle)
			CloseHandle(handle);
	}
}

/// Get state of smart card service
bool Service::Running(void) const
{
	return m_running;
}

/// atomic get instance
Service& Service::Instance(void)
{
	return *myid::Instance<Service>();
}

} // namespace Monitor
