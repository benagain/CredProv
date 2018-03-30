#pragma once

#include <string>
#define INHERIT_STACK_DUMP

namespace myid
{

/// Produces a stack dump
class StackDump
{
public:
	static bool Enabled;				///< enable/disable stack dump (default true) (used by tests)
	std::wstring	m_stackTrace;		///< stack trace
};

}
