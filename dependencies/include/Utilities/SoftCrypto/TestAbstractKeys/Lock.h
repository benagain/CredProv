#pragma once

/// Basic auto unlock mutex
/// Call register before the first call within the instance of an object (i.e. class constructor)
/// Call the constructor to lock the object (throws if it can't)
/// Allow to go out of scope to unlock it.
/// Call Unregister when the object has finished with the mutex and it can be destroyed.
/// There can only be one instance of this class in a program, because the mutex is static.
class CLock
{
public:
	static void Register(void);
	static void UnRegister(void);

	CLock(const DWORD& timeout = INFINITE);
	virtual ~CLock();

private:
	bool Lock(const DWORD& timeout = INFINITE);
	void Unlock(void);

private:
	static HANDLE m_Mutex;
	static unsigned int m_MutexCount;
};
