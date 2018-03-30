#pragma once

#include <windows.h>

// from MSDN
#pragma pack(push, 2)
typedef struct _KERB_SMARTCARD_CSP_INFO {
	DWORD dwCspInfoLen;
	DWORD MessageType;
	union {
		PVOID   ContextInformation;
		ULONG64 SpaceHolderForWow64;
	};
	DWORD flags;
	DWORD KeySpec;
	ULONG nCardNameOffset;
	ULONG nReaderNameOffset;
	ULONG nContainerNameOffset;
	ULONG nCSPNameOffset;
	TCHAR bBuffer;
} KERB_SMARTCARD_CSP_INFO, *PKERB_SMARTCARD_CSP_INFO;

struct READER_INFO
{
	ULONG nReaderNameOffset;
	ULONG nReaderNameLength;
	ULONG nCardNameOffset;
	ULONG nCardNameLength;
	TCHAR bBuffer;
};

#pragma pack(pop)
