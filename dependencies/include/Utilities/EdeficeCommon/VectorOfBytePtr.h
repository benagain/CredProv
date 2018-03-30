#pragma once

#include "VectorOfByte.h"
#include <boost/shared_ptr.hpp>

/// A smart memory-management pointer to a block of memory
typedef boost::shared_ptr<VectorOfByte> VectorOfBytePtr;

/// A smart memory-management pointer to a block of memory
typedef boost::shared_ptr<VectorOfByte const> VectorOfByteConstPtr;

