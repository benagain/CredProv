#pragma once

#include "../CommonKey.h"
#include "CSPCommon.h"

/// CSP interface
namespace CspCrypt
{

/// Perform hashing
class Hash : public MyCrypto::Hash, public CspCommon
{
public:
	Hash();
	explicit Hash(_In_ const std::wstring& csp);

	static VectorOfByte SHA1(_In_ const VectorOfByte& data);
	static VectorOfByte SHA256(_In_ const VectorOfByte& data);
	static VectorOfByte SHA384(_In_ const VectorOfByte& data);
	static VectorOfByte SHA512(_In_ const VectorOfByte& data);

	VectorOfByte sha1(_In_ const VectorOfByte& data);
	VectorOfByte sha256(_In_ const VectorOfByte& data);
	VectorOfByte sha384(_In_ const VectorOfByte& data);
	VectorOfByte sha512(_In_ const VectorOfByte& data);

private:
	VectorOfByte hash(_In_ ALG_ID algID, _In_ const VectorOfByte& data);
};

/// Perform HMAC hashing
class HMAC : public MyCrypto::HMAC, public CspCommon
{
public:
	HMAC();
	explicit HMAC(_In_ const std::wstring& csp);

	static VectorOfByte SHA1(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA256(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA384(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA512(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);

	VectorOfByte sha1(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha256(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha384(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha512(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);

private:
	VectorOfByte hmac(_In_ ALG_ID algID, _In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
};

} // namespace CspCrypt
