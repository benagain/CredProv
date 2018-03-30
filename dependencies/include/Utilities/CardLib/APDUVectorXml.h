/// \file APDUVectorXml.h
/// APDU vector - XML conversion

#pragma once

#include "APDUVector.h"
#include "Utilities\EdeficeCommon\XmlNode.h"
#include "Utilities\EdeficeCommon\Conversions\XmlWriter.h"

namespace apdu
{

/// APDU xml transformation
class ApduXml
{
public:
	static bool xmlIn(ApduCommand& APDU, const std::wstring& xmlIn);
	static bool xmlIn(ApduReply& APDU, const std::wstring& xmlIn);
	static bool xmlIn(ApduCommand& APDU, ApduReply& reply, const std::wstring& xmlIn);
	static bool xmlIn(ApduCommandList& APDU, const std::wstring& xmlIn);
	static bool xmlIn(ApduCommandList& APDU, ApduReply& reply, const std::wstring& xmlIn);
	static bool xmlIn(ApduCommandList& APDU, ApduReplyList& reply, const std::wstring& xmlIn);

	static bool xmlIn(ApduCommand& APDU, const eXML::IXMLDOMNodePtr& nodeCommand);
	static bool xmlIn(ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommand);
	static bool xmlIn(ApduCommand& APDU, ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommand);
	static bool xmlIn(ApduCommandList& APDU, const eXML::IXMLDOMNodePtr& nodeCommands);
	static bool xmlIn(ApduCommandList& APDU, ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommands);
	static bool xmlIn(ApduCommandList& APDU, ApduReplyList& reply, const eXML::IXMLDOMNodePtr& nodeCommands);

	static void xmlOut(const ApduCommand& APDU, eXML::xmlwriter& xmlOut, long id = 0);
	static void xmlOut(const ApduReply& reply, eXML::xmlwriter& xmlOut, long id = 0);
	static void xmlOut(const ApduCommand& APDU, const ApduReply& reply, eXML::xmlwriter& xmlOut, long id = 0);
	static void xmlOut(const ApduCommandList& APDU, eXML::xmlwriter& xmlOut);
	static void xmlOut(const ApduCommandList& APDU, const ApduReply& reply, eXML::xmlwriter& xmlOut);
	static void xmlOut(const ApduCommandList& APDU, const ApduReplyList& reply, eXML::xmlwriter& xmlOut);

	static void xmlOut(const ApduCommand& APDU, const eXML::IXMLDOMNodePtr& nodeCommand, long id = 0);
	static void xmlOut(const ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommand, long id = 0);
	static void xmlOut(const ApduCommand& APDU, const ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommands, long id = 0);
	static void xmlOut(const ApduCommandList& APDU, const eXML::IXMLDOMNodePtr& nodeCommands);
	static void xmlOut(const ApduCommandList& APDU, const ApduReply& reply, const eXML::IXMLDOMNodePtr& nodeCommands);
	static void xmlOut(const ApduCommandList& APDU, const ApduReplyList& reply, const eXML::IXMLDOMNodePtr& nodeCommands);
};

} // namespace apdu
