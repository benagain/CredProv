///	\file
/// log codes for Edefice Business Object Layer
/// \note log code numbers are defined in the LogCodes table in the Edefice Database

#pragma once

// NOTE to Developer: When editing this file it is important to consider that some of the entries may only
// be used in certain branches of MyID, so please **do not remove** them if they are not referenced in the branch
// that you are working on.

/// General log codes for the business object layer
namespace BOLLogCodes
{
	/*
	 Reserved log code range; -10100 to -10199 (inclusive)
	 These log codes are reserved for Cryptas' use
	*/
	
	const int CUSTOM_APPLET_REMOVED_FROM_DEVICE			= -10002;	// Custom log codes for Cryptas/BASF applet migration
	const int CUSTOM_APPLET_ADDED_TO_DEVICE				= -10001;	//
	
	const int LOGON_SUCCESS							= 19;
	const int LOGON_FAILURE							= 20;
	const int MISC_INTERNAL_ERROR					= 66;
	const int ADDACTIVCARDDEVICE_SUCCESS			= 73;
	const int ADDACTIVCARDDEVICE_FAILURE			= 74;
	const int ADDDEVICE_SUCCESS						= 75;
	const int ADDDEVICE_FAILURE						= 76;
	const int ADDGROUPS_SUCCESS						= 77;
	const int ADDGROUPS_FAILURE						= 78;
	const int ADDPERSONUSERACCOUNT_SUCCESS			= 79;
	const int ADDPERSONUSERACCOUNT_FAILURE			= 80;
	const int ADDRADIUSCLIENTS_SUCCESS				= 81;
	const int ADDRADIUSCLIENTS_FAILURE				= 82;
	const int ADDRADIUSCONNECTIONS_SUCCESS			= 83;
	const int ADDRADIUSCONNECTIONS_FAILURE			= 84;
	const int ADDRADIUSSERVERS_SUCCESS				= 85;
	const int ADDRADIUSSERVERS_FAILURE				= 86;
	const int ADDRASSERVERS_SUCCESS					= 88;
	const int ADDRASSERVERS_FAILURE					= 89;
	const int DELETEGROUPS_SUCCESS					= 90;
	const int DELETEGROUPS_FAILURE					= 91;
	const int DELETEPEOPLEUSERACCOUNTS_SUCCESS		= 92;
	const int DELETEPEOPLEUSERACCOUNTS_FAILURE		= 93;
	const int DELETERADIUSCLIENTS_SUCCESS			= 96;
	const int DELETERADIUSCLIENTS_FAILURE			= 97;
	const int DELETERADIUSCONNECTIONS_SUCCESS		= 98;
	const int DELETERADIUSCONNECTIONS_FAILURE		= 99;
	const int DELETERADIUSSERVERS_SUCCESS			= 100;
	const int DELETERADIUSSERVERS_FAILURE			= 101;
	const int DELETERASSERVERS_SUCCESS				= 102;
	const int DELETERASSERVERS_FAILURE				= 103;
	const int RESYNCTOKEN_SUCCESS					= 104;
	const int RESYNCACTIVCARD_FAILURE				= 105;
	const int UPDATEDEVICES_SUCCESS					= 106;
	const int UPDATEDEVICES_FAILURE					= 107;	// not used in Vx
	const int UPDATEGROUPS_SUCCESS					= 108;
	const int UPDATEGROUPS_FAILURE					= 109;
	const int UPDATEPEOPLEUSERACCOUNTS_SUCCESS		= 110;
	const int UPDATEPEOPLEUSERACCOUNTS_FAILURE		= 111;
	const int UPDATERADIUSCLIENTS_SUCCESS			= 112;
	const int UPDATERADIUSCLIENTS_FAILURE			= 113;
	const int UPDATERADIUSSERVERS_SUCCESS			= 114;
	const int UPDATERADIUSSERVERS_FAILURE			= 115;
	const int UPDATERASSERVERS_SUCCESS				= 116;
	const int UPDATERASSERVERS_FAILURE				= 117;
	const int BOL_XMLLOAD_FAILURE					= 120;
	const int BOL_INVALIDTASKNUMBER					= 123;
	const int BOL_EMPTYINPUTPARAMETER				= 125;
	const int BOL_CAUGHTEXCEPTION					= 126;
	const int BOL_UNHANDLEDEXCEPTION				= 127;
	const int BOL_UNENVELOPINGERROR					= 128;
	const int BOL_INVALIDMESSAGENUMBER				= 129;
	const int IMPORTTOKENAUDIT_SUCCESS				= 130;
	const int IMPORTTOKENAUDIT_FAILED				= 131;
	const int IMPORTTOKENAUDIT_NOPRIVILEGE			= 132;
	const int IMPORTTOKENAUDIT_OK					= 133;
	const int IMPORTTOKENAUDIT_DUPLICATE			= 134;
	const int IMPORTTOKENAUDIT_INCORRECT			= 135;
	const int NT_LOGON_FAILURE						= 136;
	const int CS_XMLLOAD_FAILURE					= 137;
	const int CS_INVALIDTASKNUMBER					= 138;
	const int CS_EMPTYINPUTPARAMETER				= 139;
	const int CS_CAUGHTEXCEPTION					= 140;
	const int CS_UNHANDLEDEXCEPTION					= 141;
	const int CS_INVALIDMESSAGENUMBER				= 142;
	const int CS_UNENVELOPINGERROR					= 143;
	const int CS_COCREATEINSTANCE					= 144;
	const int ADDDEVICE_DEVICEEXTANT				= 147;
	const int ADDDEVICECLEAR_DEVICEEXTANT			= 148;
	const int ADDDEVICECLEAR_SUCCESS				= 149;
	const int ADDPERSONUSERACCOUNT_USERPROFILE		= 150;
	const int UPDATEPEOPLEUSERACCOUNTS_SELFEDIT		= 151;
	const int UPDATEPEOPLEUSERACCOUNTS_USERPROFILE	= 152;
	const int UPDATEDEVICES_SELFEDIT				= 153;
	const int UPDATEPOLICY_SUCCESS					= 154;
	const int ADDPOLICY_SUCCESS						= 155;
	const int DELETEPEOPLEUSERACCOUNTS_SELFDELETE	= 156;
	const int UPDATEDEVICES_USERPROFILE				= 157;
	const int DELETEPEOPLEUSERACCOUNTS_USERPROFILE	= 158;
	const int GETPUC_USERPROFILE					= 159;
	const int GETPUCTOKEN_USERPROFILE				= 160;

	const int ADDJOBSUCCESS							= 161;
	const int ADDJOBFAILED							= 162;
	const int UPDATEJOBSUCCESS						= 163;
	const int UPDATEJOBFAILED						= 164;
	const int FINISHJOBSUCCESS						= 165;

	const int LOGON_SUCCESS_USERNAME_SECURITYPHRASES= 166;
	const int LOGON_SUCCESS_DEVICE_SECURITYPHRASES	= 167;
	const int LOGON_FAILURE_USERNAME_SECURITYPHRASES= 168;
	const int LOGON_FAILURE_DEVICE_SECURITYPHRASES	= 169;
	const int LOGON_SUCCESS_GUEST					= 170;

	const int ACTIVATE_USERACCOUNT_SUCCESS_PROFILE	= 171;
	const int ACTIVATE_USERACCOUNT_FAILURE			= 172;
	const int ACTIVATE_USERACCOUNT_SUCCESS			= 173;
	const int EMERGENCYPASSWORD_CLEAR				= 174;
	const int EMERGENCYPASSWORD_SET					= 175;
	const int EMERGENCYPASSWORD_ENABLE				= 176;
	const int REGISTERCA_SUCCESS					= 177;

	const int CS_CERTIFICATECOLLECTION				= 178;
	const int CS_SUBMITCAFAILED						= 179;
	const int CS_UNEXPECTEDRECORDCOUNT				= 180;
	const int CS_UNEXPECTEDRECORDCOUNTIGNORE		= 181;
	const int CS_REVOKEALLCERTSBYDEVICE				= 182;
	const int CS_REVOKEALLCERTSBYDEVICENORECORDS	= 183;
	const int CS_REVOCATIONREQUESTCOMPLETE			= 184;

	const int UPDATECARDLAYOUT_SUCCESS				= 185;
	const int REMOVECARDLAYOUT_SUCCESS				= 186;

	const int REMOVETEMPLATE_SUCCESS				= 187;
	const int UPDATETEMPLATE_SUCCESS				= 188;
	const int ADDTEMPLATE_SUCCESS					= 189;
	const int GETCODES_FAILURE						= 190;
	const int ENTRUST_INVALIDDN						= 191;
	const int ENTRUST_INVALIDTEMPLATE				= 192;
	const int ENTRUST_INVALIDSTATUS					= 193;

	const int GETSOPIN_SUCCESS						= 194;
	const int GETUNLOCKCODE_SUCCESS					= 195;
	const int GENERATEUNLOCKCODES_SUCCESS			= 196;
	const int GETNEXTUNUSEDUNLOCKCODE_SUCCESS		= 197;
	const int GETACTIVCARDUNLOCKCODE_SUCCESS		= 198;
	const int LOGON_FAILURE_DEVICE_NOT_ENABLED		= 199;

	const int WEBCONNECTOR_ERROR					= 200;

	const int ADDAPPLET_SUCCESS						= 201;
	const int UPDATEAPPLET_SUCCESS					= 202;
	const int UPDATEAPPLET_FAILED					= 203;

	const int APPLET_ADDED_TO_DEVICE				= 204;
	const int APPLET_REMOVED_FROM_DEVICE			= 205;
	const int UPDATED_DEVICE_KEYSET					= 206;

	const int INVALID_TEMPLATE						= 207;
	const int GETUNLOCKCODE_GENERIC					= 208;
	const int LOGON_FAIL_INSUFFICIENT_PRIVILEGES	= 209;
	const int UPDATE_SECURITYQUESTIONS				= 210;
	const int ADD_CARDPROFILE						= 211;
	const int UPDATE_CARDPROFILE					= 212;
	const int REMOVE_CARDPROFILE					= 213;
	const int UPDATE_CONFIGURATION					= 214;
	const int UPDATE_CA								= 215;
	const int SET_PIN								= 216;
	const int LDAP_PUSH_FAILED						= 217;
	const int WEBCONNECTOR_REQUEST					= 218;
	const int WEBCONNECTOR_RESPONSE					= 219;
	const int WEBCONNECTOR_REVREQUEST				= 220;
	const int WEBCONNECTOR_REVRESPONSE				= 221;
	const int SETPASSWORD							= 222;
	const int RECOVERED_OWN_KEYS					= 223;
	const int RECOVERED_ANOTHERUSERS_KEYS			= 224;

	const int BUREAUJOBBATCH_REQUEST_EMPTY			= 225;
	const int BUREAUJOBBATCH_REQUEST_CREATED		= 226;
	const int BUREAUJOBBATCH_BATCH_CREATED			= 227;
	const int BUREAUJOBBATCH_CAUGHTEXCEPTION		= 228;
	const int BUREAUJOBBATCH_UNHANDLEDEXCEPTION		= 229;
	const int VALIDATEJOB_SUCCESS					= 230;

	const int ECSRV_CONNECTOR_REQUEST				= 231;
	const int ECSRV_CONNECTOR_RESPONSE				= 232;
	const int ECSRV_CONNECTOR_REVREQUEST			= 233; // although historically ECSRV_CONNECTOR_REVREQUEST has meant either revoke, suspend, or unsuspend, this is being changed to mean revoke only - see logcodes 260-263 for dedicated (un)suspend messages.
	const int ECSRV_CONNECTOR_REVRESPONSE			= 234;
	const int ECSRV_CONNECTOR_POLICYUPDATE			= 235;

	const int BUREAUSRV_CAUGHTEXCEPTION				= 236;
	const int BUREAUSRV_UNHANDLEDEXCEPTION			= 237;
	const int BUREAUSRV_ITEMUPDATE					= 238;
	const int BUREAUSRV_BATCHITEMSUPDATE			= 239;
	const int BUREAUSRV_EMPTYREQUESTUPDATE			= 240;
	const int BUREAUSRV_BUREAURESPONSE				= 241;

	const int ECSRV_POLICYUPDATE					= 242;
	const int ECSRV_RENEWAL							= 243;
	const int ECSRV_UNEXPECTED						= 244;

	const int DEVICE_GLOBAL_PIN_SET					= 245;

	const int ENTRUST_LIBRARYFAILURE				= 246;
	const int ENTRUST_FAILURE						= 247;

	const int JOB_AUTOUPDATE						= 248;

	const int LOGON_SUCCESS_AUTOENROL				= 249;
	const int LOGON_FAILURE_DEVICE_AUTOENROL		= 250;

	const int CS_FAILEDCREATEOU						= 251;

	const int BALTIMORE_CERTREQUESTED				= 252;
	const int BALTIMORE_CERTREQCOMPLETED			= 253;
	const int BALTIMORE_CERTREVREQUESTED			= 254;
	const int BALTIMORE_CERTREVCOMPLETED			= 255;

	const int UPDATE_LICENCE						= 256;

	const int BUREAUSRV_STOCKCHANGE					= 257;
	const int CONFIGURATION_ERROR					= 258;

	const int BUREAUSRV_ITEMUPDATE_FINISHED			= 259; // differentiated from BUREAUSRV_ITEMUPDATE because this indicates a state of finality being reached, whereas BUREAUSRV_ITEMUPDATE will mean an interim update takes place, and the it has yet to succeed or fail

	// logcodes 231 to 234 are related to these, together they represent the action of eCS talking to the
	// CA to perform the revocation/(un)suspension
	const int ECSRV_CONNECTOR_SUSPEND_REQUEST		= 260;
	const int ECSRV_CONNECTOR_SUSPEND_RESPONSE		= 261;
	const int ECSRV_CONNECTOR_UNSUSPEND_REQUEST		= 262;
	const int ECSRV_CONNECTOR_UNSUSPEND_RESPONSE	= 263;

	// these logcodes represent a user initiating a revocation/(un)suspension from a workflow
	const int CERTIFICATE_REVOCATION_INITIATED		= 264;
	const int CERTIFICATE_SUSPENSION_INITIATED		= 265;
	const int CERTIFICATE_UNSUSPENSION_INITIATED	= 266;
	const int CERTIFICATE_REQUEST_INITIATED			= 267; // pkcs10 submitted for processing to edefice (though not necessarily to the CA)

	const int DEVICE_ENABLE							= 268;
	const int DEVICE_DISABLE						= 269;

	// log codes to represent failure to validate certificates used in signing operations
	const int LOGON_FAILURE_CERTIFICATE_VALIDATION	= 270;
	const int CERTIFICATE_VALIDATION_FAILURE		= 271;

	const int BOL_WINMAGIC_FAILEDLOGOFF				= 272;

	// merged in as part of enhanced witnessing & verification PDR-4776
	const int UPDATE_AUDITITEMS						= 273;
	const int UPDATE_USERPROFILEREPORT				= 274;
	//

	const int EDISKENCRYPTOR_CAUGHTEXCEPTION		= 275;
	const int EDISKENCRYPTOR_UNHANDLEDEXCEPTION		= 276;

	const int EXMLEXPORT_ERROR						= 277;
	const int START_ASYNCHRONOUSJOB					= 278;
	const int TRANSFER_FILE_OUT						= 279;
	const int EXMLEXPORT_PROCESS					= 280;

	const int LDAP_DELETE_USER_FAILED				= 281;

	const int XMLIMPORT_PROCESS						= 282;
	const int XMLIMPORT_ADDUSER						= 283;
	const int XMLIMPORT_ADDGROUP					= 284;
	const int XMLIMPORT_CARDREQUEST					= 285;
	const int XMLIMPORT_ERROR						= 286;

	const int TRANSFER_FILE_IN						= 287;

	const int DISCENCRYPTOR_FAILED_CONNECT			= 288;

	const int LOG_BATCH_JOB_CARD_PROFILE_SUCCESS	= 289;

	const int ADDGROUP_LDAP_FAILURE					= 290;

	const int GETATHENAUNLOCKCODE_SUCCESS			= 291;

	// 292-294 used by RBoS
	const int VALIDATE_ENVELOPE_SUCCESS				= 292;
	const int ADDCARDSTOCK_SUCCESS					= 293;
	const int UPDATECARDSTOCK_SUCCESS				= 294;

	// special update jobs - bureau
	const int UPDATEJOB_FAILRESUBBUREAUREQUEST		= 295;
	const int UPDATEJOB_RESUBMIT_BUREAUREQUEST		= 296;
	const int UPDATEJOB_FAILBUREAUREQUEST			= 297;

	const int BOLUPDATECERTIFICATE					= 298;

	const int UPDATETHDEVICEPROFILE_SUCCESS			= 299;

	const int GETEXTSERVERCREDENTIALS_SUCCESS		= 300;

	const int REMOVEPERSON_FAILEDCANCELPSM			= 301;

	// DB data import service log codes, so also 364+
	const int DBIMPORTSRV_CAUGHTEXCEPTION			= 302;
	const int DBIMPORTSRV_UNHANDLEDEXCEPTION		= 303;
	const int DBIMPORTSRV_JOBCREATED				= 304;

	const int LOGONEX_DEVICECERTSUPDATED			= 305;

	// log codes for auditing (added as part of the enhanced signing and verification functionality)
	const int SETDEVICESECTORPRESETS_SUCCESS		= 306;
	const int SETOPENPLATFROMKEYS_SUCCESS			= 307;
	const int SETACDEVICEPROFILE_SUCCESS			= 308;
	const int DELETEACDEVICEPROFILE_SUCCESS			= 309;
	const int IMPORTTOKENS_SUCCESS					= 310;
	const int SETSELECTOPTIONS_SUCCESS				= 311;
	const int EXPORTDEVICES_SDS_SUCCESS				= 312;
	const int EXPORTDEVICES_DEVICES_SUCCESS			= 313;
	const int ADDJOB_JOBSUPERSEDED_SUCCESS			= 314;

	const int LDAPSYNC_USER_DELETED					= 315;
	const int LDAPSYNC_USER_UPDATED					= 316;

	const int BUREAUJOBBATCH_PROCESS				= 317;

	// ExternalDataSource Log codes
	const int	EDS_LogCode_HandledException		= 318;
	const int	EDS_LogCode_UnhandledException		= 319;

	// Batch LDAP Sync
	const int LDAPSYNC_BATCH_PROCESS				= 320;
	const int LDAPSYNC_USER_DISABLED				= 321;

	// MessageConnector
	const int MESSAGECONNECTOR_EXCEPTION			= 322;
	const int EMESSAGESERVER_ERROR					= 323;
	const int MESSAGEBATCH_ERROR					= 324;

	// NVDFImportDataService Log Codes
	const int NVDFIDS_ServiceStatus					= 325;
	const int NVDFIDS_SyncFailure					= 326;

	// Axalto device profiles
	const int BOLUPDATEDEVICEPROFILE				= 327;

	const int SETMIFAREKEYS_SUCCESS					= 328;	// Renumbered due to collision with SR1 was 305

	const int UPDATEJOB_RESETBUREAUREQUEST			= 329;

	const int GETSCHLUMBERGERUNLOCKCODE_SUCCESS		= 330;
	// Automatic DOT Tachograph card expiry
	const int DOT_CARD_STATUS_UPDATE				= 331;
	// Automatic DOT Exchanged cards
	const int DOT_EXCH_CARD_STATUS_UPDATE			= 332;
	const int MESSAGE_BATCH							= 333;

	const int TCNENFORCER_EXCEPTION					= 334;
	const int REQUEST_MESSAGE_SENT					= 335;
	const int DOT_EXCH_FOREIGN_CARD_STATUS_UPDATE	= 336;
	const int TCN_NOTIFIED_DL_ISSUINGNATION_CARDISSUED = 337;
	const int DOT_CARD_STATUS_UPDATE_EXCEPTION		= 338;
	const int WEBSERVICE_CARDREQUEST				= 339;
	const int TCNCARD_EXCEPTION						= 340;
	const int TCNCARD_UPDATE_DEVICE_STATE			= 341;
	const int TCNCARD_FIND_USER_DEVICE_FAILED		= 342;
	const int TCNCARD_PREJOBCREATION_FAILED			= 343;
	const int BOLEVENTS_WARNING_OR_ERROR			= 344;
	const int UPDATEDIRECTORIES_SUCCESS				= 345;
	const int LOGON_FAILURE_EXTERNAL_FAILURE		= 346;
	const int ADDGROUPFROMOU_SUCCESS				= 347;
	const int PIV_AUDIT_WRITE_CONTAINER				= 348;
	const int EMAIL_FAILURE							= 349;
	const int BATCH_REQUEST_CARD_IMPORT_USER_FAILURE = 350; // Used directly by the web.
	const int GETGEMPLUSUNLOCKCODE_SUCCESS			= 351;
	const int ADD_APPLICATION						= 352;
	const int REMOVE_APPLICATION					= 353;

	const int IMPORTTOKENS_PROCESS					= 354;
	const int IMPORTTOKENS_FAILED					= 355;
	const int PIV_AUDIT_REMOVE_CONTAINER			= 356;
	const int GETAETUNLOCKCODE_SUCCESS				= 357;
	const int ADD_PROTECTEDKEY						= 358;
	const int TRANSFER_FILE_SERVICE					= 359;
	const int XMLIMPORT_DISABLEUSER					= 360;
	const int XMLIMPORT_ENABLEUSER					= 361;
	const int XMLIMPORT_REMOVEUSER					= 362;
	//	PDR 8555 - Syncro file import from web
	const int PROCESS_FILE_IMPORT_SUCCESS			= 363;

	const int DBIMPORTSRV_DATASELECTION				= 364;
	const int DBIMPORTSRV_MISSINGDATA				= 365;
	const int DBIMPORTSRV_DATACLEANUP				= 366;
	const int DATAIMPORT_PROCESS_START				= 367;
	const int DATAIMPORT_PROCESS_THREAD				= 368;
	const int DATAIMPORT_PROCESS					= 369;
	const int DATAIMPORT_PROCESS_LAUNCH				= 370;
	const int DBIMPORTSRV_DATASELECTION_ERROR		= 371;

	const int DATAMIGRATION_ERROR					= 372;

	const int AUTHSERVER_SYNCHRONISATION_START		= 373;
	const int AUTHSERVER_SYNCHRONISATION_FAILED		= 374;
	const int AUTHSERVER_REMOVEUSER_FAILED			= 375;

	const int EXTERNALSYSTEMS_ADD					= 376;
	const int EXTERNALSYSTEMS_UPDATE				= 377;
	const int EXTERNALSYSTEMS_DELETE				= 378;
	const int AUTHTYPES_ADD							= 379;
	const int AUTHTYPES_EDIT						= 380;

	const int DEVICE_ISSUED							= 381;
	const int DEVICE_CANCELLED						= 382;
	const int LOGON_DEVICE_SUCCESS					= 383;
	const int LOGON_DEVICE_FAILURE					= 384;

	const int REMOVED_DEVICE_KEYSET					= 385;
	const int ADDDEVICE_BATCH						= 386;
	const int LOGOFF_USER							= 387;
	const int USER_EXPORT_KEY						= 388;
	const int SCHEDULED_JOB_PROCESSED				= 389;
	const int JOB_PROCESSOR_CREATION_ERROR			= 390;
	const int IMPORT_VASCO_TOKENS					= 391;
	const int IMPORT_EMV_TOKENS						= 392;
	const int IMPORT_OATH_TOKENS					= 393;

	const int BIOMETRIC_ADJUDICATION				= 394;
	const int BIOMETRIC_ADJUDICATION_RESPONSE		= 395;
	const int BIOMETRIC_ADJUDICATION_FAILED			= 396;
	const int BIOMETRIC_ADJUDICATION_CANCELLED		= 397;

	const int BUREAUSRV_JOB_UPDATE_ERROR			= 398;
	const int IMPORT_RSA_TOKENS						= 399;


	// BOL Event listener codes using block 400-420
	const int AMAGCONNECTOR_AUDIT					= 400;
	const int TWIC_CARDSDELIVERED					= 401;
	const int GECONNECTOR_AUDIT						= 402;
	const int TWIC_REPLACEMENTCARDREQUESTED			= 403;
	const int TWIC_CARDTRANSFER						= 404;
	const int GEFCCONNECTOR_AUDIT					= 405;
	const int TWIC_CARDACTIVATE						= 406;
	const int UFCONNECTOR_AUDIT						= 407;
	const int ONGUARDCONNECTOR_AUDIT				= 408;
	const int LDAPPUBLISH_AUDIT						= 409;
	const int DTLOGONPROVIDER_ERROR					= 410;
	const int CBCONNECTOR_AUDIT						= 411;

	// back to generic LogCodes ^^ when you run out of numbers in the above block, create a new (and perhaps bigger?) block later on
	const int TL_INSTALLDATE_CALCULATED				= 421;
	const int TL_LASTACTIVITY_CALCULATED			= 422;
	const int TL_DATETAMPER_CLOCKSETBACK			= 423;
	const int TL_DATETAMPER_PRIORTOSYSTEMINSTALL	= 424;
	const int TL_INSTALLDATE_UNKNOWN				= 425;
	const int AUTHTYPES_DELETE						= 426;

	const int LOGON_SUCCESS_LOGONPROVIDER			= 427;
	const int LOGON_FAILURE_LOGONPROVIDER			= 428;

	const int EXTERNAL_NOTIFICATION_FAILED			= 429;
	const int EXTERNAL_NOTIFICATION_COMPLETELY_FAILED = 430;
	const int EXTERNAL_NOTIFICATION_ERROR			= 431;

	const int USER_OTP								= 432;
	const int USER_DATA_RETRIEVED					= 433; ///< GetPeopleUserAccountsEx called for individual user
	const int VALIDATE_QUESTIONS_VALID				= 434;
	const int VALIDATE_QUESTIONS_INVALID			= 435;
	const int VALIDATE_QUESTIONS_LOCKED				= 436;
	const int VALIDATE_QUESTIONS_INVALID_PARAM		= 437;
	const int VALIDATE_QUESTIONS_LOCKED_PARAM		= 438;
	const int INCOMING_MESSAGE_ERROR				= 439;
	const int JOBSERVER_REMOVING_DEAD_JOBSERVER		= 440;
	const int JOBSERVER_DAL_ERROR					= 441;
	const int PURGED_USER_DATA						= 442;
	const int LOGON_CODE							= 443;
	const int BUREAUJOBBATCH_NOTICKET				= 444;
	const int BUREAUJOBBATCH_EXECUTED				= 445;
	const int BUREAUSRV_HEARTBEAT					= 446;
	const int NOTIFICATION_SUPPRESSED				= 447;
	const int ORPHANEDIMAGEFILE_DELETED				= 448;
	const int ORPHANED_IMAGES_DELETE_ERROR			= 449;
	const int EXTERNAL_CERTIFICATE_MANAGEMENT		= 450;
	const int XMLIMPORT_CARDUPDATE					= 451;
	const int IMPORT_ACTIVID_TOKENS					= 452;

	const int BUREAU_PREPAREDATA					= 453;
	const int SUPERSEDED_CERTIFICATE_POLICY			= 454;

	const int VALIDATE_ENVELOPEEX_SUCCESS			= 455;

	const int ADDJOBSUCCESS_NO_TARGET				= 456;
	const int ADDJOB_JOBSUPERSEDED_SUCCESS_NO_TARGET= 457;
	const int JOBSERVER_THREAD_FAILED				= 458;
	const int RECOVERED_KEYS						= 459;
	const int XMLIMPORT_CERTIFICATE					= 460;
	const int RBAC_VIOLATION						= 461;

	const int APPLET_EXTRADITED						= 462;

	const int ADDDEVICE_BATCH_NO_JOB				= 463;
	// Assets update code
	const int ASSET_ADDED_OR_UPDATED				= 464;
	const int ASSET_DNS_ALREADY_EXISTS				= 465;
	const int ASSET_DATABASE_RECORD_NOT_FOUND		= 466;
	const int ASSET_ID_NOT_FOUND					= 467;

	const int BIOMETRIC_ADJUDICATION_NO_BIOSAMPLES	= 468;
	const int EXTERNAL_SYSTEM_FAILURE				= 469;

	// TPM Log codes
	const int CREATED_VIRTUAL_SMARTCARD				= 470;
	const int DELETED_VIRTUAL_SMARTCARD				= 471;

	//Notification
	const int ADD_EXTERNAL_NOTIFICATION				= 472;
	const int DELETE_EXTERNAL_NOTIFICATION			= 473;
	const int UPDATE_EXTERNAL_NOTIFICATION			= 474;
	const int ADD_EMAIL_TEMPLATES					= 475;
	const int UPDATE_EMAIL_TEMPLATES				= 476;

	const int LOGON_SUCCESS_BIOMETRIC				= 477;
	const int LOGON_FAILURE_BIOMETRIC				= 478;

	const int IDENTIFY_BIOLOGON_SUITABLE			= 479;
	const int IDENTIFY_BIOLOGON_UNSUITABLE			= 480;
	const int IDENTIFY_BIOLOGON_NOT_FOUND			= 481;
	const int IDENTIFY_BIOLOGON_MATCHED				= 482;
	const int IDENTIFY_BIOLOGON_NOT_MATCHED			= 483;

	const int PROCESS_FILE_IMPORT					= 484;
	const int ADD_LISTENERS_ADD						= 485;
	const int ADD_LISTENERS_UPDATE					= 486;
	const int UPDATE_LISTENERS_ADD					= 487;
	const int UPDATE_LISTENERS_UPDATE				= 488;
	const int DELETE_LISTENERS						= 489;
	const int DEVICE_PROCESS_STATUS_ADD				= 490;
	const int DEVICE_PROCESS_STATUS_UPDATE			= 491;

	const int LDAP_DELETION_SYNC					= 492;

	const int IDENTIFY_BIOGRAPHICLOGON_NOT_FOUND	= 493;
	const int IDENTIFY_BIOGRAPHICLOGON_MATCHED		= 494;

	const int DEVICEISSUANCE_NOTALLOWED				= 495;
	const int DEVICEISSUANCE_SYSTEMNOTCONFIGURED	= 496;
	const int UPDATECONFIGURATION_DEVICETYPEOVERRIDE= 497;

	const int USER_LOGONNAME_CHANGING				= 498;	// Record of logon name before it is changed (iLogonName == old LogonName)
	const int USER_LOGONNAME_CHANGED				= 499;	// Record of logon name after it has changed (iLogonName == new LogonName)

	const int UPDATEGROUPS_MOVE_SUCCESS				= 500;
	const int UPDATEGROUPS_MOVE_FAILURE				= 501;
	const int UPDATEGROUPS_MOVEUSERS_SUCCESS		= 502;
	const int UPDATEGROUPS_MOVEUSERS_FAILURE		= 503;

	const int LOGOFF_SELF							= 504;
	
	const int JOBBASEDOTP_REQUESTOTP_SUCCESS		= 505;
	const int JOBBASEDOTP_VALIDATEOTP_SUCCESS		= 506;
	
	const int GETLOGONMESSAGES_SUCCESS				= 507;
	const int GENERICUPDATEJOBSUCCESS				= 508;
	
	// NotificationListener log codes
	const int NOTIFICATIONLISTENER_ERROR			= 509;
	const int NOTIFICATIONLISTENER_SUCCESS			= 510;
	
	const int CERTIFICATE_RENEWAL_USER_SUSPENDED    = 511;
	
	// Resend external notifications log codes
	const int RESEND_INPROGRESSNOTIFICATION_SUCCESS = 512;
	const int RESEND_COMPLETEDNOTIFICATION_SUCCESS  = 513;
	
	// Deutsche Telekom Notifications Plug-In log codes
	const int DT_NOTIFICATIONS_PLUGIN_ERROR         = 514;

	// CertificateInstances log codes
	const int CERTINSTANCES_CERTFORDEVICE_ENABLED   = 515;
	const int CERTINSTANCES_CERTFORDEVICE_DISABLED  = 516;

	// Cancelled carrier message from 'UpdateCarriers'
	const int ASSET_CANCELLED						= 517;
	const int ADDJOB_DEVICE							= 518;
	const int VALIDATEJOB_DEVICE_SUCCESS			= 519;
	
	const int UPDATEJOB_DEVICE_SUCCESS				= 520;
	
	// UserRelationship log codes
	const int USERRELATIONSHIP_ADDED				= 521;
	const int USERRELATIONSHIP_DELETED				= 522;
	const int USERRELATIONSHIP_UPDATED_STATUS		= 523;
	const int USERRELATIONSHIP_UPDATED_OTHER		= 524;

	// Licence Codes
	const int LICENCE_APPROACHING_LIMIT				= 525;
	const int LICENCE_EXCEEDS_LIMIT					= 526;
	const int LICENCE_REACHED_LIMIT					= 527;
	
	// WorkflowEngine
	const int WORKFLOWENGINE_OPERATION				= 528;
	const int WORKFLOWENGINE_OPERATION_ERROR		= 529;
	
	// Provide Entrust with an update of a User DN change
	const int USER_DN_CHANGED						= 530;

	// Additional Identities
	const int CERTIFICATE_REMOVAL_EXPIRED           = 531;
	
	const int USERRELATIONSHIP_UPDATED_STATUS_IA	= 532;		// UserRelationship status was changed through InActivity
	const int USERRELATIONSHIP_DELETED_IA			= 533;		// UserRelationship was deleted by job processor

	const int DERIVEDCREDENTIAL_CHECK_SUCCESS		= 534;
	const int DERIVEDCREDENTIAL_CHECK_FAILED		= 535;
	
	const int PKI_AUTH_CHECK_SUCCESS				= 536;
	const int PKI_AUTH_CHECK_FAILED					= 537;
	
	const int AUTHENTICATEPERSONCOMPLETE			= 538;
	
	// Additional certsrv processing codes
	const int ECSRV_AUTORESTART						= 539;
	const int ECSRV_PROCESSINGFAILURE				= 540;
	
	const int CERTIFICATERENEWALPROCESSOR_STARTED   = 541;
	const int CERTIFICATERENEWALPROCESSOR_COMPLETED = 542;
	const int CERTIFICATERENEWALPROCESSOR_ERROR     = 543;

	const int LOGON_FAILURE_PASSPHRASE_LOCKEDOUT	= 544;

	// Expired Card Activation Processor log codes
	const int ECAP_REVOKED_CERTIFICATE              = 545;
	const int ECAP_STARTED                          = 546;
	const int ECAP_STATISTICS                       = 547;
	const int ECAP_SUCCESS                          = 548;
	const int ECAP_FAILURE                          = 549;
	const int ECAP_EXCEPTION                        = 550;

	// Expired Machine Identity Processor log codes
	const int EMIP_CANCELLED						= 551;
	const int EMIP_ISSUED			                = 552;
	const int EMIP_EXPIRED                          = 553;
	const int EMIP_FAILURE                          = 554;
	const int EMIP_EXCEPTION                        = 555;
	const int EMIP_PROCESSJOB                       = 556;

	// derived credential log codes
	const int DERVIEDCREDENTIAL_WHITELIST_FAILURE	= 557;
	const int DERIVEDCREDENTIAL_WHITELIST_SUCCESS	= 558;
	const int DERIVEDCREDENTIAL_BIO_CAPTURED		= 559;
	const int DERIVEDCREDENTIAL_USER_ADDED			= 560;
	const int DERIVEDCREDENTIAL_USER_EXISTS			= 561;

	// Badge Disposal Processor log codes
	const int BDP_LOST_DEVICE                       = 562;
	const int BDP_STARTED                           = 563;
	const int BDP_STATISTICS                        = 564;
	const int BDP_SUCCESS                           = 565;
	const int BDP_FAILURE                           = 566;
	const int BDP_EXCEPTION                         = 567;

	// more derived credential log codes
	const int DERIVEDCREDENTIAL_USER_DISABLED		= 568;

	// TAM Project Log Codes
	const int TAM_CONTAINER_REGISTER_NOTIFICATION	= 569;		// Request container registration response from Trustonic
	const int TAM_CONTAINER_UNREGISTER_NOTIFICATION	= 570;		// Request container unregistration response from Trustonic
	
	const int LICENCE_LIMIT							= 571;
	
	// more derived credential log codes
	const int DERIVEDCREDENTIAL_FACIALDATA_ERROR		= 572;
	const int DERIVEDCREDENTIAL_DEVICE_LICENCE_EXCEEDED = 573;
	const int DERIVEDCREDENTIAL_USER_LICENCE_EXCEEDED 	= 574;

	// TAM Project Log Codes
	const int TAM_RETURN_LICENCE					= 575;		// Reserved licence returned to free pool
	const int TAM_RESERVE_LICENCE					= 576;		// Licence reserved
	const int TAM_CONSUME_LICENCE					= 577;		// Licence permanently consumed (occurs at point of key exchange)
	const int TAM_INSTALL_APP						= 578;		// Root level message code for install process
	const int TAM_DELETE_APP						= 579;		// Root level message code for delete process
	const int TAM_CONTAINER_REGISTER_REQUEST		= 580;		// Container registration request sent to trustonic
	const int TAM_CONTAINER_UNREGISTER_REQUEST		= 581;		// Container unregistration request sent to trustonic
	const int TAM_PROCESS_COMPLETED					= 582;		// TAM process (install or delete) completed

	// Biometric sample added/removed log codes
	const int BIO_SAMPLE_ADDED                      = 583;
	const int BIO_SAMPLE_REMOVED                    = 584;

	// TAM Project Log Codes
	const int TAM_RECEIPT_VALIDATION				= 585;		// Audit record of a receipt validation attempt

	// SCEP
	const int SCEP_CERT_CONFIGURATION_ERROR			= 586;		// SCEP certificate configuration error

	// DC Notification Listener
	const int DC_LISTENER_CESSATION_OF_TRUST		= 587;
	const int DC_LISTENER_TRANSFER_OF_TRUST			= 588;
	const int DC_LISTENER_CHANGE_OF_DETAILS			= 589;

	// Certificate validation
	const int CERTIFICATE_VALIDATED					= 590;

	// SCEP - Part 2
	const int SCEP_CERT_FAILED_OTP_VALIDATION		= 591;		// SCEP failed to validate the supplied challenge OTP
	const int SCEP_CERT_FAILED_TO_ISSUE				= 592;		// SCEP certificate failed to issue
	const int SCEP_CERT_ISSUED						= 593;		// SCEP certificate successfully issued

	// Cancel unactive cards/certs processor log codes
	const int CUCCP_PROCESSJOB                      = 594;
	const int CUCCP_STATISTICS                      = 595;
	const int CUCCP_EXCEPTION                       = 596;

	// Document purge processor log codes
	const int DPP_PROCESSJOB                        = 597;
	const int DPP_STATISTICS                        = 598;
	const int DPP_EXCEPTION                         = 599;

	// Batch LDAP Sync - Part 2
	const int LDAPSYNC_BATCH_PROCESS_ABORTED		= 600;
	const int LDAPSYNC_BATCH_PROCESS_USER			= 601;

	// Unable to generate Server side PIN
	const int SERVER_SIDE_PIN_GENERATION_FAILED		= 602;
	
	// Make MobileSetup Certificate Processor Log Codes
	const int MAKE_MOBILESETUP_CERT_SUBMIT			= 603;
	const int MAKE_MOBILESETUP_CERT_EXCEPTION		= 604;

	// Cancel Expired Cards processor log codes
	const int CECP_PROCESSJOB                       = 605;
	const int CECP_STATISTICS                       = 606;
	const int CECP_EXCEPTION                        = 607;
	const int CECP_CARDCANCELLED                    = 608;

	// Cancel unactive cards/certs processor log codes - Part 2
	const int CUCCP_CARDCANCELLED                   = 609;
	const int CUCCP_CERTREVOKED                     = 610;

	// Document export utility log codes
	const int DOCEXPORT_STARTED                     = 611;
	
	// active devices per person device disabled/cancelled
	const int ACTIVE_DEVICES_PER_PERSON_DEVICE_DISABLED	= 612;
	const int ACTIVE_DEVICES_PER_PERSON_DEVICE_CANCELLED = 613;

	// Additional TAM Project Log Codes
	const int TAM_REGISTER_SPID						= 614;		// SPID registration with Trustonic
	const int TAM_ONBOARDING_TAMAPP_ACTION			= 615;		// TAM Application created, modified or removed via OnBoarding
	const int TAM_ONBOARDING_TAMAPPVERSION_ACTION	= 616;		// TAM Application Version created, modified or removed via OnBoarding
	const int TAM_ONBOARDING_TAMAPPCUSTOMER_ACTION	= 617;		// TAM Application Customer created, modified or removed via OnBoarding

	const int ADDITIONAL_IDENTITY_ADDED				= 618;
	const int ADDITIONAL_IDENTITY_REMOVED			= 619;
	const int ADDITIONAL_IDENTITY_CERT_REVOKED		= 620;

	// Additional TAM Project Log Codes
	const int TAM_ONBOARDING_TRUSTEDAPP_ACTION		= 621;		// Trusted Application created, modified or removed via OnBoarding
	const int TAM_ONBOARDING_TRUSTEDAPP_IMPORT		= 622;		// Trusted Application AXF data imported

	// Licence limit email log codes
	const int LICENCE_LIMIT_WARNING_EMAIL_SENT      = 623;

	// Enroll Identity Agent
	const int ENROLL_IDENTITY_AGENT_START			= 624;		// Start of an enroll identity agent process
	const int ENROLL_IDENTITY_AGENT_ADD_DEVICE		= 625;		// Adding a device during an identity agent enrollment
	const int ENROLL_IDENTITY_AGENT_UPDATE_DEVICE	= 626;		// Updating a device during an identity agent enrollment

	const int CS_CERT_REVOCATIONREQUESTCOMPLETE		= 627;

	// Ts & Cs
	const int TERMS_AND_CONDITIONS_ACCEPTED         = 628;
	
	const int JOB_PROCESSOR_WATCHDOG_EVENT			= 629;

	// Even more derived credential log codes
	const int DERIVEDCREDENTIAL_ARCHIVE_NOT_PRESENT		= 630;
	const int DERIVEDCREDENTIAL_ARCHIVE_CERT_IMPORTED	= 631;

	// Additional log codes for UpdateDevices to cover assignment of a device to a user
	const int UPDATEDEVICES_SUCCESS_ASSIGNED        = 632;
	const int UPDATEDEVICES_ENABLE_ASSIGNED         = 633;
	const int UPDATEDEVICES_ISSUE_ASSIGNED          = 634;

	// More for EnrollIdentityAgent
	const int ENROLL_IDENTITY_AGENT_DEVICE_IN_USE	= 635;
	const int ENROLL_IDENTITY_AGENT_UNKNOWN_DEVICE	= 636;
	const int ENROLL_IDENTITY_AGENT_DEVICE_NOT_ASSIGNED_TO_USER	= 637;
	const int ENROLL_IDENTITY_AGENT_INCORRECT_DEVICE	= 638;

	// logon failures extended
	const int LOGON_FAILURE_DEVICE_REQUIRES_ASSISTED_ACTIVATION = 639;
	
	// Log code used by MyIDMailer
	const int EMAIL_SIGNING_CERTIFICATE_INVALID = 640;
	
	// This log code is used by LogonEx when activation is attempted on a smart card
	// for which there is currently no activation job in the system
	const int LOGON_FAILURE_DEVICE_NOT_ELIGIBLE_FOR_ACTIVATION = 641;

	// User's authentication has been validated OK
	const int AUTHENTICATION_VALIDATION_SUCCESS = 642;

	// EnrollIdentityAgent, specified job is not in the correct state to be collected
	const int ENROLL_IDENTITY_AGENT_JOB_WRONG_STATUS = 643;

	// TAM Project Log Codes
	const int TAM_TDIR_OPERATION_DURATION_EXCEEDED_THRESHOLD = 644;		// A call to Trustonic from MyTAM took longer than the configured "long running" operation threshold

	const int LOGON_DEVICE_NOT_FOUND_FOR_USER = 645;

	const int LDAP_AUTOMATIC_UPDATE_EXLUDED	        = 646;
	const int LDAP_AUTOMATIC_UPDATE                 = 647;

	const int UNLOCKCODE_NOPASSWORDREQUEST			= 648;
	const int UNLOCKCODE_PASSWORDERROR              = 649;
	const int UNLOCKCODE_SOPINERROR					= 650;
	const int UNLOCKCODE_PASSWORDANSWERFAIL         = 651;
	const int UNLOCKCODE_ATTACKLOCKTRIGGERED        = 652;
	const int UNLOCKCODE_CARDOUTOFDATE              = 653;
	const int UNLOCKCODE_CARDDISABLED               = 654;
	
	const int GENERATE_VSC_UNLOCK_PSK				= 655;

	// User's authentication has not been validated
	const int AUTHENTICATION_VALIDATION_FAILURE		= 656;

	const int JOB_MAINTENANCE_PROCESS_RUN			= 657;
	const int GETOBJECTDATA_VIEW_NOT_FOUND			= 658;
	const int GETOBJECTDATA_VIEW_NO_ID				= 659;
	
	const int UNMANAGED_CERTIFICATE_NOT_REVOKED		= 660;
	const int NO_UNMANAGED_CERTIFICATES_AVAILABLE	= 661;
	
	const int BASF_MIGRATION_JOBS_TIDY				= 662;

	// Logon failure due to the certifcate used for logon not being issued (e.g. revoked/suspended )
	const int LOGON_FAILURE_CERTIFICATE_SUSPENDED	= 663;

	const int LDAPSYNC_BATCH_ROLES_REMOVED			= 664;
	const int LDAPSYNC_BATCH_ROLES_ADDED			= 665;

	const int LOGON_FAILURE_USER_DISABLED			= 666;

	const int LOGON_FAILURE_DEVICE_USER_DISABLED	= 667;

	const int LOGON_SUCCESS_LOGON_CODE              = 668;

	const int LOGON_FAILURE_LOGON_CODE				= 669;

	const int CANCEL_CREDENTIAL_COMPLETE			= 670;

	const int LOGON_SUCCESS_AUTH_CODE				= 671;
	const int LOGON_FAILURE_AUTH_CODE				= 672;

	const int DELETECARDSTOCK						= 673;

	const int WEBCONNECTOR_SUSPENDREQUEST			= 674;
	const int WEBCONNECTOR_UNSUSPENDREQUEST			= 675;

	const int CS_SUSPENDREQUESTCOMPLETE				= 676;
	const int CS_UNSUSPENDREQUESTCOMPLETE			= 677;

	const int USER_VALIDATION_FAILURE				= 678;
	const int USER_CARD_VALIDATION_FAILURE			= 679;
	const int CARD_VALIDATION_FAILURE				= 680;

	const int BATCH_ISSUE_SUMMARY					= 681;

	const int CARDPROFILE_VALIDATION_FAILURE		= 682;

	const int LOGON_FAILURE_CERTIFICATE_REVOKED		= 683;
	
	const int ISSUANCE_TOKEN_REPLAY_DETECTED		= 684;

	// DisableExpiredUsersProcessor LogCodes
	const int DEUP_PROCESSJOB						= 685;
	const int DEUP_STATISTICS						= 686;
	const int DEUP_EXCEPTION						= 687;
	const int DEUP_USERDISABLED						= 688;

	// More OnlineUnlock LogCodes
	const int UNLOCKCODE_NO_SECURITY_QUESTIONS		= 689;
	const int UNLOCKCODE_SECURITY_QUESTIONS_LOCKED	= 690;
	const int UNLOCKCODE_INVALID_CHALLENGE			= 691;
	const int UNLOCKCODE_GET_QUESTIONS_SUCCESS		= 692;

	// custom project error codes
	const int ACCREDITATION_CHECK_RUN				= 90001;	 //Othello project
	const int ACCREDITATION_ENDED					= 90002;	 // ..
	const int ONYXSCHEMA_FAILURE					= 90003;
	const int TWICREQUEST_FAILURE					= 90004;
	const int TWICREQUEST_PROCESS					= 90005;
	const int GPOMESSAGECONNECTOR_SENDMESSAGE				= 90006;
	const int GPOMESSAGECONNECTOR_MESSAGEUPDATESTATUS_NOID	= 90007;
	const int GPOMESSAGECONNECTOR_MESSAGEUPDATESTATUS		= 90008;
	const int DEVICE_CANCELLED_AUTO_CANCEL_USER = 90009;	// LMAI vNext
	const int DOCUMENT_AUTO_PURGED = 90010;	// LMAI vNext
	const int SPONSOR_USER_UNIQUEID_REPLACED = 90011;	// LMAI vNext
	const int SPONSOR_USER_LOGONNAME_IN_USE = 90012;	// LMAI vNext

	// generic message indicating a workflow has begun
	const int START_WORKFLOW						= 100000;
	// generic message indicating a workflow has failed to begin initially due to useraccount being disabled MYIDENT-5670
	const int START_WORKFLOW_ERROR					= 100001;
}

namespace StatusMappingCodes
{
	const int Unspecified							= 0;
	const int TooManySuspensions					= -1;
	const int RemovedFromLDAP						= -2;
	const int DisabledInLDAP						= -3;
	const int IssuanceTimeout						= -4;
	const int DeferredIssuanceTimeout				= -5;
	const int OtherDeviceIssued						= -6;
	const int DisabledViaLifeCycleAPI				= -7;
	const int RevokedViaLifeCycleAPI				= -8;
}
