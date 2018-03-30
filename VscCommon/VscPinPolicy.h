#pragma once
#include "..\SDK\Minidriver\MyIDVscDriverAPI.h"
#include "Utilities\EdeficeCommon\VectorOfByte.h"

namespace MyID_Vsc
{

/// Pin policy data maintenance
class PinPolicy : public PinPolicy_Data
{
public:
	PinPolicy();

	void Reset(void);
	void Get(_Out_ VectorOfByte& policy) const;
	bool Set(_In_ const VectorOfByte& policy);
	bool Set(_In_ LONG minLength, _In_ LONG maxLength, _In_ const std::wstring& allowed);
	bool ValidatePin(_In_ const VectorOfByte& pin) const;

	bool Modified(void) const;
	void Modified(bool modified);

	static bool CheckVersion(_In_reads_bytes_(cbDataLen) PBYTE pbData, _In_ DWORD cbDataLen);
	static bool Check(_In_reads_bytes_(cbDataLen) PBYTE pbData, _In_ DWORD cbDataLen);

protected:
	static bool CheckVersion(_In_ const PinPolicy_Data_1& policy);
	static bool Check(_In_ const PinPolicy_Data_1& policy);

	bool m_modified{false};			///< has it been modified
};

} // namespace MyID_Vsc
