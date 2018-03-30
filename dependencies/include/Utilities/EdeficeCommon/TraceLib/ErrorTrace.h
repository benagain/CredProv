// ErrorTrace.h : Create Function call traces and log to Debug stream
// Copyright Intercede Ltd (c) 2006.  All rights reserved.
//-------------------------------------------------------------------------------------------------------------
// In each top level COM Function declare a CErrorTrace object, pass a pointer to this object to each sub function 
// called.  In each sub function create a CLogger object (pass CErrorTrace pointer to this object) and in every sub 
// function's catch statements add a logger.AppendMsg(e.what()) type call
//-------------------------------------------------------------------------------------------------------------

#ifndef __ERRORTRACE_H_
#define __ERRORTRACE_H_



// Global trace flag

class CErrorTrace
{
public:
	CErrorTrace(bool bDbgOutput, bool bFileOutput);
	~CErrorTrace();

	static void PollTraceStatus(const std::wstring & wstrComponent);

	static bool IsTraceSet();

protected:
	friend class CLogger;
	
	void OpenNode(const std::string & strNodeName);

	void CloseNode(const std::string & strNodeName);

	void AppendMsg(const std::string & strMsg);

	void AppendMsgW(const std::wstring & wstrMsg);

	void Append(const std::string & str);

	void AddTimeAttr();

	static bool TraceOn(const std::wstring & wstrComponent);

	void Flush();

	void Output();

	void OpenLogFile();
	
	int WriteTxt() const;

	void CloseLogFile();

private:
	std::string m_strTrace;
	bool m_bDbgOutput;
	bool m_bFileOutput;
	static std::wstring sm_wstrDbgFile;
	static bool s_bTraceOn;
	FILE * m_file;
};



class CLogger
{
public:
	CLogger(CErrorTrace * pErrorTrace, const std::string& strFuncName)
	{
		m_pErrorTrace = NULL;
		
		// Need to call PollTraceStatus first
		if(CErrorTrace::IsTraceSet())
		{
			m_pErrorTrace = pErrorTrace;
		}
		if(m_pErrorTrace != NULL)
		{
			m_strFuncName = strFuncName;
			m_pErrorTrace->OpenNode(m_strFuncName);
		}
	}

	~CLogger()
	{
		if(m_pErrorTrace != NULL)
			m_pErrorTrace->CloseNode(m_strFuncName);
	}

	void AppendMsg(const std::string & strMsg)
	{
		if(m_pErrorTrace != NULL)
			m_pErrorTrace->AppendMsg(strMsg);
	}

	void AppendMsgW(const std::wstring & wstrMsg)
	{
		if(m_pErrorTrace != NULL)
			m_pErrorTrace->AppendMsgW(wstrMsg);
	}

	void Flush()
	{
		if(m_pErrorTrace != NULL)
			m_pErrorTrace->Flush();
	}

private:
	std::string m_strFuncName;
	
	CErrorTrace * m_pErrorTrace;
};

namespace ErrorTrace
{

// bol utils has a wide version of this but all our interaction in smartcard are ansi
inline std::string GetErrorText(DWORD dwError)
{
	DWORD dwFormatFlags =	FORMAT_MESSAGE_ALLOCATE_BUFFER |
							FORMAT_MESSAGE_IGNORE_INSERTS |
							FORMAT_MESSAGE_FROM_SYSTEM;

	//
	// Call FormatMessage() to allow for message 
	//  text to be acquired from the system 
	LPSTR MessageBuffer = NULL;
	
	DWORD dwBufferLength = FormatMessageA(dwFormatFlags,
										NULL, // == system
										dwError,
										MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
										(LPSTR) &MessageBuffer,
										0,
										NULL
										);

	
	std::stringstream streamOutputMessage;
	// turn the error code into a string
	streamOutputMessage << "0x" << std::hex << dwError;
	
	
	if(dwBufferLength)
	{
		// if a readable message exists, then output that also
		std::string strMessageBuffer(MessageBuffer);
		LocalFree(MessageBuffer);

		// add a readable message if available
		streamOutputMessage << " - " << strMessageBuffer;
	}

	return streamOutputMessage.str();
}

};


// Pre Call stuff here
#define ENTER_CALL(sz)																	\
CErrorTrace * pTraceObj = NULL;															\
CErrorTrace errTrace(true, true);														\
pTraceObj = &errTrace;																	\
CLogger logger(pTraceObj, sz);															\
logger.Flush();

// Add a message
#define WRITE_DBG_MSG(sz)																\
logger.AppendMsg(sz);																	\
logger.Flush();

// Add a message
#define WRITE_DBG_MSGW(sz)																\
logger.AppendMsgW(sz);																	\
logger.Flush();

// Add a message
#define WRITE_LAST_ERROR																\
DWORD dwLastError = ::GetLastError();                                                   \
if(dwLastError != 0)                                                                    \
{                                                                                       \
	logger.AppendMsg(ErrorTrace::GetErrorText(dwLastError).c_str());                                \
	logger.Flush();                                                                     \
}

// Add a message
#define WRITE_LAST_KNOWNERROR(dwLastError)												\
if(dwLastError != 0)                                                                    \
{                                                                                       \
	logger.AppendMsg(ErrorTrace::GetErrorText(dwLastError).c_str());                                \
	logger.Flush();                                                                     \
}


#endif