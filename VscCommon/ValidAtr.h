#pragma once

/// ATR support functions
namespace ValidAtr
{

bool Valid(_In_reads_(atrLen) const PBYTE atr, _In_ DWORD atrLen);
DWORD Get(_In_ Process::VscType type, _Out_ Process::ATR* atr, _Out_ DWORD* atrLen);
Process::VscType Type(_In_ const VectorOfByte& atr);

} // namespace ValidAtr
