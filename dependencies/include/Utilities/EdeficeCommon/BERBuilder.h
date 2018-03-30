#pragma once

/** \file
 * Definition of BERBuilder
 */

#include "TLVBuilder.h"
#include <string>

namespace myid
{
namespace TLV
{

/// Builds BER TLV sequences
class BERBuilder : public TLVBuilder
{
	typedef TLVBuilder inherited;

public:
	BERBuilder(void);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags, _In_ byte value);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags, _In_ byte value1, _In_ byte value2);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags, _In_ byte value1, _In_ byte value2, _In_ byte value3);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags, _In_ const VectorOfByte &value);
	BERBuilder(_In_ unsigned long tag, _In_ byte flags, _In_ const std::wstring& hexvalue);

	BERBuilder& operator=(_In_ const BERBuilder& rhs);

	void Build(_In_ unsigned long tag, _In_ byte flags);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ byte value);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ byte value1, _In_ byte value2);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ byte value1, _In_ byte value2, _In_ byte value3);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ byte value1, _In_ byte value2, _In_ byte value3, _In_ byte value4);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ const VectorOfByte& value);
	void Build(_In_ unsigned long tag, _In_ byte flags, _In_ const std::wstring& hexvalue);

	void build(_In_ unsigned long tag, _In_ byte flags, _In_ bool value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ long value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ unsigned long value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ long long value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ unsigned long long value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_z_ const char* value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_z_ const wchar_t* value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ const std::string& value);
	void build(_In_ unsigned long tag, _In_ byte flags, _In_ const std::wstring& value);

	static VectorOfByte Tag(_In_ unsigned long tag, _In_ byte flags);

protected:
	virtual void InternalBuild(_In_ const VectorOfByte& tag, _In_ size_t Length, _In_ const VectorOfByte& value);
};

} // namespace TLV
} // namespace myid