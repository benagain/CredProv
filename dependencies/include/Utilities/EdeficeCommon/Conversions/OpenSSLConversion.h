#pragma once

#include <stddef.h>
#include <string>
#include "../VectorOfBytePtr.h"
#include "../TimeCommon.h"
#include "../OIDs.h"
#include <boost/make_shared.hpp>
#include <openssl/bio.h>
#include <openssl/x509.h>

#include <stdint.h>

namespace OpenSSL
{

/// Generalised conversion from any i2d to a VectorOfByte
template <class T, int F(T* a, unsigned char** out)>
void i2d(_Out_ VectorOfByte& to, _In_opt_ const T* from)
{
	if (from)
	{
		int size = F( const_cast<T*>(from), nullptr );
		to.resize(size);
		byte* b = to.ptr();
		size = F( const_cast<T*>(from), &b );
		to.resize(size);
	}
	else
	{
		to.clear();
	}
}

/// Generalised conversion from any i2d to a VectorOfBytePtr
template <class T, int F(T* a, unsigned char** out)>
void i2d(_Out_ VectorOfBytePtr& to, _In_opt_ const T* from)
{
	if (from)
	{
		int size = F( const_cast<T*>(from), nullptr );
		to = boost::make_shared<VectorOfByte>(size);
		byte* b = to->ptr();
		size = F( const_cast<T*>(from), &b );
		to->resize(size);
	}
	else
	{
		to = boost::make_shared<VectorOfByte>(0);
	}
}

/// Generalised conversion to any d2i from a VectorOfByte
template <class T, T* F(T** a, const unsigned char** in, long len)>
T* d2i(_Out_opt_ T** a, _In_ const VectorOfByte& from)
{
	if (from.empty())
	{
		if (a)
			*a = nullptr;
		return nullptr;
	}

	const byte* bytePointer = from.ptr();
	return F(a, &bytePointer, from.lsize());
}

/// Generalised conversion to any d2i from a VectorOfByte
template <class T, T* F(T** a, const unsigned char** in, long len)>
T* d2i(_In_ const VectorOfByte& from)
{
	return d2i<T, F>(nullptr, from);
}

// to OpenSSL structures
::BIO* ToBIO(_In_ const VectorOfByte& data);
::BIO* ToBIO(_In_ const std::string& data);
::BIGNUM* ToBN(_In_ const VectorOfByte& data);
::BIGNUM* ToBN(_In_ const VectorOfBytePtr& pData);
::ASN1_OBJECT* ToASN1_OBJECT(_In_ const ASN1::OID& data);
::ASN1_OBJECT* ToASN1_OBJECT(_In_ const std::wstring& data);

// from OpenSSL structures
std::string ToStr(_In_opt_ ::BIO* bio);
std::wstring ToWstr(_In_opt_::BIO* bio);
std::wstring ToWstr(_In_opt_ const X509_name_st* name);
std::wstring ToWstr(_In_opt_ const ::ASN1_STRING* asn1);
std::wstring ToWstr(_In_opt_ const ::ASN1_OBJECT* asn1);
std::wstring ToWstr(_In_opt_ const ::ASN1_TYPE* asn1);
myid::Time ToTime(_In_opt_ const ::ASN1_TIME* asn1);
ASN1::OID ToOID(_In_opt_ const ::ASN1_OBJECT* asn1);
bool ToLong(_In_opt_ const ::ASN1_INTEGER* asn1, _Out_ int32_t& value);

VectorOfByte ToASN1(_In_opt_ const X509_name_st* name);
VectorOfByte ToASN1(_In_opt_ const ::ASN1_STRING* asn1);
VectorOfByte ToASN1(_In_opt_ const ::ASN1_OBJECT* asn1);
VectorOfByte ToASN1(_In_opt_ const ::ASN1_TYPE* asn1);
VectorOfByte ToVector(_In_opt_ const ::ASN1_STRING* asn1);
VectorOfByte ToVector(_In_opt_ const ::BIGNUM* bn);
VectorOfByte ToVector(_In_opt_ const ::BIGNUM* bn, _In_ size_t size);
VectorOfByte ToVector(_In_opt_ ::BIO* bio);

std::vector<bool> ToBoolVector(_In_opt_ ::ASN1_BIT_STRING* asn1);

} // namespace OpenSSL
