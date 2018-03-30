#pragma once

#include <string>
#include "Debug.h"

#ifndef MOBILE
class DebugFileWriter : public DebugWriter
{
public:
	explicit DebugFileWriter(_In_ std::string const & filename);

	virtual void write(_In_ std::wstring const & data);

protected:
	void _CheckFileSize() const;
	void _CreateBackup() const;
	std::wstring _CreateBackupPath() const;
	std::wstring _CreateBackupFilename() const;
	std::wstring _GetTimeStampW() const;
	void ReadRegistryData();

	DWORD m_nFileSize;
	std::string m_filename;
	bool m_bCreateBackup;
	std::wstring m_wstrBackupLocation;
};

class DebugOutputWriter : public DebugWriter
{
public:
	virtual void write(_In_ std::wstring const & data);
	virtual std::wstring Stamp(_In_ const std::wstring& component) const;
};
#endif

class DebugConsoleWriter : public DebugWriter
{
public:
	virtual void write(_In_ std::wstring const & data);
};

/// Used for tests
class DebugTestWriter : public DebugWriter
{
public:
	virtual void write(_In_ std::wstring const & data);
	virtual std::wstring Stamp(_In_ const std::wstring& component) const;

	static void Clear();
	static std::wstring Get();

protected:
	static std::wostringstream Written;		///< data been written
};
