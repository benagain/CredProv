#include "CatchMain.h"
#include "CatchException.h"
#include "Utilities/EdeficeCommon/Exceptions/StackDump.h"
#ifdef SET_COM_EXCEPTION
#include "Utilities\EdeficeCommon\Exceptions\ComException.h"
#endif
#include "Utilities/EdeficeCommon/Debug.h"
#ifdef EXTRA_TEST_INIT
// define the body of this function
void ExtraInit(int argc, char * argv[]);
#endif

int main (int argc, char * argv[])
{
#ifdef THREAD_MODEL
	AutoCom ac(THREAD_MODEL);
#else
	// cppcheck-suppress unusedVariable
	AutoCom ac;
#endif

	// suppress stack dumps, they are time consuming and tests often construct a lot of exceptions
	myid::StackDump::Enabled = false;

#ifdef SET_COM_EXCEPTION
	myid::ComException::SetComException();
#endif

	// Stops any registry or file debugging
	CDebug::SetTestDebugLevel(0);

#ifdef EXTRA_TEST_INIT
	ExtraInit(argc, argv);
#endif

	return Catch::Session().run( argc, argv );
}


#if defined(WIN32) && !defined(MOBILE)

#include "comdef.h"
#include "Utilities/EdeficeCommon/Conversions/StringUtils.h"

// Make sure that _com_error exceptions are reported well
CATCH_TRANSLATE_EXCEPTION(_com_error & e)
{
	return Catch::toString(e);
}

#endif