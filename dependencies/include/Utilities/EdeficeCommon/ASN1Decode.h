#pragma once

/** \file
 * Definition of ASNDecode
 */

#ifndef MOBILE
#include <atlcomtime.h>
#endif
#include "Utilities/EdeficeCommon/ASN1Encoder.h"
#include "BERDecode.h"
#include "OIDs.h"

namespace ASN1						/// Contains ASN1 decoding
{
namespace Decoder					/// ASN1 decoder
{

/// ASN1 tag
class ASNTag : public TLV::BERTag
{
	typedef TLV::BERTag inherited;

public:
	ASNTag();
	ASNTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag);

	virtual TLV::DecodePtr Decode(_In_ bool copy = false) const;

	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;
	virtual std::wstring ToString(void) const;
	void Encode(_In_ Encoder::ASN1Encoder* encoder) const;
	bool IsOID(_In_z_ const char* oid) const;
	bool IsOID(_In_ const OID& oid) const;
	bool IsTagged(_In_ int type) const;
	OKBOOL GetTagged(_Out_ _Always_(_Post_valid_) int& type) const;
	OKBOOL GetLong(_Out_ _Always_(_Post_valid_) int32_t& value) const;
	OKBOOL GetDate(_Out_ _Always_(_Post_valid_) tm& value) const;
	OKBOOL GetBits(_Out_ _Always_(_Post_valid_) std::vector<bool>& value) const;
	OKBOOL GetVector(_Out_ _Always_(_Post_valid_) myid::VectorOfByte& value) const;
	OKBOOL GetVector(_Out_ _Always_(_Post_valid_) myid::VectorOfByte& value, _In_ size_t size) const;

protected:
	virtual bool ProcessTag(void);
	virtual std::wstring PrintTag(void) const;
	int32_t ToLong(void) const;
	tm ToDateTime(_In_ int tag) const;
#ifndef MOBILE
	ATL::COleDateTime ToDate(_In_ int tag) const;
#endif
	std::wstring PrintValueLength(void) const;
};

class ASNTagCollection;
class ASNIterator;

/// List of tags
typedef std::list<const ASNTag*> ASNTagList;

/// ASN1 decoder. This is an in place decoder.
class ASNDecode : public TLV::BERDecode, public TLV::DecodeParent<ASNTagCollection>
{
	typedef TLV::BERDecode inherited;
	friend class TLV::IteratorCollection<ASNTag, ASNDecode, ASNTagCollection>;

public:
	ASNDecode();
	explicit ASNDecode(_In_ const ASNDecode& rhs);
	explicit ASNDecode(_In_ const ASNTagCollection* parent);
	explicit ASNDecode(_In_ const myid::VectorOfByte& rhs);
	ASNDecode(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);

	ASNDecode& operator=(_In_ const ASNDecode& rhs);
	ASNDecode& operator=(_In_ const myid::VectorOfByte& rhs);

	void EncodeCollection(_In_ Encoder::ASN1Collection* encoder) const;
	Encoder::ASN1EncoderPtr CreateEncoder(_In_ bool first = false) const;
	virtual bool Decode(void) const;

	ASNTagList ASNTags(void) const;
	const ASNTag* operator[](_In_ size_t position) const;

protected:
	virtual TLV::TLVTag* CreateTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag) const;
};

/// ASN1 decoder, containing the vector containing the original ASN1 string
typedef TLV::DecodeVector<ASNDecode> ASNDecodeVector;

/// An ASN1 collection tag (SEQUENCE, SET, tagged)
class ASNTagCollection : public ASNTag, public TLV::TagParent<ASNDecode, ASNTagCollection>
{
	typedef ASNTag inherited;
	friend class TLV::IteratorCollection<ASNTag, ASNDecode, ASNTagCollection>;

public:
	ASNTagCollection(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag, _In_ const ASNDecode* parent);

	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;
	virtual std::wstring ToString(void) const;
	virtual Encoder::ASN1Encoder* Encode(void) const;

protected:
	virtual bool ProcessTag(void);
	virtual std::wstring PrintTag(void) const;
};

/// An ASN1 wrapper tag (OCTET, BITSTRING)
/// \note These tag types may contain ASN1, or they may not
class ASNTagWrapper : public ASNTagCollection
{
	typedef ASNTagCollection inherited;

public:
	ASNTagWrapper(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag, _In_ const ASNDecode* parent);

	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;
	virtual std::wstring ToString(void) const;
	virtual Encoder::ASN1Encoder* Encode(void) const;

protected:
	virtual bool ProcessTag(void);
	virtual std::wstring PrintTag(void) const;
};

/// Allows stepping through and searching the ASN1 structure
class ASNIterator : public TLV::IteratorCollection<ASNTag, ASNDecode, ASNTagCollection>
{
	typedef IteratorCollection<ASNTag, ASNDecode, ASNTagCollection> inherited;

public:
	explicit ASNIterator(_In_ const ASNDecode& Decode);

	const ASNTag*	FindOID(_In_opt_z_ const char* szOID, _In_ bool next = false, _In_ bool forwards = true);
	const ASNTag*	FindOID(_In_ const OID& oid, _In_ bool next = false, _In_ bool forwards = true);
};


}// namespace Decoder
}// namespace ASN1
