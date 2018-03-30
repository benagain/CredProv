/// \file MiniDriverSCard.h
/// Smart card minidriver support

#pragma once

#include "MiniDriver.h"
#include "SCard.h"

namespace md
{

/// Mini driver with support functions
class MiniDriverSCard : public MiniDriver
{
	typedef MiniDriver inherited;

public:
	MiniDriverSCard();
	~MiniDriverSCard();

	virtual bool ThrowOnError(bool bThrow = true) const;

	virtual bool Connect(const std::wstring& reader);
	virtual bool Connected(void) const;
	virtual void ReConnect(void) const;
	virtual bool Acquire(void);

	virtual bool Lock(void);
	virtual void UnLock(void);
	virtual void ForceUnlock(void);
	virtual long LockCount(void) const;

	LONG Transmit(const apdu::ApduCommand& send, apdu::ApduStatus& status) const;
	LONG Transmit(const apdu::ApduCommand& send, apdu::ApduReply& reply);
	LONG Transmit(const apdu::ApduCommandList& send, apdu::ApduStatus& reply);
	LONG Transmit(const apdu::ApduCommandList& send, apdu::ApduReply& reply);
	LONG Transmit(const apdu::ApduCommandList& send, apdu::ApduReplyList& reply);

protected:
	virtual void Unload(void);
	virtual bool ThrowError(void) const;
	virtual void InCommand(bool begin) const;

	mutable scard::sCardTransmit	m_SCard;		///< card connection
};

} // namespace md
