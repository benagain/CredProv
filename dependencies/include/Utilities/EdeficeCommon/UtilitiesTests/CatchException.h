#pragma once

#include "CatchCommon.h"

namespace Catch
{

inline std::string toString( myid::Exception& value )
{
	return myid::ToStr( value.message() );
}

#if defined(WIN32) && !defined(MOBILE)
inline std::string toString( _com_error& value )
{
	std::string message = myid::ToStr(value.ErrorMessage());
	_bstr_t description = value.Description();
	if (!!description && description.length() != 0)
	{
		message.append("\n").append((const char*)description);
	}
	return message;
}
#endif

inline std::string toString( std::exception& value )
{
	return myid::ToStr(value.what());
}

// Check exception type and exception error text
#define INTERNAL_CATCH_THROWS_WITH_MATCH( expr, exceptionType, matcher, resultDisposition, macroName ) \
	do { \
		Catch::ResultBuilder __catchResult( macroName, CATCH_INTERNAL_LINEINFO, #expr, resultDisposition ); \
		if( __catchResult.allowThrows() ) \
			try { \
				expr; \
				__catchResult.captureResult( Catch::ResultWas::DidntThrowException ); \
			} \
			catch( exceptionType& arg ) { \
				INTERNAL_CHECK_THAT(Catch::toString(arg), matcher, resultDisposition, macroName); \
			} \
			catch( ... ) { \
				__catchResult.useActiveException( resultDisposition ); \
			} \
		else \
			__catchResult.captureResult( Catch::ResultWas::Ok ); \
		INTERNAL_CATCH_REACT( __catchResult ) \
	} while( Catch::alwaysFalse() )

#define REQUIRE_THROWS_WITH_MATCH( expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_WITH_MATCH( expr, exceptionType, matcher, Catch::ResultDisposition::Normal, "REQUIRE_THROWS_WITH_MATCH" )
#define CHECK_THROWS_WITH_MATCH( expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_WITH_MATCH( expr, exceptionType, matcher, Catch::ResultDisposition::ContinueOnFailure, "CHECK_THROWS_WITH_MATCH" )

#if defined(WIN32) && !defined(MOBILE)
#define INTERNAL_COM_ERROR( errorCode, matcher, resultDisposition, macroName ) \
	catch (_com_error& e) { \
		if (Catch::isTrue(errorCode != 0) && ((unsigned long)errorCode != (unsigned long)e.Error())) \
		{ \
			__catchResult \
			.setLhs(Catch::toString((unsigned long)e.Error())) \
			.setRhs(Catch::toString((unsigned long)errorCode)) \
			.setOp("==") \
			.setResultType(Catch::ResultWas::ExpressionFailed); \
			__catchResult.captureExpression(); \
		} \
		else \
		{ \
			INTERNAL_CHECK_THAT(Catch::toString(e), matcher, resultDisposition, macroName); \
		} \
	}
#else
#define INTERNAL_COM_ERROR( errorCode, matcher, resultDisposition, macroName )
#endif

#define INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, matcher, resultDisposition, macroName ) \
	do { \
		std::stringstream sstr; \
		sstr << #expr; if (Catch::isTrue(errorCode != 0)) sstr << ", " << #errorCode; \
		Catch::ResultBuilder __catchResult( macroName, CATCH_INTERNAL_LINEINFO, sstr.str().c_str(), resultDisposition ); \
		if( __catchResult.allowThrows() ) \
			try { \
				expr; \
				__catchResult.captureResult( Catch::ResultWas::DidntThrowException ); \
			} \
			catch( myid::Exception& e ) { \
				if (Catch::isTrue(errorCode != 0) && ((unsigned long)errorCode != e.getErrorNumber())) \
				{ \
					__catchResult \
						.setLhs( Catch::toString( e.getErrorNumber() ) ) \
						.setRhs( Catch::toString( (unsigned long)errorCode ) ) \
						.setOp( "==" ) \
						.setResultType( Catch::ResultWas::ExpressionFailed ); \
					__catchResult.captureExpression(); \
				} \
				else \
				{ \
					INTERNAL_CHECK_THAT(Catch::toString(e), matcher, resultDisposition, macroName); \
				} \
			} \
			INTERNAL_COM_ERROR( errorCode, matcher, resultDisposition, macroName ) \
			catch (std::exception& e) { \
				INTERNAL_CHECK_THAT(Catch::toString(e), matcher, resultDisposition, macroName); \
			} \
			catch( ... ) { \
				__catchResult.useActiveException( resultDisposition ); \
			} \
		else \
			__catchResult.captureResult( Catch::ResultWas::Ok ); \
		INTERNAL_CATCH_REACT( __catchResult ) \
	} while( Catch::alwaysFalse() )

// Check exception error code
#define REQUIRE_THROWS_ERROR( expr, errorCode ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, Contains(""), Catch::ResultDisposition::Normal, "REQUIRE_THROWS_ERROR" )
#define CHECK_THROWS_ERROR( expr, errorCode ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, Contains(""), Catch::ResultDisposition::ContinueOnFailure, "CHECK_THROWS_ERROR" )

// Check exception error text
#define REQUIRE_THROWS_MATCH( expr, matcher ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, 0, matcher, Catch::ResultDisposition::Normal, "REQUIRE_THROWS_MATCH" )
#define CHECK_THROWS_MATCH( expr, matcher ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, 0, matcher, Catch::ResultDisposition::ContinueOnFailure, "CHECK_THROWS_MATCH" )

// Check exception error code and error text
#define REQUIRE_THROWS_ERROR_MATCH( expr, errorCode, matcher ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, matcher, Catch::ResultDisposition::Normal, "REQUIRE_THROWS_ERROR_MATCH" )
#define CHECK_THROWS_ERROR_MATCH( expr, errorCode, matcher ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, matcher, Catch::ResultDisposition::ContinueOnFailure, "CHECK_THROWS_ERROR_MATCH" )
}
