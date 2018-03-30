#pragma once

#include <string>
#include "Utilities/EdeficeCommon/Conversions/HexBinConversion.h"

namespace myid
{

/// Abstraction of a Status value
template< typename StatusEnum, StatusEnum SuccessValue >
class Status
{
public:
	typedef StatusEnum S;

	Status() : _status(SuccessValue) {}
	Status(S status) : _status(status) {}
	Status(const Status& rhs) : _status(rhs._status) {}
	virtual ~Status() {}		// opencppcoverage-exclude

	Status& operator=(S rhs) { _status = rhs; return *this; }
	Status& operator=(const Status& rhs) { _status = rhs._status; return *this; }

	bool operator==(const S& rhs) const { return _status == rhs; }
	bool operator!=(const S& rhs) const { return _status != rhs; }
	operator S() const { return _status; }
	S status() const { return _status; }
	bool success() const { return _status == SuccessValue; }
	virtual std::wstring text() const { return tohex(_status); }
	virtual std::wstring hex() const { return tohex(_status); }

protected:
	template <typename _ch> std::wstring _hex() const { return myid::ToHex<_ch>((_ch)_status); }
	template <typename _ch> void _set(_ch rhs) { _status = rhs; }

	static std::wstring tohex(const S& s) { return myid::ToHex(s); }

	S _status;
};

template< typename MaskEnum>
class BitMask
{
public:
	typedef MaskEnum M;

	BitMask() : _mask(static_cast<M>(0)) {}
	BitMask(const M& rhs) : _mask(rhs) {}
	BitMask(const BitMask& rhs) : _mask(rhs._mask) {}
	virtual ~BitMask() {}		// opencppcoverage-exclude

	BitMask& operator=(const M& rhs) { _mask = rhs; return *this; }
	BitMask& operator=(const BitMask& rhs) { _mask = rhs._mask; return *this; }

	bool operator==(const M& rhs) const { return _mask == rhs; }
	bool operator!=(const M& rhs) const { return _mask != rhs; }
	operator M() const { return _mask; }
	int get() const { return static_cast<int>(_mask); }
	bool operator[](const M& rhs) const { return (_mask & rhs) != 0; }

	BitMask operator|(const M& rhs) const { return static_cast<M>(_mask | rhs); }
	BitMask operator|(const BitMask& rhs) const { return static_cast<M>(_mask | rhs._mask); }

	BitMask& operator|=(const M& rhs) { _mask = static_cast<M>(_mask | rhs); return *this; }
	BitMask& operator|=(const BitMask& rhs) { _mask = static_cast<M>(_mask | rhs._mask); return *this; }

	BitMask& set(const M& rhs) { _mask = static_cast<M>(_mask | rhs); return *this; }
	BitMask& set(const BitMask& rhs) { _mask = static_cast<M>(_mask | rhs._mask); return *this; }
	BitMask& clear(void) { _mask = static_cast<M>(0); return *this; }
	BitMask& clear(const M& rhs) { _mask = static_cast<M>(_mask & ~rhs); return *this; }
	BitMask& clear(const BitMask& rhs) { _mask = static_cast<M>(_mask & ~rhs._mask); return *this; }

	virtual std::wstring hex() const { return myid::ToHex(_mask); }

protected:

	M _mask;
};
}
