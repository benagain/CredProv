#pragma once

#include "ILogSink.h"
#include "LogManager.h"
#include <boost/shared_ptr.hpp>

namespace intercede
{
/// Provides automatic registration and deregistration of an ILogSink implementation
template<typename SinkT>
class ScopedSinkPtr : public boost::shared_ptr< SinkT >
{
public:
	/// The sink will be automatically registered with the LogManager
	ScopedSinkPtr(_In_ SinkT * sink)
		: boost::shared_ptr< SinkT >(sink)
	{
		logging::LogManager::registerObserver(*this, logging::verbose);
	}

	/// The sink will be automatically unregistered from the LogManager
	~ScopedSinkPtr()
	{
		logging::LogManager::unregisterObserver(*this);
	}
};
}
