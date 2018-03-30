#pragma once

#include "HSMType.h"

namespace TestAbstractKeys
{
	/*!
	* A simple struct to hold parameters for a call to DoTests, this is required because we exceeded
	* the number of parameters that can be passed in a call to boost::bind!
	*/
	struct TestParameters
	{
		EHSMType hsmType;
		std::wstring hsmSerial;
		std::wstring hsmPassword;

		bool bReportPassed;
		bool bReportFailures;
		bool bSaveOutput;

		int numIterations;

		// -----------------------------------------------------------------------------------------

		TestParameters() :	hsmType(eUnknown)
						,	bReportPassed(false)
						,	bReportFailures(false)
						,	bSaveOutput(false)
						,	numIterations(1)
		{
		}
	};

	struct ProgramParams
	{
		long lNumberOfThreads;
		bool bThreadCallback;
		bool explicitSN;
		bool explicitPwd;
		bool implicitSN;
		bool implicitPwd;
		bool commandLineError;
		TestParameters testParams;

		ProgramParams()
			: lNumberOfThreads(0)
			, bThreadCallback(false)
			, explicitSN(false)
			, explicitPwd(false)
			, implicitSN(false)
			, implicitPwd(false)
			, commandLineError(false)
			, testParams()
		{}
	};
}