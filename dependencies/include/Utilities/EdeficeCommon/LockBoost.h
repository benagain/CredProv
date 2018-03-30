#pragma once

#include "LockDef.h"

#if LOCK_TYPE == LOCK_BOOST
// Can use Boost threading
#include <boost/function.hpp>

#pragma warning( push )
#pragma warning( disable: 4913 )
#pragma warning( disable: 4100 ) // Unreferenced formal parameter#include <boost/thread.hpp>
#include <boost/thread.hpp>
#pragma warning( pop )

namespace myid
{
namespace lock				/// maintains locks
{

class Mutex : protected MutexDef
{
public:
	virtual ~Mutex();
	virtual void Lock(void);
	virtual void Unlock(void);

protected:
	boost::mutex		m_mutex;
};

class SharedMutex : protected SharedMutexDef
{
public:
	virtual ~SharedMutex();
	virtual void Lock(void);
	virtual void Unlock(void);
	virtual void ShareLock(void);
	virtual void ShareUnlock(void);

protected:
	boost::shared_mutex		m_mutex;
};

class CallOnce
{
public:
	CallOnce();

	void Call( boost::function<void()> func );

protected:
	boost::once_flag m_called;
};

} // namespace lock
} // namespace myid
#endif
