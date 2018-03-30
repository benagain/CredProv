#pragma once

#include "LeanWindows.h"
#include <string>

struct HKEY__;
typedef HKEY__* HKEY;

namespace RegistryExport
{
	extern void ExportRegistryKey( HKEY rootKey, std::wstring const & keyPath, std::string const & outputFileName);
};