#pragma once

/** \file
 * Definition of SimpleTLVDecode
 */

#include "TLVDecode.h"

namespace TLV				/// Contains BER decoding
{

/// Simple TLV tag.
class SimpleTLVTag : public TLVTag
{
	typedef TLVTag inherited;

public:
	SimpleTLVTag();
	SimpleTLVTag(_In_ size_t tagLength, _In_ const VectorOfByte::const_iterator& tag);

	virtual DecodePtr Decode(_In_ bool copy = false) const;

protected:
	virtual size_t		ProcessLength(_Inout_ VectorOfByte::const_iterator& pos, _In_ const VectorOfByte::const_iterator& end, _Inout_ bool& valid) const;
	virtual bool		ProcessTag(void);
};

/// Simple TLV Decoder.
class SimpleTLVDecode : public TLVDecode
{
	typedef TLVDecode inherited;

public:
	SimpleTLVDecode();
	explicit SimpleTLVDecode(_In_ const VectorOfByte& rhs);
	SimpleTLVDecode(_In_ const VectorOfByte::const_iterator& begin, _In_ const VectorOfByte::const_iterator& end);

	virtual void SetDefaultTagSize(_In_ size_t tagSize);

protected:
	virtual TLVTag* CreateTag(_In_ size_t tagLength, _In_ const VectorOfByte::const_iterator& tag) const;
};

/// Simple TLV decoder
typedef DecodeVector<SimpleTLVDecode> SimpleTLVDecodeVector;
typedef boost::shared_ptr<SimpleTLVDecodeVector> SimpleTLVDecodeVectorPtr;
typedef boost::shared_ptr<SimpleTLVDecodeVector const> SimpleTLVDecodeVectorConstPtr;

typedef DecodeVectorValue<SimpleTLVDecode> SimpleTLVDecodeVectorValue;
typedef boost::shared_ptr<SimpleTLVDecodeVectorValue> SimpleTLVDecodeVectorValuePtr;
typedef boost::shared_ptr<SimpleTLVDecodeVectorValue const> SimpleTLVDecodeVectorValueConstPtr;

} // namespace TLV
