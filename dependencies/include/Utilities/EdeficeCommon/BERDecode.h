#pragma once

/** \file
 * Definition of BERDecode
 */

//#include "BERBuilder.h"
#include "TLVDecode.h"
#include "BERDecodeTemplate.h"

namespace TLV				/// Contains BER decoding
{

namespace Flags
{
const byte BER_UNIVERSAL = 0x00;			///< the usual flag
const byte BER_APPLICATION = 0x40;
const byte BER_CONTEXT = 0x80;			///< value contains raw or BER data depending on the tag
const byte BER_PRIVATE = 0xC0;

const byte BER_PRIMITIVE = 0x00;			///< value contains raw data
const byte BER_CONSTRUCTED = 0x20;			///< value contains BER data
} // namespace Flags

//==========================================================================================================================

/// BER tag. These are tags where the tag length is determined according to BER.
class BERTag : public TLVTag
{
	typedef TLVTag inherited;

public:
	BERTag();
	BERTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag);

	unsigned long	TagType(void) const;
	byte			TagFlags(void) const;
	bool			Constructed(void) const;

	bool			Compare(_In_ unsigned long tagType, _In_ byte tagFlags) const;
	bool			Compare(_In_ unsigned long tagType, _In_ byte tagFlags, _In_ const myid::VectorOfByte& value) const;

	OKBOOL			Get(_Out_ bool& value) const;
	OKBOOL			Get(_Out_ long& value) const;
	OKBOOL			Get(_Out_ unsigned long& value) const;
	OKBOOL			Get(_Out_ long long& value) const;
	OKBOOL			Get(_Out_ unsigned long long& value) const;
	OKBOOL			Get(_Out_ std::string& value) const;
	OKBOOL			Get(_Out_ std::wstring& value) const;

	virtual DecodePtr Decode(_In_ bool copy = false) const;

protected:
	virtual bool ProcessTag(void);
	virtual std::wstring PrintDecode(_In_ int indent) const;
	virtual std::wstring PrintTag(void) const;
};

class BERTagCollection;

/// List of tags
typedef std::list<const BERTag*> BERTagList;

/// BER TLV Decoder. The tag length is determined by BER rules
class BERDecode : public TLVDecode
{
	typedef TLVDecode inherited;

public:
	BERDecode();
	explicit BERDecode(_In_ const BERDecode& rhs);
	explicit BERDecode(_In_ const myid::VectorOfByte& rhs);
	BERDecode(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);

	BERDecode& operator=(_In_ const BERDecode& rhs);
	BERDecode& operator=(_In_ const myid::VectorOfByte& rhs);

	BERTagList BERTags(void) const;
	const BERTag* operator[](_In_ size_t position) const;

protected:
	virtual size_t GetNextTagLength(_In_ myid::VectorOfByte::const_iterator& pos) const;
	virtual TLVTag* CreateTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag) const;
};

/// BER TLV decoder, containing the vector containing the original TLV data
typedef DecodeVector<BERDecode> BERDecodeVector;
typedef boost::shared_ptr<BERDecodeVector> BERDecodeVectorPtr;
typedef boost::shared_ptr<BERDecodeVector const> BERDecodeVectorConstPtr;

/// BER interator
typedef BERIteratorFind<BERTag, BERDecode> BERIterator;

/// BER TLV Decoder with collections.
class BERDecodeCollection : public BERDecode, public DecodeParent<BERTagCollection>
{
	typedef BERDecode inherited;
	friend class IteratorCollection<BERTag, BERDecodeCollection, BERTagCollection>;

public:
	BERDecodeCollection();
	explicit BERDecodeCollection(_In_ const BERTagCollection* parent);
	explicit BERDecodeCollection(_In_ const myid::VectorOfByte& rhs);
	BERDecodeCollection(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);

protected:
	virtual TLVTag* CreateTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag) const;
};

/// BER TLV decoder, containing the vector containing the original TLV data
typedef DecodeVector<BERDecodeCollection> BERDecodeCollectionVector;
typedef boost::shared_ptr<BERDecodeCollectionVector> BERDecodeCollectionVectorPtr;
typedef boost::shared_ptr<BERDecodeCollectionVector const> BERDecodeCollectionVectorConstPtr;

/// A BER collection constructed tag
class BERTagCollection : public BERTag, public TagParent<BERDecodeCollection, BERTagCollection>
{
	typedef BERTag inherited;
	friend class IteratorCollection<BERTag, BERDecodeCollection, BERTagCollection>;

public:
	BERTagCollection(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag, _In_ const BERDecodeCollection* parent);

	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;
	virtual std::wstring ToString(void) const;
	virtual DecodePtr Decode(_In_ bool copy = false) const;

protected:
	virtual bool ProcessTag(void);
};

/// A BER collection wrapped tag
class BERTagWrapper : public BERTagCollection
{
	typedef BERTagCollection inherited;

public:
	BERTagWrapper(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag, _In_ const BERDecodeCollection* parent);

	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;
	virtual std::wstring ToString(void) const;

protected:
	virtual bool ProcessTag(void);
	virtual std::wstring PrintTag(void) const;
};

typedef IteratorCollection<BERTag, BERDecodeCollection, BERTagCollection> BERIteratorCollection;

} // namespace TLV

