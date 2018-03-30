#pragma once

#include <comutil.h>

namespace myid
{
	/// a type to a _bstr_t
	template< typename T >
	inline _bstr_t ToBstr(_In_ const T& num)
	{
		std::wostringstream stream;
		stream << num;
		return stream.str().c_str();
	}
}
