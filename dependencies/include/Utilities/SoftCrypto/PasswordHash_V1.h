#pragma once

#include "PasswordHashPAB.h"

namespace myidPassword
{
/*!
* Implementation of the classic SHA1 password hashing without any salt
*/
class PasswordHash_V1 : public PasswordHashPAB
{
public:
	/*!
	* Salt is not used in V1 of the password hash
	*/
	virtual void SetPersonSalt(_In_ const std::wstring&) {}

	/*!
	* Generate a hashed form of the specified password
	*/
	virtual VectorOfBytePtr MakeHash(_In_z_ const wchar_t *pwszPassword);
};
}