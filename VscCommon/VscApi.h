/// This is the internal interface between:
/// \li reader
/// \li applet

#pragma once
typedef unsigned char byte;

/// APDU process
namespace Process
{

/// Vsc type
enum class VscType : byte
{
	CNG = 0,			///< CNG key storage, RSA only
	TPM = 1,			///< TPM key storage
	CSP = 2,			///< CSP
	IPT = 3,			///< Intel IPT for MyID
	ITL = 4,			///< Intel IPT for Windows
	ECC = 5,			///< CNG key storage, RSA & ECC only
	MaxNum = 6,			///< the number of types
	Other = 254,		///< other card
	Undefined = 255,	///< undefined
};

const int StoreSaltSize = 32;			///< size of the store salt value
typedef byte StoreSalt[StoreSaltSize];	///< store salt
typedef byte ATR[32];					///< ATR def

} // namespace Process

// Public DLL interface for the applet
typedef DWORD(WINAPI *tInitialiseRoot)(_In_z_ const WCHAR* rootDir, _In_ const WCHAR* card, _In_ Process::StoreSalt salt, _In_opt_z_ const WCHAR* csp);
typedef DWORD(WINAPI *tGetATR)(_Out_ Process::ATR* atr, _Out_ DWORD* atrLen);
typedef DWORD(WINAPI *tCardReset)(_In_ bool cold);
typedef DWORD(WINAPI *tProcessApdu)(_In_reads_(apduLen) const BYTE* apdu, _In_ DWORD apduLen, _Out_writes_(*replyLen) BYTE* reply, _Out_ DWORD* replyLen, _Out_ unsigned short* status);

DWORD WINAPI InitialiseRoot(_In_z_ const WCHAR* rootDir, _In_ const WCHAR* card, _In_ Process::StoreSalt salt, _In_opt_z_ const WCHAR* csp);
DWORD WINAPI GetATR(_Out_ Process::ATR* atr, _Out_ DWORD* atrLen);
DWORD WINAPI CardReset(_In_ bool cold);
DWORD WINAPI ProcessApdu(_In_reads_(apduLen) const BYTE* apdu, _In_ DWORD apduLen, _Out_writes_(*replyLen) BYTE* reply, _Out_ DWORD* replyLen, _Out_ unsigned short* status);
