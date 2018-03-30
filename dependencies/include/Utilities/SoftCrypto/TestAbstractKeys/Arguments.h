#pragma once

#include <string>
#include <map>
#include "Utilities\EdeficeCommon\Conversions\XmlWriter.h"
#include "Utilities\EdeficeCommon\XmlParser.h"

/// Simple class to hold all the arguments and write them to the output file.
class Arguments
{
public:
	enum EArgumentId
	{
		  eHSMType = 0
		, ePassedTests
		, eFailedTests
		, eSaveOutput
		, eThreads
		, eIterations
		, eOpenSSLCallback
		, eHSMSerialNumber
		, eHSMPassword
	};

public:
	Arguments();
	Arguments(const Arguments& src);
	virtual ~Arguments();

	// Add a processed argument to the list
	// TODO - Note string values must be of std:wstring not literals, literals will be treated as booleans (no idea why)
	void AddArgument(const EArgumentId& argumentId, const std::wstring& value);
	void AddArgument(const EArgumentId& argumentId, const int& value);
	void AddArgument(const EArgumentId& argumentId, const bool& value, const std::wstring& trueString = L"True", const std::wstring& falseString = L"False");

	// Add a password variable and record if the value was suppled by the user or not.
	void AddPassword(const EArgumentId& argumentId, const bool& valueSupplied);

	// Add an error message to the list of error messages encountered while processing the arguments.
	void AddErrorMessage(const std::wstring& message);

	// Export the data is the expected format.
	void WriteData(eXML::xmlwriter& xmlOutput) const;
	void WriteResultsSummary(eXML::xmlwriter& xmlOutput) const;
	void WriteVersionInfo(eXML::xmlwriter& xmlOutput) const;

	// Write the error messages to a string inserting the separator after each error message.
	std::wstring WriteErrorText(const std::wstring& seperator = L"\n") const;

	// Get details from the version information
	std::wstring GetApplicationName(void) const;
	std::wstring GetProductVersion(void) const;
	std::wstring GetFileVersion(void) const;
	bool GetVersionField(const std::wstring& fieldName, std::wstring& fieldValue) const;

	void SaveStartTime(void) { SaveTime(m_StartTime); }
	void SaveFinishTime(void) { SaveTime(m_FinishTime); }
	std::wstring GetFormattedStartTime(void) const { return GetFormattedTime(m_StartTime); }
	std::wstring GetFormattedFinishTime(void) const { return GetFormattedTime(m_FinishTime); }
	void SetResultsSummary(const size_t& passes, const size_t& fails, const size_t& expectedFails);

private:
	// The data will be stored in a map, so that it can be indexed via its id.
	typedef std::map<EArgumentId, std::wstring> ArgumentValues;
	// The error messages will be stored in the order that they are encountered.
	typedef std::vector<std::wstring> ErrorMessages;

private:
	// Write the data within the list to the given xmlWriter object.
	void WriteList(eXML::xmlwriter& xmlOutput, const ArgumentValues& argumentList, const std::wstring& nodeName) const;
	// Add an argument to the specified argument list
	void AddAnArgument(const EArgumentId& argumentId, const std::wstring& argumentValue);
	// Get the XML node name for a given Argument id.
	std::wstring GetArgumentNodeName(const EArgumentId& id)const;
	// Get the value of a node from the given XML.
	bool ExtractNode(const CXMLParser& parser, const std::wstring& name, std::wstring& value, const long& index) const;
	// Load the version info for the exe.
	bool LoadVersionInfo(void);
	// Get a field/node from  the version information data.
	std::wstring GetVersionField(const std::wstring& fieldName) const;
	// Remove text that might be a password from the m_CommandLine string
	bool ObscureArgumentValue(const std::wstring& argumentName, std::wstring::size_type& startPoint);
	void ObscurePasswords(void);
	// Save the current time in the given variable
	void SaveTime(SYSTEMTIME& timeStore) const;
	// Get a string telling the time.
	std::wstring GetFormattedTime(const SYSTEMTIME& timeStore) const;
	// Get the correct suffix for the date.
	std::wstring DateSuffix(const int& date) const;
private:
	// Store the whole command line
	std::wstring m_CommandLine;
	// Store the arguments that have been parsed from the command line (or defaults)
	ArgumentValues m_Arguments;

	// TODO - The following and the functions to manipulate them are not arguments
	// they are results and really ought to be in a separate class.

	// Store the error messages
	ErrorMessages m_ErrorMessages;
	// True when the version information has been loaded
	bool m_VersionInfoLoaded;
	// The version information in XML format
	CXMLParser m_VersionInfo;
	// Stores the start and end time of the run.
	SYSTEMTIME m_StartTime;
	SYSTEMTIME m_FinishTime;
	// Store the results.
	size_t m_Passes;
	size_t m_Fails;
	size_t m_ExpectedFails;
};

