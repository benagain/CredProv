/*
 * ILogSink.h
 *
 *  Created on: 12 Feb 2013
 *      Author: Roderick Heath
 *
 * Interface into the host logging.
 */

#pragma once

#include <string>
#include <boost/shared_ptr.hpp>


/// The logging sink interface used by LogStream and typically implemented by the host.
class ILogSink
{
public:
	virtual ~ILogSink() {};
	virtual void log(_In_ int level, _In_ const std::wstring& m) = 0;
};

namespace intercede
{
namespace logging
{

/// The levels of severity of log messages
enum logLevels
{
	fatal = 0,
	error = 1,
	warning = 2,
	info = 3,
	debug = 4,
	verbose = 5
};

typedef boost::shared_ptr< ILogSink > LogSinkPtr;

} // namespace logging
} // namespace intercede
