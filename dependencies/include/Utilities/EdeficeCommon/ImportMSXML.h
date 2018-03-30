#pragma once
#if !defined(_INCLUDE_MSXML) && !defined(NO_MSXML)
#define _INCLUDE_MSXML
// same define in all

#ifndef DOXYGEN

// always using msxml6 - for protection against xxe attacks
// note that even when importing msxml6 it is still necessary to use guid or progid for msxml6 - old progid or guid will still instantiate msxml3
#pragma warning (push)
#pragma warning (disable:4279)
#import <Products\Common\Microsoft\MSXML\msxml6.dll> rename_namespace("MSXML") named_guids
#pragma warning (pop)


// all c++ should use this define to instantiate a DOM. (allows global update for future version of XML.

//progids - used for pattern where COM object instantiated via progid
#define myPROGID_DOMDocument L"Msxml2.DOMDocument.6.0"
#define myPROGID_FreeThreadedDOMDocument L"Msxml2.FreeThreadedDOMDocument.6.0"
#define myPROGID_MXHTMLWriter L"Msxml2.MXHTMLWriter.6.0"
#define myPROGID_MXNamespaceManger L"Msxml2.MXNamespaceManager.6.0"
#define myPROGID_MXXMLWriter L"Msxml2.MXXMLWriter.6.0"
#define myPROGID_SAXAttributes L"Msxml2.SAXAttributes.6.0"
#define myPROGID_SAXXMLReader L"Msxml2.SAXXMLReader.6.0"
#define myPROGID_ServerXMLHTTP L"Msxml2.ServerXMLHTTP.6.0"
#define myPROGID_XMLHTTP L"Msxml2.XMLHTTP.6.0"
#define myPROGID_XML_SchemaCache L"Msxml2.XMLSchemaCache.6.0"
#define myPROGID_XSLTemplate L"Msxml2.XSLTemplate.6.0"

//classid - used for pattern where COM object instantiated via classid e.g. CoCreateInstance(__uuidof(MSXML::DOMDocument)
#define myCoclass_DOMDocument MSXML::DOMDocument60
#define myCoclass_FreeThreadedDOMDocument MSXML::FreeThreadedDOMDocument60
#define myCoclass_MXHTMLWriter MSXML::MXHTMLWriter60
#define myCoclass_MXNamespaceManager MSXML::MXNamespaceManager60
#define myCoclass_MXXMLWriter MSXML::MXXMLWriter60
#define myCoclass_SAXAttributes MSXML::SAXAttributes60
#define myCoclass_SAXXMLReader MSXML::SAXXMLReader60
#define myCoclass_ServerXMLHTTP MSXML::ServerXMLHTTP60
#define myCoclass_XMLHTTP MSXML::XMLHTTP60
#define myCoclass_XMLSchemaCache MSXML::XMLSchemaCache60
#define myCoclass_XSLTemplate MSXML::XSLTemplate60

#endif
#endif
