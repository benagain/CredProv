#include "stdafx.h"
#include "Data.h"
#include "Policy.h"
#include "ServiceMonitor.h"
#include "..\VscCommon\VscMiniDriverSCard.h"

namespace Data
{

/// Find out if the user is a VSC user
bool Credentials::IsVscUser(
	_In_opt_z_ LPCWSTR user)			///< user name
	const
{
	if (user && *user)
	{
		for (const auto& item : *this)
		{
			if (!item.vsc)
				continue;

			if (item.user == user)
				return true;
		}
	}

	return false;
}

/// Gets the credentials
Credentials& Credentials::Get(_In_ bool force)
{
	Credentials* items = myid::Instance<Credentials>();
	items->Load(force);

	return *items;
}

/// Loads the credentials
void Credentials::Load(_In_ bool force)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);

	if (!Monitor::Service::Instance().Running())
	{
		// in case server stops
		m_gotten = false;
		return;
	}

	if (m_gotten && !force)
		return;

	m_gotten = true;
	clear();

	bool signatureOnlyKeys = Policy::Get().AllowSignatureOnlyKeys();
	const Readers& readers = Readers::Get();

	std::list<std::thread> threads;
	for (const auto& reader : readers)
	{
		if (!reader.vsc)
			continue;

		threads.push_back(std::thread([&]
		{
			VscMD::MiniDriverSCard md;
			if (!md.Connect(reader.reader) ||
				!md.Acquire())
			{
				return;
			}

			md.LoadCertificate(signatureOnlyKeys);

			VectorOfByte certData;
			for (const auto& cert : md.m_Cert)
			{
				certData = md.ReadFile(szBASE_CSP_DIR, cert.name);
				if (!md.Success())
					continue;

				Credential data;
				if (!data.certificate(certData))
					continue;

				data.Reader::operator=(reader);
				data.container = cert.container;
				data.keySpec = cert.keySpec;

				m_dataLock.lock();
				push_back(data);
				m_dataLock.unlock();
			}
		}));
	}
	for (auto& thread : threads)
	{
		try
		{
			thread.join();
		}
		catch (...)
		{
		}
	}

	if (Policy::Get().FilterDuplicateCerts())
	{
		sort([](const Credential& l, const Credential& r) -> bool
		{
			if (l.reader != r.reader)
				return l.reader < r.reader;
			if (l.user != r.user)
				return l.user < r.user;
			if (l.certTemplate != r.certTemplate)
				return l.certTemplate < r.certTemplate;
			if (l.certVersion != r.certVersion)
				return l.certVersion < r.certVersion;
			// unique() will leave the first duplicate, so sort by latest expiry first
			return CompareFileTime(&l.certExpiry, &r.certExpiry) > 0;
		});

		unique([](const Credential& l, const Credential& r) -> bool
		{
			return (l.reader == r.reader) &&
				(l.user == r.user) &&
				(l.certTemplate == r.certTemplate) &&
				(l.certVersion == r.certVersion);
		});
	}
}

/// This logic matches how SmartCardCredentialProvider attaches credentials to SIDs
/// \note This is rather subtle
void Credentials::AddUsers(void)
{
	Users& usrs = Users::Get();

	for (auto& usr : usrs)
	{
		SetSID(usr.upn, usr.sid);
	}
	// add credentials not signed in to all user tiles
	for (auto& cred : *this)
	{
		if (cred.signedIn ||
			!cred.sid.empty())
			continue;

		for (const auto& usr : usrs)
		{
			push_back(cred);
			back().sid = usr.sid;
		}
	}
}

/// Make a copy of any card credentials that belong to a user tile
void Credentials::SetSID(_In_ const std::wstring& upn, _In_ const std::wstring& sid)
{
	for (auto& cred : *this)
	{
		if ((cred.user == upn) && cred.sid.empty())
		{
			// all original credentials that match the user
			// add credential to user tile
			push_back(cred);
			back().sid = sid;

			for (auto& cred : *this)
			{
				if (cred.user == upn)
				{
					// mark all as having a user tile
					cred.signedIn = true;
					// do not credential user details on a user tile
					if (!cred.sid.empty())
						cred.showUser = false;
				}
			}
		}
	}
}

} // namespace Authenticate
