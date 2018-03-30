#include "../../SalFix.h"
namespace myid
{

/// Translate error number to error text
std::wstring ErrorException::GetErrorText(_In_ unsigned long error)	///< error number
{
	UNREFERENCED_PARAMETER(error);

	return std::wstring();
}

}
