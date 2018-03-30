#pragma once

#include "LockDef.h"
#undef LOCK_TYPE
#define LOCK_TYPE LOCK_MANAGED

#if LOCK_TYPE == LOCK_MANAGED
#include <boost/function.hpp>

using namespace System::Threading;

namespace myid
{
namespace lock				/// maintains locks
{

#pragma managed(push)
ref class MutexImpl
{
public:
	~MutexImpl() {}
	virtual void Lock(void) {}
	virtual void Unlock(void) {}

protected:
	System::Threading::Mutex^	m_mutex;
};

#pragma unmanaged
class MutexManaged : public MutexDef
{
public:
	virtual ~MutexManaged();
	virtual void Lock(void);
	virtual void Unlock(void);
};

class SharedMutexManaged : protected SharedMutexDef
{
public:
	virtual ~SharedMutexManaged();
	virtual void Lock(void);
	virtual void Unlock(void);
	virtual void ShareLock(void);
	virtual void ShareUnlock(void);
};

class CallOnceManaged
{
public:
	CallOnceManaged();

	void Call(boost::function<void()> func);

protected:
	bool m_called;
};
#pragma managed(pop)

} // namespace lock
} // namespace myid
#endif
