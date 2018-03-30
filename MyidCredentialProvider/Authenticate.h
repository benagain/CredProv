#pragma once

namespace Authenticate
{

bool IsDomainJoined(void);
void DebugSerialization(_Inout_ std::wstringstream& stream, _In_opt_ const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs);
void DebugSerializationKerb(_Inout_ std::wstringstream& stream, _In_opt_ const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs);

} // namespace Authenticate

