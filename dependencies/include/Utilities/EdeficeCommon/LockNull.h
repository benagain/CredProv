#pragma once

// Does nothing

#include "LockDef.h"

#if LOCK_TYPE == LOCK_NULL
#include <boost/function.hpp>

namespace myid
{
namespace lock				/// maintains locks
{

class Mutex : public MutexDef
{
public:
	virtual ~Mutex();
	virtual void Lock(void);
	virtual void Unlock(void);
};

class SharedMutex : protected SharedMutexDef
{
public:
	virtual ~SharedMutex();
	virtual void Lock(void);
	virtual void Unlock(void);
	virtual void ShareLock(void);
	virtual void ShareUnlock(void);
};

class CallOnce
{
public:
	CallOnce();

	void Call( boost::function<void()> func );

protected:
	bool m_called;
};

} // namespace lock
} // namespace myid
#endif
