/// This is the interface for MyIDIntelAuthenticate.dll

/**
The instance ID has format ROOT\SMARTCARDREADER\000n , where n is 0 - 9
The create function populates a pre-allocated buffer of size MYIDINTEL_INSTANCE_ID_LENGTH with the instance ID.
The instance ID supplied to the Remove function is that received from the Create function.
It can also be found using the SCardGetReaderDeviceInstanceId() function.
The n value can also be obtained by using SCardGetAttrib(, SCARD_ATTR_DEVICE_UNIT, , )
The optional friendly name is the device friendly name, and is only seen in the Control Panel DeviceManager.
The reboot parameter indicates if a reboot is required.
The return value is an error code.
S_OK success
NTE_INVALID_PARAMETER null parameter
TRUST_E_CERT_SIGNATURE not signed by Intel
*/

#pragma once

/// Module name for LoadLibrary
#define MYIDINTEL_MODULE _T("MyIDIntelAuthenticate")

/// Create function name for GetProcAddress
#define MYIDINTEL_CREATE "MyID_Intel_Create"

/// Remove function name for GetProcAddress
#define MYIDINTEL_REMOVE "MyID_Intel_Remove"

/// Minimum length of instanceId parameter
#define MYIDINTEL_INSTANCE_ID_LENGTH 26

typedef HRESULT(WINAPI *tMyID_Intel_Create)(_In_opt_z_ LPCWSTR friendlyName, _Out_ BOOL* reboot, _Inout_z_ LPWSTR instanceId);
typedef HRESULT(WINAPI *tMyID_Intel_Remove)(_In_z_ LPCWSTR instanceId, _Out_ BOOL* reboot);

HRESULT WINAPI MyID_Intel_Create(_In_opt_z_ LPCWSTR friendlyName, _Out_ BOOL* reboot, _Inout_z_ LPWSTR instanceId);
HRESULT WINAPI MyID_Intel_Remove(_In_z_ LPCWSTR instanceId, _Out_ BOOL* reboot);
