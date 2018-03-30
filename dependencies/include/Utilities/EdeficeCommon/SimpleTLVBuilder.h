#pragma once

/** \file
 * Definition of SimpleTLVBuilder
 */

#include "TLVBuilder.h"

namespace myid
{
namespace TLV
{

/// Builds simple TLV sequences
class SimpleTLVBuilder : public TLVBuilder
{
	typedef TLVBuilder inherited;

public:
	SimpleTLVBuilder(void);
	explicit SimpleTLVBuilder(_In_ byte Tag);
	SimpleTLVBuilder(_In_ byte Tag, _In_ byte Value);
	SimpleTLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2);
	SimpleTLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2, _In_ byte Value3);
	SimpleTLVBuilder(_In_ byte Tag, _In_ const VectorOfByte &Value);
	SimpleTLVBuilder(_In_ byte Tag, _In_ const std::wstring& hexValue);

	SimpleTLVBuilder& operator=(_In_ const SimpleTLVBuilder& rhs);

protected:
	virtual void InternalBuild(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	virtual size_t GetLengthNumBytes(_In_ unsigned long lLength);
	virtual void AppendLength(_In_ unsigned long lLength);
};

} // namespace TLV
} // namespace myid