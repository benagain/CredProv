#pragma once

#include <stddef.h>
#include "SalFix.h"
#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include <string>

namespace ASN1
{

/// Represents an OID
class OID : public std::string
{
	typedef std::string inherited;

public:
	OID();
	// cppcheck-suppress noExplicitConstructor
	OID(_In_ const OID& rhs);
	// cppcheck-suppress noExplicitConstructor
	OID(_In_ const std::string& rhs);
	// cppcheck-suppress noExplicitConstructor
	OID(_In_z_ const char* rhs);
	explicit OID(_In_ const VectorOfByte& rhs);

	OID& operator=(_In_ const OID& rhs);
	OID& operator=(_In_ const std::string& rhs);
	OID& operator=(_In_z_ const char* rhs);
	OID& operator=(_In_ const VectorOfByte& rhs);

	std::wstring desc(_In_ bool empty = true) const;
	std::wstring brief(_In_ bool empty = true) const;
	std::wstring DN(void) const;

	VectorOfByte encode(void) const;
	OID& add(_In_ int v1);
	OID& add(_In_ int v1, _In_ int v2);
	OID& add(_In_ int v1, _In_ int v2, _In_ int v3);
	OID& add(_In_ int v1, _In_ int v2, _In_ int v3, _In_ int v4);
};

/// OID encoding and decoding
class OIDCode
{
public:
	static std::wstring Decode(_In_ const VectorOfByte& vec);
	static std::wstring Decode(_In_z_ const byte* oid, _In_ size_t length);
	static std::wstring DecodeRelative(_In_ const VectorOfByte& vec);
	static std::wstring DecodeRelative(_In_z_ const byte* oid, _In_ size_t length);

	static VectorOfByte Encode(_In_ const std::wstring& oid);
	static VectorOfByte Encode(_In_opt_z_ const wchar_t* oid);
	static VectorOfByte Encode(_In_ const std::string& oid);
	static VectorOfByte Encode(_In_opt_z_ const char* oid);
	static VectorOfByte EncodeRelative(_In_ const std::wstring& oid);
	static VectorOfByte EncodeRelative(_In_opt_z_ const wchar_t* oid);
	static VectorOfByte EncodeRelative(_In_ const std::string& oid);
	static VectorOfByte EncodeRelative(_In_opt_z_ const char* oid);

protected:
	static bool Scan(_Inout_z_ const char*& oid, _Out_ unsigned long& value);
};

/// Maintains a list of OIDs and their descriptions.
class OIDList
{
public:
	static void SetOIDfilename(_In_ const std::string& filename);

	static std::wstring OID(_In_ const std::wstring& oid, _In_ bool brief = false, _In_ bool empty = true);
	static std::wstring OID(_In_opt_z_ const wchar_t* oid, _In_ bool brief = false, _In_ bool empty = true);
	static std::wstring OID(_In_ const std::string& oid, _In_ bool brief = false, _In_ bool empty = true);
	static std::wstring OID(_In_opt_z_ const char* oid, _In_ bool brief = false, _In_ bool empty = true);
	static std::wstring DN(_In_ const std::string& oid);
	static std::wstring DN(_In_opt_z_ const char* oid);

	static class OID FromDN(_In_ const std::wstring& dn);
	static class OID FromDN(_In_opt_z_ const  wchar_t* dn);

protected:
	static void Load(void);
	static void LoadDn(void);
};

}// namespace ASN1
