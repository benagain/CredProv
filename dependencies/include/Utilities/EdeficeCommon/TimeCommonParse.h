#pragma once

namespace myid
{

enum ISODateFormats			/// various date formats
{
	iso8601Calendar,		///< YYYY-MM-DD
	iso8601CalendarShort,	///< YYYYMMDD
	iso8601Ordinal,			///< YYYY-DDD
	iso8601OrdinalShort,	///< YYYYDDD
	// Week format not currently supported
};

class Time;

OKBOOL ParseISODateTime(_In_ const std::wstring &dateString, _Out_ _Always_(_Post_valid_) Time &dest);
std::wstring FormatISODateTime(_In_ const Time &time, _In_ ISODateFormats format, _In_ bool includeTime);
std::wstring FormatDBDateTime(_In_ const Time &time, _In_ bool includeTime);

} // namespace myid
