#include "stdafx.h"
#include "VscMiniDriverSCard.h"

namespace VscMD
{

MiniDriverSCard::MiniDriverSCard()
{
	m_SCard.ThrowOnError(false);
}

/// Connect mini driver
bool MiniDriverSCard::Connect(const std::wstring& reader)		///< reader to attach to
{
	Unload();

	if (m_SCard.CondConnect(reader) != SCARD_S_SUCCESS)
		return false;

	const StringList& names = m_SCard.MiniDriver();
	if (names.empty() || names[0].empty())
		return false;

	MiniDriverName(names[0]);

	return true;
}

/// Determine if connected
bool MiniDriverSCard::Connected(void) const
{
	return m_SCard.Connected() && !m_MiniDriver.empty();
}

/// Main connection method
bool MiniDriverSCard::Acquire(void)
{
	if (!Connected())
		return false;

	ATR(m_SCard.ATR());
	const StringList& names = m_SCard.CardName();
	if (!names.empty())
		CardName(names[0]);
	if (!Load(m_SCard.Context(), m_SCard.Handle()))
		return false;

	return true;
}

/// Also unlock any transactions
void MiniDriverSCard::Unload(void)
{
	inherited::Unload();

	// unlock and force disconnect
	m_SCard.DisConnect();
}

/// Determine whether to throw an error
/// \return true if a throw is required
void MiniDriverSCard::ProcessError(void) const
{
	switch (m_rc)
	{
	case SCARD_W_RESET_CARD:
	case SCARD_W_REMOVED_CARD:
	case ERROR_INVALID_HANDLE:
	case SCARD_E_INVALID_HANDLE:
		m_SCard.AutoReConnect((LONG*)&m_rc);
		break;
	}

	inherited::ProcessError();
}

} // namespace VscMD
