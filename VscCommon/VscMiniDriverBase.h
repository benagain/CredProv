#pragma once

#include "Products\Common\Microsoft\CNG\MD\CardMod.h"

namespace VscMD
{

/// Mini driver interface
class MiniDriverBase
{
	friend class MiniDriverInCommand;

public:
	MiniDriverBase() = default;
	virtual ~MiniDriverBase();

	virtual void MiniDriverName(const std::wstring& name);
	virtual std::wstring CardName(void) const;
	virtual void CardName(const std::wstring& name);
	virtual VectorOfByte ATR(void) const;
	virtual void ATR(const VectorOfByte& atr);

	virtual DWORD Error(void) const;
	virtual bool Success(void) const;

	virtual bool SetProperty(LPWSTR _property, void* data, DWORD dataSize, DWORD flags) const;
	virtual VectorOfByte ReadFile(const std::string& directoryName, const std::string& fileName) const;

	virtual bool Authenticate(PIN_ID id, const VectorOfByte& pin, VectorOfByte* sessionPin, DWORD flags, DWORD* attemptsRemaining = nullptr) const;
	virtual bool DeAuthenticate(PIN_SET pins) const;
	virtual bool GetChallenge(PIN_ID id, VectorOfByte& challenge) const;

protected:
	virtual bool Load(SCARDCONTEXT context, SCARDHANDLE handle);
	virtual void FreeMemory(LPVOID mem) const;
	virtual bool SignData(CARD_SIGNING_INFO& info) const;

	virtual void Unload(void);
	virtual bool HandleError(void) const;
	virtual void ProcessError(void) const;
	static LPSTR NamePtr(const std::string& name);

	std::wstring	m_MiniDriver;				///< driver name
	CARD_DATA		m_CardData{};				///< card data
	VectorOfByte	m_ATR;						///< ATR for card data
	std::wstring	m_CardName;					///< card name for card data
	HMODULE			m_Module{};					///< driver DLL module handle
	mutable DWORD	m_rc{ SCARD_S_SUCCESS };	///< error code
};

} // namespace VscMD
