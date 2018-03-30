#pragma once

#include <time.h>
#include <string>
#include "SalFix.h"
#include "TimeCommonParse.h"

namespace myid
{

typedef long long time_t;			///< ensure will not 2038 bug

/// A length of time
/// Cannot be set by months as these do not have a fixed length
class TimeSpan
{
public:
	TimeSpan();
	// cppcheck-suppress noExplicitConstructor
	TimeSpan(_In_ const TimeSpan& rhs);
	explicit TimeSpan(_In_ myid::time_t rhs);
	TimeSpan(_In_ int hour, _In_ int minute, _In_ int second);
	TimeSpan(_In_ int day, _In_ int hour, _In_ int minute, _In_ int second);

	TimeSpan operator+(_In_ const TimeSpan& rhs) const;
	TimeSpan operator-(_In_ const TimeSpan& rhs) const;
	TimeSpan& operator+=(_In_ const TimeSpan& rhs);
	TimeSpan& operator-=(_In_ const TimeSpan& rhs);
	TimeSpan operator+(_In_ long long rhs) const;
	TimeSpan operator-(_In_ long long rhs) const;
	TimeSpan& operator+=(_In_ long long rhs);
	TimeSpan& operator-=(_In_ long long rhs);
	TimeSpan operator*(_In_ int rhs) const;
	TimeSpan operator/(_In_ int rhs) const;
	double operator/(_In_ const TimeSpan& rhs) const;
	TimeSpan& operator*=(_In_ int rhs);
	TimeSpan& operator/=(_In_ int rhs);
	bool operator==(_In_ const TimeSpan& rhs) const;
	bool operator!=(_In_ const TimeSpan& rhs) const;
	bool operator>(_In_ const TimeSpan& rhs) const;
	bool operator>=(_In_ const TimeSpan& rhs) const;
	bool operator<(_In_ const TimeSpan& rhs) const;
	bool operator<=(_In_ const TimeSpan& rhs) const;

	void set(_In_ int hour, _In_ int minute, _In_ int second);
	void set(_In_ int day, _In_ int hour, _In_ int minute, _In_ int second);
	void seconds(_In_ long long val);
	void minutes(_In_ long long val);
	void hours(_In_ long long val);
	void days(_In_ long long val);

	int second(void) const;
	int minute(void) const;
	int hour(void) const;
	long long seconds(void) const;
	long long minutes(void) const;
	long long hours(void) const;
	long long days(void) const;
	myid::time_t get(void) const;
	void clear(void);

protected:
	myid::time_t		m_span;		///< in seconds
};

/// Generic time handler, works on all systems
/// Time is stored as UTC
class Time
{
public:
	Time();
	// cppcheck-suppress noExplicitConstructor
	Time(_In_ const Time& rhs);
	explicit Time(_In_ myid::time_t rhs);
	explicit Time(_In_ const tm& rhs);
	Time(_In_ int year, _In_ int month, _In_ int day);
	Time(_In_ int year, _In_ int month, _In_ int day, _In_ int hour, _In_ int minute, _In_ int second);

	Time& operator=(_In_ myid::time_t rhs);
	Time& operator=(_In_ const tm& rhs);
#ifndef MOBILE
	explicit Time(_In_ const ::FILETIME& rhs);
	explicit Time(_In_ const SYSTEMTIME& rhs);
	Time& operator=(_In_ const ::FILETIME& rhs);
	Time& operator=(_In_ const SYSTEMTIME& rhs);
	operator ::FILETIME() const;
	operator SYSTEMTIME() const;
#endif

	Time& operator+=(_In_ const TimeSpan& rhs);
	Time& operator-=(_In_ const TimeSpan& rhs);
	Time operator+(_In_ const TimeSpan& rhs) const;
	Time operator-(_In_ const TimeSpan& rhs) const;
	TimeSpan operator-(_In_ const Time& rhs) const;

#ifdef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	operator bool(void) const;
#else
	explicit operator bool(void) const;
#endif
	bool operator!(void) const;

	bool operator==(_In_ const Time& rhs) const;
	bool operator!=(_In_ const Time& rhs) const;
	bool operator>(_In_ const Time& rhs) const;
	bool operator>=(_In_ const Time& rhs) const;
	bool operator<(_In_ const Time& rhs) const;
	bool operator<=(_In_ const Time& rhs) const;

	void get(_Out_ int& year, _Out_ int& month, _Out_ int& day) const;
	void get(_Out_ int& year, _Out_ int& month, _Out_ int& day, _Out_ int& hour, _Out_ int& minute, _Out_ int& second) const;
	bool set(_In_ int year, _In_ int month, _In_ int day);
	bool set(_In_ int year, _In_ int month, _In_ int day, _In_ int hour, _In_ int minute, _In_ int second);
	bool set(_In_ const std::wstring& year, _In_ const std::wstring& month, _In_ const std::wstring& day);
	bool set(_In_ const std::wstring& year, _In_ const std::wstring& month, _In_ const std::wstring& day, _In_ const std::wstring& hour, _In_ const std::wstring& minute, _In_ const std::wstring& second);
	void clear(void);

	int year(void) const;
	bool year(_In_ int val);
	bool year(_In_ const std::wstring& val);
	int month(void) const;
	bool month(_In_ int val);
	bool month(_In_ const std::wstring& val);
	int day(void) const;
	bool day(_In_ int val);
	bool day(_In_ const std::wstring& val);
	int hour(void) const;
	void hour(_In_ int val);
	void hour(_In_ const std::wstring& val);
	int minute(void) const;
	void minute(_In_ int val);
	void minute(_In_ const std::wstring& val);
	int sec(void) const;
	void sec(_In_ int val);
	void sec(_In_ const std::wstring& val);
	int week_day(void) const;
	int year_day(void) const;

	bool leap_year(void) const;
	bool set(void) const;

	tm* time(_Inout_ tm* ptm) const;
	myid::time_t getTime(void) const;

	std::wstring format(_Printf_format_string_ const char* format) const;
	std::wstring iso(_In_ bool tz = false) const;
	std::wstring ymd(void) const;

	static Time now(void);
	static Time local(void);

	static bool leap_year(_In_ int year);
	static int days_year(_In_ int month, _In_ bool leap);

protected:
	bool check_year(_In_ int year) const;
	bool check_month(_In_ int month) const;
	bool check_day(_In_ int day) const;

	void normalise();
	void initialised();

	tm		m_tm;				///< time in UTC, to the nearest second
	bool	m_initialised;		///< if a time is set
};

} // namespace myid
