#pragma once

#include <boost/scoped_ptr.hpp>
#include "Lock.h"

namespace myid
{

/// Ensure pointer is reset on destruction, as is used as a global variable
template <class S>
class scoped_ptr : public boost::scoped_ptr < S >
{
public:
	~scoped_ptr()
	{
		this->reset();
	}
};

/// Generate an atomic instance of a pointer on first use, return it on subsequent uses
/// \note This also prevent the object being created during the destruction sequence at exit
template <class S>
S* Instance(void)
{
	static scoped_ptr<S> instance;				///< Owned variable instance, ensures destructor gets called
	static myid::lock::CallOnce loaded;			///< initialise once only

	loaded.Call([&]()
	{
		instance.reset(new S);
	});

	return instance.get();
}

/// Generate a member function to create an Instance
template <class S>
class WithInstance
{
public:
	static S& Instance(void)
	{
		return *shared();
	}

	static S* shared(void)
	{
		return myid::Instance<S>();
	}
};

} // namespace myid
