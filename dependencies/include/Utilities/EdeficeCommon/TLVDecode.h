#pragma once

/** \file
 * Definition of TLVDecode
 */

#include "VectorOfByte.h"
#include <list>
#include <boost/shared_ptr.hpp>
#include "Utilities/EdeficeCommon/Conversions/VectorOfByteConversion.h"
#include "TLVDecodeTemplate.h"

namespace TLV				/// Contains TLV etc decoding
{

typedef boost::shared_ptr<class TLVDecode> DecodePtr;

/// A TLV tag. This does not contain any data, but references part of a string held elsewhere.
class TLVTag
{
	friend class TLVDecode;

public:
	TLVTag();
	TLVTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag);
	virtual ~TLVTag();

	virtual myid::VectorOfByte	Tag(void) const;
	virtual byte		Tag(_In_ size_t pos) const;
	std::wstring		HexTag(void) const;
	size_t				TagLength(void) const;
	unsigned long		TagValue(void) const;

	myid::VectorOfByte	Value(void) const;
	byte				Value(_In_ size_t pos) const;
	myid::VectorOfByte	Value(_In_ size_t pos, _In_ size_t count) const;
	std::wstring		HexValue(void) const;
	size_t				ValueLength(void) const;
	bool				ValueIsPrintable(void) const;

	virtual DecodePtr	Decode(_In_ bool copy = false) const;

	bool				Compare(_In_ byte tag) const;
	bool				Compare(_In_ const myid::VectorOfByte& tag) const;
	bool				Compare(_In_ byte tag, _In_ const myid::VectorOfByte& value) const;
	bool				Compare(_In_ const myid::VectorOfByte& tag, _In_ const myid::VectorOfByte& value) const;
	bool				CompareValue(_In_ const myid::VectorOfByte& value) const;

	virtual std::wstring ToString(void) const;
	virtual std::wstring Print(_In_ bool nest, _Inout_ int& indent) const;

protected:
	void				Tag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag);
	void				Value(_In_ size_t valueLength, _In_ const myid::VectorOfByte::const_iterator& value);
	virtual bool		ProcessTag(void);
	virtual size_t		ProcessLength(_Inout_ myid::VectorOfByte::const_iterator& pos, _In_ const myid::VectorOfByte::const_iterator& end, _Inout_ bool& valid) const;
	virtual std::wstring PrintTag(void) const;
	virtual std::wstring PrintDecode(_In_ int indent) const;
	bool				IndefiniteLength(void) const;

	size_t								m_TagLength;		///< length of Tag (usually 1)
	myid::VectorOfByte::const_iterator	m_Tag;				///< pointer to start of Tag
	size_t								m_ValueLength;		///< length of Value
	myid::VectorOfByte::const_iterator	m_Value;			///< pointer to start of Value
};

/// List of tags
typedef std::list<TLVTag*> TagList;

/// TLV Decoder. This is an in place decoder. The original TLV data is only referenced.
class TLVDecode
{
public:
	TLVDecode();
	explicit TLVDecode(_In_ const TLVDecode& rhs);
	explicit TLVDecode(_In_ const myid::VectorOfByte& rhs);
	TLVDecode(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);
	virtual ~TLVDecode();

	TLVDecode& operator=(_In_ const TLVDecode& rhs);
	TLVDecode& operator=(_In_ const myid::VectorOfByte& rhs);
	const TagList& Tags(void) const;
	size_t Count(void) const;
	bool Empty(void) const;
	const TLVTag* operator[](_In_ size_t position) const;

	void Set(_In_ const TLVTag& tag);
	void Set(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);
	void SetValue(_In_ const myid::VectorOfByte& value);
	void SetValue(_In_ const myid::VectorOfByte::const_iterator& begin, _In_ const myid::VectorOfByte::const_iterator& end);
	void SetEmpty(void);

	const TLVTag* Find(_In_ byte tag) const;
	const TLVTag* Find(_In_ const myid::VectorOfByte& tag) const;
	const TLVTag* Find(_In_ const std::wstring& hextag) const;
	const TLVTag* Find(_In_ byte tag, _In_ const myid::VectorOfByte& value) const;
	const TLVTag* Find(_In_ const myid::VectorOfByte& tag, _In_ const myid::VectorOfByte& value) const;
	bool FindValue(_In_ byte tag, _Out_ myid::VectorOfByte& value) const;
	bool FindValue(_In_ const myid::VectorOfByte& tag, _Out_ myid::VectorOfByte& value) const;
	bool FindValue(_In_ const std::wstring& hextag, _Out_ myid::VectorOfByte& value) const;

	virtual void SetDefaultTagSize(_In_ size_t tagSize);

	void Reset(void) const;
	virtual bool Decode(void) const;
	bool Valid(void) const;
	std::wstring Print(_In_ bool nest = true, _In_ int indent = 0) const;
	myid::VectorOfByte Data(void) const;
	myid::VectorOfByte Value(void) const;

protected:
	virtual size_t GetNextTagLength(_In_ myid::VectorOfByte::const_iterator& pos) const;
	virtual TLVTag* CreateTag(_In_ size_t tagLength, _In_ const myid::VectorOfByte::const_iterator& tag) const;
	bool CondDecode(void) const;

	size_t				m_DefaultTagSize;				///< default tag size
	mutable bool		m_Valid;						///< decode is valid
	mutable bool		m_Decoded;						///< whether or not a decode has been done
	mutable TagList		m_TagList;						///< list of tags
	myid::VectorOfByte::const_iterator	m_Begin;		///< begin position
	myid::VectorOfByte::const_iterator	m_End;			///< end position
	bool				m_SeparateValue;				///< value array is separate
	myid::VectorOfByte::const_iterator	m_BeginValue;	///< begin value position
	myid::VectorOfByte::const_iterator	m_EndValue;		///< end value position
	static VectorOfByte EmptyData;						///< empty vector to keep iterators populated
};

/// TLV Decoder. This contains a vector to hold the data to decode.
typedef DecodeVector<TLVDecode> TLVDecodeVector;
typedef boost::shared_ptr<TLVDecodeVector> TLVDecodeVectorPtr;
typedef boost::shared_ptr<TLVDecodeVector const> TLVDecodeVectorConstPtr;
typedef DecodeVectorValue<TLVDecode> TLVDecodeVectorValue;

/// Generic TLV iterator
typedef Iterator<TLVTag, TLVDecode> TLVIterator;

} // namespace TLV

