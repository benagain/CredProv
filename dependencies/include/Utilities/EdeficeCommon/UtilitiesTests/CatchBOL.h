#pragma once

#include "CatchCommon.h"
#include "CatchException.h"

// Obsoleted by REQUIRE_THROWS_ERROR & CHECK_THROWS_ERROR

/*!
* Usage: REQUIRE_THROWS_BOL_ERRORCODE(CodeToTest, BOLErrors::MISC_Min_Data);
*/
#define REQUIRE_THROWS_BOL_ERRORCODE( expr, errorCode ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, Contains(""), Catch::ResultDisposition::Normal, "REQUIRE_THROWS_BOL_ERRORCODE" )

/*!
* Usage: CHECK_THROWS_BOL_ERRORCODE(CodeToTest, BOLErrors::MISC_Min_Data);
*/
#define CHECK_THROWS_BOL_ERRORCODE( expr, errorCode ) INTERNAL_CATCH_THROWS_ERROR_MATCH( expr, errorCode, Contains(""), Catch::ResultDisposition::ContinueOnFailure, "CHECK_THROWS_BOL_ERRORCODE" )