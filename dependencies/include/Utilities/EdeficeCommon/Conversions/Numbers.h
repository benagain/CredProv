#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <boost/lexical_cast.hpp>
#ifndef MOBILE
#include "Win\Numbers.h"
#endif

namespace myid
{

template< typename T, typename C >
inline T ToNum(_In_ std::basic_string<C> const & str, _In_ const T defaultValue = 0)
{
	std::basic_stringstream<C> stream;
	T nResult = defaultValue;

	stream << str;
	stream >> nResult;

	return nResult;
}

template< typename T >
inline T STRtoNum(_In_ std::string const & str, _In_ const T defaultValue = 0)
{
	return ToNum<T, char>(str, defaultValue);
}

template< typename T >
inline T WSTRtoNum(_In_ std::wstring const & str, const T defaultValue = 0)
{
	return ToNum<T, wchar_t>(str, defaultValue);
}

/// Integer or float to string
template< typename T, typename C >
inline std::basic_string<C> FromNum(_In_ const T& num, _In_ int nDecimalPlaces = 0)
{
	std::basic_stringstream<C> stream;
	stream << std::fixed << std::setprecision(nDecimalPlaces) << num;
	return stream.str();
}

template< typename T >
inline std::string NumToSTR(_In_ const T& num, _In_ int nDecimalPlaces = 0)
{
	return FromNum<T, char>(num, nDecimalPlaces);
}

template< typename T >
inline std::wstring NumToWSTR(_In_ const T& num, _In_ int nDecimalPlaces = 0)
{
	return FromNum<T, wchar_t>(num, nDecimalPlaces);
}

enum FromNumFormat
{
	FNF_LEFT = 0,			///< \li 0 left, space filled
	FNF_RIGHT = 1,			///< \li 1 right, space filled
	FNF_ZERO = 2			///< \li 2 right, zero filled
};

/// Integer to string conversion
template< typename T, typename C >
inline std::basic_string<C> FromNum(
	_In_ const T& num,			///< integer type
	_In_ int width,				///< width of output
	_In_ FromNumFormat format)	///< number format
{
	std::basic_ostringstream<C> stream;

	stream << std::dec << std::setw(width);
	switch (format)
	{
	case FNF_LEFT:
		stream << std::left;
		break;
	case FNF_RIGHT:
		stream << std::right;
		break;
	case FNF_ZERO:
		stream << std::right << std::setfill((C)'0');
		break;
	}
	stream << num;
	return stream.str();
}

template< typename T >
inline std::string NumToSTR(_In_ const T& num, _In_ int width, _In_ FromNumFormat format)
{
	return FromNum<T, char>(num, width, format);
}

template< typename T >
inline std::wstring NumToWSTR(_In_ const T& num, _In_ int width, _In_ FromNumFormat format)
{
	return FromNum<T, wchar_t>(num, width, format);
}

/// Integer or float to hex string
template< typename T, typename C >
inline std::basic_string<C> FromNumToHex(_In_ const T& num, _In_ int minWidth = 0)
{
	std::basic_stringstream<C> stream;
	stream << (C)'0' << (C)'x' << std::hex << std::setw(minWidth)
		<< std::setfill((C)'0') << std::right << num;
	return stream.str();
}

template< typename T >
inline std::wstring NumToHexWSTR(_In_ const T& num, _In_ int minWidth = 0)
{
	return FromNumToHex<T, wchar_t>(num, minWidth);
}

/// Numeric test
/// \note Not using isdigit() as don't want locale to slow things down
template <typename C>
bool isNum(_In_ C num)
{
	return (num >= '0' && num <= '9');
}

/// Numeric test
/// \note MyID does not have signed numbers, so there is no test for leading +-
template <typename C>
bool isNum(
	_In_reads_bytes_(len) const C* num,
	_In_ size_t len)
{
	size_t n = 0;
	// skip leading spaces
	for (; (n < len) && (*num == ' '); ++n, ++num);

	for (; (n < len) && *num; ++n, ++num)
	{
		if (!isNum(*num))
			return false;
	}
	return true;
}

/// Numeric test
template<typename C >
inline bool isNum(_In_ std::basic_string<C> const & str)
{
	return isNum(str.c_str(), str.size());
}

//--------------------------------------
// from std::string

inline int STRtoINT(_In_ std::string const & strNum, _In_ const int defaultValue = 0)
{
	return STRtoNum<int>(strNum, defaultValue);
}

inline unsigned int STRtoUINT(_In_ std::string const & strNum, _In_ const unsigned int defaultValue = 0)
{
	return STRtoNum<unsigned int>(strNum, defaultValue);
}

//--------------------------------------
// from std::wstring

inline int WSTRtoINT(std::wstring const & wstrNum, const int defaultValue = 0)
{
	return WSTRtoNum<int>(wstrNum, defaultValue);
}

inline long WSTRtoLONG(std::wstring const & wstrNum, const long defaultValue = 0)
{
	return WSTRtoNum<long>(wstrNum, defaultValue);
}


//--------------------------------------

// obsolete discrete functions can now use templated function

// to std::string
#define UINTtoSTR NumToSTR
#define INTtoSTR NumToSTR
#define SIZETtoSTR NumToSTR

// to std::wstring
#define DBLEtoWSTR NumToWSTR
#define INTtoWSTR NumToWSTR
#define UINTtoWSTR NumToWSTR
#define LONGtoWSTR NumToWSTR
#define ULONGtoWSTR NumToWSTR

// to hex std::wstring
#define DBLEtoHexWSTR NumToHexWSTR
#define INTtoHexWSTR NumToHexWSTR
#define UINTtoHexWSTR NumToHexWSTR
#define LONGtoHexWSTR NumToHexWSTR
#define ULONGtoHexWSTR NumToHexWSTR

/// In certain template situations we can not know if the input is a string
/// or an integer, this abstracts that away in a fashion that can be used as a functor.
class StringOrNumberToString
{
public:
	template<typename T>
	std::wstring operator()(_In_ T value) const
	{
		return boost::lexical_cast<std::wstring>(value);
	}
};
} // namespace myid
