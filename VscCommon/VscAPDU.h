#pragma once
#include "Utilities\CardLib\APDUVector.h"

namespace Process			/// APDU process
{

/// CLA byte definitions
/// \note These are in the proprietary range
enum class CLA : byte
{
	GENERIC_00		= 0x00,
	GENERIC_80		= 0x80,
	AUTHENTICATE	= 0x81,
	FILE			= 0x82,
	CONTAINER		= 0x83,
};

/// INS byte definitions for CLA::GENERIC_00 and CLA::GENERIC_80
enum class INS_GENERIC : byte
{
	SELECT					= 0xA4,
	GET_DATA				= 0xCA,
};

/// INS byte definitions for CLA::AUTHENTICATE
enum class INS_AUTHENTICATE : byte
{
	LOGGEDIN				= 1,
	GENERATE_CHALLENGE		= 2,
	AUTHENTICATE			= 3,
	UNBLOCK_PIN				= 4,
	CHANGE_PIN				= 5,
	DEAUTHENTICATE			= 6,
	VALID_PINS				= 7,
	LOGGEDIN_PINS			= 8,
	GET_PIN_STRENGTH		= 9,
	SET_PIN_STRENGTH		= 10,
	GET_PIN_INFO			= 11,
	SET_PIN_INFO			= 12,
	GET_PIN_POLICY			= 13,
	SET_PIN_POLICY			= 14,
	GENERATE_SESSION		= 15,
	AUTHENTICATE_SESSION	= 16,
};

/// INS byte definitions for CLA::FILE
enum class INS_FILE : byte
{
	CREATE_DIRECTORY		= 1,
	DELETE_DIRECTORY		= 2,
	CREATE_FILE				= 3,
	DELETE_FILE				= 4,
	READ_FILE				= 5,
	WRITE_FILE				= 6,
	ENUM_FILE				= 7,
	INFO_FILE				= 8,
};

/// INS byte definitions for CLA::CONTAINER
enum class INS_CONTAINER : byte
{
	CREATE_CONTAINER		= 1,
	IMPORT_CONTAINER		= 2,
	DELETE_CONTAINER		= 3,
	INFO_CONTAINER			= 4,
	RSA_DECRYPT				= 5,
	SIGN					= 6,
	FREE_SPACE				= 7,
	PINID					= 8,
	CAPABILITIES			= 9,
	KEY_SIZES				= 10,
	LAST_ERROR				= 11,
	PARENT_WINDOW			= 12,
	PIN_CONTEXT_STRING		= 13,
	READ_ONLY				= 14,
	ECDH					= 15,
	PROCESS					= 16,
};

/// APDU status values in the proprietary range 67xx
class Status : public apdu::ApduStatus
{
public:
	/// All errors codes defined in the minidriver specification
	enum values
	{
		SC_E_INVALID_HANDLE				= 0x6701,
		SC_E_INVALID_PARAMETER			= 0x6702,
		SC_E_UNSUPPORTED_FEATURE		= 0x6703,
		SC_W_CHV_BLOCKED				= 0x6704,
		SC_W_WRONG_CHV					= 0x6705,
		SC_W_SECURITY_VIOLATION			= 0x6706,
		SC_E_UNKNOWN_CARD				= 0x6707,
		SC_E_DIR_NOT_FOUND				= 0x6708,
		SC_E_FILE_NOT_FOUND				= 0x6709,
		SC_E_NO_KEY_CONTAINER			= 0x670A,
		SC_E_INSUFFICIENT_BUFFER		= 0x670B,
		SC_F_COMM_ERROR					= 0x670C,
		SC_E_UNEXPECTED					= 0x670D,
		SC_ERROR_FILE_EXISTS			= 0x670E,
		SC_ERROR_DIR_NOT_EMPTY			= 0x670F,
		SC_E_NO_MEMORY					= 0x6710,
		SC_E_WRITE_TOO_MANY				= 0x6711,
		SC_ERROR_REVISION_MISMATCH		= 0x6712,
		SC_ERROR_NOT_ENOUGH_MEMORY		= 0x6713,
		SC_ERROR_INSUFFICIENT_BUFFER	= 0x6714,
		SC_W_CANCELLED_BY_USER			= 0x6715,
		SC_E_NO_ACCESS					= 0x6716
	};

	Status() {}
	// cppcheck-suppress noExplicitConstructor
	Status(_In_ unsigned short _status) : apdu::ApduStatus(_status) {}

	/// Status word text
	std::wstring Text(void) const
	{
		static struct errorText
		{
			values status;				///< status value
			const wchar_t* text;		///< status description
		} error[] =
		{
			{SC_E_INVALID_HANDLE, L"Invalid handle"},
			{SC_E_INVALID_PARAMETER, L"Invalid parameter"},
			{SC_E_UNSUPPORTED_FEATURE, L"Unsupported feature"},
			{SC_W_CHV_BLOCKED, L"PIN blocked"},
			{SC_W_WRONG_CHV, L"Wrong PIN"},
			{SC_W_SECURITY_VIOLATION, L"Security violation"},
			{SC_E_UNKNOWN_CARD, L"Unknown card"},
			{SC_E_DIR_NOT_FOUND, L"Dir not found"},
			{SC_E_FILE_NOT_FOUND, L"File not found"},
			{SC_E_NO_KEY_CONTAINER, L"No key container"},
			{SC_E_INSUFFICIENT_BUFFER, L"Insufficient buffer"},
			{SC_F_COMM_ERROR, L"Comms error"},
			{SC_E_UNEXPECTED, L"Unexpected"},
			{SC_ERROR_FILE_EXISTS, L"File exists"},
			{SC_ERROR_DIR_NOT_EMPTY, L"Dir not empty"},
			{SC_E_NO_MEMORY, L"No memory"},
			{SC_E_WRITE_TOO_MANY, L"Write too many"},
			{SC_ERROR_REVISION_MISMATCH, L"Revision mismatch"},
			{SC_ERROR_NOT_ENOUGH_MEMORY, L"Not enough memory"},
			{SC_ERROR_INSUFFICIENT_BUFFER, L"Insufficient buffer"},
			{SC_W_CANCELLED_BY_USER, L"Cancelled by user"},
			{SC_E_NO_ACCESS, L"Access denied"}
		};

		for (const auto& e : error)
		{
			if (e.status == m_status)
				return e.text;
		}

		return apdu::ApduStatus::Text();
	}
};

const int ChallengeSize = 8;			///< challenge size
const int SessionPinSize = 8;			///< session PIN size

} // namespace Process
