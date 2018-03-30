#include "../SalFix.h"

#ifndef COMPONENTNAME
#	include "DebugWriter.h"
#else
#	include "..\DebugWriter.cpp"
#endif

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

namespace
{

bool TraceTested = false;		///< if existence of Trace registry has been tested
bool TraceExists = false;		///< if Trace registry exists

std::wstring Component;			///< module component name

struct DebugCache				/// debug data
{
	DWORD m_level;				///< debug level
	std::string m_location;		///< output location
};

typedef std::map<std::wstring, DebugCache> cache;
cache Cache;					///< cache data
time_t CacheTime = 0;			///< last refresh time
ATL::CComAutoCriticalSection CacheLock;	///< cache lock
} // anon namespace

// constructor - reads registry to set trace level and location
CDebug::CDebug()
	: m_nDebugLevel((DWORD)LevelUndefined)
	, m_nLevelFlag(LevelFlag::ENABLED)
{
	DWORD dwLastError = GetLastError(); // rather than lose it
	ReadRegistryData();
	AddWriters();
	SetLastError(dwLastError); // reset it
}

CDebug::CDebug(_In_opt_z_ char const * fn)
	: m_nDebugLevel((DWORD)LevelUndefined)
	, m_nLevelFlag(LevelFlag::ENABLED)
{
	ReadRegistryData();
	AddWriters();

	if (fn && *fn)
		m_function = myid::ToWstr(fn);
}


/// Create a debugger that pretends to be in a different component, and so will
/// pick up the configuration for that component from the registry.
CDebug::CDebug(_In_ CDebug::ComponentName const & component)
	: m_nDebugLevel((DWORD)LevelUndefined)
	, m_nLevelFlag(LevelFlag::ENABLED)
	, m_component( component )
{
	ReadRegistryData(true);
	AddWriters();
}

/// reset the cache state
void CDebug::ClearCache(void)
{
	if (CacheTime != 0)
	{
		CacheLock.Lock();

		TraceTested = false;
		TraceExists = false;

		Component.clear();
		Cache.clear();

		CacheTime = 0;

		CacheLock.Unlock();
	}
}

/// Method to read registry for debug settings and set them in the class
void CDebug::ReadRegistryData(_In_ bool all)
{
	m_nDebugLevel = (DWORD)LevelUndefined;
	m_strDebugLocation = DEBUGLOG;

	if (TraceTested && !TraceExists)
		return;

	try
	{
		CacheLock.Lock();
		if (m_component.empty())
		{
			if (Component.empty())
			{
				// this is static, and only needs to be determined once
#ifndef COMPONENTNAME // COMPONENTNAME definition will override automatic name retrieval
				wchar_t szDLLPath[MAX_PATH];
				GetModuleFileNameW((HINSTANCE)&__ImageBase, szDLLPath, MAX_PATH);

				std::wstring wstrPath = szDLLPath;
				size_t lastSlashPos = wstrPath.rfind(L"\\");
				size_t lastDotPos = wstrPath.rfind(L".");

				if (lastSlashPos != wstrPath.npos && lastDotPos > lastSlashPos)
					Component = wstrPath.substr(lastSlashPos + 1, lastDotPos - lastSlashPos - 1);
				else
					Component = wstrPath;
#else
				Component = COMPONENTNAME;
#endif
			}

			m_component = Component;
		}

		if (TestDebugLevel != (DWORD)LevelUndefined)
		{
			m_nDebugLevel = TestDebugLevel;
			TraceExists = true;
			CacheTime = 1;
		}
		else
		{
			// clear the cache every 10 seconds
			time_t n;
			time(&n);
			if (CacheTime + 10 < n)
			{
				Cache.clear();
				CacheTime = n;
			}

			// search the cache
			cache::iterator iter = Cache.find(m_component);
			if (iter != Cache.end())
			{
				m_nDebugLevel = iter->second.m_level;
				m_strDebugLocation = iter->second.m_location;
			}
			else
			{
				LPCWSTR TracePath = L"SOFTWARE\\Intercede\\Edefice\\Trace";
				HKEY EdeficeKey;
				LONG regResult = RegOpenKeyExW(HKEY_LOCAL_MACHINE, TracePath, 0, KEY_READ, &EdeficeKey);

				TraceTested = true;
				// in the event of failure set debug level to 0 and return
				if (ERROR_SUCCESS == regResult)
				{
					TraceExists = true;

					DWORD dwDebugLevel;
					DWORD dwordSize = sizeof(dwDebugLevel);

					regResult = RegQueryValueExW(EdeficeKey, m_component.c_str(), NULL, NULL,
									reinterpret_cast<BYTE *>(&dwDebugLevel), &dwordSize);

					// close top-level Edefice key and open component subkey
					RegCloseKey(EdeficeKey);

					// in the event of failure set debug level to 0 and return
					if (ERROR_SUCCESS == regResult)
					{
						m_nDebugLevel = dwDebugLevel;
						if (all || (m_nDebugLevel != 0))
						{
							std::wstring KeyPath = TracePath;
							KeyPath += L"\\";
							KeyPath += m_component;

							HKEY ComponentKey;
							regResult = RegOpenKeyExW(HKEY_LOCAL_MACHINE, KeyPath.c_str(), 0, KEY_READ, &ComponentKey);
							// in the event of failure set location to debug log and return
							if (ERROR_SUCCESS == regResult)
							{
								char buffer[BUFSIZ];
								DWORD bufsize = BUFSIZ;

								regResult = RegQueryValueExA(ComponentKey, "Location", NULL, NULL,
												reinterpret_cast<BYTE *>(buffer), &bufsize);
								RegCloseKey(ComponentKey);

								// in the event of failure set location to debug log and return
								if (ERROR_SUCCESS == regResult)
								{
									m_strDebugLocation = buffer;
								}
							}
						}
					}
				}

				// add to cache
				DebugCache c;
				c.m_level = m_nDebugLevel;
				c.m_location = m_strDebugLocation;
				Cache[m_component] = c;
			}
		}
	}
	catch (...)
	{
		// in the event of any error set the debug level to -1
		m_nDebugLevel = (DWORD)LevelUndefined;
	}
	CacheLock.Unlock();
}

void CDebug::AddWriters()
{
	if (operator bool())
	{
		if (TestDebugLevel != (unsigned long)LevelUndefined)
		{
			m_writers.push_back(DebugWriterPtr(new DebugTestWriter));
		}
		else
		{
			// Always log to DebugOut
			m_writers.push_back(DebugWriterPtr(new DebugOutputWriter));

			if (!m_strDebugLocation.empty() && (m_strDebugLocation != DEBUGLOG))
			{
				m_writers.push_back(DebugWriterPtr(new DebugFileWriter(m_strDebugLocation)));
			}
		}
	}
}

std::wstring DebugWriter::Stamp(_In_ const std::wstring& component) const
{
	SYSTEMTIME sysTime;
	GetSystemTime(&sysTime); // method does not return a value

	std::wstringstream stamp;
	stamp << std::setfill(L'0') << std::setw(4)
		<< (int)sysTime.wYear << L"-"
		<< std::setfill(L'0') << std::setw(2)
		<< (int)sysTime.wMonth << L"-"
		<< std::setfill(L'0') << std::setw(2)
		<< (int)sysTime.wDay << L" ";

	stamp << std::setfill(L'0') << std::setw(2)
		<< (int)sysTime.wHour << L":"
		<< std::setfill(L'0') << std::setw(2)
		<< (int)sysTime.wMinute << L":"
		<< std::setfill(L'0') << std::setw(2)
		<< (int)sysTime.wSecond << L"."
		<< std::setfill(L'0') << std::setw(3)
		<< (int)sysTime.wMilliseconds;
	stamp << L" [" << GetCurrentProcessId() << L"." << GetCurrentThreadId() << L"] ";
	stamp << component << L" ";

	return stamp.str();
}

