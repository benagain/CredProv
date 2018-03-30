#pragma once

#include <iomanip>
#include <sstream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include "SalFix.h"
#include "Lock.h"

/// constant for writing to debug log
static const char DEBUGLOG[] = "DebugString";

typedef boost::shared_ptr<class DebugWriter> DebugWriterPtr;
typedef std::vector<DebugWriterPtr> DebugWriters;


/// Class for writing trace information
class CDebug : private boost::noncopyable
{
public:
	class ComponentName : public std::wstring
	{
	public:
		explicit ComponentName(_In_ std::wstring const & rhs) : std::wstring(rhs) {}
		explicit ComponentName(_In_z_ wchar_t const * rhs) : std::wstring(rhs) {}
	};

public:
	enum LevelFlag
	{
		ENABLED = 0x00000001,
		TIMER = 0x00000002,
		LOCKS = 0x00000004,
		PARAMS = 0x00000008,
		APDU = 0x00000010,
		LevelUndefined = 0xffffffff
	};

	CDebug();
	explicit CDebug(_In_opt_z_ char const * functionName);
	~CDebug();

	explicit CDebug(_In_ ComponentName const & name);

	/// Get the string stream for << access
	/// @return reference to the internal stringstream object
	std::stringstream &GetStream() { return m_stringstream; }
	/// Get the wide string stream for << access
	/// @return reference to the internal wide stringstream object

	std::wstringstream &GetWStream() { return m_wstringstream; }

	std::wstring ModuleName() const;

	void Write();
	void Write(_In_ const std::wstring &wstrInput);
	void Write(_In_ const std::string &strInput);
	void Write(_In_opt_z_ const wchar_t* wstrInput);
	void Write(_In_opt_z_ const char* strInput);

#ifdef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	operator bool(void) const;
#else
	explicit operator bool(void) const;
#endif
	bool operator!() const;
	bool Enabled(_In_ unsigned long flag = ENABLED) const;
	unsigned long Level() const;
	void Flag(_In_ unsigned long flag);
	std::string Location() const;

	static void ScrubSensitiveData(_In_ const std::string &strStart, _In_ const std::string &strEnd, _Inout_ std::string &strData);
	static void ScrubSensitiveData(_In_ const std::wstring &wstrStart, _In_ const std::wstring &wstrEnd, _Inout_ std::wstring &wstrData);
	static void ClearCache(void);
	static unsigned long SetTestDebugLevel(_In_ unsigned long level);

private:
	std::string m_strDebugLocation;		///< Output Location - either 'DebugString' or a file location
	std::stringstream m_stringstream;	///< internal string stream - with help of GetStream() allows << writing to debug
	std::wstringstream m_wstringstream;	///< internal wide string stream - with help of GetWStream() allows << writing to debug

	std::wstring BuildMessage(_In_ std::wstring const & data) const;

	myid::lock::Mutex		m_lock;		///< write lock
#ifndef MOBILE
	void ReadRegistryData(_In_ bool all = false);
#endif

	std::wstring m_component;			///< component name
	std::wstring m_function;			///< function name

protected:
	DebugWriters & writers();
	void AddWriters();

	static unsigned long TestDebugLevel;	///< test debug level

	unsigned long m_nDebugLevel;		///< debug level from registry
	unsigned long m_nLevelFlag;			///< required debug level
	DebugWriters m_writers;				///< the writers that the messages will end up in
};

/// Wrapper for entry/exit trace
class CDebugWrapper : public CDebug
{
	typedef CDebug inherited;

public:
	// Ctor - Log "ENTER"
	explicit CDebugWrapper(_In_opt_z_ char const * functionName);
	~CDebugWrapper();
};

/// Parent for all writers
class DebugWriter
{
public:
	virtual void write(_In_ std::wstring const & data) = 0;
	virtual std::wstring Stamp(_In_ const std::wstring& component) const;
};

/// Allow setting of debug test mode for the duration of a test
class DebugTestMode
{
public:
	DebugTestMode(_In_ unsigned long level);
	~DebugTestMode();

protected:
	unsigned long m_level;
};
