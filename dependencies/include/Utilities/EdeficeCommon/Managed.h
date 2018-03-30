#pragma once

/** \file
 * Managed to std interface functions
 */

#if defined(_MANAGED) && !defined(MOBILE)

#include <string>
#include <sstream>
#include <vcclr.h>
#include "VectorOfByte.h"
#include "StringList.h"
#include "Utilities\EdeficeCommon\Conversions\VectorOfByteConversion.h"

#using <System.dll>
#using <System.Drawing.dll>
#using <System.Xml.dll>

using namespace System;
using namespace System::Text;
using namespace System::Xml;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Specialized;

/// Append a .NET string to an STL string
inline std::wstring & operator<<(std::wstring& lhs,			///< STL string to append to
								 String^ rhs)				///< .NET string to append
{
	if (rhs != nullptr)
	{
		int length = rhs->Length;
		if (length > 0)
		{
			pin_ptr<const wchar_t> p = PtrToStringChars(rhs);
			lhs.append(p, length);
		}
	}

	return lhs;
}

/// Append an .NET XML node text to an STL string
inline std::wstring & operator<<(std::wstring& lhs,			///< STL string to append to
								 XmlNode^ rhs)				///< .NET node to append
{
	if (rhs != nullptr)
	{
		lhs << rhs->Value;
	}

	return lhs;
}

/// Append an arbitrary object to an STL string
inline std::wstring & operator<<(std::wstring& lhs,			///< STL string to append to
								 Object^ rhs)				///< .NET object to append
{
	if (rhs != nullptr)
	{
		lhs << rhs->ToString();
	}

	return lhs;
}

namespace myid						/// myid conversions
{

/// Convert a string to a .NET string
/// \tparam _Ch string type, either char or wchar_t
template<typename _Ch>
String^ ToString( const std::basic_string< _Ch > & rhs )	///< STL string type
{
	if (rhs.empty())
		return gcnew String("");

	return gcnew String(rhs.c_str(), 0, (int)rhs.size());
}

/// Convert a char array to a .NET string
/// \tparam _Ch string type, either char or wchar_t
template<typename _Ch>
String^ ToString( const _Ch * rhs )							///< string type, may be nullptr
{
	if( rhs == nullptr )
		return gcnew String("");

	return gcnew String(rhs);
}

/// Convert a bstr string to a .NET string
inline String^ ToString(const _bstr_t& rhs)					///< source
{
	if (rhs.length() == 0)
		return gcnew String("");

	return gcnew String((const wchar_t*)rhs, 0, rhs.length());
}

/// Convert a string to a .NET string buffer
inline StringBuilder^ ToStringBuilder(const std::wstring& rhs)	///< source
{
	if (rhs.empty())
		return gcnew StringBuilder();

	return gcnew StringBuilder(ToString(rhs));
}

/// Convert a .NET string to a COM return string
inline BSTR ToBSTR(String^ rhs)								///< source
{
	return (BSTR)Marshal::StringToBSTR(rhs).ToPointer();
}

/// Convert a string
inline _bstr_t ToBstr(String^ rhs)							///< source
{
	if (rhs != nullptr)
	{
		int length = rhs->Length;
		if (length > 0)
		{
			pin_ptr<const wchar_t> p = PtrToStringChars(rhs);
			return _bstr_t(p);
		}
	}

	return L"";
}

/// Convert arbitrary object
inline _bstr_t ToBstr(Object^ rhs)							///< source
{
	if (rhs != nullptr)
	{
		return ToBstr(rhs->ToString());
	}

	return L"";
}

/// Convert a string
inline std::wstring ToWstr(String^ rhs)						///< source
{
	if (rhs != nullptr)
	{
		int length = rhs->Length;
		if (length > 0)
		{
			pin_ptr<const wchar_t> p = PtrToStringChars(rhs);
			return std::wstring(p, length);
		}
	}

	return L"";
}

/// Convert arbitrary object
inline std::wstring ToWstr(Object^ rhs)						///< source
{
	if (rhs != nullptr)
	{
		return ToWstr(rhs->ToString());
	}

	return L"";
}

/// Convert a string collection to a string list
inline StringList ToWstr(StringCollection^ list)			///< source
{
	StringList rtn;
	if (list != nullptr)
	{
		rtn.reserve(list->Count);
		for each (String^ string in list)
		{
			rtn.push_back(myid::ToWstr(string));
		}
	}

	return rtn;
}

/// Convert a string
inline std::string ToStr(String^ rhs)						///< source
{
	if (rhs != nullptr)
	{
		return myid::StringToUTF8String(ToWstr(rhs));
	}

	return "";
}

/// Convert arbitrary object
inline std::string ToStr(Object^ rhs)						///< source
{
	if (rhs != nullptr)
	{
		return myid::StringToUTF8String(ToWstr(rhs));
	}

	return "";
}

/// Convert a byte array to a vector
inline myid::VectorOfByte ToVector(cli::array<byte>^ bytes)	///< source
{
	if (bytes != nullptr)
	{
		int length = bytes->Length;
		if (length > 0)
		{
			myid::VectorOfByte vec(length);

			pin_ptr<byte> b = &bytes[0];
			byte* pb = b;
			memcpy(&vec[0], pb, length);
			return vec;
		}
	}

	return myid::VectorOfByte();
}

/// Convert part of a byte array to a vector
/// \note If Offset greater than Length, nothing is copied. If offset + length greater than Length,
/// only available bytes are copied.
inline myid::VectorOfByte ToVector(cli::array<byte>^ bytes,	///< source
								   int offset,				///< start position, initial = 0
								   int length)				///< number of bytes
{
	if (bytes != nullptr)
	{
		if (offset < 0)
			throw myid::LocalisedException(LOCALISE_FN_STATIC, L"offset < 0");
		if (length > bytes->Length - offset)
			length = bytes->Length - offset;
		if (length > 0)
		{
			myid::VectorOfByte vec(length);

			pin_ptr<byte> b = &bytes[offset];
			byte* pb = b;
			memcpy(&vec[0], pb, length);
			return vec;
		}
	}

	return myid::VectorOfByte();
}

/// Convert a stream to a vector
inline myid::VectorOfByte ToVector(IO::Stream^ stream)		///< source
{
	if (stream != nullptr)
	{
		// stream->Length may not be valid, so process in blocks
		const int block = 0x4000;
		myid::VectorOfByte vec;
		cli::array<unsigned char>^ data = gcnew cli::array<unsigned char>(block);
		for (;;)
		{
			int read = stream->Read(data, 0, block);
			if (read == 0)
				break;
			vec += myid::ToVector(data, 0, read);
		}
		return vec;
	}

	return myid::VectorOfByte();
}

/// Convert a vector to byte array
inline cli::array<byte>^ ToArray(const myid::VectorOfByte& vec)	///< source
{
	int length = vec.lsize();
	cli::array<byte>^ ar = gcnew cli::array<byte>(length);
	if (length > 0)
	{
		Marshal::Copy(IntPtr((void*)&vec[0]), ar, 0, length);
	}

	return ar;
}

/// Convert a vector to byte array
inline cli::array<byte>^ ToArray(const byte* data,			///< source
	int length)												///< length
{
	cli::array<byte>^ ar = gcnew cli::array<byte>(length);
	if (length > 0)
	{
		Marshal::Copy(IntPtr((void*)data), ar, 0, length);
	}

	return ar;
}

/// Convert a vector to a bitmap
inline System::Drawing::Bitmap^ ToBitmap(const myid::VectorOfByte& vec)		///< source
{
	System::IO::UnmanagedMemoryStream^ stream = gcnew System::IO::UnmanagedMemoryStream((byte*)vec.ptr(), vec.size());
	return gcnew System::Drawing::Bitmap(stream);
}

/// Convert a wide string list to a string collection
inline StringCollection^ ToString(const StringList& list)	///< source
{
	StringCollection^ rtn = gcnew StringCollection;
	for each (const std::wstring& string in list)
	{
		rtn->Add(gcnew String(string.c_str()));
	}
	return rtn;
}

/// Convert a string list to a string collection
inline StringCollection^ ToString(const std::vector<std::string>& list)	///< source
{
	StringCollection^ rtn = gcnew StringCollection;
	for each (const std::string& string in list)
	{
		rtn->Add(gcnew String(string.c_str()));
	}
	return rtn;
}

} // namespace myid

/// Concatenate String and wstring
/// \return new String^ object
inline String^ operator+(String^ lhs,						///< source
						 const std::wstring& rhs)			///< what to append
{
	return lhs + myid::ToString(rhs);
}

/// Concatenate wstring and String
/// \return new String^ object
inline String^ operator+(const std::wstring& lhs,			///< source
						 String^ rhs)						///< what to append
{
	return myid::ToString(lhs) + rhs;
}

#endif
