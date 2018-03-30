#include <stdlib.h>
#include <string.h>
#include <cstring>

namespace myid
{

/// in future improve further by defining version of VectorOfByte with custom allocator class which auto clears memory during every deallocation
bool SecureClear(VectorOfByte& data)
{
	if(data.empty())
		return false;

	memset(&data[0], 0, data.size());

	return true;
}

bool SecureClear(void* first, size_t length)
{
	if ((first == nullptr) || (length == 0))
		return false;

	memset(first, 0, length);

	return true;
}

bool SecureClear(std::string& data)
{
	if(data.empty())
		return false;

	memset(&data[0], 0, data.size());

	return true;
}

bool SecureClear(std::wstring& data)
{
	if(data.empty())
		return false;

	memset(&data[0], 0, data.size() * sizeof(wchar_t));

	return true;
}

}	// end namespace myid
