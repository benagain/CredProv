#include "B64Conversion.h"
#include "../B64ConversionDirect.h"

namespace myid
{

/// Convert from B64 string to vector
VectorOfBytePtr fromBase64(const std::string& b64)
{
	VectorOfBytePtr bytes(new VectorOfByte);
	base64(b64, (VectorOfByte&)*bytes);
	return bytes;
}

std::string toBase64String(VectorOfByte const & bin)
{
	std::string b64;
	base64(bin, b64);
	return b64;
}

std::wstring toBase64Wstr(VectorOfByte const & bin)
{
	std::wstring b64;
	base64(bin, b64);
	return b64;
}


}	// end namespace myid
