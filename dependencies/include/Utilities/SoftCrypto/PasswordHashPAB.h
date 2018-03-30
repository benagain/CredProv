#pragma once

#include <string>
#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"

namespace myidPassword
{
/*!
* Pure Abstract Baseclass for password hashing algorithm. Concrete implementations of this will be
* suitable for saving password hashes, and also suitable for use inside ClientPasswordAuthenticator
*/
class PasswordHashPAB
{
public:
	/*!
	* Set the person salt to be combined with the password when generating the hash. This should be
	* called before MakeHash() where a salt is required.
	*/
	virtual void SetPersonSalt(_In_ const std::wstring &wstrPersonSalt) = 0;

	/*!
	* Generate a hashed form of the specified password, taking into account the person salt previously
	* set via a call to SetPersonSalt() where supported by the algorithm implementation.
	*/
	virtual VectorOfBytePtr MakeHash(_In_z_ const wchar_t *pwszPassword) = 0;
};
}