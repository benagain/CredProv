#include "stdafx.h"
#include "VscProvider.h"
#include "CardMonitor.h"
#include "ServiceMonitor.h"
#include "dllmain.h"
#include <LM.h>
#define SECURITY_WIN32
#include <security.h>

#pragma comment(lib, "Netapi32.lib")

VscProvider::VscProvider()
	: m_debug(L"VscProvider")
{
	_AtlModule.Lock();
#ifdef DEBUG_COM
	m_debug.Log(L"Start", myid::ToHex((ULONG_PTR)this));
#endif
	Monitor::Service::Instance().SetupMonitor(this);
	Monitor::Card::Instance().SetupMonitor(this);

	if (m_debug)
	{
		WCHAR filePath[MAX_PATH] {};
		if (GetModuleFileName(nullptr, filePath, MAX_PATH))
			m_debug.Log(L"Module", filePath);
	}
}

VscProvider::~VscProvider()
{
	Monitor::Card::Instance().CancelMonitor();
	Monitor::Service::Instance().CancelMonitor();
	ClearCredential();
#ifdef DEBUG_COM
	m_debug.Log(L"End", myid::ToHex((ULONG_PTR)this));
#endif
	_AtlModule.Unlock();
}

/// Release all credentials
/// \note the object are not deleted
void VscProvider::ClearCredential(void)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);

	try
	{
		if (!m_credential.empty())
		{
			for (auto& cred : m_credential)
			{
				if (cred == nullptr)
					continue;

				cred->Release();
			}
			m_credential.clear();
		}
	}
	catch (...)
	{
	}
}

/// Create the credentials array
void VscProvider::GetCredentials(void)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);

	if (m_needCredentials)
	{
		try
		{
			Data::Credentials& credentials = Data::Credentials::Get(true);
			if (m_cpus != CPUS_CREDUI)
			{
				credentials.AddUsers();
			}

			ClearCredential();

			size_t sz = credentials.size();
			m_credential.reserve(sz);

			for (const auto& credential : credentials)
			{
				ATL::CComObject<MyidCredential>* cred(nullptr);
				HRESULT hr = ATL::CComObject<MyidCredential>::CreateInstance(&cred);
				if (FAILED(hr))
				{
					return;
				}
				cred->AddRef();
				cred->Init((DWORD)m_credential.size(), credential, m_cpus);

				m_credential.push_back(cred);
			}
			m_needCredentials = false;
		}
		catch (myid::Exception& e)
		{
			m_debug.Log(L"GetCredentials", e.message());
		}
		catch (...)
		{
			m_debug.Log(L"GetCredentials", L"unknown exception");
		}
	}
}

/// Trigger a changed event
void VscProvider::OnCredentialsChanged(void)
{
#ifdef MYID_DEBUG
	m_debug.Log(L"OnCredentialsChanged");
#endif

	Data::Readers::Get(true);
	m_needCredentials = true;

	if (m_providerEvents)
		m_providerEvents->CredentialsChanged(m_adviseContext);
}

