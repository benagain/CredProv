#pragma once

#include <string>
#include <tchar.h>

namespace EdeficeCommon {

#ifdef _UNICODE
	typedef std::wstring		tstring;
	typedef std::wstringstream	tstringstream;

#else
	typedef std::string			tstring;
	typedef std::stringstream	tstringstream;

#endif

}

namespace eUtil {
	using EdeficeCommon::tstring;
	using EdeficeCommon::tstringstream;
}
