#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/format.hpp>

namespace myid
{

	template< class T >
	std::wstring reportException(T const& e);
	template< class T >
	std::wstring reportException(T const& e, HRESULT& error);

	typedef boost::shared_ptr< class ExceptionReporter > ExceptionReporterPtr;

	/// Structure for generic reporting of exception messages
	class ExceptionReporter
	{
	public:
		virtual ~ExceptionReporter() {}

		/// Add specific exception handler of type T.  The catch
		/// handlers are evaluated in the same order they are added to
		/// ExceptionReporter, so
		/// reporter.then( handler_1 ).then( handler_ ).then( handler_3 )
		/// is equivalent to
		/// try { } catch( handler_1 ) { } catch( handler_2 ) { } catch( handler_3 ) { }
		template< class T >
		ExceptionReporter & then(ExceptionReporter* e = new ExceptionReporterGeneric< T >)
		{
			return add( ExceptionReporterPtr( e ) );
		}

		/// Return the message string from the thrown exception
		/// Must be called from inside a catch(...) { } block
		// Configure then exception handlers with then()
		virtual std::wstring report() = 0;
		virtual std::wstring report(HRESULT& error) = 0;

	protected:
		ExceptionReporterPtr outerCatch;

		ExceptionReporter & add( ExceptionReporterPtr r )
		{
			if( outerCatch )
				r->outerCatch = outerCatch;

			outerCatch = r;

			return *this;
		}

		std::wstring rethrow()
		{
			if( outerCatch )
				return outerCatch->report();

			throw;
		}

		std::wstring rethrow(HRESULT& error)
		{
			if( outerCatch )
				return outerCatch->report(error);

			throw;
		}
	};


	/// Reporter that will catch any uncaught exception, this should be the first
	/// reporter in the list as it will effectively block all reporters added before it
	class ExceptionReporterCatchAll : public ExceptionReporter
	{
	public:
		virtual std::wstring report()
		{
			try
			{
				return rethrow();
			}
			catch(...)
			{
				return L"Unknown exception";
			}
		}

		virtual std::wstring report(HRESULT& error)
		{
			try
			{
				return rethrow(error);
			}
			catch(...)
			{
				error = E_FAIL;
				return L"Unknown exception";
			}
		}
	};


	/// Report on exceptions of type T (i.e. std::exception or _com_error)
	template< class T >
	class ExceptionReporterGeneric : public ExceptionReporter
	{
	public:
		virtual std::wstring report()
		{
			try
			{
				return rethrow();
			}
			catch(T const & e)
			{
				return reportException(e);
			}
		}

		virtual std::wstring report(HRESULT& error)
		{
			try
			{
				return rethrow(error);
			}
			catch(T const & e)
			{
				return reportException(e, error);
			}
		}
	};
}
