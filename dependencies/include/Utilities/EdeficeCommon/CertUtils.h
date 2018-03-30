#pragma once

namespace myid
{

class CertUtils
{ 
public:

	static myid::VectorOfByte DecodeB64Cert( std::wstring const & certB64 );

	// decode a buffer containing a TLV
	static void DecodeTLV( myid::VectorOfByte const & tlv, byte & tag, myid::VectorOfByte & value);

	// extract a TLV from a buffer
	static myid::VectorOfByte ExtractTLV(byte const * const pByte, DWORD bytesRemaining);

};

} // namespace myid 
