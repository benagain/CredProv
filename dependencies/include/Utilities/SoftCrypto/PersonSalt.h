#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"

namespace myidPassword
{
class PersonSalt
{
public:
	/*!
	* Calculate the password salt for a person given their ID
	*/
	void Calculate(_In_ const long lID, _Out_ VectorOfByte &vecSalt);
};
}