#pragma once

// Warning: to use this version helper be sure to include the following
// libraries - Version.lib, Shlwapi.lib.

#include <string>
#include <vector>
#include "VectorOfByte.h"
#include "Utilities\EdeficeCommon\Conversions\XmlWriter.h"
#include "GlobalOperator.h"

#pragma comment(lib, "version.lib")

namespace myid
{

inline void GetVersionXml(_In_ std::wstring const & dllPath, _In_ eXML::xmlwriter& xml)
{	// pass in dll path and retrieve the corresponding dll information
	// if failed to extract version information fails at any point then
	// return empty xml block

	VS_FIXEDFILEINFO * pStructFileInfo = NULL;

	DWORD dwFileVersion(0);
	const DWORD dwFileInfoSize = GetFileVersionInfoSizeW(dllPath.c_str(), &dwFileVersion);
	if (!dwFileInfoSize)
	{
		return;
	}

	VectorOfByte TByteBuffer(dwFileInfoSize);
	if (!GetFileVersionInfoW(dllPath.c_str(), NULL, dwFileInfoSize, &TByteBuffer[0]))
	{
		return;
	}

	UINT ValueSize(0);
	if (!VerQueryValueW(&TByteBuffer[0], L"\\",
		reinterpret_cast <LPVOID*> (&pStructFileInfo), &ValueSize))
	{
		// don't need to free pStructFileInfo, it will get freed with TByteBuffer
		return;
	}

	// Purposely don't include <parameters> so this function can be called
	// iteratively over multiple dlls (i.e. in function BOL GetVersion)
	xml.OpenNode(L"component");

	// enclose cdata tags
	xml.Node(L"name", dllPath);
	xml.Node(L"fileName", PathFindFileNameW(dllPath.c_str()));

	if (pStructFileInfo)
	{
		xml.Node(L"majorVersion", pStructFileInfo->dwFileVersionMS);
		xml.Node(L"minorVersion", pStructFileInfo->dwFileVersionLS);

		std::wstring version;
		version << HIWORD(pStructFileInfo->dwFileVersionMS) << L"."
			<< LOWORD(pStructFileInfo->dwFileVersionMS) << L"."
			<< HIWORD(pStructFileInfo->dwFileVersionLS) << L"."
			<< LOWORD(pStructFileInfo->dwFileVersionLS);
		xml.Node(L"fileVersion", version);

		xml.Node(L"productMajorVersion", pStructFileInfo->dwProductVersionMS);
		xml.Node(L"productMinorVersion", pStructFileInfo->dwProductVersionLS);

		version.clear();
		version << HIWORD(pStructFileInfo->dwProductVersionMS) << L"."
			<< LOWORD(pStructFileInfo->dwProductVersionMS) << L"."
			<< HIWORD(pStructFileInfo->dwProductVersionLS) << L"."
			<< LOWORD(pStructFileInfo->dwProductVersionLS);
		xml.Node(L"productVersion", version);
	}

	// any other version details
	// .................
	xml.CloseNode();
}

inline std::wstring GetVersionXml(_In_ std::wstring const & dllPath)
{
	eXML::xmlwriter xml(eXML::xmlwriter::CRLF);
	GetVersionXml(dllPath, xml);
	return xml;
}
}

