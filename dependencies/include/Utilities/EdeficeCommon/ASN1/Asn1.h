#pragma once
#include "berfunctions.h"
#include <list>
#include <vector>

#include "Utilities\EdeficeCommon\VectorOfByte.h"

namespace ASN1
{
	typedef enum 
	{
		EndOfContent =		0x00,	//  0: End-of-contents octets
		Boolean =			0x01,	//  1: Boolean
		Integer =			0x02,	//  2: Integer 
		BitString =			0x03,	//  2: Bit string
		OctectString =		0x04,	//  4: Byte string
		NullString =		0x05,	/*  5: NULL */
		ObjectID =			0x06,	/*  6: Object Identifier */
		ObjectDescriptor =	0x07,	/*  7: Object Descriptor */
		External =			0x08,	/*  8: External */
		Real =				0x09,	/*  9: Real */
		Enumerated =		0x0A,	/* 10: Enumerated */
		EmbeddedPDV	=		0x0B,	/* 11: Embedded Presentation Data Value */
		UTF8String =		0x0C,	/* 12: UTF8 string */
		Sequence =			0x10,	/* 16: Sequence/sequence of */
		Set =				0x11,	/* 17: Set/set of */
		NumericString =		0x12,	/* 18: Numeric string */
		PrintableString =	0x13,	/* 19: Printable string (ASCII subset) */
		T61String =			0x14,	/* 20: T61/Teletex string */
		VideoTextString =	0x15,	/* 21: Videotex string */
		IA5String =			0x16,	/* 22: IA5/ASCII string */
		UTCTime =			0x17,	/* 23: UTC time */
		GeneralizedTime =	0x18,	/* 24: Generalized time */
		GraphicString =		0x19,	/* 25: Graphic string */
		VisibleString =		0x1A,	/* 26: Visible string (ASCII subset) */
		GeneralString =		0x1B,	/* 27: General string */
		UniversalString =	0x1C,	/* 28: Universal string */
		BMPString =			0x1E,	/* 30: Basic Multilingual Plane/Unicode string */
		Unknown =			0xFF	/* Unknown type */
	} ASN;

	class CAsn1Object;
	typedef std::list<CAsn1Object*> ComponentsList;


	class CAsn1Object
	{
	protected:
		BERHEADER * m_pHeader;
		unsigned char* m_berData;
		ComponentsList m_Components;
		virtual void decode()= 0;
		ASN m_type;


	public:
		CAsn1Object(void);
		CAsn1Object( unsigned char* berData );
		virtual ~CAsn1Object(void);

		virtual unsigned long get_element_length() { return (unsigned long)m_pHeader->length; };
		virtual unsigned long get_header_length() { return (unsigned long)m_pHeader->headerSize; };

		virtual int countComponents(){ return (int)m_Components.size(); };
		virtual ASN getAsnType();
		virtual bool IsA( ASN type );
		virtual bool IsConstructed();
		virtual ASN getType() { return m_type; };
		virtual CAsn1Object* getComponentAt(int index);
		char* toString();
		virtual CAsn1Object* toASN1Object();
		virtual const char* getValue() = 0;
	};

	class CAsn1BitString : public CAsn1Object
	{
	};

	class CAsn1BMPString : public CAsn1Object
	{
	};

	class CAsn1Boolean : public CAsn1Object
	{
	};

	class CAsn1ConstructedType : public CAsn1Object
	{
	protected:
	public:
		CAsn1ConstructedType(unsigned char* berData ) : CAsn1Object(berData) {};
	};

	class CAsn1ContextSpecific : public CAsn1ConstructedType
	{
	public:
		CAsn1ContextSpecific( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue(){ return NULL; };
	};

	class CAsn1OctectString : public CAsn1ConstructedType
	{
	private:
		VectorOfByte m_Value;
		std::string m_strDisplayValue;
	protected:
		virtual void decode();
	public:
		CAsn1OctectString(unsigned char* berData);
		virtual const char* getValue();
		const byte* getData();
	};

	class CAsn1Sequence : public CAsn1ConstructedType
	{
	protected:
		virtual void decode();
	public:
		CAsn1Sequence(unsigned char* berData);
		virtual const char* getValue(){ return NULL; };
	};

	class CAsn1Set : public CAsn1ConstructedType
	{
	public:
		CAsn1Set( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue(){ return NULL; };
	};

	class CAsn1Unknown : public CAsn1ConstructedType
	{
	protected:
		virtual void decode();

	public:
		CAsn1Unknown( unsigned char* berData );
		virtual const char* getValue(){ return NULL; };
	};

	class CAsn1Enumeration : public CAsn1Object
	{
	};

	class CAsn1GeneralizedTime : public CAsn1Object
	{
	};

	class CAsn1GeneralString : public CAsn1Object
	{
	};

	class CAsn1IA5String : public CAsn1Object
	{
		char* m_pValue;
	public:
		CAsn1IA5String( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue(){ return NULL; };
	};

	class CAsn1Integer : public CAsn1Object
	{
		int m_Value;
		char m_strValue[25];
		VectorOfByte m_largeValue;
		bool m_bLargeValue;
		std::string m_strDisplayValue;
	public:
		CAsn1Integer( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue();
		const byte* getData();
		const int getInteger();

	};

	class CAsn1Null : public CAsn1Object
	{
	};

	class CAsn1NumericString : public CAsn1Object
	{
	};

	class CAsn1ObjectId : public CAsn1Object
	{
		int m_valueLen;
		char* m_value;
	public:
		CAsn1ObjectId( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue();
	};

	class CAsn1PrintableString : public CAsn1Object
	{
		char* m_pValue;
	public:
		CAsn1PrintableString( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue();
	};

	class CAsn1T61String : public CAsn1Object
	{
	};

	class CAsn1UNIString : public CAsn1Object
	{
	};

	class CAsn1UTCTime : public CAsn1Object
	{
	};

	class CAsn1UTF8String : public CAsn1Object
	{
		char* m_pValue;
	public:
		CAsn1UTF8String( unsigned char* berData );
		virtual void decode();
		virtual const char* getValue(){ return m_pValue; };
	};

	class CAsn1VisibleString : public CAsn1Object
	{
	};



	class CAsn1
	{
		std::list<unsigned char*> ComponentList;
		unsigned char* m_berData;
	public:
		CAsn1(void);
		CAsn1(CAsn1Object& o);
		CAsn1(unsigned char* p);
		virtual ~CAsn1(void);

		int countComponents( ){ return (int)ComponentList.size(); };
		CAsn1Object* getComponentAt(int index);
		unsigned char* getFirstObject();
		CAsn1Object* toASN1Object();
		CAsn1Object* findObject(CAsn1Object* pSrc,ASN type,void* pVal);
	};

	class CDerCoder
	{
	public:
		static CAsn1Object* decode(unsigned char* berData);
	};

	class CCodingException 
	{
		char* m_szMessage;
	public:
		CCodingException();
		CCodingException( char* str ){ m_szMessage = str;};
		char* getMessage();
	};
}
