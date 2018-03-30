#pragma once

#include "PasswordHashPAB.h"

namespace myidPassword
{
/*!
* Salts and hashes a password using multiple iterations of SHA256
*/
class PasswordHash_V2 : public PasswordHashPAB
{
public:
	static const unsigned int SHA256_ITERATIONS = 1009;

	/*!
	* Set the person salt to be combined with the password when generating the hash. This should be
	* called before MakeHash() where a salt is required.
	*/
	virtual void SetPersonSalt(_In_ const std::wstring &wstrPersonSalt);

	/*!
	* Generate a hashed form of the specified password, taking into account the person salt previously
	* set via a call to SetPersonSalt().
	*/
	virtual VectorOfBytePtr MakeHash(_In_z_ const wchar_t *pwszPassword);

private:
	std::wstring m_wstrPersonSalt;
};
}