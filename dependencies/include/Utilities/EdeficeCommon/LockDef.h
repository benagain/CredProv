#pragma once

#define LOCK_BOOST 1		///< use boost, Platform, IOS, Android
#define LOCK_NULL 2			///< do nothing
#define LOCK_MANAGED 3		///< use managed, Managed platform, Win RT

#if defined(_MSC_VER)
	#if defined(_MANAGED) || defined(_DLL)
		#define LOCK_TYPE LOCK_NULL
	#else
		#define LOCK_TYPE LOCK_BOOST
	#endif
	#pragma warning( disable: 4793 4913 )
#else
	#define LOCK_TYPE LOCK_BOOST
#endif

#include <boost/noncopyable.hpp>

namespace myid
{
namespace lock				/// maintains locks
{

class Lockable
{
public:
	virtual void Lock(void) = 0;
	virtual void Unlock(void) = 0;
};

class Shareable
{
public:
	virtual void ShareLock(void) = 0;
	virtual void ShareUnlock(void) = 0;
};

class MutexDef : public Lockable, private boost::noncopyable
{
public:
	MutexDef(void);
	virtual ~MutexDef();
};

class SharedMutexDef : public Lockable, public Shareable, private boost::noncopyable
{
public:
	SharedMutexDef();
	virtual ~SharedMutexDef();
};

} // namespace lock
} // namespace myid
