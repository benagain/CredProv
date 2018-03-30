#include "../SalFix.h"

#pragma comment(lib, "crypt32.lib")

namespace ASN1
{
using namespace Tags;

namespace Encoder
{

/// \deprecated - It probably is easier to use the Encode* functions or ASN1Collection directly than 
/// to try to interface to CryptEncodeObject()
/// \exception myid::ErrorException
/// \exception myid::LocalisedException
void ASN1Encoder::ASN1Encode(_In_z_ const char* lpszStructType, _In_ const void* pvStructInfo, _In_z_ const char *pszEncodingType)
{
	unsigned long dwSizeOfEncodedData(0);
	BOOL bRet = CryptEncodeObject(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, lpszStructType, pvStructInfo, NULL, &dwSizeOfEncodedData);
	if(!bRet)
	{
		unsigned long error = GetLastError();
		throw myid::ErrorException(LOCALISE_FN, error, myid::ToWstr(pszEncodingType));
	}
	
	if (dwSizeOfEncodedData == 0)
		throw myid::LocalisedException(LOCALISE_FN, L"No bytes allocated");

	resize(dwSizeOfEncodedData);
	bRet = CryptEncodeObject(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, lpszStructType, pvStructInfo, &front(), &dwSizeOfEncodedData);
	if(!bRet)
	{
		unsigned long error = GetLastError();
		throw myid::ErrorException(LOCALISE_FN, error, myid::ToWstr(pszEncodingType));
	}
}

/// encode a string into one of several types
/// \exception myid::LocalisedException
void ASN1Encoder::EncodeString(_In_ unsigned long dwStringValueType, _In_opt_z_ const wchar_t* pszString)
{
	switch(dwStringValueType)
	{
	case CERT_RDN_NUMERIC_STRING:
		EncodeString(ASN_NUMERICSTRING, pszString);
		break;

	case CERT_RDN_T61_STRING:
		EncodeString(ASN_T61STRING, pszString);
		break;

	case CERT_RDN_IA5_STRING:
		EncodeString(ASN_IA5STRING, pszString);
		break;

	case CERT_RDN_PRINTABLE_STRING:
		EncodeString(ASN_PRINTABLESTRING, pszString);
		break;

	case CERT_RDN_UNICODE_STRING:
		EncodeString(ASN_BMPSTRING, pszString);
		break;

	case CERT_RDN_UTF8_STRING:
		EncodeString(ASN_UTF8STRING, pszString);
		break;

	default:
		throw myid::LocalisedException(LOCALISE_FN, L"Unknown string type");
	}
}

/// Encode a UTC time
void ASN1Encoder::EncodeUTCTime(_In_ const ATL::COleDateTime& dt)
{
	std::stringstream str;
	str << std::dec << std::setw(2) << std::setfill('0');
	str << (dt.GetYear() % 100) << dt.GetMonth() << dt.GetDay();
	str << dt.GetHour() << dt.GetMinute() << dt.GetSecond() << "Z";

	std::string data = str.str();

	Reserve(static_cast<unsigned long>(data.length()));
	push_back(ASN_UTCTIME);
	AppendLength(static_cast<unsigned long>(data.length()));
	insert(end(), data.begin(), data.end());
}

/// Encode a general time
void ASN1Encoder::EncodeGeneralTime(_In_ const ATL::COleDateTime& dt)
{
	std::stringstream str;
	str << std::dec << std::setw(4) << std::setfill('0');
	str << dt.GetYear() << std::setw(2) << dt.GetMonth() << dt.GetDay();
	str << dt.GetHour() << dt.GetMinute() << dt.GetSecond() << "Z";

	std::string data = str.str();

	Reserve(static_cast<unsigned long>(data.length()));
	push_back(ASN_GENERALTIME);
	AppendLength(static_cast<unsigned long>(data.length()));
	insert(end(), data.begin(), data.end());
}

/// Adds to the collection
void ASN1Collection::AddString(_In_ unsigned long dwStringValueType, _In_opt_z_ const wchar_t* pszString)
{
	ASN1EncoderPtr asn1Content( new ASN1Encoder) ;
	asn1Content->EncodeString(dwStringValueType, pszString);
	AddItem(asn1Content);
}

/// Adds to the collection
void ASN1Collection::AddUTCTime(_In_ const ATL::COleDateTime& dt)
{
	ASN1EncoderPtr asn1Content( new ASN1Encoder) ;
	asn1Content->EncodeUTCTime(dt);
	AddItem(asn1Content);
}

/// Adds to the collection
void ASN1Collection::AddGeneralTime(_In_ const ATL::COleDateTime& dt)
{
	ASN1EncoderPtr asn1Content( new ASN1Encoder) ;
	asn1Content->EncodeGeneralTime(dt);
	AddItem(asn1Content);
}

}// namespace Encoder
}// namespace ASN1
