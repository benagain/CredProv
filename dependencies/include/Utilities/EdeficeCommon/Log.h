#pragma once
#ifdef _MSC_VER
#pragma warning (disable:4512)
#endif

#include "ILogSink.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <boost/shared_ptr.hpp>
#include "Utilities/EdeficeCommon/Conversions/StringUtils.h"

// verbose - function trace with no data
// debug - function trace with data or arguments
// info - other useful state information
// warning - mild error condition, recovered automatically
// error - exception thrown , other serious error
// fatal - program may as well terminate

// Debug and Release builds
#define LogV(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::verbose, x)
#define LogD(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::debug, x)
#define LogI(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::info, x)
#define LogW(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::warning, x)
#define LogE(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::error, x)
#define LogF(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::fatal, x)

// debug mode only
#ifdef MYID_DEBUG
#define LogDebugV(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::verbose, x)
#define LogDebugD(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::debug, x)
#define LogDebugI(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::info, x)
#define LogDebugW(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::warning, x)
#define LogDebugE(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::error, x)
#define LogDebugF(x) INTERCEDE_INTERNAL_LOG_FOR_LEVEL(intercede::logging::fatal, x)
#else
#define LogDebugV(x)
#define LogDebugD(x)
#define LogDebugI(x)
#define LogDebugW(x)
#define LogDebugE(x)
#define LogDebugF(x)
#endif

#define LogFunctionName() DECLARE_SCOPED_FUNCTION_PREPENDER
#define LogFunctionName_(x) LogFunctionNameD(x)
#define LogFunctionNameV(x) do { LogFunctionName(); LogV(x); } while(isAlwaysFalse())
#define LogFunctionNameD(x) do { LogFunctionName(); LogD(x); } while(isAlwaysFalse())
#define LogFunctionNameI(x) do { LogFunctionName(); LogI(x); } while(isAlwaysFalse())
#define LogFunctionNameW(x) do { LogFunctionName(); LogW(x); } while(isAlwaysFalse())
#define LogFunctionNameE(x) do { LogFunctionName(); LogE(x); } while(isAlwaysFalse())
#define LogFunctionNameF(x) do { LogFunctionName(); LogF(x); } while(isAlwaysFalse())

#define DebugFunctionTraceLogger() LogFunctionName(); DECLARE_FUNCTION_TRACER
#define DebugFunctionTraceLogger_(x) do { DebugFunctionTraceLogger(); LogD(x); } while(isAlwaysFalse())


namespace intercede
{
namespace logging
{
/**
LogStream provides simple call-site logging syntax, deferring actual logging to
the LogManager.  It is best used with the helper macros.

Create a logging object with either
DebugLogger					// Basic log object, simply writes what you tell it to
LogFunctionName			// Log object that prepends the function name to each line
DebugFunctionTraceLogger	// LogFunctionName that automatically logs entry and
// exit of function

Write log messages using
Log( "streamable " << "log " << "messages " );  // log is written and flushed automatically

Example:
LogFunctionName();
Log( "About to call some dodgy function with param1=" << param1 << ", param2=" << param2 );
Log( "Result: " << myid::bin_to_hex(result) );

*/
class LogStream : public std::wostream
{
	/// Internal buffer implementation to push messages to the log sink
	class LogStreamBuf : public std::wstringbuf
	{
	public:
		logLevels currentLevel;		///< The priority level of the currently logging message

		LogStreamBuf() : currentLevel(info) {}
		virtual ~LogStreamBuf();

		virtual int sync();
	} buffer;					///< Buffers all log messages before sending to sink

public:
	explicit LogStream(_In_ logLevels level = info);
};


/// Write the current log message to the sink
inline std::wostream& eol(_Inout_ std::wostream& ostr)
{
	ostr.flush();
	return ostr;
}

class LogPrefixInserter
{
public:
	explicit LogPrefixInserter(_In_opt_z_ char const * prefix)
		: f(myid::ToStr(prefix))
	{}

	LogStream & operator()(_Inout_ LogStream & logger)
	{
		if (!f.empty())
			logger << f.c_str() << L": ";
		return logger;
	}

	std::string f;
};

class OverridePrefixInserter
{
public:
	OverridePrefixInserter(_In_opt_z_ const char *prefix, _In_ LogPrefixInserter &inserter)
		: m_Inserter(inserter)
		, m_OldPrefix(inserter.f)
	{
		inserter.f = prefix ? prefix : "";
	}

	~OverridePrefixInserter()
	{
		m_Inserter.f = m_OldPrefix;
	}
	LogStream & operator()(_Inout_ LogStream & logger)
	{
		m_Inserter(logger);
		return logger;
	}

protected:
	LogPrefixInserter &m_Inserter;
	const std::string m_OldPrefix;
};
} // namespace logging
} // namespace intercede

namespace
{
/// This little hackery relies on scope name resolution to find this instance of
/// intercede_logging_prefix_scoped_inserter unless DebugFunctionTraceLogger() has
/// been used in which case a local scoped named intercede_logging_prefix_scoped_inserter
/// replaces it
intercede::logging::LogPrefixInserter  intercede_logging_prefix_scoped_inserter(nullptr);

/// Avoid warnings on all platforms (so far)
bool isAlwaysFalse() { return false; }

/// Stream narrow strings to the unicode stream
std::wostream & operator<< (_Inout_ std::wostream & ostr, _In_ std::string const & str)
{
	std::copy(str.begin(), str.end(), std::ostream_iterator<char, wchar_t>(ostr));
	return(ostr);
}

} // anon namespace


namespace intercede
{
namespace logging
{
/// Trace entry and exit of functions
class FunctionTrace
{
private:
	LogPrefixInserter prepender;

public:
	explicit FunctionTrace(_In_ LogPrefixInserter prep) : prepender(prep)
	{
		LogStream log(debug);
		prepender(log) << L">>>>";
	}

	~FunctionTrace()
	{
		LogStream log(debug);
		prepender(log) << L"<<<<";
	}
};
} // namespace logging
} // namespace intercede


#ifndef NO_INTERCEDE_EOL
using intercede::logging::eol;
#endif

#if defined ( WIN32 ) || defined (WINAPI_FAMILY_APP)
#define __FUNC__ __FUNCTION__
#elif defined (MYID_DEBUG)
#define __FUNC__ __PRETTY_FUNCTION__
#else
#define __FUNC__ __func__
#endif

// note that none of these have terminating ;
#define INTERCEDE_INTERNAL_LOG_FOR_LEVEL(l, x) do { intercede::logging::LogStream intercedeLogger(l); LOG_PREFIX() << x ; } while(isAlwaysFalse())

#define DECLARE_SCOPED_FUNCTION_PREPENDER intercede::logging::OverridePrefixInserter prefix_overrider(__FUNC__, intercede_logging_prefix_scoped_inserter)

#define DECLARE_FUNCTION_TRACER intercede::logging::FunctionTrace intercedeLoggerTrace(intercede_logging_prefix_scoped_inserter)

#define LOG_PREFIX() intercede_logging_prefix_scoped_inserter( intercedeLogger )

