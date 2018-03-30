#pragma once

namespace Authenticate
{

HRESULT GetAuthPackage(_Out_ ULONG& authPackage);
std::wstring GetAuthPackageName(_In_ ULONG authPackage);

} // namespace Authenticate

