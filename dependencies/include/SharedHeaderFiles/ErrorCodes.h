// NOTE to Developer: When editing this file it is important to consider that some of the entries may only
// be used in certain branches of MyID, so please **do not remove** them if they are not referenced in the branch
// that you are working on.
///////////////////////////////////////////////////////////////////////////////////////
//
/// \file
/// Error codes (custom HRESULTS) for Edefice Business Object Layer
/// Used for CEdeficeBOLException class for return values
//
///////////////////////////////////////////////////////////////////////////////////////
//
//	Note 1: If you add an error code to this file then you must add an appropriate line
//			in the file EdeficeBOLException.cpp with a meaningful message
//
//	Note 2: This file should be appended to the BOL technical specification at each release
//			of the product
//
//	Note 3: The error range for the BOL is 0x80046000 to 0x80046FFF
//			This range has been subdivided into:
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046000 to 0x8004604F	Miscellaneous errors
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046050 to 0x800460FF	Enveloping errors
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046100 to 0x800462FF	Errors on the IEdeficeBOL interface
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046300 to 0x800463FF	Errors on the IEdeficeAuth interface
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046400 to 0x800464FF	Errors on the IEdeficeCert interface
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046500 to 0x800465FF	Errors on the IEdeficeARM interface
///////////////////////////////////////////////////////////////////////////////////////
//			0x80046800 to 0x800468FF    More errors on the IEdeficeBOL interface
///////////////////////////////////////////////////////////////////////////////////
//			0x80046900 to 0x80046FFF	SPARE
///////////////////////////////////////////////////////////////////////////////////
//			0x80047000 to 0x80047FFF	eDiskEncryptor
///////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace BOLErrors								/// BOL error codes
{
	///////////////////////////////////////////////////////////////////////////////////
	// Miscellaneous BOL errors
	// Error number range 0x80046000 to 0x8004604F
	///////////////////////////////////////////////////////////////////////////////////
	const long	MISC_Unknown_Error								= 0x80046000;	///< unknown error
	const long	MISC_Input_BSTR_Null							= 0x80046001;	///< input BSTR to a method is NULL
	const long	MISC_ChangeType_Failed							= 0x80046002;	///< changeType failed
	const long	MISC_Caught_Std_Exception						= 0x80046003;	///< Caught Std Exception in COM_CATCH_HANDLER
	const long	MISC_Caught_Default_Exception					= 0x80046004;	///< Caught ... exception in COM_CATCH_HANDLER
	const long	MISC_Min_Data									= 0x80046005;	///< Minimum Data not supplied to function
	const long	MISC_Generate_Rand_Failed						= 0x80046006;	///< Unable to generate random string
	const long  MISC_NoData										= 0x80046007;	///< No data supplied to function
	const long  MISC_Cant_Instantiate_Module					= 0x80046008;	///< Unable to load the specified module
	const long  MISC_Device_Not_Found							= 0x80046009;	///< The specified device could not be found
	const long  MISC_Applet_Not_Found							= 0x8004600A;	///< The specified applet could not be found
	const long	MISC_InvalidScope								= 0x8004600B;	///< The user does not have sufficient privileges to carry out this action
	const long	MISC_AuditError									= 0x8004600C;	///< Audit operation failed
	const long  MISC_ExternalServerCredentials_NotFound			= 0x8004600D;	///< External Server Credentials not found
	const long  MISC_UDLError									= 0x8004600E;	
	const long  MISC_Output_Recordset_Null                      = 0x8004600F;	///< [out, retval] LPDISPATCH* pointer is NULL
	const long  MISC_MultipleMatch			                    = 0x80046010;	///< Multiple Records returned
	const long  MISC_FileWriteError								= 0x80046011;	///< Error Writing File
	const long  MISC_Certificate_Not_Found						= 0x80046012;	///< The specified certificate could not be found
	const long  MISC_ScopeCheck_DataNotSupplied					= 0x80046013;	///< Data required to check scope has not been supplied
	const long  MISC_InvalidData                                = 0x80046014;	///< Data supplied to the function is invalid
	const long  MISC_InvalidProgId                              = 0x80046015;	///< A Prog ID could not be made into a Class ID
	const long  MISC_CardProfile_Not_Found				        = 0x80046016;	///< The specified CardProfile could not be found
	const long  MISC_Missing_Task_Type							= 0x80046017;	///< The requesting task type is missing from the database
	const long  MISC_BinaryObject_Not_Found						= 0x80046018;	///< The requested BinaryObject could not be found
	const long	MISC_Key_Not_Found								= 0x80046019;	///< The requested key could not be found
	const long	MISC_OutputTypeNotSupported						= 0x8004601A;	///< The requested output type is not supported
	const long	MISC_NoMatch									= 0x8004601B;	///< No Records returned
	const long	MISC_XMLError									= 0x8004601C;	///< Error parsing XML
	const long	MISC_Missing_Cert_Tag							= 0x8004601D;	///< PIVAuthDecompressor Certificate Tag 0x70 Missing from cert container
	const long	MISC_Missing_Certinfo_Tag						= 0x8004601E;	///< PIVAuthDecompressor Certinfo tag 0x71 Missing from cert container
	const long	MISC_Cert_Decompression_Error					= 0x8004601F;	///< PIVAuthDecompressor Error during decompression of cert data
	const long	MISC_Invalid_CertInfoByte_Value					= 0x80046020;	///< PIVAuthDecompressor Value of Cert Infobyte invalid (not 0 or 1)
	const long  MISC_CertificateInvalid							= 0x80046021;   ///< Certificate is invalid
	const long  MISC_Device_Not_Issued							= 0x80046022;	///< The specified device is not issued
	const long  MISC_UserHasNotBeenAuthenticated				= 0x80046023;	///< The target user has not been successfully validated via role-based authentication

	///////////////////////////////////////////////////////////////////////////////////
	// Enveloping Errors
	// Error number range 0x80046050 to 0x800560FF
	///////////////////////////////////////////////////////////////////////////////////
	const long  ENV_LoadClearEnv_InvalidXML						= 0x80046050;	///< invalid XML in loadclearenv method
	const long  ENV_LoadSignedEnv_InvalidXML					= 0x80046051;	///< invalid XML in loadSignedEnv method
	const long  ENV_LoadXML_InvalidXML							= 0x80046052;	///< invalid XML in loadXML method
	const long  ENV_LoadXML_XMLElement_NotFound					= 0x80046053;	///< XML element not found in loadXML method
	const long  ENV_XMLHeaderFormatNode_NotFound				= 0x80046054;	///< format node not found in envelope header
	const long  ENV_XMLSecuritySenderDeviceIDNode_NotFound		= 0x80046055;	///< Security Sender Device ID not found in envelope
	const long	ENV_SigningDevice_NotFoundInDB					= 0x80046056;	///< Signing device SN not found in DB
	const long	ENV_SigningDevice_KeyNull						= 0x80046057;	///< Signing device key from DB is NULL
	const long  ENV_SigningDevice_UserAccountIDZero				= 0x80046058;	///< user account id associated with signing device is 0
	const long	ENV_SigningDevice_UserNotFound					= 0x80046059;	///< user account associated with signing device not found
	const long	ENV_SigningDevice_UserAccountIDNull				= 0x8004605A;	///< user account id associated with signing device is NULL
	const long	ENV_SigningDevice_LogonNameNull					= 0x8004605B;	///< logonname associated with device is NULL
	const long	ENV_CheckTaskNumberSessionID_MinData			= 0x8004605C;	///< Minimum data not supplied
	const long	ENV_CheckTaskNumberSessionID_TaskNumberInvalid	= 0x8004605D;	///< TaskNumber is invalid
	const long  ENV_XMLHeaderVersionNode_NotFound				= 0x8004605E;	///< version node not found in envelope header
	const long  ENV_XMLHeaderInvalidVersion						= 0x8004605F;	///< Invalid version
	const long  ENV_SignatureInvalid							= 0x80046060;	///< Envelope signature verication failed
	const long	ENV_SessionID_Mismatch							= 0x80046061;	///< Session ID in envelope does not match envelope header
	const long	ENV_NoLogon_Session      						= 0x80046062;	///< No logon session for the task
	const long	ENV_Task_Expired         						= 0x80046063;	///< Task has timed out
	const long	ENV_OperationID_Zero_NotAllowed					= 0x80046064;	///< OperationID of zero not permitted
	const long	ENV_OperationID_Task_Mismatch					= 0x80046065;	///< OperationID in envelope body does not match OperationID in TaskNumbers table
	const long	ENV_SoftwareSignedForDevice						= 0x80046066;	///< Software signed when Device signed is required
	const long	ENV_InvalidSignatureType						= 0x80046067;	///< Invalid signature type in envelope header
	const long	ENV_ClearEnvelopeNotPermitted					= 0x80046068;	///< A clear enveloped is not permitted here
	const long	ENV_InvalidEnvelopeFormat						= 0x80046069;	///< Invalid envelope format
	const long	ENV_PersistedEnvelopeRequired					= 0x80046070;	///< Persisted envelope required
	const long	ENV_CheckLogonBlock_LogonBlockInvalid			= 0x80046071;	///< LogonBlock is invalid
	const long	ENV_PendingAuthenticationNotPermitted			= 0x80046072;	///< Pending authentication not permitted


	////////////////////////////////////////////////////////////////////////////////////
	// Errors on the BOL modules
	// Error number range 0x80046100 to 0x800462FF
	////////////////////////////////////////////////////////////////////////////////////
	const long	BOL_AddActivCardDevice_NoData					= 0x80046100;	///< AddActivCardDevice, no data
	const long	BOL_AddActivCardDevice_MinData					= 0x80046101;	///< AddActivCardDevice, minimum data not supplied
	const long	BOL_AddActivCardDevice_NoSuchDevice				= 0x80046102;	///< AddActivCardDevice, no such device
	const long	BOL_AddActivCardDevice_DeviceID_Null			= 0x80046103;	///< AddActivCardDevice, DeviceID null
	const long	BOL_AddActivCardDevice_MinSlotData				= 0x80046104;	///< AddActivCardDevice, minimum slot data not supplied
	const long	BOL_AddDevice_NoData							= 0x80046105;	///< AddDevice, no data
	const long	BOL_AddDevice_MinData							= 0x80046106;	///< AddDevice, minimum data not supplied
	const long	BOL_AddDevice_DeviceExists						= 0x80046107;	///< AddDevice, device already exists
	const long	BOL_AddDeviceClear_NoData						= 0x80046108;	///< AddDeviceClear, no data
	const long	BOL_AddDeviceClear_MinData						= 0x80046109;	///< AddDeviceClear, minimum data not supplied
	const long	BOL_AddDeviceClear_DeviceExists					= 0x8004610A;	///< AddDeviceClear, device exists
	const long	BOL_AddGroups_NoData							= 0x8004610B;	///< AddGroups, no data
	const long	BOL_AddGroups_MinData							= 0x8004610C;	///< AddGroups, minimum data not supplied
	const long	BOL_AddPersonUserAccount_NoData					= 0x8004610D;	///< Empty input for function AddPersonUserAccount
	const long	BOL_AddPersonUserAccount_NoManagerData			= 0x8004610E;	///< AddPersonUserAccount, no manager data
	const long	BOL_AddPersonUserAccount_MinManagerData			= 0x8004610F;	///< AddPersonUserAccount, minimum manager data not supplied
	const long	BOL_AddPersonUserAccount_ManagersUserProfileExceeded = 0x80046120;	///< AddPersonUserAccount, managers UserProfileID exceeded
	const long	BOL_AddPersonUserAccount_ManagerNoFound			= 0x80046121;	///< AddPersonUserAccount, manager not found in DB
	const long	BOL_AddPersonUserAccount_ManagerNotUnique		= 0x80046122;	///< AddPersonUserAccount, manager not unique
	const long	BOL_AddPersonUserAccount_ManagerUserProfileIDNull	= 0x80046123;	///< AddPersonUserAccount, Manager's UserProfileID is NULL
	const long	BOL_AddPersonUserAccount_NoPersonData			= 0x80046124;	///< AddPersonUserAccount, no person data
	const long	BOL_AddPersonUserAccount_MinPersonData			= 0x80046125;	///< AddPersonUserAccount, minmum person data not supplied
	const long	BOL_AddPersonUserAccount_SystemAccIDNull		= 0x80046126;	///< AddPersonUserAccount, SystemAccount ID field is NULL
	const long	BOL_AddPersonUserAccount_NoUserAccountData		= 0x80046127;	///< AddPersonUserAccount, No UserAccount data
	const long	BOL_AddPersonUserAccount_MinUserAccountData		= 0x80046128;	///< AddPersonUserAccount, minimum UserAccount data not supplied
	const long	BOL_AddPinPolicy_NoData							= 0x80046129;	///< AddPINPolicy, minimum data not supplied
	const long	BOL_AddPinPolicy_MinData						= 0x8004612A;	///< AddPINPolicy, minimum data not supplied
	const long	BOL_AddRadiusClients_NoData						= 0x8004612B;	///< AddRadiusClients, no data
	const long	BOL_AddRadiusClients_MinData					= 0x8004612C;	///< AddRadiusClients, minimum data not supplied
	const long	BOL_AddRadiusConnections_NoData					= 0x8004612D;	///< AddRadiusConnections, no data
	const long	BOL_AddRadiusConnections_MinData				= 0x8004612E;	///< AddRadiusConnections, minimum data not supplied
	const long	BOL_AddRadiusServers_NoData						= 0x8004612F;	///< AddRadiusServers, no data
	const long	BOL_AddRadiusServers_MinData					= 0x80046130;	///< AddRadiusServers, minimum data not supplied
	const long	BOL_AddRasServers_NoData						= 0x80046131;	///< AddRasServers, no data
	const long	BOL_AddRasServers_MinData						= 0x80046132;	///< AddRasServers, minimum data not supplied
	const long	BOL_BOLGetCertificates_NoData					= 0x80046133;	///< BOLGetCertificates, no data
	const long	BOL_BOLGetCertificates_MinData					= 0x80046134;	///< BOLGetCertificates, minimum data not supplied
	const long	BOL_BOLUpdateCertificates_NoData				= 0x80046135;	///< BOLUpdateCertificates, no data
	const long	BOL_BOLUpdateCertificates_MinData				= 0x80046136;	///< BOLUpdateCertificates, minimum data not supplied
	const long	BOL_CheckAuthorisation_NoData					= 0x80046137;	///< Empty input for function Check Authorisation
	const long	BOL_CheckAuthorisation_MinData					= 0x80046138;	///< Min data for CheckAuthorisation not supplied
	const long	BOL_CheckMessageNumber_Offset_Null				= 0x80046139;	///< CheckMessageNumber, offset field in DB is Null
	const long	BOL_CheckMessageNumber_MessageNumberExpired		= 0x8004613A;	///< CheckMessageNumber, message number has expired
	const long	BOL_CompleteTask_NoData							= 0x8004613B;	///< CompleteTask, no data
	const long	BOL_CompleteTask_MinData						= 0x8004613C;	///< CompleteTask, minimum data not supplied
	const long	BOL_DeleteGroups_NoData							= 0x8004613D;	///< DeleteGroups, no data
	const long	BOL_DeleteGroups_MinData						= 0x8004613E;	///< DeleteGroups, minimum data not supplied
	const long	BOL_DeleteGroups_ParentGroupID_Null				= 0x8004613F;	///< DeleteGroups, ParentGroupID field in database is Null
	const long	BOL_DeleteGroups_ParentGroupDeleted				= 0x80046140;	///< DeleteGroups, identified ParentGroup is marked as deleted
	const long	BOL_DeletePeopleUserAccounts_NoData				= 0x80046141;	///< DeletePeopleUserAccounts, no data
	const long	BOL_DeletePeopleUserAccounts_MinData			= 0x80046142;	///< DeletePeopleUserAccounts, minimum data not supplied
	const long	BOL_DeletePeopleUserAccounts_ManagerNoMatch		= 0x80046143;	///< DeletePeopleUserAccounts, manager data not found in database
	const long	BOL_DeletePeopleUserAccounts_ManagerMultipleMatch = 0x80046144;	///< DeletePeopleUserAccounts, manager data multiply matched in database
	const long	BOL_DeletePeopleUserAccounts_ManagerUserAccountID_Null = 0x80046145;///< DeletePeopleUserAccounts, managerUserAccountID null
	const long	BOL_DeletePeopleUserAccounts_ManagerSelfDel		= 0x80046146;	///< DeletePeopleUserAccounts, manager is attempting to delete themself
	const long	BOL_DeletePeopleUserAccounts_SystemAccountID_Null = 0x80046147;	///< DeletePeopleUserAccounts, SystemAccountID field in DB is Null
	const long	BOL_DeleteRadiusClients_NoData					= 0x80046148;	///< DeleteRadiusClients, no data
	const long	BOL_DeleteRadiusClients_MinData					= 0x80046149;	///< DeleteRadiusClients, minimum data not supplied
	const long	BOL_DeleteRadiusConnections_NoData				= 0x8004615A;	///< DeleteRadiusConnections, no data
	const long	BOL_DeleteRadiusConnections_MinData				= 0x8004615B;	///< DeleteRadiusConnections, minimum data not supplied
	const long	BOL_DeleteRadiusServers_NoData					= 0x8004615C;	///< DeleteRadiusServers, no data
	const long	BOL_DeleteRadiusServers_MinData					= 0x8004615D;	///< DeleteRadiusServers, minimum data not supplied
	const long	BOL_DeleteRadiusServers_MachineName_Null		= 0x8004615E;	///< DeleteRadiusServers, machine name field from database is Null
	const long	BOL_DeleteRasServers_NoData						= 0x8004615F;	///< DeleteRasServers, no data
	const long	BOL_DeleteRasServers_MinData					= 0x80046160;	///< DeleteRasServers, minimum data not supplied
	const long	BOL_GetADOrganisation_NoData					= 0x80046161;	///< GetADOrganisation, no data
	const long	BOL_GetADUserAccounts_NoData					= 0x80046162;	///< GetADUserAccounts, no data
	const long	BOL_GetADUserAccountInfo_NoData					= 0x80046163;	///< GetADUserAccountInfo, no data
	const long	BOL_GetADUserAccountInfo_UserNotFound			= 0x80046164;	///< GetADUserAccountInfo, user account not found
	const long	BOL_GetCardProfileByUserAccountID_NoData		= 0x80046165;	///< GetCardProfileByUserAccountID, no data
	const long	BOL_GetCertificatePolicy_NoData					= 0x80046166;	///< GetCertificatePolicy, no data
	const long	BOL_GetClientOS_NoData							= 0x80046167;	///< GetClientOS, no data
	const long	BOL_GetDevices_NoData							= 0x80046168;	///< GetDevices, no data
	const long	BOL_GetDevicesByPersonID_NoData					= 0x80046169;	///< GetDevicesByPersonId, no data
	const long	BOL_GetDeviceTypes_NoData						= 0x8004616A;	///< GetDeviceTypes, no data
	const long	BOL_GetEdeficePublicKeys_NoData					= 0x8004616B;	///< GetEdeficePublicKeys, no data
	const long	BOL_GetGroupIDs_NoData							= 0x8004616C;	///< Empty input for function GetGroupIDs
	const long	BOL_GetGroups_NoData							= 0x8004616D;	///< GetGroups, no data
	const long	BOL_GetMachines_NoData							= 0x8004616E;	///< GetMachines, no data
	const long	BOL_GetPeopleByDeviceSN_NoData					= 0x8004616F;	///< GetPeopleByDeviceSN, no data
	const long	BOL_GetPeopleByDeviceSN_MinData					= 0x80046170;	///< GetPeopleByDeviceSN, minimum data not supplied
	const long	BOL_GetPeopleID_NoData							= 0x80046171;	///< GetPeopleID, no data
	const long	BOL_GetPeopleID_MinData							= 0x80046172;	///< GetPeopleID, minimum data not supplied
	const long	BOL_GetPeopleID_NoMatch							= 0x80046173;	///< GetPeopleID, fullname not matched
	const long	BOL_GetPeopleID_MultipleMatch					= 0x80046174;	///< GetPeopleID, fullname matched to multiple people
	const long	BOL_GetPeopleID_ID_Null							= 0x80046175;	///< GetPeopleID, ID field in database is null
	const long	BOL_GetPeopleUserAccounts_NoData				= 0x80046176;	///< GetPeopleUserAccounts, no data
	const long	BOL_GetPersonSecret_NoData						= 0x80046177;	///< GetPersonSecret, no data
	const long	BOL_GetPersonSecret_MinData						= 0x80046178;	///< GetPersonSecret, minimum data not supplied
	const long	BOL_GetPINPolicy_NoData							= 0x80046179;	///< GetPINPolicy, no data
	const long	BOL_GetPINPolicy_MinData						= 0x80046180;	///< GetPINPolicy, minimum data not supplied
	const long  BOL_GetProcessStages_NoData						= 0x80046181;	///< Empty input for function GetPRocessStages
	const long	BOL_GetPUC_NoData								= 0x80046182;	///< GetPUC, no data
	const long	BOL_GetPUC_MinData								= 0x80046183;	///< GetPUC, minimum data not supplied
	const long	BOL_GetPUC_NoMatch								= 0x80046184;	///< GetPUC, serial number not matched in database
	const long	BOL_GetPUC_MultipleMatch						= 0x80046185;	///< GetPUC, serial number multiply matched in database
	const long	BOL_GetPUC_Unlock_Null							= 0x80046186;	///< GetPUC, unlock field in database is Null
	const long	BOL_SigningDevice_NoMatch						= 0x80046187;	///< Signing device details not matched in DB
	const long	BOL_SigningDevice_MultipleMatch					= 0x80046188;	///< Signing device details multiply matched in DB
	const long	BOL_SigningDevice_EncryptKey_Null				= 0x80046189;	///< Signing device encrypt key is null
	const long	BOL_GetPUCToken_NoData							= 0x8004618A;	///< GetPUCToken, no data
	const long	BOL_GetPUCToken_MinData							= 0x8004618B;	///< GetPUCToken, minimum data not supplied
	const long	BOL_GetPUCToken_NoMatch							= 0x8004618C;	///< GetPUCToken, device not matched in DB
	const long	BOL_GetPUCToken_MultipleMatch					= 0x8004618D;	///< GetPUCToken, device multiply matched in DB
	const long	BOL_GetPUCToken_Unlock_Null						= 0x8004618E;	///< GetPUCToken, Unlock field in DB is Null
	const long	BOL_GetPUCToken_UnlockCodeCD_Null				= 0x8004618F;	///< GetPUCToken, UnlockCodeCD field in DB is Null
	const long	BOL_GetPUCToken_UnlockChalCD_Null				= 0x80046190;	///< GetPUCToken, UnlockChalCD field in DB is Null
	const long	BOL_GetPUCToken_NotActivCardInstall				= 0x80046191;	///< GetPUCToken, not an ActivCard install
	const long	BOL_GetPUCToken_SignDevice_NoMatch				= 0x80046192;	///< GetPUCToken, signing device details not matched in DB
	const long	BOL_GetPUCToken_SignDevice_MultipleMatch		= 0x80046193;	///< GetPUCToken, signing device details multiply matched in DB
	const long	BOL_GetPUCToken_EncryptKey_Null					= 0x80046194;	///< GetPUCToken, EncryptKey field in DB is Null
	const long	BOL_GetRadiusClients_NoData						= 0x80046195;	///< GetRadiusClients, no data
	const long	BOL_GetRadiusConnections_NoData					= 0x80046196;	///< GetRadiusConnections, no data
	const long	BOL_GetRadiusDevices_NoData						= 0x80046197;	///< GetRadiusDevices, no data
	const long	BOL_GetRadiusProfiles_NoData					= 0x80046198;	///< GetRadiusProfiles, no data
	const long	BOL_GetRadiusServers_NoData						= 0x80046199;	///< GetRadiusServers, no data	
	const long	BOL_GetRasServers_NoData						= 0x8004619A;	///< GetRasServers, no data
	const long	BOL_GetSecurityQuestions_NoData					= 0x8004619B;	///< GetSecurityQuestions, no data
	const long	BOL_GetSyncAuth_NoData							= 0x8004619C;	///< GetSyncAuth, no data
	const long	BOL_GetSystemAccountInfo_NoData					= 0x8004619D;	///< GetSystemAccountInfo, no data
	const long	BOL_GetSystemAccountInfo_MinData				= 0x8004619E;	///< GetSystemaccountinfo, minimum data not supplied
	const long	BOL_GetTaskNumber_TimeOffset_Null				= 0x8004619F;	///< GetTaskNumber, TimeOffset is NULL
	const long	BOL_GetTitles_NoData							= 0x800461A0;	///< Empty input for function GetTitles
	const long	BOL_GetUnassignedDevices_NoData					= 0x800461A1;	///< GetUnassignedDevices, no data
	const long	BOL_GetUserProfileIDs_NoData					= 0x800461A2;	///< Empty input for function GetUserProfileIDs	
	const long  BOL_Logon_NoData								= 0x800461A3;	///< Logon, Empty input string
	const long  BOL_Logon_MinData								= 0x800461A4;	///< Logon, minmum data not supplied
	const long	BOL_Logon_UnauthorisedLogon						= 0x800461A5;	///< Logon, unauthorised logon
	const long	BOL_Logon_UserProfileID_Null					= 0x800461A6;	///< Logon, userprofileID is null
	const long	BOL_ResyncActivCardDevice_NoData				= 0x800461A7;	///< ResyncActivCardDevice, no data
	const long	BOL_ResyncActivCardDevice_MinData				= 0x800461A8;	///< ResyncActivCardDevice, minimum data not supplied
	const long	BOL_ResyncActivCardDevice_NoMatch				= 0x800461A9;	///< ResyncActivCardDevice, no match
	const long	BOL_ResyncActivCardDevice_MultipleMatch			= 0x800461BA;	///< ResyncActivCardDevice, multiple match
	const long	BOL_ResyncActivCardDevice_ACounterDiffLimit		= 0x800461BB;	///< ResyncActivCardDevice, ACounter difference limit exceeded
	const long	BOL_ResyncActivCardDevice_DeviceID_Null			= 0x800461BC;	///< ResyncActivCardDevice, device ID field in DB is Null
	const long	BOL_ResyncActivCardDevice_ACounter_Null			= 0x800461BD;	///< ResyncActivCardDevice, ACounter field in DB is Null
	const long	BOL_ResyncActivCardDevice_ASyncKey_Null			= 0x800461BE;	///< ResyncActivCardDevice, ASyncKey field in DB is Null
	const long	BOL_ResyncActivCardDevice_Offset_Null			= 0x800461BF;	///< ResyncActivCardDevice, Offset field in DB is Null
	const long	BOL_ResyncActivCardDevice_NotActivCardInstall	= 0x800461C0;	///< ResyncActivCardDevice, not an ActivCard installation
	const long	BOL_UpdateDevices_ID_NoMatch					= 0x800461C1;	///< UpdateDevices, ID not matched in database
	const long	BOL_UpdateDevices_SerialNumber_Null				= 0x800461C2;	///< UpdateDevices, SerialNumber field in database is null
	const long	BOL_UpdateDevices_DeviceType_Null				= 0x800461C3;	///< UpdateDevices, DeviceType field in database is null
	const long	BOL_UpdateDevices_ManagerSelfEdit				= 0x800461C4;	///< UpdateDevices, manager cannot edit their own device
	const long	BOL_UpdateDevices_CardXML_NoData				= 0x800461C5;	///< UpdateDevices, no data in the CardXML input
	const long	BOL_UpdateDevices_MinData						= 0x800461C6;	///< UpdateDevices, minimum data not supplied
	const long	BOL_UpdateGroups_NoData							= 0x800461C7;	///< UpdateGroups, no data
	const long	BOL_UpdateGroups_MinData						= 0x800461C8;	///< UpdateGroups, minimum data not supplied
	const long	BOL_UpdatePeopleUserAccounts_NoData					= 0x800461C9;	///< UpdatePeopleUserAccounts, no data
	const long	BOL_UpdatePeopleUserAccounts_NoManagerData			= 0x800461CA;	///< UpdatePeopleUserAccounts, no manager data
	const long	BOL_UpdatePeopleUserAccounts_MinManagerData			= 0x800461CB;	///< UpdatePeopleUserAccounts, minimum manager data not supplied
	const long	BOL_UpdatePeopleUserAccounts_NoManagerMatch			= 0x800461CC;	///< UpdatePeopleUserAccounts, manager data not matched in database
	const long	BOL_UpdatePeopleUserAccounts_MultipleManagerMatch	= 0x800461CD;	///< UpdatePeopleUserAccounts, multiple match in database for manager data
	const long	BOL_UpdatePeopleUserAccounts_UserProfileID_Null		= 0x800461CE;	///< UpdatePeopleUserAccounts, manager UserProfileID field is NULL in database
	const long	BOL_UpdatePeopleUserAccounts_UserAccountID_Null		= 0x800461CF;	///< UpdatePeopleUserAccounts, manager UserAccountID field is NULL in database
	const long	BOL_UpdatePeopleUserAccounts_PersonID_Null			= 0x800461D0;	///< UpdatePeopleUserAccounts, manager PersonID field is NULL in database
	const long	BOL_UpdatePeopleUserAccounts_MinPeopleData			= 0x800461D1;	///< UpdatePeopleUserAccounts, minimum people data not supplied
	const long	BOL_UpdatePeopleUserAccounts_ManagerSelfEdit		= 0x800461D2;	///< UpdatePeopleUserAccounts, manager cannot edit their own details
	const long	BOL_UpdatePeopleUserAccounts_MinUserAccountData		= 0x800461D3;	///< UpdatePeopleUserAccounts, minimum user account data not supplied
	const long	BOL_UpdatePeopleUserAccounts_ManagerUserProfileIDExceeded = 0x800461D4;	///< UpdatePeopleUserAccounts, attempting to set UserProfileID greater than managers
	const long	BOL_UpdatePeopleUserAccounts_SystemAccountID_Null	= 0x800461D5;	///< UpdatePeopleUserAccounts, system account ID field in database is null
	const long	BOL_UpdatePINPolicy_NoData							= 0x800461D6;	///< UpdatePINPolicy, no data
	const long	BOL_UpdatePINPolicy_MinData							= 0x800461D7;	///< UpdatePINPolicy, minimum data not supplied
	const long	BOL_UpdateRadiusClients_NoData						= 0x800461D8;	///< UpdateRadiusClients, no data
	const long	BOL_UpdateRadiusClients_MinData						= 0x800461D9;	///< UpdateRadiusClients, minimum data not supplied
	const long	BOL_UpdateRadiusServers_NoData						= 0x800461DA;	///< UpdateRadiusServers, no data
	const long	BOL_UpdateRadiusServers_MinData						= 0x800461DB;	///< UpdateRadiusServers, minimum data not supplied
	const long	BOL_UpdateRasServers_NoData							= 0x800461DC;	///< UpdateRasServers, no data
	const long	BOL_UpdateRasServers_MinData						= 0x800461DD;	///< UpdateRasServers, minimum data not supplied
	/////////////////bunch of codes added related to change in way reporting is done///////////////////////////////////////////
	const long	BOL_UpdatePeopleUserAccounts_PeopleID_NoMatch		= 0x800461DE;	///< UpdatePeopleUserAccounts, ID not found in People Table
	const long	BOL_UpdatePeopleUserAccounts_PeopleID_MultipleMatch = 0x800461DF;	///< UpdatePeopleUserAccounts, ID multiply found in People Table
	const long	BOL_UpdatePeopleUserAccounts_FullName_Null			= 0x800461E1;	///< UpdatePeopleUserAccounts, FullName field in People Table is Null
	const long	BOL_UpdatePeopleUserAccounts_UserAccountsID_NoMatch = 0x800461E2;	///< UpdatePeopleUserAccounts, ID not found in UserAccounts Table
	const long	BOL_UpdatePeopleUserAccounts_UserAccountsID_MultipleMatch	= 0x800461E3;	///< UpdatePeopleUserAccounts, ID multiply found in UserAccounts Table
	const long	BOL_UpdatePeopleUserAccounts_LogonName_Null			= 0x800461E4;	///< UpdatePeopleUserAccounts, LogonName field in UserAccounts Table is Null
	const long	BOL_DeleteRadiusClients_NoMatch						= 0x800461E5;	///< DeleteRadiusClients, ID not found in RadiusClients table
	const long	BOL_DeleteRadiusClients_MultipleMatch				= 0x800461E6;	///< DeleteRadiusClients, ID multiply matched in RadiusClients table
	const long	BOL_DeleteRadiusClients_Name_Null					= 0x800461E7;	///< DeleteRadiusClients, Name field in Radiusclients table is Null
	const long	BOL_UpdateGroups_NoMatch							= 0x800461E8;	///< UpdateGroups, ID not found in Groups table
	const long	BOL_UpdateGroups_MultipleMatch						= 0x800461E9;	///< UpdateGroups, ID multiply matches in Groups table
	const long	BOL_UpdateGroups_Name_Null							= 0x800461EA;	///< UpdateGroups, Name field in Groups table is Null
	const long	BOL_UpdateDevices_ID_MultipleMatch					= 0x800461EB;	///< Updatedevices, ID multiply found in Devices table
	const long	BOL_DeleteRadiusServers_NoMatch						= 0x800461EC;	///< DeleteRadiusServers, ID not found in RadiusServers table
	const long	BOL_DeleteRadiusServers_MultipleMatch				= 0x800461ED;	///< DeleteRadiusServers, ID multiply found in RadiusServers table
	const long	BOL_UpdateRadiusServers_NoMatch						= 0x800461EE;	///< UpdateRadiusServers, ID not found in RadiusServers table
	const long	BOL_UpdateRadiusServers_MultipleMatch				= 0x800461EF;	///< UpdateRadiusServers, ID multiply found in RadiusServers table
	const long	BOL_UpdateRadiusServers_MachineName_Null			= 0x800461F1;	///< UpdateRadiusServers, MachineName field is Null
	const long	BOL_AddRadiusConnections_RadiusClient_NoMatch		= 0x800461F2;	///< AddRadiusConnections, RadiusClientID not found in RadiusClient table
	const long	BOL_AddRadiusConnections_RadiusClient_MultipleMatch = 0x800461F3;	///< AddRadiusConnections, RadiusClientID multiply found in RadiusClient table
	const long	BOL_AddRadiusConnections_RadiusClient_Name_Null		= 0x800461F4;	///< AddRadiusConnections, Name field in RadiusClients table is Null
	const long	BOL_AddRadiusConnections_RadiusServer_NoMatch		= 0x800461F5;	///< AddRadiusConnections, RadiusServerID not found in RadiusServers table
	const long	BOL_AddRadiusConnections_RadiusServer_MultipleMatch = 0x800461F6;	///< AddRadiusConnections, RadiusServerID multiply found in RadiusServers table
	const long	BOL_AddRadiusConnections_RadiusServer_Name_Null		= 0x800461F7;	///< AddRadiusConnections, MachineName field in RadiusServers table is Null
	const long	BOL_DeleteRadiusConnections_Servers_NoMatch			= 0x800461F8;	///< DeleteRadiusConnections, RadiusServerID not matched in RadiusServers table
	const long	BOL_DeleteRadiusConnections_Servers_MultipleMatch	= 0x800461F9;	///< DeleteRadiusConnections, RadiusServerID multiply found in RadiusServers table
	const long	BOL_DeleteRadiusConnections_ServerName_Null			= 0x800461FA;	///< DeleteRadiusConnections, MachineName in RadiusServers table is Null
	const long	BOL_DeleteRadiusConnections_Clients_NoMatch			= 0x800461FB;	///< DeleteRadiusConnections, RadiusClientID not found in RadiusClients table
	const long	BOL_DeleteRadiusConnections_Clients_MultipleMatch	= 0x800461FC;	///< DeleteRadiusConnections, RadiusClientID multiply found in RadiusClients table
	const long	BOL_DeleteRadiusConnections_ClientName_Null			= 0x800461FD;	///< DeleteRadiusConnections, Name field in RadiusClients table is Null
	const long	BOL_UpdateRadiusClients_NoMatch						= 0x800461FE;	///< UpdateRadiusClients, ID not found in RadiusClients table
	const long	BOL_UpdateRadiusClients_MultipleMatch				= 0x800461FF;	///< UpdateRadiusClients, ID multiply found in RadiusClients table
	const long	BOL_UpdateRadiusClients_Name_Null					= 0x80046200;	///< UpdateRadiusClients, Name field in RadiusClients table is Null
	const long	BOL_UpdateRasServers_NoMatch						= 0x80046201;	///< UpdateRasServers, ID not found in RasServers table
	const long	BOL_UpdateRasServers_MultipleMatch					= 0x80046202;	///< UpdateRasServers, ID multiply found in RasServers table
	const long	BOL_UpdateRasServers_MachineName_Null				= 0x80046203;	///< UpdateRasServers, MachineName field in RasServers table is Null
	const long	BOL_DeleteRasServers_NoMatch						= 0x80046204;	///< DeleteRasServers, ID not found in RasServers table
	const long	BOL_DeleteRasServers_MultipleMatch					= 0x80046205;	///< DeleteRasServers, ID multiply found in RasServers table
	const long	BOL_DeleteRasServers_MachineName_Null				= 0x80046206;	///< DeleteRasServers, MachineName field in RasServers table is Null
	const long	BOL_DeletePeopleUserAccounts_People_NoMatch			= 0x80046207;	///< DeletePeopleUserAccounts, PersonID not found in People table
	const long	BOL_DeletePeopleUserAccounts_People_MultipleMatch	= 0x80046208;	///< DeletePeopleUserAccounts, PersonID multiply found in People table
	const long	BOL_DeletePeopleUserAccounts_FullName_Null			= 0x80046209;	///< DeletePeopleUserAccounts, FullName field in People table is Null
	const long	BOL_DeletePeopleUserAccounts_UserAccounts_NoMatch	= 0x8004620A;	///< DeletePeopleUserAccounts, UserAccountID not found in UserAccounts table
	const long	BOL_DeletePeopleUserAccounts_UserAccounts_MultipleMatch = 0x8004620B;	///< DeletePeopleUserAccounts, UserAccountID multiply found in UserAccounts table
	const long	BOL_DeletePeopleUserAccounts_LogonName_Null			= 0x8004620C;	///< DeletePeopleUserAccounts, LogonName field in UserAccounts table if Null
	const long	BOL_DeleteGroups_NoMatch							= 0x8004620D;	///< DeleteGroups, ID not found in Groups table
	const long	BOL_DeleteGroups_MultipleMatch						= 0x8004620E;	///< DeleteGroups, ID multiply found in Groups table
	const long	BOL_DeleteGroups_Name_Null							= 0x8004620F;	///< DeleteGroups, Name field in Groups table is Null
		
/////////////////////////////
	const long	BOL_UpdateDevices_ManagerNoMatch				= 0x80046210;	///< UpdateDevices, Manager information not found in Devices table
	const long	BOL_UpdateDevices_ManagerMultipleMatch			= 0x80046211;	///< UpdateDevices, Manager information multiply found in Devices table
	const long	BOL_UpdateDevices_UserProfileID_Null			= 0x80046212;	///< UpdateDevices, UserProfileID field in UserAccounts table is Null
	const long	BOL_UpdateDevices_DeviceNoMatch					= 0x80046213;	///< UpdateDevices, Device details not found in Database
	const long	BOL_UpdateDevices_DeviceMultipleMatch			= 0x80046214;	///< UpdateDevices, Device details multiply found in Database
	const long	BOL_UpdateDevices_UserProfileExceeded			= 0x80046215;	///< UpdateDevices, Managers authority exceeded
	const long	BOL_DeletePeopleUserAccounts_UserProfileID_Null = 0x80046216;	///< DeletePeopleUserAccounts, UserProfileID field in Database is Null
	const long	BOL_DeletePeopleUserAccounts_UserProfileExceeded= 0x80046217;	///< DeletePeopleUserAccounts, Managers UserProfileID exceeded
	const long	BOL_GetPUC_ManagerNoMatch						= 0x80046218;	///< GetPUC, Managers details not found in Database
	const long	BOL_GetPUC_ManagerMultipleMatch					= 0x80046219;	///< GetPUC, Managers details multiply found in Database
	const long	BOL_GetPUC_UserProfileID_Null					= 0x8004621A;	///< GetPUC, UserProfileID field in Database is Null
	const long	BOL_GetPUC_LockedDevNoMatch						= 0x8004621B;	///< GetPUC, Locked device details not found in Database
	const long	BOL_GetPUC_LockedDevMultipleMatch				= 0x8004621C;	///< GetPUC, Locked device details multiply found in Database
	const long	BOL_GetPUC_UserProfileExceeded					= 0x8004621D;	///< GetPUC, Managers authority exceeded
	const long	BOL_GetPUCToken_ManagerNoMatch					= 0x8004621E;	///< GetPUCToken, Managers details not found in Database
	const long	BOL_GetPUCToken_ManagerMultipleMatch			= 0x8004621F;	///< GetPUCToken, Managers details multiply found in Database
	const long	BOL_GetPUCToken_UserProfileID_Null				= 0x80046220;	///< GetPUCToken, UserProfileID field in Database is Null
	const long	BOL_GetPUCToken_LockedDevNoMatch				= 0x80046221;	///< GetPUCToken, Locked device details not found in Database
	const long	BOL_GetPUCToken_LockedDevMultipleMatch			= 0x80046222;	///< GetPUCToken, Locked device details multiply found in database
	const long	BOL_GetPUCToken_UserProfileExceeded				= 0x80046223;	///< GetPUCToken, Managers authority exceeded

	const long	BOL_AddCardProfile_NoData						= 0x80046224;	///< AddCardProfile, Locked device details multiply found in database
	const long	BOL_AddCardProfile_MinData						= 0x80046225;	///< AddCardProfile, Managers authority exceeded
	const long	BOL_UpdateCardProfile_NoData					= 0x80046226;	///< UpdateCardProfile, Locked device details multiply found in database
	const long	BOL_UpdateCardProfile_MinData					= 0x80046227;	///< UpdateCardProfile, Managers authority exceeded
	const long	BOL_RemoveCardProfile_NoData					= 0x80046228;	///< RemoveCardProfile, Locked device details multiply found in database
	const long	BOL_RemoveCardProfile_MinData					= 0x80046229;	///< RemoveCardProfile, Managers authority exceeded
	const long	BOL_GetCardProfile_NoData						= 0x8004622A;	///< GetCardProfile, Locked device details multiply found in database
	const long	BOL_AddJob_NoData								= 0x8004622B;	///< AddJob, Managers authority exceeded
	const long	BOL_AddJob_MinData								= 0x8004622C;	///< AddJob, Locked device details multiply found in database
	const long	BOL_UpdateJob_NoData							= 0x8004622D;	///< UpdateJob, Managers authority exceeded
	const long	BOL_UpdateJob_MinData							= 0x8004622E;	///< UpdateJob, Locked device details multiply found in database
	const long	BOL_FinishJob_NoData							= 0x8004622F;	///< FinishJob, Managers authority exceeded
	const long	BOL_FinishJob_MinData							= 0x80046230;	///< FinishJob, Managers authority exceeded

	const long	BOL_AddJob_NoTaskID								= 0x80046231;	///< AddJob, NoTaskID
	const long	BOL_AddJob_UnknownInitiator						= 0x80046232;	///< AddJob, UnknownInitiator
	const long	BOL_UpdateJob_UnknownValidator					= 0x80046233;	///< UpdateJob, UnknownValidator
	const long	BOL_UpdateJob_UnknownActioner					= 0x80046234;	///< UpdateJob, UnknownActioner

	const long	BOL_GetActivCardProfileNames_NoData				= 0x80046235;	///< GetActivCardProfileNames, No data
	const long	BOL_GetActivCardProfileDeltasByID_NoData		= 0x80046236;	///< GetActivCardProfileDeltasByID, No data
	const long	BOL_GetActivCardProfileDeltasByID_NoProfileID	= 0x80046237;	///< GetActivCardProfileDeltasByID, No profile ID
	const long	BOL_GetActivCardServiceProfileNames_NoData		= 0x80046238;	///< GetActivCardServiceProfileNames, No data
	const long	BOL_GetIssueTags_NoData							= 0x80046239;	///< GetIssueTags, No data
	const long	BOL_ExportDevices_NoSDSData						= 0x8004623A;	///< ExportDevices, no data for SDS XML
	const long	BOL_ExportDevices_NoDeviceData					= 0x8004623B;	///< ExportDevices, no data for Devices XML
	const long	BOL_ExportDevices_MinData						= 0x8004623C;	///< ExportDevices, minimum data not supplied
	const long	BOL_ExportDevices_SigningDevice_NoMatch			= 0x8004623D;	///< ExportDevices, signing device details not matched in DB
	const long	BOL_ExportDevices_SigningDevice_MultipleMatch	= 0x8004623E;	///< ExportDevices, signing device details multiply matched in DB
	const long	BOL_ExportDevices_SigningDevice_EncryptKey_Null	= 0x8004623F;	///< ExportDevices, signing device encrypt key is null

	const long	BOL_SetACDeviceProfile_NoData					= 0x80046240;	///< SetACDeviceProfile, No data
	const long	BOL_SetACDeviceProfile_CompileDeltaEmpty		= 0x80046241;	///< SetACDeviceProfile, Compile Delta Empty
	const long	BOL_SetACDeviceProfile_ActivCardProfileEmpty	= 0x80046242;	///< SetACDeviceProfile, ActivCard Profile Empty
	const long	BOL_SetACDeviceProfile_MinServiceDataNotSupplied= 0x80046243;	///< SetACDeviceProfile, Insufficient service data supplied
	const long	BOL_SetACDeviceProfile_MinDataForNewNotSupplied = 0x80046244;	///< SetACDeviceProfile, Minimum data for adding a new device profile not supplied
	const long	BOL_SetACDeviceProfile_MinDataForNewNotSupplied_ServicesNodeEmpty	= 0x80046245;	///< SetACDeviceProfile, Minimum data for adding a new device profile not supplied, no service node was found
	const long	BOL_SetACDeviceProfile_ExtDataForEditProfileSupplied_ServicesNode	= 0x80046246;	///< SetACDeviceProfile, Service nodes specified when they are not required
	const long	BOL_SetACDeviceProfile_MinDataForEditServiceNotSupplied_ServicesNodeEmpty = 0x80046247;	///< SetACDeviceProfile, Service nodes not specified for edit service
	const long	BOL_SetACDeviceProfile_MinDataForEdit_ActivCardProfileIDNotFound	= 0x80046248;	///< SetACDeviceProfile, ActivCardProfile ID must be specified for an edit
	const long	BOL_SetACDeviceProfile_MinDataForEdit_ActivCardProfileIDInvalid		= 0x80046249;	///< SetACDeviceProfile, ActivCardProfile ID specified is not recognised
	const long	BOL_SetACDeviceProfile_ParametersEmpty			= 0x8004624A;	///< SetACDeviceProfile, Parameters node empty
	const long	BOL_SetACDeviceProfile_UnableToCompileDeltas	= 0x8004624B;	///< SetACDeviceProfile, Unable to Compile Deltas
	const long	BOL_SetACDeviceProfile_UnableToCompileDeltas_CompilerNotInstalled	= 0x8004624C;	///< SetACDeviceProfile, Unable to Compile Deltas no compiler has been installed

	const long	BOL_DeleteACDeviceProfile_NoData				= 0x8004624D;	///< DeleteACDeviceProfile, No data
	const long	BOL_DeleteACDeviceProfile_ParametersEmpty		= 0x8004624E;	///< DeleteACDeviceProfile, Parameters node empty
	const long	BOL_DeleteACDeviceProfile_ActivCardProfileEmpty	= 0x8004624F;	///< DeleteACDeviceProfile, ActivCard Profile Empty
	const long	BOL_DeleteACDeviceProfile_MinData_ActivCardProfileIDNotFound = 0x80046250;	///< DeleteACDeviceProfile, ActivCard Profile ID Not Found
	
	const long	BOL_UpdateUserProfileReport_NoData				= 0x80046251;	///< UpdateUserProfileReport, No data
	const long	BOL_UpdateUserProfileReport_MinData				= 0x80046252;	///< UpdateUserProfileReport, MinData
	const long	BOL_UpdateUserProfileReport_NoTransferTo		= 0x80046253;	///< UpdateUserProfileReport, Delete requested with no TranferTo ID given

	const long  BOL_ResyncActivCardDevice_DesKeyType_Null			= 0x80046254;	
	const long  BOL_ResyncActivCardDevice_SlotKeyDerive_Null		= 0x80046255; 
	const long  BOL_ResyncActivCardDevice_SlotCounterIncrement_Null = 0x80046256; 

	const long  BOL_GetSecurityQuestions_SpecifiedUserDoesNotExist	= 0x80046257;	///< GetSecurityQuestions, User Not Found
	const long  BOL_GetSecurityQuestions_PersonID_Null				= 0x80046258;	///< GetSecurityQuestions, PersonID field is NULL

	const long  BOL_UpdateSecurityQuestions_NoData					= 0x80046259;	///< UpdateSecurityQuestions, No data
	const long  BOL_UpdateSecurityQuestions_MinData					= 0x8004625A;	///< UpdateSecurityQuestions, Minimum data not supplied
	const long  BOL_UpdateSecurityQuestions_SpecifiedUserDoesNotExist= 0x8004625B;	///< UpdateSecurityQuestions, User Not Found

	const long  BOL_Logon_UserAccountID_Null					= 0x8004625C;	///< Logon UserAccountID is NULL
	const long  BOL_ActivateUserAccount_NoData					= 0x8004625D;	///< ActivateUserAccount, no data supplied
	const long  BOL_ActivateUserAccount_MinData					= 0x8004625E;	///< ActivateUserAccount, minimum data not supplied
	const long  BOL_ActivateUserAccount_UserNotFound			= 0x8004625F;	///< ActivateUserAccount, User Not Found
	const long  BOL_ActivateUserAccount_ActivationCodeIncorrect	= 0x80046260;	///< ActivateUserAccount, Activation Code Incorrect
	const long  BOL_ActivateUserAccount_SecurityPhrase_Null		= 0x80046261;	///< ActivateUserAccount, Security Phrase field is NULL
	const long  BOL_UpdateSecurityQuestions_ActivationCodeSpecified = 0x80046262;	///< UpdateSecurityQuestions, Activation Code cannot be chosen as a security question
	const long  BOL_DeviceAbsence_NoData						= 0x80046263;	///< GetReasonForCardAbsence, no data
	const long  BOL_EmergencyPwdNoData							= 0x80046264;	///< EmrgencyPwd, no data
	const long  BOL_EmergencyPwdMinData							= 0x80046265;	///< EmrgencyPwd, min data not supplied
	const long  BOL_EmergencyPwdInvalidUser						= 0x80046266;	///< EmrgencyPwd, invalid user
	const long	BOL_EmergencyPwdNotSet							= 0x80046267;	///< Emergency password not set
	const long	BOL_ActivPackNoSDBForDevice						= 0x80046268;	///< ActivPack export, no SDB exists for this device
	const long	BOL_ActivPackUpdateError						= 0x80046269;	///< ActivPack Update Error.
	const long	BOL_ActivPack_CantCreate						= 0x8004626A;	///< Unable to Instantiate ActivPack COM. 
	const long	BOL_ActivPack_NoCredentials						= 0x8004626B;	///< Unable to determine logon credentials for ActivPack. 
	const long	BOL_ActivPack_Logon_Error						= 0x8004626C;	///< Error logging on to ActivPack
	const long	BOL_ActivPack_CantFindSystemAccountName			= 0x8004626D;	///< Unable to determine System Account Name for owner of this Device
	const long	BOL_ActivPack_Resync_Fail						= 0x8004626E;	///< Unable to Resynchronise device for ActivPack
	const long	BOL_AddCA_NoData								= 0x8004626F;	///< AddCA, no data supplied
	const long	BOL_AddCA_MinData								= 0x80046270;	///< AddCA, minimum data not supplied
	const long	BOL_AddCA_InvalidName							= 0x80046271;	///< AddCA, name is invalid or not unique
	const long	BOL_AddCA_InvalidFriendlyName					= 0x80046272;	///< AddCA, Friendly name is invalid or not unique
	const long	BOL_ActivPackSetEmergencyPassword				= 0x80046273;	///< ActivPack error setting emergency password.

	const long	BOL_UpdateConfiguration_MinData					= 0x80046274;	///< UpdateConfiguration, minimum data not supplied
	const long	BOL_UpdateConfiguration_NoData					= 0x80046275;	///< UpdateConfiguration, No data supplied.
	const long	BOL_GetPUCToken_DeviceUnSupported				= 0x80046276;	///< GetPUCToken, Device type specified is unsupported for unlock
	const long	BOL_DeviceCouldNotBeFound						= 0x80046277;	///< Device specified does not exist
	const long	BOL_UnableToRetrieveUnlockCode					= 0x80046278;	///< Unable to retrieve corresponding unlock code for this challenge

	const long	BOL_GetCardLayout_NoData						= 0x80046279;	///< GetCadLayout, No data supplied
	const long	BOL_UpdateCardLayout_NoData						= 0x8004627A;	///< UpdateCardLayout, No data supplied
	const long	BOL_UpdateCardLayout_MinData					= 0x8004627B;	///< UpdateCardLayout, minimum data not supplied
	const long	BOL_RemoveCardLayout_NoData						= 0x8004627C;	///< RemoveCardLayout, No data supplied
	const long	BOL_RemoveCardLayout_MinData					= 0x8004627D;	///< RemoveCardLayout, minimum data not supplied
	const long	BOL_RemoveCardLayout_CardLayoutNotFound			= 0x8004627E;	///< RemoveCardLayout, specified card layout does not exist
	const long	BOL_RemoveCardLayout_Name_Null					= 0x8004627F;	///< RemoveCardLayout, CardLayout Name is null

	const long	BOL_CheckSecurityPhrases_NoData					= 0x80046280;	///< CheckSecurityPhrases, No data supplied
	const long	BOL_CheckSecurityPhrases_MinData				= 0x80046281;	///< CheckSecurityPhrases, minimum data not supplied
	const long	BOL_CheckSecurityPhrases_AccessDenied			= 0x80046282;	///< CheckSecurityPhrases, Access Denied

	const long	BOL_EntrustCredentials							= 0x80046283;	///< Entrust credentials not available

	const long BOL_SetEntrustProfileTemplate_InvalidProfile		= 0x80046284;	///< SetEntrustProfileTemplate, invalid profile template

	const long BOL_AddPersonUserAccount_InvalidProfile			= 0x80046285;	///< AddPersonUserAccount, invalid Entrust profile template
	
	const long BOL_UpdatePeopleUserAccounts_MinBiometricData	= 0x80046286;	///< UpdatePeopleUserAccounts, minimum BiometricData not supplied

	const long BOL_UpdateDevices_UserNotRSAEnabled				= 0x80046287;	///< UpdateDevices, attempted to issue an RSA device to a user who is not RSA enabled
	const long MISC_No_Client_Prefix							= 0x80046288;	///< Client prefix config setting is needed and not present
	const long BOL_ACE_Failed									= 0x80046289;	///< An error was returned from the RSA ACE Database
	const long BOL_ResyncDevice_NoMatch							= 0x8004628A;	///< ResyncDevice, device not found
	const long BOL_GetTokenInfo_NoMatch							= 0x8004628B;	///< GetTokenInfo, device not found

	const long BOL_GetTaskNumber_InvalidLogonBlock				= 0x8004628C;	///< GetTaskNumber, invalid logon block
	
	const long BOL_OperationIDNotFound							= 0x8004628D;	///< OperationID not found
	const long BOL_CompleteTask_InvalidStatus					= 0x8004628E;	///< CompleteTask, Invalid Status

	const long BOL_Licence_Invalid								= 0x8004628F;	///< Licence information is invalid. Please contact your vendor.
	const long BOL_AddPersonUserAccount_LicenceLimit			= 0x80046290;	///< AddPersonUserAccount, licence limit reached.

	const long BOL_ACE_Resync_Failed							= 0x80046291;	///< Failed to resynchronise RSA SecurID token

	const long BOL_SetPassword_InvalidPasswordType				= 0x80046292;	///< SetPassword - invalid password type
	const long BOL_SetPassword_UnableToGenerateNTSEPassword		= 0x80046293;	///< SetPassword - unable to generate NTSE password
	const long BOL_SetPassword_NoFindCredentials				= 0x80046294;	///< SetPassword - required credentials are not known for this user

	const long BOL_RecoverKey_LogonTypeNotAllowed				= 0x80046295;	///< RecoverKey - Logon type invalid. Key recovery only allowed with device logon
	const long BOL_RecoverKey_NoPermissionToRecoverOwnKey		= 0x80046296;	///< RecoverKey - This user does not have permission to recover their own keys
	const long BOL_RecoverKey_NoPermissionToRecoverOthersKey	= 0x80046297;	///< RecoverKey - This validating user does not have permission to recover the other users key
	const long BOL_RecoverKey_SpecifiedKeyNotFound				= 0x80046298;	///< RecoverKey - The specified key to recover could not be found
	const long BOL_RecoverKey_TargetDeviceInvalid				= 0x80046299;	///< RecoverKey - The device specified to recover the key to is invalid
	const long BOL_RecoverKey_ErrorRetrievingArchivedKey		= 0x8004629A;	///< RecoverKey - Error retrieving archived key
	const long BOL_RecoverKey_ContainerNameMissing				= 0x8004629B;	///< RecoverKey - The container name for the key to recover is unknown
	const long BOL_RecoverKey_KeyDataInvalid					= 0x8004629C;	///< RecoverKey - The key data is invalid or corrupt
	const long BOL_RecoverKey_KRAPrivateKeyNotAvailable			= 0x8004629D;	///< RecoverKey - Unable to decrypt users private key - the KRA private key may not be available

	const long BOL_GetDeviceDetails_NoData						= 0x8004629E;	///< GetDeviceDetails, no data
	const long BOL_GetDeviceDetails_MinData						= 0x8004629F;	///< GetDeviceDetails, Min data
	const long BOL_ListUserBiometricSamples_NoData				= 0x800462A0;	///< ListUserBiometricSamples, no data
	const long BOL_Logon_FailedPriorToBOLCall					= 0x800462A1;	///< LogonEx, asked to audit a failed logon attempt

	const long BOL_UpdateEmailTemplates_NoID					= 0x800462B0;	///< Unable to obtain new ID for email template
	const long BOL_OTP_Resync_Failed							= 0x800462B1;	///< Failed to resynchronise OTP device.
	const long BOL_UpdateDevices_UserNotAuthEnabled				= 0x800462B2;	///< UpdateDevices, attempted to issue an RSA device to a user who is not enabled for authentication
	const long BOL_ProcessOTP_NoFreeOTPdeviceFound				= 0x800462B3;	///< ProcessOTP, No Free OTP device found (table empty or all OTPs assigned)
	const long BOL_InitAdminSession_NotConfigured				= 0x800462B4;	///< Your system is not configured to use authentication servers

	const long BOL_CheckCardForIssuance_OTP_NotSupported		= 0x800462B5;	///< One Time Password is not supported for this device
	const long BOL_CheckCardForIssuance_Device_NotLicensed		= 0x800462B6;	///< Device is not Licensed
	const long BOL_CheckCardForIssuance_OTP_NotLicensed			= 0x800462B7;	///< One Time Password is not licensed for this device
	const long BOL_CheckCardForIssuance_OTP_MAXTokensExceeded	= 0x800462B8;	///< Max number of otp tokens exceeded
	const long BOL_CheckCardForIssuance_OTP_NOTokensAvailable	= 0x800462B9;	///< There are no Software tokens available for issue
	const long BOL_CheckCardForIssuance_OTP_TokensAlreadyAssigned = 0x800462BA;	///< Token is already assigned to a user
	const long BOL_CheckCardForIssuance_SOFTOTP_NotSupported	= 0x800462BB;	///< Software One Time Password is not supported for this device
	const long BOL_CheckCardForIssuance_HARDOTP_NotSupported	= 0x800462BC;	///< Hardware One Time Password is not supported for this device
	const long BOL_CheckCardForIssuance_ChangeSoftIDCount		= 0x800462BD;	///< Changing the number of softis's is not allowed
	const long BOL_CheckCardForIssuance_ChangeSoftIDOrder		= 0x800462BE;	///< Changing the order of softis's is not allowed
	const long BOL_CheckCardForIssuance_ChangeSoftIDDescription	= 0x800462BF;	///< Changing the description of softis's is not allowed
	const long BOL_CheckCardForIssuance_ChangeSoftIDPinType		= 0x800462C0;	///< Changing the pin type of softid's is not allowed
	const long BOL_CheckCardForIssuance_ChangeHardIDPinType		= 0x800462C1;	///< Changing the pin type of hardware otp is not allowed
	const long BOL_CheckCardForIssuance_OTP_TokenNotExist		= 0x800462C2;	///< This token does not exist within the authentication servers database
	const long BOL_CheckCardForIssuance_PINTypeNotSupported		= 0x800462C3;	///< This token does not support the required PIN Type
	const long BOL_AdjudicationNotLicenced 						= 0x800462C4;	///< The requested adjudication service is not licenced on this system
	const long BOL_Logon_FailTimeBasedLicenceCheck				= 0x800462C5;	///< Logon Failed - Time based licence has expired or a critical system error has occurred
	const long BOL_AuthTypeReferenced							= 0x800462C6;	///< Auth Type cannot be deleted as referenced by other table
	const long BOL_AddPersonRoleSetViolation					= 0x800462C7;	///< Roleset violation when adding a person
	const long BOL_UpdatePersonRoleSetViolation					= 0x800462C8;	///< Roleset violation when updating a person
	const long BOL_UpdateDevices_DeviceUserKindMismatch			= 0x800462C9;	///< UpdateDevices, Device cannot be assigned to this kind of user
	const long BOL_GetIssuanceCardContent_CardProfileDeviceMismatch	= 0x800462CA;	///< Card profile is incompatible for the device
	const long BOL_AddJob_CardProfileDeviceMismatch				= 0x800462CB;	///< Card profile is incompatible for the device
	const long BOL_CheckCardForIssuance_DeviceDisposed			= 0x800462CC;	///< Card has been disposed

	const long BOL_UpdateUserFromUserAccountID_Empty_Email_And_DN = 0x800462CD;	    ///< User update request contained empty Email and DN update data in supplied ID node
	const long BOL_UpdateUserFromUserAccountID_Invalid_User_Data_Found = 0x800462CE;	///< Empty DN, SystemAccountID or PersonID record found using supplied ID node
	const long BOL_UpdateUserFromUserAccountID_No_Unique_DN_Found = 0x800462CF;	    ///< Unique DN could not be found using supplied ID node
	const long BOL_UpdateUserFromUserAccountID_Empty_UserAccountID = 0x800462D0;	///< Empty UserAccountID supplied in ID node
	const long BOL_UpdateUserFromUserAccountID_Invalid_DN_Supplied = 0x800462D1;	///< Invalid_New DN Supplied Empty DN or CN extracted

	const long BOL_Logon_AssistedActivationRequired			= 0x800462D2;	///< Logon, Self activation attempt for card requiring assisted activation

	const long BOL_EnrollIdentityAgent_None_Unique_JobID_Supplied = 0x800462D3;				///< EnrollIdentityAgent, <JobID> supplied did not reference a unique record in jobs table
	const long BOL_EnrollIdentityAgent_None_Unique_LogonName = 0x800462D4;					///< EnrollIdentityAgent, LogonName extracted from <jobID> does not refrerence a unique record
	const long BOL_EnrollIdentityAgent_None_Unique_CardProfileID = 0x800462D5;				///< EnrollIdentityAgent, CardProfilesmID extracted from <jobID> does not refrerence a unique record
	const long BOL_EnrollIdentityAgent_No_Keystores_Supplied = 0x800462D6;					///< EnrollIdentityAgent, No Keystores data supplied in XML input
	const long BOL_EnrollIdentityAgent_Specific_Keystores_Incorrectly_Defined = 0x800462D7;	///< EnrollIdentityAgent, Either logonDevice or default keystore not uniquely defined
	const long BOL_EnrollIdentityAgent_Multiple_Carrier_References = 0x800462D8;			///< EnrollIdentityAgent, Multiple references to carrier identified from XML input
	const long BOL_EnrollIdentityAgent_Invalid_Carrier_DeviceTypename = 0x800462D9;			///< EnrollIdentityAgent, Invalid DeviceTypeName specified for carrier
	const long BOL_EnrollIdentityAgent_Invalid_Device_DeviceTypename = 0x800462DA;			///< EnrollIdentityAgent, Invalid DeviceTypeName specified for device
	const long BOL_EnrollIdentityAgent_Multiple_Device_References = 0x800462DB;				///< EnrollIdentityAgent, Multiple references to device identified from XML input
	const long BOL_EnrollIdentityAgent_Device_Already_Assigned = 0x800462DC;				///< EnrollIdentityAgent, Device already assigned to UserAccountID != 0
	const long BOL_EnrollIdentityAgent_Device_Not_Assigned_To_User = 0x800462DD;			///< EnrollIdentityAgent, Device not assigned to the user collecting the job
	const long BOL_EnrollIdentityAgent_No_Valid_Keystores_Supplied = 0x800462DE;			///< EnrollIdentityAgent, No valid Keystores data supplied in XML input
	const long BOL_RenewCertificate_CertNotOnDevice	= 0x800462DF;							///< RenewCertificate, Certificate is not on the device
	const long BOL_GetMultipleObjectData_TooManyResults = 0x800462E0;						///< GetMultipleObjectData, too many results
	const long BOL_ServerDocuments_MailerName_Not_Found = 0x800462E1;						///< ServerDocuments, mailer name document not found

	
	///////////////////////////////////////////////////////////// LAST CODE			// Create a new block /////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////// see 0x80046800    ///////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// IEdeficeAuth interface error codes
	// Range 0x80046300 to 0x800463ff
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const long	AUTH_ChangeNTPassword_NoData					= 0x80046300;	///< Empty input string for function ChangeNTPassword
	const long	AUTH_Decrypt_NoData								= 0x80046301;	///< Empty input string for function decrypt
	const long	AUTH_Encrypt_NoData								= 0x80046302;	///< Empty input string for function encrypt
	const long	AUTH_GetActivCardData_SNEmpty					= 0x80046303;	///< Empty input string for GetActivCardData
	const long	AUTH_GetActivCardSlotData_SNEmpty				= 0x80046304;	///< Empty input string for GetActivCardSlotData
	const long	AUTH_GetCardInfoByLogonName_LogonEmpty			= 0x80046305;	///< Empty input string for GetinfoByLogonname
	const long	AUTH_GetCardInfoBySerialNumber_SNEmpty			= 0x80046306;	///< Empty input string for GetCardInfoBySerialNumber
	const long	AUTH_GetLicense_DatabaseVersionEmpty			= 0x80046307;
	const long	AUTH_GetLicense_LicenceNULL						= 0x80046308;
	const long	AUTH_GetRadiusClients_MachineNameEmpty			= 0x80046309;	///< Empty machine name string for GetRadiusClients
	const long	AUTH_GetRadiusClients_ClientIPEmpty				= 0x8004630A;	///< Empty clientip string for GetRadiusClients
	const long	AUTH_GetRadiusServersByMachineRegName_MachineNameEmpty	= 0x8004630B;	///< Empty machine name for GetRadiusServersByMachineRegName
	const long	AUTH_GetRasServersByMachineRegName_MachineRegNameEmpty	= 0x8004630C;	///< empty machine reg name for GetrasServersByMachineRegName
	const long	AUTH_GetStaticPasswordByDeviceID_UserAccIDNull			= 0x8004630D;
	const long	AUTH_GetStaticPasswordByLogonName_LogonNameEmpty		= 0x8004630E;	///< empty logonname for GetStaticPasswordByLogonName
	const long	AUTH_LANValidate_NoData							= 0x8004630F;	///< empty input for LanValidate
	const long	AUTH_PutLicense_NoData							= 0x80046310;	///< no data for PutLicense
	const long	AUTH_UpdateActivCardData_SNEmpty				= 0x80046311;	///< empty input string for UpdateActivCardData
	const long	AUTH_UpdateActivCardData_NoMatch				= 0x80046312;	///< no match in UpdateActivCardData
	const long	AUTH_UpdateActivCardData_MultipleMatch			= 0x80046313;	///< multiple match in UpdateActivCardData
	const long	AUTH_UpdateActivCardData_IDNull					= 0x80046314;	///< ID field in Devices table is NULL
	const long	AUTH_UpdateSlotData_SNEmpty						= 0x80046315;	///< SN input string in UpdateSlotData is empty
	const long	AUTH_UpdateSlotData_ASyncKeyEmpty				= 0x80046316;	///< ASyncKey string in UpdateSlotData is empty
	const long	AUTH_UpdateSlotData_ACounterEmpty				= 0x80046317;	///< ACounter string in UpdateSlotData is empty
	const long	AUTH_UpdateSlotData_NoMatch						= 0x80046318;	///< no match in updateslotdata
	const long	AUTH_UpdateSlotData_MultipleMatch				= 0x80046319;	///< multiple match in updateslotdata
	const long	AUTH_UpdateSlotData_IDNull						= 0x8004631A;	///< updateslotdata, device Id is null
	const long	AUTH_ChangeNTPassword_MinData					= 0x8004631B;	///< ChangeNTPassword, minimum data not supplied
	const long	AUTH_ChangeNTPassword_NoMatch					= 0x8004631C;	///< ChangeNTPassword, device details not matched in DB
	const long	AUTH_ChangeNTPassword_MultipleMatch				= 0x8004631D;	///< ChangeNTPassword, device details multiply matched in DB
	const long	AUTH_ChangeNTPassword_EncryptKey_Null			= 0x8004631E;	///< ChangeNTPassword, encrypt key field in DB is Null
	const long	AUTH_ChangeNTPassword_InvalidMessageNumber		= 0x8004631F;	///< ChangeNTPassword, invalid message number
	const long	AUTH_GetStaticPasswordByDeviceID_NoMatch		= 0x80046320;	///< GetStaticPasswordByDeviceID, device details not matched in DB
	const long	AUTH_GetStaticPasswordByDeviceID_MultipleMatch	= 0x80046321;	///< GetStaticPasswordByDeviceID, device details multiply matched in DB
	const long	AUTH_LANValidate_MinData						= 0x80046322;	///< LANValidate, minimum data not supplied
	const long	AUTH_LANValidate_NoMatch						= 0x80046323;	///< LANValidate, device details not matched in DB
	const long	AUTH_LANValidate_MultipleMatch					= 0x80046324;	///< LANValidate, device details multiply matched in DB
	const long	AUTH_LANValidate_EncryptKey_Null				= 0x80046325;	///< LANValidate, EncryptKey field in database is Null
	const long	AUTH_LANValidate_InvalidMessageNumber			= 0x80046326;	///< LANValidate, InvalidMessageNumber

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// IEdeficeCert interface error codes
	// Range 0x80046400 to 0x800464ff
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const long	CERT_CheckIfCertIssued_NoData					= 0x80046400;	///< no data for CheckIfCertIssued
	const long	CERT_CheckIfCertIssued_MinData					= 0x80046401;	///< minimum data for CheckIfCertIssued not supplied
	const long	CERT_CheckIfCertIssued_MultipleMatch			= 0x80046402;	///< multiple match for CheckIfCertIssued
	const long	CERT_GetPendingCertRequestID_NoData				= 0x80046403;	///< no data for GetPendingCertRequestID
	const long	CERT_GetPendingCertRequestID_MinData			= 0x80046404;	///< minimum data for GetPendingCertRequestID not supplied
	const long	CERT_GetPendingCertRequestID_NoMatch			= 0x80046405;	///< no match for GetPendingCertRequestID
	const long	CERT_GetPendingCertRequestID_MultipleMatch		= 0x80046406;	///< multiple match data for GetPendingCertRequestID
	const long	CERT_ProcessFailedCertPending_NoData			= 0x80046407;	///< no data for ProcessFailedCertPending
	const long	CERT_ProcessFailedCertPending_MinData			= 0x80046408;	///< minimum data for ProcessFailedCertPending not supplied
	const long	CERT_ProcessIssuedCertPending_NoData			= 0x80046409;	///< no data for ProcessIssuedCertPending
	const long	CERT_ProcessIssuedCertPending_MinData			= 0x8004640A;	///< minimum data for ProcessIssuedCertPending not supplied
	const long	CERT_RetrieveAllCertsByStatus_NoData			= 0x8004640B;	///< no data for RetrieveAllCertsByStatus
	const long	CERT_RetrieveAllCertsByStatus_MinData			= 0x8004640C;	///< minimum data for RetrieveAllCertsByStatus not supplied
	const long	CERT_RetrieveAllCertsByUser_NoData				= 0x8004640D;	///< no data for RetrieveAllCertsByUser 
	const long	CERT_RetrieveAllCertsByUser_MinData				= 0x8004640E;	///< minimum data for RetrieveAllCertsByUser not supplied
	const long	CERT_RetrieveCertBySerialNo_NoData				= 0x8004640F;	///< no data for RetrieveCertBySerialNo
	const long	CERT_RetrieveCertBySerialNo_MinData				= 0x80046410;	///< minimum data for RetrieveCertBySerialno not supplied
	const long	CERT_RetrieveCertsByDeviceSerialNo_NoData		= 0x80046411;	///< no data for RetrieveCertsByDeviceSerialNo
	const long	CERT_RetrieveCertsByDeviceSerialNo_MinData		= 0x80046412;	///< minimum data for RetrieveCertsByDeviceSerialNo not supplied
	const long	CERT_RetrieveCertPoliciesInfo_NoData			= 0x80046413;	///< no data for RetrieveCertPoliciesInfo
	const long	CERT_RetrieveCertPoliciesInfo_MinData			= 0x80046414;	///< minimum data for RetrieveCertPoliciesInfo not supplied
	const long	CERT_RetrieveCertPoliciesInfo_NoMatch			= 0x80046415;	///< no match for RetrieveCertPoliciesInfo
	const long	CERT_RetrievePendingCertificate_NoData			= 0x80046416;	///< no data for RetrievePendingCertificate
	const long	CERT_RetrievePendingCertificate_MinData			= 0x80046417;	///< minimum data for RetrievePendingCertificate not supplied
	const long	CERT_RetrievePendingCertificate_NoMatch			= 0x80046418;	///< no match for RetrievePendingCertificate
	const long	CERT_RetrievePendingCertificate_MultipleMatch	= 0x80046419;	///< multiple match for RetrievePendingCertificate
	const long	CERT_SetIssuedCertADSSync_NoData				= 0x8004641A;	///< no data for SetIssuedCertADSSync
	const long	CERT_SetIssuedCertADSSync_MinData				= 0x8004641B;	///< minimum data for SetIssuedCertADSSync not supplied
	const long	CERT_UpdateCertIssuedToRevocationPending_NoData	= 0x8004641C;	///< no data for UpdateCertIssuedToRevocationPending
	const long	CERT_UpdateCertIssuedToRevocationPending_MinData= 0x8004641D;	///< minimum data for UpdateCertIssuedToRevocationPending not supplied
	const long	CERT_UpdateCertIssuedToRevoked_NoData			= 0x8004641E;	///< no data for UpdateCertIssuedToRevoked
	const long	CERT_UpdateCertIssuedToRevoked_MinData			= 0x8004641F;	///< minimum data for UpdateCertIssuedToRevoked not supplied
	const long	CERT_UpdatePendingCert_NoData					= 0x80046420;	///< no data for UpdatePendingCert
	const long	CERT_UpdatePendingCert_MinData					= 0x80046421;	///< minimum data for UpdatePendingCert not supplied
	const long	CERT_UpdatePKIConfig_NoData						= 0x80046422;	///< no data for UpdatePKIConfig
	const long	CERT_UpdatePKIConfig_MinData					= 0x80046423;	///< minimum data for UpdatePKIConfig not supplied
	const long	CERT_UpdatePKIConfig_NoMatch					= 0x80046424;	///< no match for UpdatePKIConfig. ID specified does not exist
	const long	CERT_WriteCertIssue_NoData						= 0x80046425;	///< no data for WriteCertIssue
	const long	CERT_WriteCertIssue_MinData						= 0x80046426;	///< minimum data for WriteCertIssue not supplied
	const long	CERT_WriteCertRequest_NoData					= 0x80046427;	///< no data for WriteCertRequest
	const long	CERT_WriteCertRequest_MinData					= 0x80046428;	///< minimum data for WriteCertRequest not supplied
	const long	CERT_WriteFailedCertRequest_NoData				= 0x80046429;	///< no data for WriteFailedCertRequest
	const long	CERT_WriteFailedCertRequest_MinData				= 0x8004642A;	///< minimum data for WriteFailedCertRequest not supplied
	const long	CERT_WritePendingCert_NoData					= 0x8004642B;	///< no data for WritePendingCert
	const long	CERT_WritePendingCert_MinData					= 0x8004642C;	///< minimum data for WritePendingCert not supplied
	const long	CERT_GetDevicesByPersonID_NoData				= 0x8004642D;	///< no data for GetDevicesByPersonID
	const long	CERT_GetDevicesByPersonID_MinData				= 0x8004642E;	///< minimum data for GetDevicesByPersonID not supplied

	const long	CERT_UpdateCertStatus_NoData					= 0x8004642F;	///< no data for UpdateCertStatus
	const long	CERT_UpdateCertStatus_MinData					= 0x80046430;	///< minimum data for UpdateCertStatus not supplied
																					
	const long	CERT_WritePendingCert_MultipleMatch				= 0x80046431;	///< multiple match for WritePendingCert
	const long	CERT_WriteCertRequest_MultipleMatch				= 0x80046432;	///< multiple match for WriteCertRequest
	const long	CERT_WriteFailedCertRequest_MultipleMatch		= 0x80046433;	///< multiple match for WriteFailedCertRequest
	const long	CERT_UpdatePendingCert_MultipleMatch			= 0x80046434;	///< multiple match for UpdatePendingCert
	const long	CERT_WriteCertIssue_MultipleMatch				= 0x80046435;	///< multiple match for WriteCertIssue

	const long  CERT_GetCertPolicy_NoData                       = 0x80046436;	///< no data for GetCertPolicyDetails
	const long  CERT_CreateOU_NoData                            = 0x80046437;	///< no data for CreateOU
	const long  CERT_CreateOU_UnexpectedData                    = 0x80046438;	///< unexpected data for CreateOU, is there an "E="?
	const long	CERT_RetrieveArchivedCertsByUser_NoData			= 0x80046439;	///< no data for RetrieveArchivedCertsByUser 
	const long	CERT_RetrieveArchivedCertsByUser_MinData		= 0x8004643A;	///< minimum data for RetrieveArchivedCertsByUser not supplied

	//////////////////////////////////////////////////////////////////////////////////////////////
	// IEdeficePKI/IEdeficePKIByCA interface error codes
	// Range 0x80046500 to 0x800465ff
	//////////////////////////////////////////////////////////////////////////////////////////////
	const long	PKI_DatabaseVersion_TableEmpty					= 0x80046500;
	const long	PKI_BaltimoreOffset_NotSet						= 0x80046501;
	const long	PKI_GetCertificateRequest_ID_Null				= 0x80046502;
	const long	PKI_GetCertificateRequest_PKCS10_Null			= 0x80046503;
	const long	PKI_GetCertificateRequest_Template_NULL			= 0x80046504;
	const long	PKI_GetCertificateRequest_KeyUsage_NULL			= 0x80046505;
	const long	PKI_GetCertificateRequest_ExtKeyUsage_NULL		= 0x80046506;
	const long	PKI_PutIssuedCertificate_NoData					= 0x80046507;
	const long	PKI_PutIssuedCertificate_MinData				= 0x80046508;
	const long	PKI_GetRevocationRequest_ID_Null				= 0x80046509;
	const long	PKI_GetRevocationRequest_SNCert_Null			= 0x8004650A;
	const long	PKI_PutPolicy_NoData							= 0x8004650C;	///< put policy, input string empty
	const long	PKI_UpdateCertificates_NoData					= 0x8004650D;	///< UpdateCertificates, input string empty
	const long	PKI_UpdateCertificates_MinData					= 0x8004650E;	///< UpdateCertificates, minimum data not supplied
	const long	PKI_UpdateCertificates_NoMatch					= 0x8004650F;
	const long	PKI_UpdateCertificates_MultipleMatch			= 0x80046510;
	const long	PKI_UpdateCertificates_CertStatus_NULL			= 0x80046511;
	const long  PKI_GetCertificateRequest_CAPath_NULL			= 0x80046512;
	const long  PKI_GetCertificateRequest_FileName_NULL			= 0x80046513;
	const long  PKI_GetCertificateRequest_CAType_NULL			= 0x80046514;
	const long  PKI_GetRevocationRequest_CAPath_NULL			= 0x80046515;
	const long  PKI_GetRevocationRequest_FileName_NULL			= 0x80046516;
	const long  PKI_GetRevocationRequest_CAType_NULL			= 0x80046517;
	const long  PKI_GetRevocationRequest_UserDN_NULL			= 0x80046518;
	const long  PKI_GetCertificateRequest_CertType_NULL			= 0x80046519;
	const long  PKI_GetCertificateRequestFilter_NoData			= 0x80046520;
	const long  PKI_GetRevocationRequestFilter_NoData			= 0x80046521;

	//////////////////////////////////////////////////////////////////////////////////////////////
	// APDU card server error codes
	// Range 0x80046600 to 0x800466ff
	//////////////////////////////////////////////////////////////////////////////////////////////

	const long APDU_Device_NotSupportApplet						= 0x80046600;	///< The specified device does not support the specified applet
	const long APDU_APDUError									= 0x80046601;	///< An Error occurred processing APDU commands for the target Device
	const long APDU_APDUDeviceError								= 0x80046602;	///< The APDU commands did not execute successfully on the clients device
	const long APDU_Device_OperationNotPossible					= 0x80046603;	///< The APDU operation requested is not possible

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Signed database operation error codes
	// Range 0x80046700 to 0x800467ff
	//////////////////////////////////////////////////////////////////////////////////////////////
	const long SIGNDB_SignatureVerificationFail					= 0x80046700;	///< Signed database operation failure, The signature for the database record is invalid. This may indicate data tampering
	const long SIGNDB_DataToSignCannotBeIdentified				= 0x80046701;	///< Signed database operation failure, Unable to unambiguously identify data to sign
	const long SIGNDB_NoSignatureFieldOnRecord					= 0x80046702;	///< Signed database operation failure, The record to be signed does not have a Signature field
	const long SIGNDB_XMLError									= 0x80046703;	///< Signed database operation failure, Unable to load XML

	////////////////////////////////////////////////////////////////////////////////////
	// Errors on the IEdeficeBOL interface continued
	// Error number range 0x80046800 to 0x800468FF
	////////////////////////////////////////////////////////////////////////////////////
	const long BOL_GetDeviceDetails_MultipleMatch				= 0x80046800;	///< GetDeviceDetails, MultipleMatch
	const long BOL_GetOPKSearchCriteria_NoData					= 0x80046801;	///< GetOPKSearchCriteria No Data
	const long BOL_GetOpenPlatformKeys_NoData					= 0x80046802;	///< GetOpenPlatformKeys NoData
	const long BOL_SetOpenPlatformKeys_NoData					= 0x80046803;	///< SetOpenPlatformKeys NoData
	const long BOL_SetOpenPlatformKeys_MinData					= 0x80046804;	///< SetOpenPlatformKeys MinData
	const long BOL_SetOpenPlatformKeys_InvalidSelection			= 0x80046805;	///< SetOpenPlatformKeys Invalid Data selection from XML
	const long BOL_SetSelectOptions_MinData                     = 0x80046806;	///< SetSelectOptions_MinData
	const long BOL_GetMifareKeysets_NoData                      = 0x80046807;	///< GetMifareKeysets_NoData
	const long BOL_GetMifareMapping_NoData                      = 0x80046809;	///< GetMifareMapping_NoData
	const long BOL_GetViewFields_NoData							= 0x8004680a;	///< GetViewFields NoData
	const long BOL_GetMifareMapping_MinData						= 0x8004680b;	///< GetMifareMapping MinData
	const long BOL_GetMifareMapping_BadData						= 0x8004680c;	///< GetMifareMapping BadData
	const long BOL_AddCardProfile_MifareBadData					= 0x8004680d;	///< AddCardProfile BadData
	const long BOL_UpdateCardProfile_MifareBadData				= 0x8004680e;	///< UpdateCardProfile BadData
	const long BOL_GetEditMifareMapping_MinData					= 0x8004680f;	///< GetEditMifareMapping MinData
	const long BOL_GetEditMifareMapping_NoData					= 0x80046810;	///< GetEditMifareMapping No Data
	const long BOL_GetEditMifareMapping_BadData					= 0x80046811;	///< GetEditMifareMapping Bad Data
	const long BOL_ATBridge_Error								= 0x80046812;	///< Failure within AT Bridge
	const long BOL_LDAPWriteError								= 0x80046813;	///< Error writing data to LDAP
	const long BOL_UpdateGroups_DuplicateGroup					= 0x80046814;	///< UpdateGroups, Group name and parent ID is duplicated
	const long BOL_Logon_RegisterCerts_Devices_NoData           = 0x80046815;	///< Register Certificates, unable to locate Device data
	const long BOL_Logon_RegisterCerts_Devices_BadData          = 0x80046816;	///< Register Certificates, incompatible Device data
	const long BOL_Logon_RegisterCerts_CardProfiles_NoData      = 0x80046817;	///< Register Certificates, unable to locate CardProfiles data
	const long BOL_Logon_RegisterCerts_CardProfiles_BadData     = 0x80046818;	///< Register Certificates, incompatible CardProfiles data
	const long BOL_Logon_RegisterCerts_Certificates_NoData      = 0x80046819;	///< Register Certificates, unable to locate Certificates data
	const long BOL_Logon_RegisterCerts_Certificates_BadData     = 0x8004681a;	///< Register Certificates, incompatible Certificates data
	const long BOL_Logon_RegisterCerts_Certificates_DecodeError	= 0x8004681b;	///< Register Certificates, failed to extract required data from certificate
	const long BOL_Logon_RegisterCerts_UpdateDevices_MinData	= 0x8004681c;	///< Register Certificates, minimum data missing for device update
	const long BOL_Logon_RegisterCerts_UpdateDevices_NoData		= 0x8004681d;	///< Register Certificates, update device data missing
	const long BOL_GetDeviceX509SerialNumbers_MinData			= 0x8004681e;	///< GetDeviceX509SerialNumbers, minimum data missing
	const long BOL_GetDeviceX509SerialNumbers_NoData			= 0x8004681f;	///< GetDeviceX509SerialNumbers, data missing
	const long BOL_GetDeviceX509SerialNumbers_BadData			= 0x80046820;	///< GetDeviceX509SerialNumbers, bad data
	const long BOL_UserLicenceCheckingError						= 0x80046821;	///< An error occured checking the user licence
	const long BOL_UserLicenceUpdatingError						= 0x80046822;	///< An error occured updating the user licence
	const long BOL_LicenceFileInvalid							= 0x80046823;	///< The licence file is not valid for this system
	const long BOL_SetDeviceSectorPresets_MinData				= 0x80046824;	///< SetDeviceSectorPresets, Minimum data not supplied
	const long BOL_SetDeviceSectorPresets_InvalidOperation		= 0x80046825;	///< SetDeviceSectorPresets, Invalid Operation
	const long BOL_SetMifareKeys_MinData						= 0x80046826;	///< SetMifareKeys, Minimum data not supplied
	const long BOL_SetMifareKeys_InvalidID						= 0x80046827;	///< SetMifareKeys, Invalid Record ID
	const long BOL_SetMifareKeys_InvalidOperation				= 0x80046828;	///< SetMifareKeys, Invalid Operation
	const long BOL_GetDeviceXML_NoData							= 0x80046829;	///< GetDeviceXML, No Data supplied
	const long BOL_GetDeviceXML_MinData							= 0x8004682A;	///< GetDeviceXML, Minimum data not supplied
	const long BOL_AsyncJob_NotFound							= 0x8004682B;	///< StartAsynchronousJob, Job Not Found
	const long BOL_AsyncJob_WrongStatus							= 0x8004682C;	///< StartAsynchronousJob, Job is wrong status for starting	asynchronous job
	const long BOL_AsyncJob_TaskType_Unknown					= 0x8004682D;	///< StartAsynchronousJob, TaskType unknown
	const long BOL_AsyncJob_RegistryError						= 0x8004682E;	///< StartAsynchronousJob, Registry Error
	const long BOL_AsyncJob_ErrorStartingProcess				= 0x8004682F;	///< StartAsynchronousJob, Error Starting Process
	const long BOL_TransferFileOut_StateXML_InvalidXML			= 0x80046830;	///< TransferFileOut, Invalid XML contained in Job
	const long BOL_TransferFileOut_Unknown_FileName				= 0x80046831;	///< TransferFileOut, File Name is unknown
	const long BOL_TransferFileOut_UnknownTaskType				= 0x80046832;	///< TransferFileOut, Task Type is unknown
	const long BOL_TransferFileOut_ErrorLoadingFile				= 0x80046833;	///< TransferFileOut, Error loading file
	const long BOL_Logon_Mifare_Multiple_SerialNo_Error			= 0x80046834;	///< Logon, Multiple Mifare SerialNo's Found
	const long BOL_ReserveLicence_InvalidData					= 0x80046835;	///< ReserveLicence, invalid data
	const long BOL_ReserveLicence_LicenceLimit					= 0x80046836;	///< ReserveLicence, Licence Limit has been reached or a critical system error has occurred
	const long BOL_LicenceType_NotSupported						= 0x80046837;	///< Licence type not supported
	const long BOL_TransferFileIn_FileNameInvalid				= 0x80046838;	///< TransferFileIn, File Name is invalid
	const long BOL_TransferFileIn_Hash_NoMatch					= 0x80046839;	///< TransferFileIn, Hash does not match
	const long BOL_TransferFileIn_RegistryError					= 0x8004683A;	///< TransferFileIn, Registry error
	const long BOL_TransferFileIn_UnknownTaskType				= 0x8004683B;	///< TransferFileIn, TaskType is unknown
	const long BOL_CertificateStatus_Changed					= 0x8004683C;	///< The Certificates status has changed
	const long BOL_UpdateTHDeviceProfile_MinData				= 0x8004683D;	///< UpdateTHDeviceProfile, Minimum data not supplied
	const long BOL_UpdateTHDeviceProfile_ProfileAssociated		= 0x8004683E;	///< UpdateTHDeviceProfile, The Device Profile is already associated with a card profile
	const long BOL_GetExtServerCredentials_InvalidName			= 0x8004683F;	///< GetExternalServerCredentials, The Internal Name requested is not valid
	const long BOL_SSAS_Config									= 0x80046840;	///< Configuration for the SSAS Server is incorrect.
	const long BOL_SSAS_PostFailed								= 0x80046841;	///< A request posted to the SSAS server failed.
	const long BOL_LDAP_Resync_Failed							= 0x80046842;	///< An error occurred when updating the user from LDAP
	const long BOL_UpdateCertificatesCertInfo_NoData			= 0x80046843;	///< UpdateCertificatesCertInfo, No data provided
	const long BOL_UpdateCertificatesCertInfo_MinData			= 0x80046844;	///< UpdateCertificatesCertInfo, Minimum data not provided
	const long BOL_GetDeviceProfiles_ProfileNotFound			= 0x80046845;	///< The requested device profile does not exist.
	const long BOL_UpdateDeviceProfiles_ProfileUsed				= 0x80046846;	///< The device profile being updated is already included in a card	profile.
	const long BOL_GetPUC_KeyNotFound							= 0x80046847;	///< The unlock key could not be found in the database.
	const long BOL_GetPUC_InsufficientData						= 0x80046848;	///< Insufficient data is available to generate an unlock code.
	const long BOL_GetPUC_ChallengeInvalid						= 0x80046849;	///< The Challenge presented is invalid.
	const long BOL_UpdateDirectories_NoData						= 0x8004684A;	///< UpdateDirectories, No data provided
	const long BOL_UpdateDirectories_InvalidOperation			= 0x8004684B;	///< UpdateDirectories, Invalid operation
	const long BOL_GetDirectories_NoData						= 0x8004684C;	///< GetDirectories, No data provided
	const long BOL_GetPeopleUserAccountsEx_InvDataSrc			= 0x8004684D;	///< GetPeopleUserAccountsEx, Invalid data source
	const long BOL_GetPeopleUserAccountsEx_NoLDAPID				= 0x8004684E;	///< GetPeopleUserAccountsEx, LDAPID missing
	const long BOL_GetPeopleUserAccountsEx_MinData				= 0x8004684F;	///< GetPeopleUserAccountsEx, Minimum data not provided
	const long BOL_UpdateDirectories_MinData					= 0x80046850;	///< UpdateDirectories, Minimum data not provided
	const long BOL_UpdateDirectories_DelWhenExistingUsers		= 0x80046851;	///< UpdateDirectories, Delete attempted while users still exist
	const long BOL_GetPeopleUserAccountsEx_NoData				= 0x80046852;	///< GetPeopleUserAccountsEx, No data provided
	const long BOL_GetPersonDefaults_NoData						= 0x80046853;	///< GetPersonDefaults, No data provided
	const long BOL_TestDirectorySettings_NoData					= 0x80046854;	///< TestDirectorySettings, No data provided
	const long BOL_GetBaseDNs_NoData							= 0x80046855;	///< GetBaseDNs, No data provided
	const long BOL_GetDirectoryTypes_NoData						= 0x80046856;	///< GetDirectoryTypes, No data provided
	const long BOL_GetPeopleUserAccountsEx_NoGroupID			= 0x80046857;	///< GetPeopleUserAccountsEx, No Group ID provided
	const long BOL_TestDirectorySettings_MinData				= 0x80046858;	///< TestDirectorySettings, Minimum data not provided
	const long BOL_GetADOrganisation_MinData					= 0x80046859;	///< GetADOrganisation, Minimum data not provided
	const long BOL_GetADUserAccounts_MinData					= 0x8004685A;	///< GetADUserAccounts, Minimum data not provided
	const long BOL_GetADUserAccountInfo_MinData					= 0x8004685B;	///< GetADUserAccountInfo, Minimum data not provided
	const long BOL_UpdateCardProfile_ProfileUsed				= 0x8004685C;	///< The Card Profile cannot be deleted as it is in use
	const long BOL_RecoverKey_CertificateNotIssued				= 0x8004685D;	///< RecoverKey - The Certificate has not been issued
	const long BOL_GetCerificate_ErrorGettingExchangeCert		= 0x8004685E;	///< Error getting exchange certificate for CA
	const long BOL_InvalidConfigForOperation					= 0x8004685F;	///< The current configuration does not support the required operation
	const long BOL_FileTransfer_GeneralError					= 0x80046860;	///< Error occurred during file transfer
	const long BOL_FileTransfer_ValidationError					= 0x80046861;	///< Error occurred during file transfer validation
	const long BOL_FileImport_Invalid_TaskType					= 0x80046862;	///< Error occurred retrieving the tasktype id
	const long BOL_ExternalSystemsRegistryError					= 0x80046863;	///< Error occurred retrieving Components registry data
	const long BOL_ExternalSystemsDirectoryError				= 0x80046864;	///< Error occurred enumerating external system mappings
	const long BOL_ExternalSystemsReferenced					= 0x80046865;	///< External System cannot be deleted as referenced by other table
	const long BOL_ExternalSystemsConnectionCheck				= 0x80046866;	///< External System connection check
	const long BOL_ExternalSystemNotDefined						= 0x80046867;	///< External System not defined
	const long BOL_HookError									= 0x80046868;	///< Error from listener hook
	const long BOL_HookWarning									= 0x80046869;	///< Warning from listener hook
	const long BOL_Logon_Denied									= 0x8004686A;	///< Logon is denied
	const long BOL_AuthenticateOTPDisabled						= 0x8004686B;	///< OTP device is disabled
	const long BOL_AuthenticateOTPNotIssued						= 0x8004686C;	///< OTP device is not issued
	const long BOL_AuthenticateOTPValidDates					= 0x8004686D;	///< Current date is outside OTP device birth and death dates
	const long BOL_AuthenticateOTPFail							= 0x8004686E;	///< OTP device failed to authenticate
	const long BOL_NotLoggedOn									= 0x8004686F;	///< Not logged on
	const long BOL_LogOnTimeOut									= 0x80046870;	///< Log on timeout
	const long BOL_ExportKey_KeyNotExportable					= 0x80046871;	///< ExportKey, the key is not exportable
	const long BOL_PSMProfileInvalid							= 0x80046872;	///< Error parsing PSM Profile
	const long BOL_PSMGetMetaDataError							= 0x80046873;	///< Error getting PSM Metadata
	const long BOL_FeatureNotLicensed							= 0x80046874;	///< The requested feature is not licenced.
	const long BOL_CheckCardForIssuance_OPKeysNotDefined		= 0x80046875;	///< Open Platform keys are not defined for the device.
	const long BOL_GetSecurityQuestions_Lev2PWFailCountExceeded = 0x80046876;	///< User has exceeded the password fail count for Level 2 authentication
	const long BOL_GetSecurityQuestions_Lev2PWOutOfQuestions    = 0x80046877;	///< There are not enough questions for the current user to satisfy Level 2 authentication
	const long BOL_GetPUCEx_CreatePINGeneratorFailed		    = 0x80046878;	///< The call to create the PIN Generator instance failed
	const long BOL_GetPUCEx_PINGeneratorFailed					= 0x80046879;	///< Error during PIN generation
	const long BOL_Level2Validate_PersonID_Null					= 0x8004687A;	///< Level 2 validate was attempted with no person id supplied
	const long BOL_Level2Validate_PasswordLockError				= 0x8004687B;	///< Level 2 validate encountered an error with the user's PasswordLocked field
	const long BOL_Level2Validate_PasswordIsLocked				= 0x8004687C;	///< Level 2 validate was attempted on a user whose password has been locked
	const long BOL_Level2Validate_IncorrectResponseCount		= 0x8004687D;	///< Level 2 validate was attempted with the wrong number of responses
	const long BOL_GetPeopleUserAccountsEx_UserLocked			= 0x8004687E;	///< User already locked
	const long BOL_BinaryObject_TammisError						= 0x8004687F;	///< Tammis Finger Print storage caused an error
	const long BOL_AuthenticateBio_Quality						= 0x80046880;	///< Fingerprint capture not of sufficient quality
	const long BOL_BinaryObjectAccessibility					= 0x80046881;	///< Binary object retrieval attempted without appropriate accessibility control
	const long BOL_SecurityQuestions_NoData						= 0x80046882;	///< Request to validate security questions with an empty/null data set
	const long BOL_SecurityQuestions_PersonID_Null				= 0x80046883;	///< No PersonID supplied in request to validate security questions
	const long BOL_SecurityQuestions_LogonName_Invalid			= 0x80046884;	///< Invalid LogonName field supplied in request to validate security questions
	const long BOL_SecurityQuestions_PasswordLockError			= 0x80046885;	///< ValidateSecurityQuestions could not resolve the locked status of a users password
	const long BOL_SecurityQuestions_PasswordIsLocked			= 0x80046886;	///< ValidateSecurityQuestions called for a user whose password is already locked
	const long BOL_SecurityQuestions_QuestionListError			= 0x80046887;	///< ValidateSecurityQuestions generated an error while reading previous question list
	const long BOL_SecurityQuestions_DataValidationError		= 0x80046888;	///< ValidateSecurityQuestions supplied xml didn't match question information expected
	const long BOL_SecurityQuestions_IncorrectResponseCount		= 0x80046889;	///< ValidateSecurityQuestions was passed the wrong number of response questions
	const long BOL_InvalidStatusMappingID						= 0x8004688A;	///< Invalid Status Mapping ID specified
	const long BOL_UnMappedCertificateExtension					= 0x8004688B;	///< Certificate policy missing mandatory extension
	const long BOL_GetCarriers_NoData							= 0x8004688C;   ///< GetAssets No Data
	const long BOL_GetCarriers_NoLDAPID							= 0x8004688D;   ///< GetAssets No LDAP ID
	const long BOL_UpdateCarriers_NoData						= 0x8004688E;   ///< UpdateAssets No LDAP ID
	const long BOL_UpdateJob_JobIsInProgress					= 0x8004688F;   ///< Job can't be called because it is 'In Progress'
	const long BOL_ValidateOTP_NoData							= 0x80046890;	///< ValidateOTP, No input data provided
	const long BOL_ValidateOTP_MinData							= 0x80046891;	///< ValidateOTP, Minimum data not provided
	const long BOL_RequestOTP_NoData							= 0x80046892;	///< RequestOTP, No input data provided
	const long BOL_RequestOTP_MinData							= 0x80046893;	///< RequestOTP, Minimum data not provided
	const long BOL_RequestOTP_JobNotFound						= 0x80046894;	///< RequestOTP, Unable to locate a job with the specified ID
	const long BOL_RequestOTP_InvalidXML						= 0x80046895;	///< RequestOTP, Invalid XML
	const long BOL_GetLogonMessages_NoData						= 0x80046896;	///< GetLogonMessages, No input data provided
	const long BOL_GetLogonMessages_MinData						= 0x80046897;	///< GetLogonMessages, Minimum data not provided
	const long BOL_AddPersonUserAccount_KindInvalid				= 0x80046898;	///< AddPersonUserAccount, invalid Kind node passed in
	const long BOL_UpdatePersonUserAccount_KindInvalid			= 0x80046899;	///< UpdatePersonUserAccount, invalid Kind node passed in
	const long BOL_DeletePeopleUserAccounts_MachineHasDevices	= 0x8004689A;	///< DeletePeopleUserAccounts, deleting a machine with allocated devices
	const long BOL_ResendExternalNotification_MinData           = 0x8004689B;	///< ResendExternalNotification, Minimum data not provided
	const long BOL_ResendExternalNotification_NoMatch           = 0x8004689C;	///< ResendExternalNotification, Database query returned zero records
	const long BOL_ResendExternalNotification_MultipleMatch     = 0x8004689D;	///< ResendExternalNotification, Database query returned multiple records, one expected
	const long BOL_CertInstances_MinData						= 0x8004689E;	///< CertificateInstances, Minimum data not provided
	const long BOL_CertInstances_InvalidInstanceID				= 0x8004689F;	///< CertificateInstances, Invalid instance ID specified
	const long BOL_CertInstances_InvalidCertificateID			= 0x800468A0;	///< CertificateInstances, Invalid certificate ID specified
	const long BOL_CertInstances_InvalidDeviceID				= 0x800468A1;	///< CertificateInstances, Invalid device ID specified
	const long BOL_CertInstances_InvalidRelationshipType		= 0x800468A2;	///< CertificateInstances, Invalid relationship type specified
	const long BOL_UserRelationships_NoMatch					= 0x800468A3;	///< UserRelationships, Database query returned zero records
	const long BOL_UserRelationships_Exists						= 0x800468A4;	///< UserRelationships, specified relationship already exists
	const long BOL_CertInstances_Exists							= 0x800468A5;	///< CertificateInstances, CertInstance already exists
	const long BOL_ValidateSecurityQuestions_AccessDenied       = 0x800468A6;	///< ValidateSecurityQuestions, Access denied
	const long BOL_GetCardProfile_LicenceLimit					= 0x800468A7;	///< GetCardProfile, Licence limit reached.
	const long BOL_AddJobs_LicenceLimit						    = 0x800468A8;	///< AddJobs, Licence limit reached.
	const long BOL_TAM_ValidationKeyMissing						= 0x800468A9;	///< Validate was called on an IReceiptValidator without first calling SetValidationKey
	const long BOL_TAM_ReceiptTypeNotSupported					= 0x800468AA;	///< The receipt type passed to a receipt validator factory was not supported
	const long BOL_TAM_ReceiptInvalid							= 0x800468AB;	///< Generic error validating receipt
	const long BOL_TAM_ReceiptInvalidPayload					= 0x800468AC;	///< Receipt didn't contain the expected payload data
	const long BOL_TAM_ReceiptInvalidSignature					= 0x800468AD;	///< Receipt didn't match the provided signature
	const long BOL_TAM_ImportTA_DecryptFailed					= 0x800468AE;	///< An error occurred during AXF file decryption (invalid transport key, invalid data etc)
	const long BOL_TAM_ImportTA_AXFFormatInvalid				= 0x800468AF;	///< AXF file was not in a valid format (missing ELF header etc)
	const long BOL_TAM_ImportTA_AXFChecksum_NoMatch				= 0x800468BA;	///< AXF file did not match user-supplied checksum after decryption
	const long BOL_TAM_ImportTA_AXFConversionError				= 0x800468BB;	///< An error occurred during AXF file conversion (likely caused by a malformed AXF file)
	const long BOL_TAM_CannotEdit_ItemInUse						= 0x800468BC;	///< The item is "in use" (delivered to a device) and cannot be edited
	const long BOL_UpdatePeopleUserAccounts_InvalidLogonName	= 0x800468BD;	///< The new LogonName is invalid ( possibly a duplicate )
	const long BOL_TAM_UpdateAppVersionTAs_Duplicate_UUIDs		= 0x800468BE;	///< Cannot add multiple TAs with the same UUID to a TAM App Version
	const long BOL_DerivedCredInvalidArchivePolicy				= 0x800468BF;   ///< The configured archive policy for derived credential import is missing or invalid.
	const long BOL_DerivedCredArchiveCertExpired				= 0x800468C0;	///< The supplied archive certificate has expired
	const long BOL_CredentialCertificateStorageError			= 0x800468C1;	///< The certificate storage is incompatible with the credential type
	const long BOL_CannotSponsorLogonNameAlreadyExists			= 0x800468C2;	///< The user cannot be sponsored because another user with the same LogonName already exists
	const long BOL_CannotIssueDisabledCertificatePolicy			= 0x800468C3;	///< The certificate policy is disabled and cannot be issued
	const long BOL_MailCheckEmailNotificationsTurnedOff         = 0x800468C4;	///< The global configuration setting EMAIL NOTIFICATIONS is turned off
	const long BOL_MailCheckEmailNotifyNotifyNotSet             = 0x800468C5;	///< The global configuration setting EMAIL NOTIFY is not set
	const long BOL_MailCheckFailedToSendMail                    = 0x800468C6;	///< The mailer component was unable to send the mail to the specified SMTP server
	const long BOL_DeleteCertificates_CertInUse					= 0x800468C7;	///< DeleteCertificates, Certificate is on a credential
	const long BOL_UnmanagedCertificatePolicyLiveCertNotFound	= 0x800468C8;	///< The certificate policy is unmanaged we cannot find a live certificate
	const long BOL_LogonOTP_FormatError							= 0x800468C9;   ///< The LogonOTP Format is incorrect
	const long BOL_AsyncJob_ErrorProcessTimedOut				= 0x800468CA;	///< The import process timed out waiting for AsyncImport to return.

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Disk	Encryptor Errors
	// Error number	range 0x80046900 to	0x800469FF
	//////////////////////////////////////////////////////////////////////////////////////////////
	const long DiskEncryptor_CantCreateDiskEncryptor			= 0x80046900;	///< CDiskEncryptor, Failed to create instance of Central Database API DLL
	const long DiskEncryptor_NoCredentials						= 0x80046901;	///< CDiskEncryptor, Unable to find logon credentials for Central Database
	const long DiskEncryptor_Notconnected						= 0x80046902;	///< CDiskEncryptor, not connected to Central Database
	
	///////////////////////////////////////////////////////////////////////////////////
	//			0x80047000 to 0x80047FFF	eDiskEncryptor
	//		defined	in eDiskEncryptor project
	///////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////
	// N.B.	In version 6.7.3 (RCMS)	the	following block	of error codes use the range
	// 0x80046900 to 0x800469FF, as	these are used for DiskEncryptor_ in this version
	// we must use the values below
	//////////////////////////////////////////////////////////////////////////////////////////////
	// Errors for enhanced signing & verification checking of enveloped	inputs 
	// Error number	range 0x80048000 to	0x800480FF
	const long VERIFY_ClearEnvelopeNotAllowed				= 0x80048000;	///< A clear envelope is invalid in this context
	const long VERIFY_CertificateNotFound					= 0x80048001;	///< Unable to retrieve certificate from database
	const long VERIFY_CertDevice_PublicKeyMismatch			= 0x80048002;	///< The public key held for the device does not match the public key held in the corresponding certificate
	const long VERIFY_DeviceDetailsNotFound					= 0x80048003;	///< Required device details were not found in the database
	const long VERIFY_CertificateValidation_BadData			= 0x80048004;	///< Certificate validation process did not return necessary information
	const long VERIFY_CertificateValidation_Error			= 0x80048005;	///< Certificate validation process failed
	const long VERIFY_StageDetailsNotFound					= 0x80048006;	///< Stage details not found in database
	const long VERIFY_StageDetailsBadData					= 0x80048007;	///< Invalid stage data found in database
	const long VERIFY_XMLBadData							= 0x80048008;	///< Invalid xml data found
	const long VERIFY_InvalidStageEnvelopeConstruction		= 0x80048009;	///< Unexpected envelope construction for stage
	const long VERIFY_CertificateValidation_Failed			= 0x8004800A;	///< Failed to validate certificate(s)
	const long VERIFY_Cert_SerialNumberMismatch				= 0x8004800B;	///< The certificate serial number held in the database does not match the serial number in the corresponding certificate
	const long VERIFY_DecodeCertificate_Error				= 0x8004800C;	///< Error decoding certificate data
	const long VERIFY_UnexpectedEnvelopeFormat				= 0x8004800D;	///< The envelope format is invalid in this context
	const long VERIFY_WitnessLayerNotDeviceSigned			= 0x8004800E;	///< Witness layer is not device signed
	const long VERIFY_WitnessScoping						= 0x8004800F;	///< Logged on user not in witness scope
	const long VERIFY_CoreWitnessName						= 0x80048010;	///< Logged on user name and all witness names must be different

	///////////////////////////////////////////////////////////////////////////////////
	//			0x80049000 to 0x80049FFF	Authentication Server Error	Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long AUTHSERVER_DatabaseError						= 0x80049001;	///< The Database access layer threw an exception
	const long AUTHSERVER_LoginError						= 0x80049002;	///< Administrator logon to authentication server failed
	const long AUTHSERVER_SessionError						= 0x80049003;	///< General admin session error
	const long AUTHSERVER_NotInitialsed						= 0x80049004;	///< Autheentication Server not initialised
	const long AUTHSERVER_ChangePin_InvalidPIN				= 0x80049005;	///< Invalid PIN specified for Cange PIN Command
	const long AUTHSERVER_NotConfigured						= 0x80049006;	///< Authentication Server not configured.
	
	///////////////////////////////////////////////////////////////////////////////////
	//			0x80050000 to 0x80050FFF	OfflineUnblock Error Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long OFFLINEUNBLOCK_InvalidXML					= 0x80050001;	///< The XML data provided contains errors
	const long OFFLINEUNBLOCK_MinData						= 0x80050002;	///< Minimum data not supplied to function
	const long OFFLINEUNBLOCK_NoMatch						= 0x80050003;	///< No matches returned by database query
	const long OFFLINEUNBLOCK_MultipleMatch					= 0x80050004;	///< Multiple matches returned by database query, expecting one
	const long OFFLINEUNBLOCK_ChallengeNot16				= 0x80050005;	///< Challenge code not 16 bytes in length
	const long OFFLINEUNBLOCK_ChallengeNotHex				= 0x80050006;	///< Challenge code not hexadecimal
	const long OFFLINEUNBLOCK_NoBOL							= 0x80050007;	///< Failed to instantiate BOL interface
	const long OFFLINEUNBLOCK_NoServiceUnlock				= 0x80050008;	///< No ServiceUnlock node in return XML
	const long OFFLINEUNBLOCK_LockoutInEffect				= 0x80050009;	///< A lockout is in effect on this user account

	///////////////////////////////////////////////////////////////////////////////////
	//			0x80051000 to 0x800510FF	Job Maintenance Processor Error Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long JOBMAINTPROC_InvalidEnumeratedName			= 0x80051001;	///< Invalid enumerated name
	const long JOBMAINTPROC_InvalidEnumeratedValue			= 0x80051002;	///< Invalid enumerated value
	const long JOBMAINTPROC_DatabaseTableOrViewNotSupported = 0x80051003;	///< The specified database table or view is not currently supported

	///////////////////////////////////////////////////////////////////////////////////
	//			0x80051100 to 0x800511FF	Security Phrase Error Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long SECPHRASE_InvalidHashLength					= 0x80051101;	///< Unexpected security phrase length
	const long SECPHRASE_InvalidHashAlgorithm				= 0x80051102;	///< Incorrect security phrase hash received
	const long SECPHRASE_InvalidHashAlgorithmConfiguration	= 0x80051103;	///< Unexpected value for security question algorithm configuration setting
	const long SECPHRASE_InvalidHashData					= 0x80051104;	///< The hashed security phrase data provided is invalid
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//			0x80052000 to 0x800520FF	Card Server Error Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long CardServer_FingerPrintBiometrics_Expired		= 0x80052001;	///< Finger print biometrics have expired
	const long CardServer_FacialBiometrics_Expired			= 0x80052002;	///< Facial biometrics have expired
	const long CardServer_IRISBiometrics_Expired			= 0x80052003;	///< Iris biometrics have expired
	const long CardServer_Biometrics_Expired				= 0x80052004;	///< Biometrics have expired
	const long CardServer_FacialBiometrics_NotPresent		= 0x80052005;	///< Facial biometrics have not been found
	const long CardServer_ContentSigningCertificateExpiry	= 0x80052006;	///< The server content signing certificate will expire before the device expires. Please contact your system administrator
	const long CardServer_VSCIssuanceOfNonVSCDevice         = 0x80052007;	///< CardServer, VSC card profile issuance of non VSC device, IsRemovable!=0
	const long CardServer_LegacyDataModelDisabled           = 0x80052008;	///< Legacy datamodel configuration is disabled
	const long CardServer_ContentSignerNotConfigured		= 0x80052009;	///< Content signing certificate not specified or could not be loaded


	///////////////////////////////////////////////////////////////////////////////////
	//			0x80052100 to 0x800521FF	Key Server Error Codes
	//	
	///////////////////////////////////////////////////////////////////////////////////
	const long KeyServer_FatalHSMDriverError				= 0x80052101;	//!< A fatal error has occurred in the HSM driver requiring a device reset

	//////////////////////////////////////////////////////////////////////////////////////////////
}
