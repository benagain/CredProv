#pragma once

#include "APDUVector.h"
#include "ReaderStatus.h"
#include "Utilities/EdeficeCommon/Status.h"

namespace scard
{

class Reader_Status : public myid::Status<ReaderStatus, READER_SUCCESS>
{
	typedef myid::Status<ReaderStatus, READER_SUCCESS> inherited;
public:
	Reader_Status() {}
	explicit Reader_Status(_In_ S status) : inherited(status) {}
	Reader_Status& operator=(S rhs) { _status = rhs; return *this; }
	std::wstring text() const;

	static std::wstring Error(_In_ const wchar_t* error, _In_ const ReaderStatus status);

protected:
	static std::wstring txt(_In_ const ReaderStatus status);
};

class ApduTransmit
{
public:
	virtual bool IsConnected(void) const = 0;
	virtual ReaderStatus Lock(_In_ bool wait = true) = 0;
	virtual ReaderStatus UnLock(_In_ CardDisposition disp = LEAVE_CARD) = 0;
	virtual bool Locked(void) const = 0;

	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommand& send, _Out_ apdu::ApduStatus& status);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommand& send, _Out_ apdu::ApduReply& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduStatus& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduReply& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduReplyList& reply);

protected:
	virtual ReaderStatus MoreData(_In_ const apdu::ApduCommand& send, _Inout_ apdu::ApduReply& reply);
	virtual ReaderStatus TransmitSingle(_In_ const apdu::ApduCommand& send, _Out_ apdu::ApduReply& reply) const;

	virtual bool Simplex(void) const = 0;
	virtual ReaderStatus TransmitRaw(_In_ const myid::VectorOfByte& send, _In_ unsigned long sendLength, _Out_ myid::VectorOfByte& reply, _Out_ unsigned long* le) const = 0;
	virtual bool TraceApdu(void) const = 0;
	virtual void TraceApdu(_In_ const std::wstring& text) const = 0;
};

} // namespace scard
