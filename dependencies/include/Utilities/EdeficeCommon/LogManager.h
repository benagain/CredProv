#pragma once

#include "ILogSink.h"
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Lock.h"
#include "Instance.h"

namespace intercede
{
namespace logging
{
typedef boost::shared_ptr< ILogSink > LogSinkPtr;

/// The Observer class for registered observers of the logging.
class Observer
{
public:
	Observer(_In_ LogSinkPtr sink, _In_ logLevels level);
	bool operator==(_In_ const LogSinkPtr& rhs) const;
	void log(_In_ logLevels level, _In_ std::wstring const & text);

private:
	LogSinkPtr		m_sink;		///< where the log messages go
	logLevels		m_level;	///< level for sink
};

typedef boost::shared_ptr<Observer> ObserverPtr;

//virtual class for stack printing for platforms to implement
class StackDelegate
{
public:
	virtual void printStack() = 0;
};

/// Provide an interface to an external singleton logging sink
class LogManager
	: public myid::WithInstance<LogManager>
	, private boost::noncopyable
{
public:
	static void registerObserver(_In_ LogSinkPtr sink, _In_ logLevels level);
	static void unregisterObserver(_In_ LogSinkPtr sink);
	static void clearObservers();

	static std::wstring getStamp(_In_ logLevels level);

	static void setStackDelegate(_In_ StackDelegate* delegate);
	static void printStack();

	static void log(_In_ logLevels level, _In_ std::wstring const & out);

	/** Define the text names for the log levels. */
	const static wchar_t* logLevelNames[];

protected:
	friend LogManager* myid::Instance<LogManager>();

	LogManager();

	void l_registerObserver(_In_ LogSinkPtr sink, _In_ logLevels level);
	void l_unregisterObserver(_In_ LogSinkPtr sink);
	void l_clearObservers();

	void l_setStackDelegate(_In_ StackDelegate* delegate);
	void l_printStack();

	void l_log(_In_ logLevels level, _In_ std::wstring const & out);

	typedef std::vector< ObserverPtr > ObserverList;
	ObserverList				m_observers;			///< list of observers
	myid::lock::SharedMutex		m_observers_mutex;		///< protect list of observers
	StackDelegate*				m_stackDelegate;		///< stack printing
};
}
}

// The core logging macros.
#define DEBUG_FUNCTION_TRACE() DebugFunctionTraceLogger()
#define DEBUG_FUNCTION_TRACE_NO_TIME() DEBUG_FUNCTION_TRACE()
