#pragma once

#include "VS2005Fix.h"
#include <vector>
#include "Utilities/EdeficeCommon/Crypt.h"
#include "Utilities/EdeficeCommon/SalFix.h"
#include "Allocators.h"
#include <boost/config.hpp>


/// A single byte of memory, usually 8 bits
typedef unsigned char byte;

namespace myid
{

/// A contiguous block of bytes
class VectorOfByte : public std::vector<byte, SecureAlloc<byte> >
{
	typedef std::vector<byte, SecureAlloc<byte> > inherited;

public:
	VectorOfByte();
	// cppcheck-suppress noExplicitConstructor
	VectorOfByte(_In_ const VectorOfByte& rhs);
	explicit VectorOfByte(_In_ size_type _Count);
	VectorOfByte(_In_ size_type _Count, _In_ const byte& _Val);
	template<class _Iter> VectorOfByte(_In_ _Iter _First, _In_ _Iter _Last) : inherited(_First, _Last) {}
	explicit VectorOfByte(_In_ const DATA_BLOB& Blob);
	VectorOfByte(_In_reads_bytes_(length) const byte* first, _In_ size_type length);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	// cppcheck-suppress noExplicitConstructor
	VectorOfByte(_In_ std::initializer_list<byte> rhs);
#endif

	VectorOfByte& operator=(_In_ const VectorOfByte& rhs);
	VectorOfByte& operator=(_In_ const DATA_BLOB& Blob);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	VectorOfByte& operator=(_In_ std::initializer_list<byte> rhs);
#endif
	VectorOfByte& operator+=(_In_ const VectorOfByte& rhs);

	byte* ptr(void);
	const byte* ptr(void) const;
	void* vptr(void);
	const void* vptr(void) const;
	iterator iter(_In_ size_type _Off);
	const_iterator iter(_In_ size_type _Off) const;
	unsigned long lsize(void) const;

	void reverse(void);

	void NewBlob(_Out_ DATA_BLOB& Blob) const;
	void SetBlob(_Out_ DATA_BLOB& Blob) const;

	bool get(_Out_writes_bytes_opt_(max_length) void* destination, _In_ size_type max_length) const;
	void set(_In_reads_bytes_opt_(length) const void* first, _In_ size_type length);
};

} // namespace myid

/// A contiguous block of bytes
/// \note This provides a typedef in the global namespace
typedef myid::VectorOfByte VectorOfByte;
