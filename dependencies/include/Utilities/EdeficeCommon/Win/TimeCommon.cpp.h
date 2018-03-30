#include <WinDef.h>

namespace myid
{

Time::Time(_In_ const ::FILETIME& rhs)
{
	operator=(rhs);
}

Time::Time(_In_ const SYSTEMTIME& rhs)
{
	operator=(rhs);
}

Time& Time::operator=(_In_ const ::FILETIME& rhs)
{
	SYSTEMTIME st;
	if (FileTimeToSystemTime(&rhs, &st))
		return operator=(st);

	clear();
	return *this;
}

Time& Time::operator=(_In_ const SYSTEMTIME& rhs)
{
	if (set(rhs.wYear, rhs.wMonth, rhs.wDay, rhs.wHour, rhs.wMinute, rhs.wSecond))
		normalise();
	else
		clear();

	return *this;
}

Time::operator ::FILETIME() const
{
	::FILETIME rtn;
	if (m_initialised)
	{
		SYSTEMTIME st = operator SYSTEMTIME();
		if (SystemTimeToFileTime(&st, &rtn))
			return rtn;
	}
	memset(&rtn, 0, sizeof(rtn));

	return rtn;
}

Time::operator SYSTEMTIME() const
{
	SYSTEMTIME rtn;
	if (m_initialised)
	{
		rtn.wYear = (WORD)year();
		rtn.wMonth = (WORD)month();
		rtn.wDay = (WORD)day();
		rtn.wHour = (WORD)hour();
		rtn.wMinute = (WORD)minute();
		rtn.wSecond = (WORD)sec();
		rtn.wMilliseconds = 0;
		rtn.wDayOfWeek = (WORD)week_day();
	}
	else
	{
		memset(&rtn, 0, sizeof(rtn));
	}
	return rtn;
}

} // namespace myid
