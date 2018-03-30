#pragma once

// Allocators used with STL collection classes

#include "LeanWindows.h"

// Allocator to zero the used memory when the collection is destructed
template <class T> class SecureAlloc : public std::allocator<T>
{
	typedef std::allocator<T> inherited;

public:
	template<class U> struct rebind
	{
		typedef SecureAlloc<U> other;
	};

	SecureAlloc() throw() : m_bIsSecure(true) {}
	// cppcheck-suppress noExplicitConstructor
	SecureAlloc(_In_ const SecureAlloc& copy) throw() : inherited(copy), m_bIsSecure(copy.m_bIsSecure) {}
	// cppcheck-suppress noExplicitConstructor
	template <class U> SecureAlloc(_In_ const SecureAlloc<U>& copy) throw() : inherited(copy), m_bIsSecure(copy.GetSecure()) {}
	bool GetSecure() const { return m_bIsSecure; }

	/// clear the memory prior to it being freed
	void deallocate(typename inherited::pointer p, typename inherited::size_type n)
	{
		if (m_bIsSecure && n)
		{
#if (defined(_MANAGED) && defined(_M_X64)) || defined(MOBILE)
			// this is a fixed version copied from the low level implementation in winnt.h
			volatile char *v = (volatile char *)p;
			while (n)
			{
				*v = 0;
				v++;
				n--;
			}
#else
			SecureZeroMemory(p, n * sizeof(T));
#endif
		}

		inherited::deallocate(p, n);
	}
protected:
	bool m_bIsSecure;
};

