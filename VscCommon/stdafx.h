#pragma once
#include "Utilities\EdeficeCommon\VS2005Fix.h"
#undef _CRT_SECURE_NO_WARNINGS
#include "Utilities\EdeficeCommon\LeanWindows.h"

#define RPC_USE_NATIVE_WCHAR

#include <string>
#include <vector>
#include <algorithm>

#include "Products\Common\Microsoft\CNG\MD\CardMod.h"

#include "Errors.h"
#include "Utilities\CardLib\APDUVector.h"
#include "Utilities\EdeficeCommon\VectorOfByte.h"
#include "Utilities\EdeficeCommon\Debug.h"
