#pragma once

#include <string>
#include "Debug.h"

class DebugLogWriter : public DebugWriter
{
public:
	virtual void write(std::wstring const & data);
};
