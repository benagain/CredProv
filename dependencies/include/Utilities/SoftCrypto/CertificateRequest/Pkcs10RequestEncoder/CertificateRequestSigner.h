#pragma once

#include "Utilities\EdeficeCommon\VectorOfBytePtr.h"
#include "CertificateRequestEncoder.h"

/** Interface for signing portions of a PKCS#10 certificate request.
 \see CertificateRequestEncoder::signedEncode()
 */
class Pkcs10RequestSigner
{
public:
	/// Sign the given data and return the signature
	virtual VectorOfBytePtr SignPkcs10Request(VectorOfByte const& data, std::wstring const& keyName) = 0;

protected:
	virtual Pkcs10RequestEncoder* CreateEncoder(Pkcs10RequestEncoder::Endian endian = Pkcs10RequestEncoder::big_endian, bool bNoASN1Auto = false)
	{
		return new Pkcs10RequestEncoder( endian, bNoASN1Auto);
	}
};
