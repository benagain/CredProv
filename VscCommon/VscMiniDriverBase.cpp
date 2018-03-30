#include "stdafx.h"
#include "VscMiniDriverBase.h"

#if _MSC_VER < 1400
#define SCARD_W_CACHE_ITEM_NOT_FOUND     _HRESULT_TYPEDEF_(0x80100070L)
#endif

/// Minidriver call back functions
namespace callback
{

extern "C" {

/// Allocate memory
LPVOID WINAPI _Alloc(SIZE_T cBytes)
{
	if (cBytes == 0)
		return nullptr;

	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cBytes);
}

/// Free memory
void WINAPI _Free(LPVOID pvMem)
{
	if (pvMem != nullptr)
	{
		HeapFree(GetProcessHeap(), 0, pvMem);
	}
}

/// Reallocate memory
LPVOID WINAPI _ReAlloc(LPVOID pvMem,
					   SIZE_T cBytes)
{
	if (cBytes == 0)
	{
		_Free(pvMem);
		return nullptr;
	}

	if (pvMem == nullptr)
	{
		return _Alloc(cBytes);
	}

	return HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, pvMem, cBytes);
}

} // extern C

} // namespace callback

namespace VscMD
{

/// Destructor, unloads
MiniDriverBase::~MiniDriverBase()
{
	Unload();
}

//
/// Process error condition
bool MiniDriverBase::HandleError(void)
const
{
	ProcessError();
	return Success();
}

/// Determine whether to throw an error
/// \return true if a throw is required
void MiniDriverBase::ProcessError(void) const
{
}

/// Get the last error code
DWORD MiniDriverBase::Error(void) const
{
	return m_rc;
}

/// Determine if the previous function succeeded
bool MiniDriverBase::Success(void) const
{
	return m_rc == SCARD_S_SUCCESS;
}

/// Service function to get name pointer
LPSTR MiniDriverBase::NamePtr(const std::string& name)		///< directory or filename
{
	if (name.empty())
		return nullptr;

	return (char*)name.c_str();
}

/// Set the mini driver filename
void MiniDriverBase::MiniDriverName(const std::wstring& name)	///< mini driver name
{
	m_MiniDriver = name;
}

/// Get the card name
std::wstring MiniDriverBase::CardName(void) const
{
	return m_CardName;
}

/// Set the card name
void MiniDriverBase::CardName(const std::wstring& name)			///< card name
{
	m_CardName = name;

	m_CardData.pwszCardName = (LPWSTR)m_CardName.c_str();
}

/// Get the ATR
VectorOfByte MiniDriverBase::ATR(void) const
{
	return m_ATR;
}

/// Set the ATR
void MiniDriverBase::ATR(const VectorOfByte& atr)				///< ATR of card
{
	m_ATR = atr;

	m_CardData.pbAtr = m_ATR.ptr();
	m_CardData.cbAtr = m_ATR.lsize();
}

/// Acquire context and load minidriver
bool MiniDriverBase::Load(SCARDCONTEXT context,					///< card context
						  SCARDHANDLE handle)					///< card handle
{
	if (m_Module != nullptr)
		return false;
	if (m_MiniDriver.empty())
		return false;

	m_Module = LoadLibraryW(m_MiniDriver.c_str());
	if (m_Module == nullptr)
	{
		HandleError();
		return false;
	}

	memset(&m_CardData, 0, sizeof(CARD_DATA));
	m_CardData.dwVersion = CARD_DATA_CURRENT_VERSION;

	PFN_CARD_ACQUIRE_CONTEXT acquireContext = (PFN_CARD_ACQUIRE_CONTEXT)GetProcAddress(m_Module, "CardAcquireContext");
	if (acquireContext == nullptr)
	{
		Unload();
		HandleError();
		return false;
	}

	m_CardData.pbAtr = m_ATR.ptr();
	m_CardData.cbAtr = m_ATR.lsize();
	m_CardData.pwszCardName = (LPWSTR)m_CardName.c_str();

	m_CardData.pfnCspAlloc = callback::_Alloc;
	m_CardData.pfnCspReAlloc = callback::_ReAlloc;
	m_CardData.pfnCspFree = callback::_Free;

	m_CardData.hSCardCtx = context;
	m_CardData.hScard = handle;

	try
	{
		m_rc = acquireContext(&m_CardData, 0);
		if (!Success())
		{
			HandleError();
			return false;
		}
	}
	catch (...)
	{
	}
	return true;
}

/// Unload minidriver
void MiniDriverBase::Unload(void)
{
	HMODULE	module = (HMODULE)InterlockedExchange((PULONG_PTR)&m_Module, NULL);
	if (module != nullptr)
	{
		if (m_CardData.pfnCardDeleteContext != nullptr)
		{
			try
			{
				m_rc = m_CardData.pfnCardDeleteContext(&m_CardData);
			}
			catch (...)
			{
			}
		}

		m_CardData = {};

		FreeLibrary(module);
	}
	m_rc = SCARD_S_SUCCESS;
}

/// Free mini allocated memory
void MiniDriverBase::FreeMemory(LPVOID mem)			///< memory pointer
const
{
	m_CardData.pfnCspFree(mem);
}

//==========================================================================================
// end of service functions
// now do function interfaces

bool MiniDriverBase::SetProperty(LPWSTR _property,
	void* data,
	DWORD dataSize,
	DWORD flags)
	const
{
	m_rc = m_CardData.pfnCardSetProperty((PCARD_DATA)&m_CardData, _property, (PBYTE)data, dataSize, flags);
	return HandleError();
}

VectorOfByte MiniDriverBase::ReadFile(const std::string& directoryName,
									  const std::string& fileName)
const
{
	VectorOfByte data;
	PBYTE pbData = nullptr;
	DWORD cbData = 0;

	m_rc = m_CardData.pfnCardReadFile((PCARD_DATA)&m_CardData, NamePtr(directoryName), NamePtr(fileName), 0, &pbData, &cbData);
	if (Success())
	{
		if (cbData > 0)
		{
			data.set(pbData, cbData);
			FreeMemory(pbData);
		}
	}
	else
	{
		HandleError();
	}

	return data;
}

bool MiniDriverBase::Authenticate(PIN_ID id,
	const VectorOfByte& pin,
	VectorOfByte* sessionPin,
	DWORD flags,
	DWORD* attemptsRemaining)
	const
{
	if (attemptsRemaining)
		*attemptsRemaining = 0;

	if (sessionPin)
	{
		PBYTE sesPin = nullptr;
		DWORD cbSesPin = 0;
		m_rc = m_CardData.pfnCardAuthenticateEx((PCARD_DATA)&m_CardData, id, flags, (PBYTE)pin.ptr(), pin.lsize(), &sesPin, &cbSesPin, attemptsRemaining);
		if (Success())
		{
			if (cbSesPin > 0)
			{
				sessionPin->set(sesPin, cbSesPin);
				FreeMemory(sesPin);
			}
		}
	}
	else
	{
		m_rc = m_CardData.pfnCardAuthenticateEx((PCARD_DATA)&m_CardData, id, flags, (PBYTE)pin.ptr(), pin.lsize(), nullptr, nullptr, attemptsRemaining);
	}
	return Success() || HandleError();
}

bool MiniDriverBase::GetChallenge(PIN_ID id,
	VectorOfByte& challenge)
	const
{
	challenge.clear();

	BYTE*	challengeData = nullptr;
	DWORD	cbChallengeData = 0;

	m_rc = m_CardData.pfnCardGetChallengeEx((PCARD_DATA)&m_CardData, id, &challengeData, &cbChallengeData, 0);
	if (Success())
	{
		if (cbChallengeData > 0)
		{
			challenge.set(challengeData, cbChallengeData);
			FreeMemory(challengeData);
		}
		return true;
	}

	return HandleError();
}

bool MiniDriverBase::DeAuthenticate(PIN_SET pins)
const
{
	m_rc = m_CardData.pfnCardDeauthenticateEx((PCARD_DATA)&m_CardData, pins, 0);
	return Success() || HandleError();
}

bool MiniDriverBase::SignData(CARD_SIGNING_INFO& info)
const
{
	m_rc = m_CardData.pfnCardSignData((PCARD_DATA)&m_CardData, &info);

	return Success() || HandleError();
}

} // namespace VscMD
