#pragma once

/** \file
 * Definition of CompactTLVDecode
 */

#include "TLVDecode.h"

namespace TLV				/// Contains TLV decoding
{

/// Compact TLV tag. The format is a byte XY followed by the value,
/// where X is the tag in the range 0 to 15, and Y is the length in the range 0 to 15.
class CompactTLVTag : public TLVTag
{
	typedef TLVTag inherited;

public:
	CompactTLVTag();
	explicit CompactTLVTag(_In_ const VectorOfByte::const_iterator& tag);

	virtual VectorOfByte	Tag(void) const;
	virtual byte		Tag(_In_ size_t pos) const;

	virtual DecodePtr Decode(_In_ bool copy = false) const;

protected:
	virtual size_t		ProcessLength(_Inout_ VectorOfByte::const_iterator& pos, _In_ const VectorOfByte::const_iterator& end, _Inout_ bool& valid) const;
	virtual std::wstring PrintDecode(_In_ int indent) const;
	virtual std::wstring PrintTag(void) const;
};

/// Compact TLV (CTLV) decoder
class CompactTLVDecode : public TLVDecode
{
	typedef TLVDecode inherited;

public:
	CompactTLVDecode();
	explicit CompactTLVDecode(_In_ const VectorOfByte& rhs);
	CompactTLVDecode(_In_ const VectorOfByte::const_iterator& begin, _In_ const VectorOfByte::const_iterator& end);

	virtual void SetDefaultTagSize(_In_ size_t tagSize);

protected:
	virtual TLVTag* CreateTag(_In_ size_t tagLength, _In_ const VectorOfByte::const_iterator& tag) const;
};

/// Compact TLV decoder, containing the vector containing the original TLV data
typedef DecodeVector<CompactTLVDecode> CompactTLVDecodeVector;
typedef boost::shared_ptr<CompactTLVDecodeVector> CompactTLVDecodeVectorPtr;
typedef boost::shared_ptr<CompactTLVDecodeVector const> CompactTLVDecodeVectorConstPtr;

} // namespace TLV

