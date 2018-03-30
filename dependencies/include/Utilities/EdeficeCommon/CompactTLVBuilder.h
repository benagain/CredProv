#pragma once

/** \file
 * Definition of CompactTLVBuilder
 */

#include "TLVBuilder.h"

namespace myid
{
namespace TLV
{

/// Builds compact TLV sequences
class CompactTLVBuilder : public TLVBuilder
{
	typedef TLVBuilder inherited;

public:
	CompactTLVBuilder(void);
	explicit CompactTLVBuilder(_In_ byte Tag);
	CompactTLVBuilder(_In_ byte Tag, _In_ byte Value);
	CompactTLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2);
	CompactTLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2, _In_ byte Value3);
	CompactTLVBuilder(_In_ byte Tag, _In_ const VectorOfByte &Value);
	CompactTLVBuilder(_In_ byte Tag, _In_ const std::wstring& hexValue);

	CompactTLVBuilder& operator=(_In_ const CompactTLVBuilder& rhs);

protected:
	virtual void InternalBuild(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	virtual size_t GetLengthNumBytes(_In_ unsigned long lLength);
	virtual void AppendLength(_In_ unsigned long lLength);
	virtual void Reserve(_In_ size_t Tag, _In_ size_t Length, _In_ size_t Value);
};

} // namespace TLV
} // namespace myid