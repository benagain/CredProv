#include <atlbase.h>

namespace myid
{

	/** Because this is likely to be used for the returning of error code on the COM boundary, it important that a success
	HRESULT is not returned if the intention is to report an error.
	If this exception is constructed without passing in an errorcode, GetLastError() will have been used for the errorReason.
	This may return a windows error code which is not a failure HRESULT.
	The implication of accidentally returning success when an error is intended to be returned is undefined behaviour, since COM
	stipulates that all [out] params must be initialised if a success code is returned*/
	long Exception::getHRESULT(void) const
	{
		const unsigned long ulErrorNumber = getErrorNumber();
		if(FAILED(ulErrorNumber))
			return (long)ulErrorNumber;

		long HResult((long)HRESULT_FROM_WIN32(ulErrorNumber));
		if(SUCCEEDED(HResult))
		{
			return E_FAIL;
		}

		return HResult;
	}
}

