#pragma once

/** \file
 * Definition of TLVBuilder
 */

#include <boost/shared_ptr.hpp>
#include "VectorOfByte.h"
#include "Crypt.h"
#include <vector>
#include <string>

namespace myid
{
namespace TLV
{

/// Builds DER TLV sequences
class TLVBuilder : public myid::VectorOfByte
{
	typedef myid::VectorOfByte inherited;

public:
	TLVBuilder(void);
	explicit TLVBuilder(_In_ byte Tag);
	TLVBuilder(_In_ byte Tag, _In_ byte Value);
	TLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2);
	TLVBuilder(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2, _In_ byte Value3);
	TLVBuilder(_In_ byte Tag, _In_ const VectorOfByte &Value);
	TLVBuilder(_In_ byte Tag, _In_ const std::wstring& hexValue);
	TLVBuilder(_In_ byte Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	TLVBuilder(_In_ byte Tag, _In_ size_t Length, _In_ const std::wstring& hexValue);
	TLVBuilder(_In_ const VectorOfByte& Tag, _In_ const VectorOfByte& Value);
	TLVBuilder(_In_ const std::wstring& hexTag, _In_ const VectorOfByte& Value);
	TLVBuilder(_In_ const std::wstring& hexTag, _In_ const std::wstring& hexValue);
	TLVBuilder(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	TLVBuilder(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const std::wstring& hexValue);
	TLVBuilder(_In_ const byte* first, _In_ const byte* last);
	virtual ~TLVBuilder(void);

	TLVBuilder& operator=(_In_ const TLVBuilder& rhs);
	TLVBuilder& operator=(_In_ const VectorOfByte& rhs);

	void Build(_In_ byte Tag);
	void Build(_In_ byte Tag, _In_ byte Value);
	void Build(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2);
	void Build(_In_ byte Tag, _In_ byte Value1, _In_ byte Value2, _In_ byte Value3);
	void Build(_In_ byte Tag, _In_ const VectorOfByte& Value);
	void Build(_In_ byte Tag, _In_ const std::wstring& hexValue);
	void Build(_In_ byte Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	void Build(_In_ byte Tag, _In_ size_t Length, _In_ const std::wstring& hexValue);
	void Build(_In_ const VectorOfByte& Tag, _In_ const VectorOfByte& Value);
	void Build(_In_ const std::wstring& hexTag, _In_ const VectorOfByte& Value);
	void Build(_In_ const std::wstring& hexTag, _In_ const std::wstring& hexValue);
	void Build(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	void Build(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const std::wstring& hexValue);

	const VectorOfByte& GetData(void);
	void NewBlob(_Out_ DATA_BLOB& Blob);
	void SetBlob(_Out_ DATA_BLOB& Blob);

protected:
	virtual void InternalBuild(void);
	virtual void UpdateBuild(void);

	virtual void InternalBuild(_In_ const VectorOfByte& Tag, _In_ size_t Length, _In_ const VectorOfByte& Value);
	virtual size_t GetLengthNumBytes(_In_ unsigned long lLength);
	virtual void AppendLength(_In_ unsigned long lLength);
	virtual void AppendValue(_In_ size_t ValueLength, _In_ const VectorOfByte& Value);
	virtual void Reserve(_In_ size_t Tag, _In_ size_t Length, _In_ size_t Value);
};

/// smart pointer for TLVBuilder
typedef boost::shared_ptr<TLVBuilder> TLVEncoderPtr;

} // namespace TLV
} // namespace myid

// for old code
typedef myid::TLV::TLVBuilder TLVBuilder;
typedef myid::TLV::TLVEncoderPtr TLVEncoderPtr;

