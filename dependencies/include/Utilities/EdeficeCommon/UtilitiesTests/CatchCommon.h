#pragma once

#if (_MSC_VER >= 1600)
	#define CATCH_CONFIG_CPP11_NULLPTR
#endif

#pragma warning(push)
#pragma warning (disable:28251)
#include "catch.hpp"
#pragma warning(pop)
#include "Utilities/EdeficeCommon/Conversions/StringUtils.h"
#include "Utilities/EdeficeCommon/Conversions/VectorOfByteConversion.h"
#include "Utilities/EdeficeCommon/StringList.h"
#include "Utilities/EdeficeCommon/TimeCommon.h"
#ifdef CATCH_CARDLIB
#include "Utilities/CardLib/APDUVector.h"
#endif

namespace Catch
{

inline std::string toString( myid::VectorOfByte const& value )
{
	return myid::bin_to_hex(value);
}

inline std::string toString( const myid::StringList& value )
{
	std::ostringstream oss;
	std::for_each(value.begin(), value.end(), [&](const std::wstring & s)
	{
		oss << toString(s);
	});

	return oss.str();
}

inline std::string toString( const myid::Time& value )
{
	return myid::ToStr(value.iso());
}

inline std::string toString( const myid::TimeSpan& value )
{
	return std::to_string(value.get());
}

#if defined(WIN32) && !defined(MOBILE)
inline std::string toString(const _bstr_t & value)
{
	return myid::ToStr(value);
}

inline std::string toString(const _variant_t & value)
{
	return myid::ToStr(value);
}

inline std::string toString(const ATL::CComBSTR & value)
{
	return myid::ToStr(value);
}
#endif

#ifdef CATCH_UNSIGNED_AS_HEX
inline std::string toString(unsigned short value)
{
	std::string rtn("0x");
	return rtn += myid::ToSHex(value);
}

inline std::string toString(unsigned long long value)
{
	std::string rtn("0x");
	return rtn += myid::ToSHex(value);
}
#endif

#ifdef CATCH_CARDLIB
inline std::string toString( const apdu::ApduReply& value )
{
	std::ostringstream oss;
	oss << myid::ToSHex(value.status()) << " " << myid::bin_to_hex(value);
	return oss.str();
}

inline std::string toString( const apdu::ApduStatus& value )
{
	return myid::ToSHex(value.status());
}

inline std::string toString( apdu::ApduStatus::values value )
{
	return myid::ToSHex((unsigned short)value);
}
#endif

} // namespace Catch
