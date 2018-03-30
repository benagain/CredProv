/// \file MiniDriverCompress.h
/// Mini driver certificate compression

#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"

namespace md
{

bool Compress(VectorOfByte& data);
bool DeCompress(VectorOfByte& data);

} // namespace md
