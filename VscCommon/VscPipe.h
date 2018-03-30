/// This is the internal interface between:
/// \li applet
/// \li service
/// \li IPT UI

#pragma once
#include "VscAPDU.h"

/// Pipe interface for UI and service
namespace Pipe
{

#pragma pack (push, 1)

#define EventService L"Global\\MyIDVscService"
#define PipeService L"\\\\.\\pipe\\MyIDVscService"

const int SIZE{0x11000};		///< max pipe buffer, enough for APDU_SIZE plus other data
const int APDU_SIZE{0x10100};	///< max pipe buffer, enough for 65536 APDU plus header
const int NAME_SIZE{50};		///< max size of pipe and event name
const int CONTAINER_SIZE{40};	///< max size of container name (matches MAX_CONTAINER_NAME_LEN + 1 from cardmod.h)

/// Pipe command
enum class Cmd : byte
{
	EXIT = 0,					///< exit command (Service, IPT, ITL)
	IPTSTART = 1,				///< Start IPT command (Service)
	GENKEY = 2,					///< Generate key (IPT, ITL)
	IMPKEY = 3,					///< Import key (IPT, ITL)
	DELKEY = 4,					///< Delete a key (IPT, ITL)
	PUBKEY = 5,					///< Get public key (IPT, ITL)
	SIGN = 6,					///< Sign (IPT, ITL)
	DECRYPT = 7,				///< Decrypt (IPT, ITL)
};

/// Common pipe send header
class cmd
{
public:
	cmd();
	explicit cmd(Cmd rhs);

	static void set(_In_z_ LPCWSTR data, _Out_writes_bytes_(size) LPWSTR where, _In_ size_t size);
	static void set(_In_ const std::wstring& data, _Out_writes_bytes_(size) LPWSTR where, _In_ size_t size);

	Cmd command;				///< pipe command
};
/// Exit command
class cmdExit : public cmd
{
public:
	cmdExit();
};
/// Launch IPT command
class cmdIPT : public cmd
{
public:
	cmdIPT();

	WCHAR csp[MAX_PATH] {};			///< CSP name
	WCHAR pipe[NAME_SIZE] {};		///< pipe name
	WCHAR evnt[NAME_SIZE] {};		///< event name
	bool remote{};					///< process is remote
	DWORD processId{};				///< process ID of source
	DWORD sessionId{};				///< matching session ID
	WCHAR desktop[MAX_PATH] {};		///< window station and desktop composite
	bool alt{};						///< try alternative desktop, toggle
};

/// Generate key command
class cmdGen : public cmd
{
public:
	cmdGen();

	WCHAR name[CONTAINER_SIZE] {};	///< max container name length (GUID)
	DWORD keySpec{};				///< AT_KEYEXCHANGE or AT_SIGNATURE
	DWORD keySize{};				///< key size in bits
};
/// Delete command
class cmdDelete : public cmd
{
public:
	cmdDelete();

	WCHAR name[CONTAINER_SIZE] {};	///< max container name length (GUID)
};
/// get public key command
class cmdKey : public cmd
{
public:
	cmdKey();

	WCHAR name[CONTAINER_SIZE] {};	///< max container name length (GUID)
	DWORD keySpec{};				///< AT_KEYEXCHANGE or AT_SIGNATURE
};
const DWORD SignDataLen{64};
/// Sign command
class cmdSign : public cmd
{
public:
	cmdSign();

	WCHAR name[CONTAINER_SIZE] {};	///< max container name length (GUID)
	DWORD keySpec{};				///< AT_KEYEXCHANGE or AT_SIGNATURE
	DWORD paddingType{};			///< CARD_PADDING_NONE or CARD_PADDING_PKCS1
	DWORD signFlags{};				///< signing flags
	DWORD len{};					///< data length
	WCHAR alg[30]{};				///< BCRYPT algorithm name
	DWORD salt{};					///< PSS salt value
	byte data[SignDataLen] {};		///< max hash data SHA512
};
const DWORD DecryptDataLen{512};
/// Decrypt command
class cmdDecrypt : public cmd
{
public:
	cmdDecrypt();

	WCHAR name[CONTAINER_SIZE] {};	///< max container name length (GUID)
	DWORD keySpec{};				///< AT_KEYEXCHANGE or AT_SIGNATURE
	DWORD paddingType{};			///< CARD_PADDING_NONE or CARD_PADDING_PKCS1
	DWORD len{};					///< data length
	byte data[DecryptDataLen] {};	///< data (4096 RSA)
};

/// Common pipe receive header
const DWORD RespErrorLen{50};
class resp
{
public:
	resp();

	void clear();

	Process::Status status{Process::Status::SUCCESS};	///< return code
	DWORD response{ERROR_SUCCESS};	///< detailed HRESULT or error code
	wchar_t error[RespErrorLen] {};	///< origin of error
};
/// Launch IPT response
class respIPT : public resp
{
public:
	respIPT();

	void clear();

	DWORD processId{};				///< IPT process ID
	DWORD threadId{};				///< IPT thread ID
};
const DWORD RespDataLen{532};
/// Sign, decrypt and public key response
class respData : public resp
{
public:
	respData();

	void clear();

	DWORD len{};					///< reply length
	byte data[RespDataLen] {};		///< data reply, max of:
	///< \li 512 (4096 RSA block size)
	///< \li 532 = 512 + sizeof(PUBLICKEYSTRUC) + sizeof(RSAPUBKEY) (4096 RSA public key)
};

#pragma pack (pop)

} // namespace Pipe
