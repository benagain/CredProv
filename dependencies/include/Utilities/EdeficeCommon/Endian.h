#pragma once

#include "VectorOfByte.h"

template<typename T>
T reverseEndian(_In_ VectorOfByte const & data, _In_ size_t offset = 0)
{
	const size_t typeSize = sizeof(T);
	VectorOfByte reversable(&data[offset], &data[offset + typeSize]);
	std::reverse(reversable.begin(), reversable.end());
	return *reinterpret_cast<T*>(&reversable[0]);
}

template<typename T>
T reverseEndian(_In_ T value)
{
	const size_t typeSize = sizeof(T);
	VectorOfByte reversable(typeSize);
	memcpy(&reversable[0], &value, typeSize);
	std::reverse(reversable.begin(), reversable.end());
	return *reinterpret_cast<T*>(&reversable[0]);
}
