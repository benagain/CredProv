#pragma once

#include "../CommonKey.h"

/// CNG bcrypt interface
namespace CngCrypt
{

/// Perform hashing
class Hash : public MyCrypto::Hash
{
public:
	static VectorOfByte SHA1(_In_ const VectorOfByte& data);
	static VectorOfByte SHA256(_In_ const VectorOfByte& data);
	static VectorOfByte SHA384(_In_ const VectorOfByte& data);
	static VectorOfByte SHA512(_In_ const VectorOfByte& data);

	VectorOfByte sha1(_In_ const VectorOfByte& data);
	VectorOfByte sha256(_In_ const VectorOfByte& data);
	VectorOfByte sha384(_In_ const VectorOfByte& data);
	VectorOfByte sha512(_In_ const VectorOfByte& data);
};

/// Perform HMAC hashing
class HMAC : public MyCrypto::HMAC
{
public:
	static VectorOfByte SHA1(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA256(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA384(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	static VectorOfByte SHA512(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);

	VectorOfByte sha1(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha256(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha384(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
	VectorOfByte sha512(_In_ const VectorOfByte& data, _In_ const VectorOfByte& key);
};

} // namespace CngCrypt
