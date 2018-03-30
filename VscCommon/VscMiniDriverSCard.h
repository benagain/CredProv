#pragma once

#include "VscMiniDriver.h"
#include "Utilities\CardLib\SCard.h"

namespace VscMD
{

/// Mini driver with support functions
class MiniDriverSCard : public MiniDriver
{
	typedef MiniDriver inherited;

public:
	MiniDriverSCard();

	virtual bool Connect(const std::wstring& reader);
	virtual bool Connected(void) const;
	virtual bool Acquire(void);

protected:
	virtual void Unload(void);
	virtual void ProcessError(void) const;

	mutable scard::sCardTransmit	m_SCard;		///< card connection
};

} // namespace VscMD
