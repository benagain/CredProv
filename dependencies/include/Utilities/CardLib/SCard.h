/// \file SCard.h
/// Smart card interface

#pragma once

#pragma warning( push )
#pragma warning( disable : 4201 )
#include <winscard.h>
#pragma warning( pop )

#include "ApduTransmit.h"
#include "ATR.h"
#if defined(MYID_DEBUG) && !defined(MOBILE)
#define DEBUG_SCARD
#endif
#if defined(DEBUG_SCARD)
#include "Utilities\EdeficeCommon\DebugTimer.h"
#endif
#include "Utilities\EdeficeCommon\StringList.h"
#include <boost/noncopyable.hpp>

/// Smart card interface
namespace scard
{

/// Smart card root class, does context handling
class sCardRoot
{
public:
	sCardRoot();
	virtual ~sCardRoot();

	size_t NumReaders(void);
	StringList Readers(void);
	OKBOOL OpenContext(void);
	void CloseContext(void);
	void OpenContextScope(DWORD scope);
	OKBOOL UseContext(_In_ SCARDCONTEXT context);
	SCARDCONTEXT Context(void);
	OKBOOL ContextValid(void) const;
	virtual LONG DisConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD);

	bool ThrowOnError(_In_ bool bThrow = true);
	bool ThrowOnError(void) const;
	static std::wstring SCardError(_In_z_ const wchar_t* error, _In_ LONG lReturn);
	std::wstring ErrorText(_In_z_ const wchar_t* error);
	LONG LastError(void) const;
	OKBOOL Success(void) const;

	std::wstring CSP(_In_ const std::wstring& name);
	std::wstring Primary(_In_ const std::wstring& name);
	std::wstring MiniDriver(_In_ const std::wstring& name);
	std::wstring KSP(_In_ const std::wstring& name);
	std::wstring DeviceInstanceId(_In_ const std::wstring& reader);
	StringList ReadersWithDeviceInstanceId(_In_ const std::wstring& id);
	VectorOfByte ReaderIcon(_In_ const std::wstring& reader);

protected:
	void FreeMemory(_Inout_opt_ LPWSTR& pvMem) const;
	void FreeMemory(_Inout_opt_ LPBYTE& pvMem) const;
	LONG HandleError(_In_ LONG lReturn, _In_z_ const wchar_t* message = nullptr) const;
	OKBOOL HandleError(_In_z_ const wchar_t* message = nullptr) const;
	std::wstring Provider(_In_ const std::wstring& name, _In_ DWORD provider);

	static OKBOOL DynamicFunction(_Inout_ void** func, _In_z_ const char* name);
	static HMODULE Winscard(void);

	mutable LONG	m_lReturn;			///< last return code
	bool			m_globalContext;	///< whether context is the global one
	SCARDCONTEXT	m_hSC;				///< context handle
	DWORD			m_scope;			///< establish context scope
	bool			m_Throw;			///< throw on error
#ifdef DEBUG_SCARD
	mutable DebugTimer m_debug;			///< debug output
#endif

private:
	typedef LONG(WINAPI *fSCardGetReaderDeviceInstanceId)(SCARDCONTEXT hContext, LPCWSTR szReaderName, LPWSTR szDeviceInstanceId, LPDWORD cchDeviceInstanceId);
	typedef LONG(WINAPI *fSCardListReadersWithDeviceInstanceId)(SCARDCONTEXT hContext, LPCWSTR szDeviceInstanceId, LPWSTR mszReaders, LPDWORD pcchReaders);
	typedef LONG(WINAPI *fSCardGetReaderIcon)(SCARDCONTEXT hContext, LPCWSTR szReaderName, LPBYTE pbIcon, LPDWORD pcbIcon);

	static HMODULE			m_Winscard;			///< card module handle
	static fSCardGetReaderDeviceInstanceId m_fSCardGetReaderDeviceInstanceId;
	static fSCardListReadersWithDeviceInstanceId m_fSCardListReadersWithDeviceInstanceId;
	static fSCardGetReaderIcon m_fSCardGetReaderIcon;
};

/// Smart card connection handling
class sCardConnect : public sCardRoot
{
	typedef sCardRoot inherited;

public:
	sCardConnect();
	~sCardConnect();

	LONG UseHandle(_In_ SCARDHANDLE handle);
	LONG Connect(_In_ const std::wstring& reader, _In_ DWORD shareMode = SCARD_SHARE_SHARED, _In_ DWORD protocol = SCARD_PROTOCOL_Tx, _In_ bool wait = true);
	LONG CondConnect(_In_ const std::wstring& reader, _In_ DWORD shareMode = SCARD_SHARE_SHARED, _In_ DWORD protocol = SCARD_PROTOCOL_Tx, _In_ bool wait = false);
	LONG DirectConnect(_In_ const std::wstring& reader, _In_ bool wait = true);
	LONG TryConnect(_In_ const std::wstring& reader);
	virtual LONG ReConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD, _In_ bool wait = true);
	virtual bool Connected(void) const;
	virtual LONG DisConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD);
	void AutoReConnect(_Out_opt_ LONG* lReturn = nullptr);
	void SetAutoReConnect(_In_ bool _auto, _In_ DWORD disposition = SCARD_LEAVE_CARD);

	SCARDHANDLE Handle(void) const;
	bool Status(void);
	VectorOfByte ATR(void);
	std::wstring Reader(void) const;
	StringList CSP(void);
	StringList Primary(void);
	StringList MiniDriver(void);
	StringList KSP(void);
	StringList CardName(void);
	bool ExtendedApdu(void);

	DWORD ShareMode(void) const;
	DWORD RequestProtocol(void) const;
	DWORD ActiveProtocol(void) const;
	DWORD Disposition(void) const;

	bool Control(_In_ DWORD controlCode, _In_ const VectorOfByte& in, _Out_ VectorOfByte& out, _In_ DWORD outSize);
	bool GetAttrib(_In_ DWORD attrId, _Out_ VectorOfByte& out);
	bool SetAttrib(_In_ DWORD attrId, _In_ const VectorOfByte& in);

protected:
	LONG WaitTry(_In_ LPTHREAD_START_ROUTINE lpStartAddress) const;
	static DWORD __stdcall TryConnectThread(void* lpParam);
	static DWORD __stdcall TryReConnectThread(void* lpParam);

	std::wstring	m_Reader;			///< reader to which the card is attached
	SCARDHANDLE		m_hCardHandle;		///< card handle
	bool			m_globalHandle;		///< whether handle is supplied
	bool			m_Connected;		///< if connected
	DWORD			m_ShareMode;		///< connect share mode
	DWORD			m_RequestProtocol;	///< requested protocol
	DWORD			m_ActiveProtocol;	///< connected protocol
	DWORD			m_Disposition;		///< last disposition
	bool			m_Auto;				///< auto reconnect following SCARD_W_RESET_CARD
	DWORD			m_AutoDisposition;	///< auto reconnect disposition
	scard::ATR		m_atr;				///< ATR
	bool			m_ExtendedApdu;		///< supports extended APDUs
};

/// Handle sending and receiving data to and from a smart card
class sCardTransmit : public sCardConnect, public ApduTransmit
{
	typedef sCardConnect inherited;

public:
	sCardTransmit();
	~sCardTransmit();

	virtual bool IsConnected(void) const;
	virtual ReaderStatus Lock(_In_ bool wait = true);
	virtual ReaderStatus UnLock(_In_ CardDisposition disposition = LEAVE_CARD);
	ReaderStatus ForceUnlock(_In_ CardDisposition disposition = LEAVE_CARD);
	virtual bool Locked(void) const;
	bool TestLock(void) const;
	long LockCount(void) const;
	void LockRefresh(void) const;
	void Transmitting(_In_ bool transmitting) const;

	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommand& send, _Out_ apdu::ApduStatus& status);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommand& send, _Out_ apdu::ApduReply& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduStatus& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduReply& reply);
	virtual ReaderStatus Transmit(_In_ const apdu::ApduCommandList& send, _Out_ apdu::ApduReplyList& reply);

	LONG TransmitCount(_Out_ DWORD* count);
	ReaderStatus UID(_Out_ myid::VectorOfByte& uid);

	virtual LONG ReConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD, _In_ bool wait = true);
	virtual LONG DisConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD);

protected:
	static DWORD __stdcall TryLockThread(void* lpParam);
	ReaderStatus InternalUnLock(_In_ CardDisposition disposition);

	virtual bool Simplex(void) const;
	virtual ReaderStatus TransmitRaw(_In_ const myid::VectorOfByte& send, _In_ unsigned long sendLength, _Out_ myid::VectorOfByte& reply, _Inout_ unsigned long* le) const;
	virtual bool TraceApdu(void) const;
	virtual void TraceApdu(_In_ const std::wstring& text) const;

	long	m_lockCount;				///< locked state and count
	mutable bool	m_Transmitting;		///< doing a transmit
#ifdef DEBUG_SCARD
	bool DebugSend(_In_ const apdu::ApduCommand& send) const;
	mutable bool	m_debugChain;		///< chained debug
#endif

private:
	typedef LONG(WINAPI *fSCardGetTransmitCount)(SCARDHANDLE hCard, LPDWORD pcTransmitCount);
	fSCardGetTransmitCount m_fSCardGetTransmitCount;	///< function pointer
};

/// Monitor readers and card insertions and removals
class sCardMonitor : public sCardRoot
{
	typedef sCardRoot inherited;

public:
	enum MonitorResult				/// state of card monitoring
	{
		NO_CHANGE = 0,				///< no change in cards
		CARD_INSERTED = 1,			///< card inserted
		CARD_REMOVED = 2,			///< card removed
		READER_CHANGE = 3,			///< the number of readers has changed
		TERMINATED = 4				///< monitoring terminated
	};

	class MonitorData
	{
	public:
		MonitorResult	result;		///< result
		std::wstring	reader;		///< affected reader
	};

	sCardMonitor();
	~sCardMonitor();

	virtual LONG DisConnect(_In_ DWORD disposition = SCARD_LEAVE_CARD);
	bool SetupMonitor(void);
	MonitorData Monitor(_In_ bool reader_only = false);
	void CancelMonitor(void);
	void RefreshMonitor(void);
	void SuspendUpdate(_In_ bool suspend);
	long GetStatusChange(_In_ DWORD timeout);
	size_t NumReaderState(void) const;
	const SCARD_READERSTATE& ReaderState(_In_ size_t reader) const;

protected:
	StringList		m_readerName;		///< list of reader names
	std::vector<SCARD_READERSTATE> m_readerState;	///< reader state array
	HANDLE			m_event[2];			///< \li 0 cancel event
	///< \li 1 refresh event
	volatile bool	m_cancel;			///< if monitoring is canceled
	volatile bool	m_suspended;		///< if monitoring is suspended
};

/// Manage locks for a smart card with auto unlock.
/// Only a single lock may be attempted by a each instance of this class.
/// If multiple locks are required, then use multiple instances of this class.
class sCardLock : private boost::noncopyable
{
public:
	explicit sCardLock(_In_ scard::sCardTransmit& scard);
	virtual ~sCardLock();

	bool Lock(_In_ bool force = false, _In_ bool wait = true);
	bool TryLock(void);
	void UnLock(void);
	bool Locked(void) const;

protected:
	sCardTransmit&	m_scard;			///< smart card being locked
	bool			m_locked;			///< ensure single lock only by this object
};

/// Auto lock a smart card
class sCardAutoLock : public sCardLock
{
	typedef sCardLock inherited;

public:
	explicit sCardAutoLock(_In_ scard::sCardTransmit& scard);
};

} // namespace scard
