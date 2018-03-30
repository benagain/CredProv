#pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1700)
	#define _VARIADIC_MAX 10
#endif

#define GTEST_DONT_DEFINE_FAIL 1
#define GTEST_DONT_DEFINE_SUCCEED 1
#include "gmock/gmock.h"
