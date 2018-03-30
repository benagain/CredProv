#pragma once

#include "../VectorOfByte.h"
#include "../Exceptions/LocalisedException.h"

namespace myid
{

	template<typename T> T ExtractBigEndianNumber(byte const * const p, size_t len)
	{
		if ( sizeof( T ) < len )
		{
			throw myid::LocalisedException(LOCALISE_FN_STATIC, L"Type too small to contain data");
		}

		return std::accumulate(p, p + len, (T)0, [](T total, byte addition){ return (total << 8) + addition; });
	}

	template<typename T> T ExtractBigEndianNumber(byte const * const p)
	{
		return ExtractBigEndianNumber<T>(p, sizeof(T));
	}

	template<typename T> T ExtractBigEndianNumber(VectorOfByte const & buffer, size_t offset = 0)
	{
		if ( (buffer.size() - offset) < sizeof(T))
		{
			throw myid::LocalisedException(LOCALISE_FN_STATIC, L"Buffer too small to contain type");
		}

		ExtractBigEndianNumber( &buffer[offset], sizeof(T));
	}
}
