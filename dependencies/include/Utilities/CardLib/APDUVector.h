/// \file APDUVector.h
/// APDU vector definition

#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include <boost/shared_ptr.hpp>
#include "Utilities/EdeficeCommon/GlobalOperator.h"
#include <string>
#include <list>

/// APDU interface
namespace apdu
{

const byte MaxLc = 255;
const unsigned long MaxLe = 256;
const unsigned short MaxExtLc = 65535;
const unsigned long MaxExtLe = 65536;

/// APDU command for sending to a smart card.
/// It is limited to sending and receiving 255 bytes at a time.
class ApduCommand : public myid::VectorOfByte
{
	typedef myid::VectorOfByte inherited;

public:
	ApduCommand();
	// cppcheck-suppress noExplicitConstructor
	ApduCommand(_In_ const ApduCommand& rhs);
	ApduCommand(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2);
	ApduCommand(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _le);
	virtual ~ApduCommand();

	ApduCommand& operator=(_In_ const ApduCommand& rhs);
	ApduCommand& operator=(_In_ const VectorOfByte& rhs);
	ApduCommand& operator=(_In_ const std::wstring& rhs);

	void build(_In_ const ApduCommand& rhs);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _le);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ const VectorOfByte& _data);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_z_ const wchar_t* hexData);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ const std::wstring& hexData);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _le, _In_ const VectorOfByte& _data);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _le, _In_z_ const wchar_t* hexData);
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _le, _In_ const std::wstring& hexData);

	ApduCommand& operator+=(_In_ const VectorOfByte& _data);
	ApduCommand& operator+=(_In_ const std::wstring& hexData);

	byte cla(void) const;
	void cla(_In_ byte b);
	byte ins(void) const;
	void ins(_In_ byte b);
	byte p1(void) const;
	void p1(_In_ byte b);
	byte p2(void) const;
	void p2(_In_ byte b);
	unsigned long lc(void) const;
	unsigned long le(void) const;
	void le(_In_ unsigned long b);
	virtual unsigned long leBytes(void) const;
	bool duplex(void) const;
	virtual bool single(void) const;
	VectorOfByte data(void) const;
	void data(_In_ const VectorOfByte& _data);
	std::wstring hexData(void) const;
	void hexData(_In_ const std::wstring& hexData);
	void Reset(void);
	bool valid(void) const;
	virtual bool extended(void) const;

protected:
	void build(_In_ byte _cla, _In_ byte _ins, _In_ byte _p1, _In_ byte _p2, _In_ unsigned long _lc, _In_ unsigned long _le, _In_opt_ const byte* _data);
	virtual void setSize(void);
	virtual void setLc(void);
	virtual void setLe(void);
	virtual byte* dp(void) const;
	virtual void restrict(void) const;

	unsigned long	m_lc;				///< length of data to send
	unsigned long	m_le;				///< expected length of data to receive
	bool	m_valid;					///< true if buffer is valid
};

typedef boost::shared_ptr<ApduCommand> ApduCommandPtr;		///< APDU command pointer

/// An APDU command that allows extended Lc and Le to allow up to 65535 bytes of data in one command
/// Unless forced, it will generate a standard 255 byte APDU if short enough
class ApduExtCommand : public ApduCommand
{
	typedef ApduCommand inherited;

public:
	ApduExtCommand();
	explicit ApduExtCommand(_In_ const ApduExtCommand& rhs);
	explicit ApduExtCommand(_In_ const ApduCommand& rhs);

	ApduExtCommand& operator=(_In_ const ApduExtCommand& rhs);
	ApduExtCommand& operator=(_In_ const ApduCommand& rhs);
	ApduExtCommand& operator=(_In_ const VectorOfByte& rhs);

	virtual unsigned long leBytes(void) const;
	virtual bool extended(void) const;
	virtual void extended(_In_ bool force);
	virtual bool single(void) const;

protected:
	virtual void setSize(void);
	virtual void setLc(void);
	virtual void setLe(void);
	virtual byte* dp(void) const;
	virtual void restrict(void) const;

	bool	m_forceExtended;			///< force command to be always extended
};

/// An APDU command with an unlimited amount of data. It will be split into blocks by ApduCommandList for transmission to the card.
/// \note byte 5 (the length) is invalid and is set to zero. There are no le bytes.
class ApduLongCommand : public ApduCommand
{
	typedef ApduCommand inherited;

public:
	ApduLongCommand();
	explicit ApduLongCommand(_In_ const ApduLongCommand& rhs);
	explicit ApduLongCommand(_In_ const ApduCommand& rhs);

	ApduLongCommand& operator=(_In_ const ApduLongCommand& rhs);
	ApduLongCommand& operator=(_In_ const ApduCommand& rhs);

	bool extract(_Out_ ApduCommand& command, _Inout_ unsigned long& position, _In_ unsigned short length = MaxLc) const;
	bool more(_In_ unsigned long position) const;
	virtual bool extended(void) const;

protected:
	virtual void setSize(void);
	virtual void setLc(void);
	virtual void setLe(void);
	virtual void restrict(void) const;
};

/// A list of APDU commands generated from ApduLongCommand
class ApduCommandList : public std::list<ApduCommandPtr>
{
	typedef std::list<ApduCommandPtr> inherited;

public:
	ApduCommandList();
	void add(_In_ const ApduCommand& rhs);
	void add(_In_ const ApduExtCommand& rhs);

	void build(_In_ const ApduLongCommand& command, _In_ byte length = MaxLc);
	void buildExt(_In_ const ApduLongCommand& command, _In_ unsigned short length = MaxExtLc);
	void buildChain(_In_ const ApduLongCommand& command, _In_ byte length = MaxLc);
	void buildChainExt(_In_ const ApduLongCommand& command, _In_ unsigned short length = MaxExtLc);
	void buildBlock(_In_ const ApduLongCommand& command, _In_ byte length = MaxLc);
	bool linked(void) const;
	void linked(_In_ bool _linked);
	bool errorStop(void) const;
	void errorStop(_In_ bool _stop);

protected:
	bool	m_linked;					///< if the list has been made as a set of chained commands
	bool	m_errorStop;				///< stop on error
};

/// APDU reply status word
class ApduStatus
{
public:
#if _MSC_VER >= 1800
	enum values : unsigned short	/// APDU reply status values
#else
	enum values						/// APDU reply status values
#endif
	{
		SUCCESS							= 0x9000,
		UNSET							= 0,			///< unset
		WARNING_NO_INFORMATION_62		= 0x6200,		///< 62 warnings
		MAY_BE_CORRUPT					= 0x6281,
		LESS_DATA_THAN_EXPECTED			= 0x6282,
		SELECTED_FILE_DEACTIVATED		= 0x6283,
		FILE_CONTROL_BAD_FORMAT			= 0x6284,
		SELECTED_FILE_IN_TERMINATION	= 0x6285,
		NO_INPUT_DATA_AVAILABLE			= 0x6286,
		WARNING_NO_INFORMATION_63		= 0x6300,		///< 63 warnings
		FILE_FILLED_UP_BY_LAST_WRITE	= 0x6381,
		VERIFY_FAILED					= 0x63C0,
		EXECUTION_ERROR					= 0x6400,		///< 64 errors
		IMMEDIATE_RESPONSE_REQUIRED		= 0x6401,
		ERROR_NO_INFORMATION_65			= 0x6500,		///< 65 errors
		MEMORY_FAILURE					= 0x6581,
		ERROR_NO_INFORMATION_66			= 0x6600,		///< 66 errors
		WRONG_LENGTH					= 0x6700,		///< 67 errors
		ERROR_NO_INFORMATION_68			= 0x6800,		///< 68 errors
		LOGICAL_CHANNEL_UNSUPPORTED		= 0x6881,
		SECURE_MESSAGING_UNSUPPORTED	= 0x6882,
		LAST_CHAIN_COMMAND_EXPECTED		= 0x6883,
		COMMAND_CHAINING_UNSUPPORTED	= 0x6884,
		ERROR_NO_INFORMATION_69			= 0x6900,		///< 69 errors
		COMMAND_INCOMPATIBLE			= 0x6981,
		SECURITY_STATUS					= 0x6982,
		PIN_LOCKED						= 0x6983,
		REFERENCE_DATA_NOT_USABLE		= 0x6984,
		INVALID_CONDITIONS				= 0x6985,
		COMMAND_NOT_ALLOWED				= 0x6986,
		SECURE_MESSAGING_DATA_MISSING	= 0x6987,
		INCORRECT_SECURE_MESSAGING_DATA	= 0x6988,
		ERROR_NO_INFORMATION_6A			= 0x6a00,		///< 6A errors
		INCORRECT_PARAMETER				= 0x6a80,
		FUNCTION_NOT_SUPPORTED			= 0x6a81,
		OBJECT_NOT_FOUND				= 0x6a82,
		RECORD_NOT_FOUND				= 0x6a83,
		NOT_ENOUGH_MEMORY				= 0x6a84,
		INVALID_LENGTH_FOR_TLV			= 0x6a85,
		INCORRECT_P1_P2					= 0x6a86,
		INVALID_LENGTH_P1_P2			= 0x6a87,
		DATA_NOT_FOUND					= 0x6a88,
		FILE_ALREADY_EXISTS				= 0x6a89,
		DF_NAME_ALREADY_EXISTS			= 0x6a8a,
		INVALID_P1_P2					= 0x6b00,
		INVALID_INSTRUCTION				= 0x6d00,
		INVALID_CLASS					= 0x6e00,
		UNKNOWN_PROBLEM					= 0x6f00,
		ALGORITHM_NOT_SUPPORTED			= 0x9484,
		INVALID_KEY_CHECK_VALUE			= 0x9485
	};

	enum status_type
	{
		ST_UNSET,				///< 0
		ST_SUCCESS,				///< 9000 or 61xx
		ST_WARNING,				///< 62xx or 63xx
		ST_ERROR,				///< other from ISO 7816
		ST_PROPRIETARY			///< undefined status
	};

	ApduStatus();
	explicit ApduStatus(_In_ unsigned short _status);
	explicit ApduStatus(_In_ values _status);

	ApduStatus& operator=(_In_ unsigned short _status);
	operator unsigned short() const;
	bool success(void) const;
	bool warning(void) const;
	bool error(void) const;
	status_type type(void) const;
	std::wstring Text(void) const;
	bool verifyFailed(_Out_opt_ int* retries = nullptr) const;

	unsigned short status(void) const;
	std::wstring statusHex(void) const;
	byte sw1(void) const;
	byte sw2(void) const;

protected:
	unsigned short m_status;			///< APDU status word
};

/// Complete APDU reply encapsulation
class ApduReply : public myid::VectorOfByte, public ApduStatus
{
public:
	ApduReply();
	ApduReply(_In_ const ApduReply& rhs);
	explicit ApduReply(_In_ const VectorOfByte& rhs);
	explicit ApduReply(_In_ unsigned short _status);
	explicit ApduReply(_In_ const ApduStatus& _status);
	ApduReply(_In_ unsigned short _status, _In_ const VectorOfByte& rhs);
	ApduReply(_In_ const ApduStatus& _status, _In_ const VectorOfByte& rhs);

	ApduReply& operator=(_In_ unsigned short _status);
	ApduReply& operator=(_In_ const ApduStatus& _status);
	ApduReply& operator=(_In_ const VectorOfByte& reply);
	void operator+=(_In_ const ApduReply& reply);
	void SetStatus(bool force = false);
	void Reset(size_t size = 0);
	std::wstring hexData(void) const;
	void hexData(_In_ const std::wstring& hexData);
	void Data(_In_ const VectorOfByte& data);
	VectorOfByte DataWithStatus(void) const;
	bool valid(void) const;

protected:
	bool	m_valid;					///< true if buffer is valid
	bool	m_statusExtracted;			///< true if the status word has been removed
};

/// A list of APDU replies
class ApduReplyList : public std::list<ApduReply>
{
	typedef std::list<ApduReply> inherited;

public:
	bool success(void) const;
	ApduStatus status(void) const;
};

} // namespace myid
