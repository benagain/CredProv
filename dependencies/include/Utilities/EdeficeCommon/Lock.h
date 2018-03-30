#pragma once

#include "LockDef.h"

#if LOCK_TYPE == LOCK_BOOST
	#include "LockBoost.h"
#elif LOCK_TYPE == LOCK_NULL
	#include "LockNull.h"
#elif LOCK_TYPE == LOCK_MANAGED
	#include "LockManaged.h"
#endif

namespace myid
{
namespace lock				/// maintains locks
{

/// Auto locks on create
class AutoMutex : public Mutex
{
public:
	AutoMutex(void);
};

/// Auto share locks on create
class AutoSharedMutex : public SharedMutex
{
public:
	AutoSharedMutex(void);
};

template <class L>
class Auto : private boost::noncopyable
{
public:
	Auto()
		: m_lockable(nullptr)
	{
	}

	explicit Auto(L& lockable)
		: m_lockable(&lockable)
	{
		if (m_lockable)
			m_lockable->Lock();
	}

	virtual ~Auto()
	{
		if (m_lockable)
			m_lockable->Unlock();
	}

protected:
	L* m_lockable;
};

template <class S>
class AutoShared : private boost::noncopyable
{
public:
	AutoShared()
		: m_shareable(nullptr)
	{
	}

	explicit AutoShared(S& shareable)
		: m_shareable(&shareable)
	{
		if (m_shareable)
			m_shareable->ShareLock();
	}

	virtual ~AutoShared()
	{
		if (m_shareable)
			m_shareable->ShareUnlock();
	}

protected:
	S* m_shareable;
};

typedef myid::lock::Auto<myid::lock::Mutex> LockMutex;
typedef myid::lock::Auto<myid::lock::SharedMutex> LockSharedMutex;
typedef myid::lock::AutoShared<myid::lock::SharedMutex> ShareSharedMutex;

} // namespace lock
} // namespace myid
