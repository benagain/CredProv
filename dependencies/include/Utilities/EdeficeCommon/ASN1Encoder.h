#pragma once

/** \file
 * Definition of ASN1Encoder, ASN1Sequence, ASN1Set, ASN1Tagged
 */

#ifndef MOBILE
#include <atlcomtime.h>
#endif
#include <list>
#include <string>
#include <vector>
#include <stdint.h>
#include "VectorOfBytePtr.h"
#include "TLVBuilder.h"
#include "BERDecode.h"
#include "OIDs.h"
#include "Crypt.h"
#include <time.h>

namespace ASN1
{

namespace Tags
{
const byte ASN_UNIVERSAL = TLV::Flags::BER_UNIVERSAL;
const byte ASN_APPLICATION = TLV::Flags::BER_APPLICATION;
const byte ASN_CONTEXT = TLV::Flags::BER_CONTEXT;
const byte ASN_PRIVATE = TLV::Flags::BER_PRIVATE;

const byte ASN_PRIMITIVE = TLV::Flags::BER_PRIMITIVE;
const byte ASN_CONSTRUCTED = TLV::Flags::BER_CONSTRUCTED;

const byte ASN_BOOL = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x01);
const byte ASN_INTEGER = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x02);
const byte ASN_BITSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x03);
const byte ASN_OCTETSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x04);
const byte ASN_NULL = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x05);
const byte ASN_OBJECTIDENTIFIER = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x06);
const byte ASN_OBJECTDESCRIPTOR = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x07); // not implemented
const byte ASN_EXTERNAL = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x08); // not implemented
const byte ASN_REAL = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x09); // not implemented
const byte ASN_ENUMERATED = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x0a);
const byte ASN_EMBEDDEDPDV = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x0b); // not implemented
const byte ASN_UTF8STRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x0c);
const byte ASN_RELATIVEOID = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x0d);
const byte ASN_SEQUENCE = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x10);
const byte ASN_SEQUENCEOF = ASN_SEQUENCE;
const byte ASN_SET = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x11);
const byte ASN_SETOF = ASN_SET;

const byte ASN_NUMERICSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x12);
const byte ASN_PRINTABLESTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x13);
const byte ASN_T61STRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x14);
const byte ASN_VIDEOTEXSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x15); // not implemented
const byte ASN_IA5STRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x16);
const byte ASN_UTCTIME = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x17);
const byte ASN_GENERALTIME = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x18);
const byte ASN_GRAPHICSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x19); // not implemented
const byte ASN_VISIBLESTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x1a); // not implemented
const byte ASN_GENERALSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x1b); // not implemented
const byte ASN_UNIVERSALSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x1c);
const byte ASN_CHARACTERSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x1d); // not implemented
const byte ASN_BMPSTRING = (ASN_UNIVERSAL | ASN_PRIMITIVE | 0x1e);

const byte ASN_EXPLICIT = (ASN_CONTEXT | ASN_CONSTRUCTED | 0x00);
} // namespace Tags

namespace Encoder
{
class ASN1Collection;

typedef boost::shared_ptr< class ASN1Encoder > ASN1EncoderPtr;


/** Container class for ASN1 data, with inbuilt encoding of primitives*/
class ASN1Encoder : public myid::TLV::TLVBuilder
{
	typedef myid::TLV::TLVBuilder inherited;
	friend class ASN1Collection;

public:
	ASN1Encoder();

	ASN1Encoder& operator=(_In_ const ASN1Encoder& rhs);
	ASN1Encoder& operator=(_In_ const VectorOfByte& rhs);

#ifndef MOBILE
	void ASN1Encode(const char* lpszStructType, const void* pvStructInfo, const char *pszEncodingType = nullptr);
#endif

	virtual void Clear(void);
	virtual bool IsCollection(void) const;

	void EncodeBool(_In_ bool bBool);
	void EncodeInteger(_In_ int32_t lDataToEncode);
	void EncodeInteger(_In_ uint32_t lDataToEncode);
	void EncodeInteger(_In_ const VectorOfByte& vecDataToEncode, _In_ bool positive = false);
	void EncodeIntegerBlob(_In_ const DATA_BLOB& blob);
	void EncodeEnumerated(_In_ int32_t lDataToEncode);
	void EncodeEnumerated(_In_ uint32_t lDataToEncode);
	void EncodeAttribute(_In_z_ const char* pszOID);
	void EncodeAttribute(_In_z_ const char* pszOID, _In_ const VectorOfByte& vecAttribute);
	void EncodeAttribute(_In_z_ const char* pszOID, _In_ ASN1EncoderPtr& vecAttribute);
	void EncodeAttribute(_In_ const OID& oid);
	void EncodeAttribute(_In_ const OID& oid, _In_ const VectorOfByte& vecAttribute);
	void EncodeAttribute(_In_ const OID& oid, _In_ ASN1EncoderPtr& vecAttribute);
	void EncodeOID(_In_z_ const char* pszOID);
	void EncodeOID(_In_ const OID& oid);
	void EncodeRelativeOID(_In_z_ const char* pszOID);
	void EncodeBitString(_In_ const byte* data, _In_ long lNumBits);
	void EncodeBitString(_In_ const VectorOfByte& vecDataToEncode);
	void EncodeOctetString(_In_ const VectorOfByte& vecDataToEncode);
	void EncodeNumericString(_In_opt_z_ const char* pszString);
	void EncodeT61String(_In_opt_z_ const char* pszString);
	void EncodeIA5String(_In_opt_z_ const char* pszString);
	void EncodePrintableString(_In_opt_z_ const char* pszString);
	void EncodeBMPString(_In_opt_z_ const wchar_t* pszString);
	void EncodeUniversalString(_In_opt_z_ const wchar_t* pszString);
	void EncodeUTF8String(_In_opt_z_ const wchar_t* pszString);
	void EncodeString(_In_ byte stringType, _In_opt_z_ const wchar_t* pszString);
	void EncodeNULL(void);
#ifndef MOBILE
	void EncodeString(_In_ unsigned long dwStringValueType, _In_opt_z_ const wchar_t* pszString);
	void EncodeUTCTime(_In_ const ATL::COleDateTime& dt);
	void EncodeGeneralTime(_In_ const ATL::COleDateTime& dt);
#endif
	void EncodeUTCTime(_In_ const tm& dt);
	void EncodeGeneralTime(_In_ const tm& dt);
	void EncodeTag(_In_ int type, _In_ const VectorOfByte& vecDataToEncode);
	void EncodeTag(_In_ int type, _In_opt_z_ const wchar_t* pszString);
	void Encode(_In_ byte flags, _In_ byte type, _In_ const VectorOfByte& vecDataToEncode);
	void Encode(_In_ byte flags, _In_ byte type, _In_ const byte* data, _In_ unsigned long length);

protected:
	ASN1Encoder(_In_ const byte* first, _In_ const byte* last);

	void Reserve(_In_ unsigned long lLength);
	virtual void Invalidate(void);

	ASN1Collection* m_owner;
};


typedef std::list<ASN1EncoderPtr> TListData;

typedef boost::shared_ptr< class ASN1Collection > ASN1CollectionPtr;

/// Container class for ASN1 sequences
class ASN1Collection : public ASN1Encoder
{
	typedef ASN1Encoder inherited;
	friend class ASN1Encoder;

public:
	virtual void Clear(void);
	virtual bool IsCollection(void) const;
	size_t Count(void) const;
	ASN1Encoder* operator[](_In_ int pos);
	ASN1Collection* Collection(_In_ int pos);

	void AddItem(_In_ ASN1EncoderPtr asn1Content);
	void AddCollection(_In_ ASN1CollectionPtr& asn1Content);

	void AddBlob(_In_ const DATA_BLOB& Blob);
	void AddEncodedData(_In_ const byte* Data, _In_ unsigned long Size);
	void AddBool(_In_ bool bBool);
	void AddInteger(_In_ int32_t lDataToEncode);
	void AddInteger(_In_ uint32_t lDataToEncode);
	void AddInteger(_In_ const VectorOfByte& vecDataToEncode, _In_ bool positive = false);
	void AddIntegerBlob(_In_ const DATA_BLOB& Blob);
	void AddEnumerated(_In_ int32_t lDataToEncode);
	void AddEnumerated(_In_ uint32_t lDataToEncode);
	void AddAttribute(_In_z_ const char* pszOID);
	void AddAttribute(_In_ const OID& oid);
	void AddOID(_In_z_ const char* pszOID);
	void AddOID(_In_ const OID& oid);
	void AddRelativeOID(_In_z_ const char* pszOID);
	void AddBitString(_In_ const byte* data, _In_ long lNumBits);
	void AddBitString(_In_ const VectorOfByte& vecDataToEncode);
	void AddOctetString(_In_ const VectorOfByte& vecDataToEncode);
	void AddNumericString(_In_opt_z_ const char* pszString);
	void AddT61String(_In_opt_z_ const char* pszString);
	void AddIA5String(_In_opt_z_ const char* pszString);
	void AddPrintableString(_In_opt_z_ const char* pszString);
	void AddBMPString(_In_opt_z_ const wchar_t* pszString);
	void AddUniversalString(_In_opt_z_ const wchar_t* pszString);
	void AddUTF8String(_In_opt_z_ const wchar_t* pszString);
	void AddString(_In_ byte stringType, _In_opt_z_ const wchar_t* pszString);
	void AddNULL(void);
#ifndef MOBILE
	void AddString(_In_ unsigned long dwStringValueType, _In_opt_z_ const wchar_t* pszString);
	void AddUTCTime(_In_ const ATL::COleDateTime& dt);
	void AddGeneralTime(_In_ const ATL::COleDateTime& dt);
#endif
	void AddUTCTime(_In_ const tm& dt);
	void AddGeneralTime(_In_ const tm& dt);
	void AddTag(_In_ int type, _In_ const VectorOfByte& vecDataToEncode);

protected:
	ASN1Collection();

	virtual void InternalBuild(void);
	virtual void UpdateBuild(void);
	virtual void DataBuild(void);
	virtual void Invalidate(void);

	TListData m_listContent;				///< individual sequences
	bool	  m_bEncoded;					///< determine if InternalBuild() needs to do anything
};

/// Container class for ASN1 sequences (SEQUENCE and SEQUENCE OF)
class ASN1Sequence : public ASN1Collection
{
	typedef ASN1Collection inherited;

protected:
	virtual void DataBuild(void);
};

/// Container class for ASN1 sets (SET and SET OF)
class ASN1Set : public ASN1Collection
{
	typedef ASN1Collection inherited;

protected:
	virtual void DataBuild(void);
};

/// Container class for ASN1 implicit and explicit tagged types ([0] by default)
class ASN1Tagged : public ASN1Collection
{
	typedef ASN1Collection inherited;

public:
	explicit ASN1Tagged(_In_ int type = 0);

protected:
	virtual void DataBuild(void);

	int	m_type;							///< type of tagged sequence
};

/// Container class for ASN1 constructed octet and bit sequences
class ASN1Wrapped : public ASN1Collection
{
	typedef ASN1Collection inherited;

public:
	explicit ASN1Wrapped(_In_ bool bitstring = false);

protected:
	virtual void DataBuild(void);

	bool m_bitstring;					///< type of wrapped sequence
};

typedef ASN1Encoder CASN1Encoder;
typedef ASN1EncoderPtr CASN1EncoderPtr;
typedef ASN1Collection CASN1Collection;
typedef ASN1CollectionPtr CASN1CollectionPtr;
typedef ASN1Sequence CASN1Sequence;
typedef ASN1Set CASN1Set;
typedef ASN1Tagged CASN1Tagged;
typedef ASN1Wrapped CASN1Wrapped;

}// namespace Encoder
}// namespace ASN1
