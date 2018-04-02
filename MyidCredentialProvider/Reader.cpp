#include "stdafx.h"
#include "Data.h"
#include "ServiceMonitor.h"
#include "Utilities\CardLib\SCard.h"
#include "..\VscCommon\VscApi.h"
#include "..\VscCommon\ValidAtr.h"

namespace Data
{

//====================================================================================================================================

void Reader::clear()
{
	reader.clear();
	card.clear();
	ipt = false;
	vsc = false;
}

//====================================================================================================================================

Readers& Readers::Get(_In_ bool force)
{
	Readers* items = myid::Instance<Readers>();
	items->Load(force);

	return *items;
}


/// Loads the readers
void Readers::Load(_In_ bool force)
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

	scard::sCardConnect sc;
	sc.ThrowOnError(false);
	StringList allReaders = sc.Readers();

	Reader item;
	for (const auto& reader : allReaders)
	{
		if (sc.Connect(reader) != SCARD_S_SUCCESS)
			continue;

		Process::VscType type = ValidAtr::Type(sc.ATR());
		item.reader = reader;
		item.card = sc.CardName()[0];
		item.ipt = (type == Process::VscType::IPT) || (type == Process::VscType::ITL);
		item.vsc = type != Process::VscType::Undefined;
		push_back(item);
	}
	sc.DisConnect();
}

/// Test a reader name
bool Readers::IsVscReader(_In_z_ LPCWSTR reader) const
{
	for (const auto& item : *this)
	{
		if (item.reader == reader)
			return item.vsc;
	}
	return false;
}

/// Test a reader name for an IPT reader
bool Readers::IsIptReader(_In_z_ LPCWSTR reader) const
{
	for (const auto& item : *this)
	{
		if (item.reader == reader)
			return item.ipt;
	}
	return false;
}

//====================================================================================================================================

Users& Users::Get(void)
{
	return *myid::Instance<Users>();
}

} // namespace Data
