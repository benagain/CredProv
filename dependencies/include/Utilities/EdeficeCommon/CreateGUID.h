#pragma once

#include <string>

/// Generate random GUIDs
class CreateGUID
{
public:
	enum TGuidFormat
	{
		GuidFormatStandard,			///<  3F0D046F-9178-4DC1-A063-FF58B9C95288  - As created by DataExchange.CreateGUID
		GuidFormatRegistry,			///< {3F0D046F-9178-4DC1-A063-FF58B9C95288} - GUIDGen Registry format
		GuidFormatSerial16,			///< 3F0D046F91784DC1A063FF58B9C95288       - Numeric serial-like 16 byte string
		GuidFormatSerial			///< 001057817711037240019905160099255088185201082136 - Numeric serial-like string
	};

	static std::wstring Create(TGuidFormat format = GuidFormatStandard);
};
