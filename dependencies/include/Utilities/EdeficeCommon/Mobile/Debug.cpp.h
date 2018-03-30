#include "../TimeCommon.h"
#include "../DebugLog.h"

CDebug::CDebug()
	: m_nDebugLevel(LevelFlag::ENABLED)
	, m_nLevelFlag(LevelFlag::ENABLED)
{
	AddWriters();
}

CDebug::CDebug(_In_opt_z_ char const * fn)
	: m_nDebugLevel(LevelFlag::ENABLED)
	, m_nLevelFlag(LevelFlag::ENABLED)
{
	AddWriters();

	if (fn && *fn)
		m_function = myid::ToWstr(fn);
}


/// Create a debugger that pretends to be in a different component, and so will
/// pick up the configuration for that component from the registry.
CDebug::CDebug(_In_ CDebug::ComponentName const & component)
	: m_nDebugLevel(LevelFlag::ENABLED)
	, m_nLevelFlag(LevelFlag::ENABLED)
	, m_component( component )
{
	AddWriters();
}

void CDebug::AddWriters()
{
	if (operator bool())
	{
		m_writers.push_back(DebugWriterPtr(new DebugLogWriter));
	}
}

/// reset the cache state
void CDebug::ClearCache(void)
{
}

std::wstring DebugWriter::Stamp(_In_ const std::wstring& component) const
{
	std::wstringstream stamp;

	stamp << myid::Time::local().iso();

	stamp << L" " << component << L" ";

	return stamp.str();
}
