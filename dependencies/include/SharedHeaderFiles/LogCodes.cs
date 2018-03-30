// Repository Location: $Logfile: /Projects/Edefice/EdeficeVx/Utilities/EdeficeCommon/Exceptions/LocalisedException.cpp $
// Last Modification:   $Modtime: 17/09/07 9:15 $
// Repository Revision: $Revision: 3 $
// Check-in:            $Date: 21/09/07 13:47 $

namespace MyId
{
	/// <summary>
	/// This is a *COPY* of LogCodes.h which resides in the same directory.  LogCodes.h is the master file, all new
	/// Additions should be made there first to avoid clashes, and then copied here if required.
	/// </summary>
	public enum LogCodes
	{
		/*
		 Reserved log code range; -10100 to -10199 (inclusive)
		 These log codes are reserved for Cryptas' use
		*/

		CustomAppletRemovedFromDevice			      = -10002, // Custom log codes for Cryptas/BASF applet migration
		CustomAppletAddedToDevice                     = -10001,	//
		LogonSuccess								  = 19,
		LogonFailure								  = 20,
		MISC_INTERNAL_ERROR                           = 66,
		AddActivCardDeviceSuccess					  = 73,
		AddActivCardDeviceFailure					  = 74,
		AddDeviceSuccess							  = 75,
		AddDeviceFailure							  = 76,
		AddGroupsSuccess							  = 77,
		AddGroupsFailure							  = 78,
		AddpersonuseraccountSuccess					  = 79,
		AddpersonuseraccountFailure					  = 80,
		AddRadiusClientsSuccess						  = 81,
		AddRadiusClientsFailure						  = 82,
		AddRadiusConnectionsSuccess					  = 83,
		AddRadiusConnectionsFailure					  = 84,
		AddRadiusServersSuccess						  = 85,
		AddRadiusServersFailure						  = 86,
		AddrasserversSuccess						  = 88,
		AddrasserversFailure						  = 89,
		DeleteGroupsSuccess							  = 90,
		DeleteGroupsFailure							  = 91,
		DeletepeopleUserAccountsSuccess				  = 92,
		DeletepeopleUserAccountsFailure				  = 93,
		DeleteRadiusClientsSuccess					  = 96,
		DeleteRadiusClientsFailure					  = 97,
		DeleteRadiusConnectionsSuccess				  = 98,
		DeleteRadiusConnectionsFailure				  = 99,
		DeleteRadiusServersSuccess					  = 100,
		DeleteRadiusServersFailure					  = 101,
		DeleterasServersSuccess						  = 102,
		DeleterasServersFailure						  = 103,
		ResyncTokenSuccess							  = 104,
		ResyncActivCardFailure						  = 105,
		UpdateDevicesSuccess						  = 106,
		UpdateDevicesFailure						  = 107,
		UpdateGroupsSuccess							  = 108,
		UpdateGroupsFailure							  = 109,
		UpdatepeopleuseraccountsSuccess				  = 110,
		UpdatepeopleuseraccountsFailure				  = 111,
		UpdateRadiusClientsSuccess					  = 112,
		UpdateRadiusClientsFailure					  = 113,
		UpdateRadiusServersSuccess					  = 114,
		UpdateRadiusServersFailure					  = 115,
		UpdateRASServersSuccess						  = 116,
		UpdateRASServersFailure						  = 117,
		BOLXMLLoadFailure							  = 120,
		BOLInvalidTaskNumber						  = 123,
		BOLEmptyInputParameter						  = 125,
		BOLCaughtException							  = 126,
		BOLUnhandledException						  = 127,
		BOLUnenvelopingError						  = 128,
		BOLInvalidmessagenumber						  = 129,
		ImportTokenAuditSuccess						  = 130,
		ImportTokenAuditFailed						  = 131,
		ImportTokenAuditNoPrivilege					  = 132,
		ImportTokenAuditOk							  = 133,
		ImportTokenAuditDuplicate					  = 134,
		ImportTokenAuditIncorrect					  = 135,
		NTLogonFailure								  = 136,
		CSXMLLoadFailure							  = 137,
		CSInvalidTaskNumber							  = 138,
		CSEmptyInputParameter						  = 139,
		CSCcaughtException							  = 140,
		CSUnhandledException						  = 141,
		CSInvalidMessageNumber						  = 142,
		CSUnenvelopingError							  = 143,
		CSCCocreateInstance							  = 144,
		AddDeviceDeviceextant						  = 147,
		AddDeviceClearDeviceExtant					  = 148,
		AddDeviceClearSuccess						  = 149,
		AddPersonUserAccountUserProfile			      = 150,
		UpdatePeopleUserAccountsSelfEdit			  = 151,
		UpdatePeopleUserAccountsUserProfile			  = 152,
		UpdateDevicesSelfEdit						  = 153,
		UpdatepolicySuccess							  = 154,
		AddPolicySuccess							  = 155,
		DeletePeopleUserAccountsSelfDelete			  = 156,
		UpdateDevicesUserProfile					  = 157,
		DeletePeopleUserAccountsUserProfile			  = 158,
		GetPUCUserProfile							  = 159,
		GetPUCTokenUserProfile						  = 160,
		AddJobSuccess								  = 161,
		AddJobFailed								  = 162,
		UpdateJobSuccess							  = 163,
		UpdateJobFailed								  = 164,
		FinishJobSuccess							  = 165,
		LogonSuccessUsernameSecurityPhrases			  = 166,
		LogonSuccessDeviceSecurityPhrases			  = 167,
		LogonFailureUsernameSecurityPhrases			  = 168,
		LogonFailureDeviceSecurityPhrases			  = 169,
		LogonSuccessGuest							  = 170,
		AtivateUserAccountSuccessProfile			  = 171,
		ActivateUserAccountFailure					  = 172,
		ActivateUserAccountSuccess					  = 173,
		EmergencyPasswordClear						  = 174,
		EmergencyPasswordSet						  = 175,
		EmergencyPasswordEnable						  = 176,
		RegisterCASuccess							  = 177,
		CSCertificateCollection						  = 178,
		CSSubmitCAFailed							  = 179,
		CSUnexpectedRecordCount						  = 180,
		CSUnexpectedRecordCountIgnore				  = 181,
		CSRevokeAllCertsbyDevice					  = 182,
		CSRevokeAllCertsByDeviceNoRecords			  = 183,
		CSRevocationRequestComplete					  = 184,
		UpdateCardLayoutSuccess						  = 185,
		RemoveCardLayoutSuccess						  = 186,
		RemoveTemplateSuccess						  = 187,
		UpdateTemplateSuccess						  = 188,
		AddTemplateSuccess							  = 189,
		GetCodesFailure								  = 190,
		EntrustInvalidDN							  = 191,
		EntrustInvalidTemplate						  = 192,
		EntrustInvalidStatus						  = 193,
		GetSOPINSuccess								  = 194,
		GetUnlockCodeSuccess						  = 195,
		GenerateUnlockCodesSuccess					  = 196,
		GetNextUnusedUnlockCodeSuccess				  = 197,
		GetActivCardUnlockCodeSuccess				  = 198,
		LogonFailureDeviceNotEnabled				  = 199,
		AddAppletSuccess							  = 201,
		UpdateAppletSuccess							  = 202,
		UpdateAppletFailed							  = 203,
		AppletAddedToDevice							  = 204,
		AppletRemovedFromDevice						  = 205,
		UpdatedDeviceKeyset							  = 206,
		InvalidTemplate								  = 207,
		GetUnlockCodeGeneric					      = 208,
		LogonFailInsufficientPrivileges	          	  = 209,
		UpdateSecurityQuestions				       	  = 210,
		AddCardProfile						          = 211,
		UpdateCardProfile					          = 212,
		RemoveCardProfile					          = 213,
		UpdateConfiguration					      	  = 214,
		UpdateCA								      = 215,
		SetPIN								          = 216,
		LDAPPushFailed						      	  = 217,
		WebConnectorRequest					      	  = 218,
		WebConnectorResponse					      = 219,
		WebConnectorRevRequest				          = 220,
		WebConnectorRevResponse				      	  = 221,
		SetPassword							          = 222,
		RecoveredOwnKeys					          = 223,
		RecoveredAnotherUsersKeys			          = 224,
		BureauJobBatchRequestEmpty					  = 225,
		BureauJobBatchRequestCreated				  = 226,
		BureauJobBatchBatchCreated				  	  = 227,
		BureauJobBatchCaughtException				  = 228,
		BureauJobBatchUnhandledException			  = 229,
		ValidateJobSuccess							  = 230,
		ECSRVConnectorRequest						  = 231,
		ECSRVConnectorResponse						  = 232,
		ECSRVConnectorRevRequest					  = 233,
		ECSRVConnectorRevResponse					  = 234,
		ECSRVConnectorPolicyUpdate					  = 235,
		BureauSRVCaughtException				   	  = 236,
		BureauSRVUnhandledException					  = 237,
		BureauSRVItemUpdate							  = 238,
		BureauSRVBatchItemsUpdate					  = 239,
		BureauSRVEmptyRequestUpdate					  = 240,
		BureauSRVBureauResponse						  = 241,
		ECSRVPolicyUpdate							  = 242,
		ECSRVRenewal								  = 243,
		ECSRVUnexpected								  = 244,
		DeviceGlobalPINSet							  = 245,
		EntrustLibraryFailure						  = 246,
		EntrustFailure								  = 247,
		JobAutoUpdate								  = 248,
		LogonSuccessAutoEnrol					      = 249,
		LogonFailureDeviceAutoEnrol					  = 250,
		CSFailedCreateOU							  = 251,
		BaltimoreCertRequested						  = 252,
		BaltimoreCertReqCompleted					  = 253,
		BaltimoreCertRevRequested					  = 254,
		BaltimoreCertRevCompleted					  = 255,
		UpdateLicence								  = 256,
		BureauSRVStockChange						  = 257,
		ConfigurationError							  = 258,
		BureauSRVItemUpdateFinished					  = 259,
		ECSVRConnectorSuspendRequest			      = 260,
		ECSVRConnectorSuspendResponse				  = 261,
		ECSVRConnectorUnsuspendRequest				  = 262,
		ECSVRConnectorUnsuspendResponse				  = 263,
		CertificateRevocationInitiated				  = 264,
		CertificateSuspensionInitiated				  = 265,
		CertificateUnsuspensionInitiated			  = 266,
		CertificateRequestInitiated					  = 267,
		DeviceEnable								  = 268,
		DeviceDisable								  = 269,
		LogonFailureCertificateValidation			  = 270,
		CertificateValidationFailure				  = 271,
		BOLWinMagicFailedLogoff						  = 272,
		UpdateAuditItems							  = 273,
		UpdateUserProfileReport						  = 274,
		EDiskEncryptorCaughtException				  = 275,
		EDiskEncryptorUnhandledException			  = 276,
		EXMLExportError							 	  = 277,
		StartAsynchronousJob						  = 278,
		TransferFileOut								  = 279,
		EXMLExportProcess							  = 280,
		LDAPDeleteUserFailed						  = 281,
		XMLImportProcess							  = 282,
		XMLImporAddUser								  = 283,
		XMLImportAddGroup							  = 284,
		XMLImportCardRequest						  = 285,
		XMLImportError								  = 286,
		TransferFileIn								  = 287,
		DiscEncryptorFailedConnect					  = 288,
		LogBatchJobCardProfileSuccess				  = 289,
		AddGroupLDAPFailure							  = 290,
		GetAthenaUnlockCodeSuccess					  = 291,
		ValidateEnvelopeSuccess	 		 			  = 292,
		AddCardStockSuccess							  = 293,
		UpdateCardStockSuccess						  = 294,
		UpdateJobFailResubBureauRequest				  = 295,
		UpdateJobResubmitBureauRequest				  = 296,
		UpdateJobFailBureauRequest					  = 297,
		BOLUpdateCertificate						  = 298,
		UpdateTHDeviceProfileSuccess				  = 299,
		GetExtServerCredentialsSuccess				  = 300,
		RemovePersonFailedCancelPSM					  = 301,
		DBImportSRVCaughtException					  = 302,
		DBImportSRVUnhandledException				  = 303,
		DBImportSRVJobCreated						  = 304,
		LogonExDeviceCertsUpdated					  = 305,
		SetDeviceSectorPresetsSuccess				  = 306,
		SetOpenPlatformKeysSuccess					  = 307,
		SetACDeviceProfileSuccess					  = 308,
		DeleteACDeviceProfileSuccess				  = 309,
		ImportTokensSuccess							  = 310,
		SetSelectOptionsSuccess						  = 311,
		ExportDevicesSDSSuccess						  = 312,
		ExportDevicesDevicesSuccess					  = 313,
		AddJobJobSupersededSuccess					  = 314,
		LDAPSyncUserDeleted							  = 315,
		LDAPSyncUserUpdated							  = 316,
		BureauJobBatchProcess						  = 317,
		EDSLogCodeHandledException					  = 318,
		EDSLogCodeUnhandledException				  = 319,
		LDAPSyncBatchProcess						  = 320,
		LDAPSyncUserDisabled						  = 321,
		MessageConnectorException					  = 322,
		EMessageserverError							  = 323,
		MessageBatchError							  = 324,
		nvdfidsServiceStatus						  = 325,
		nvdfidsSyncFailure							  = 326,
		BOLUpdateDeviceProfile						  = 327,
		SetmifarekeysSuccess						  = 328,
		UpdateJobResetBureauRequest					  = 329,
		GetSchlumbergerUnlockCodeSuccess			  = 330,
		DotCardStatusUpdate							  = 331,
		DotExchCardStatusUpdate						  = 332,
		MessageBatch								  = 333,
		TCNEnforcerException						  = 334,
		RequestMessageSent							  = 335,
		DotExchForeignCardStatusUpdate				  = 336,
		TCNNotified_dl_issuingnationCardIssued 		  = 337,
		DotCardStatusUpdateException			 	  = 338,
		WebServiceCardRequest						  = 339,
		TCNCardException							  = 340,
		TCNCardUpdateDeviceState					  = 341,
		TCNCardfindUserDeviceFailed				 	  = 342,
		TCNCardprejobcreationFailed					  = 343,
		BOLEventsWarningOrError					  	  = 344,
		UpdateDirectoriesSuccess					  = 345,
		LogonFailureExternalFailure				 	  = 346,
		AddGroupFromOUSuccess						  = 347,
		PIVAuditWriteContainer						  = 348,
		EmailFailure								  = 349,
		BatchRequestCardImportUserFailure			  = 350,
		GetGemplusUnlockCodeSuccess					  = 351,
		AddApplication								  = 352,
		RemoveApplication							  = 353,
		ImportTokensProcess							  = 354,
		ImportTokensFailed							  = 355,
		PIVAuditRemoveContainer						  = 356,
		GetAETUnlockCodeSuccess						  = 357,
		AddProtectedKey								  = 358,
		TransferFileService							  = 359,
		XMLImportDisableUser						  = 360,
		XMLImportEnableUser							  = 361,
		XMLImportRemoveUser							  = 362,
		ProcessFileImportSuccess					  = 363,
		DBImportSRVDdataSelection					  = 364,
		DBImportSRVMissingData						  = 365,
		DBImportSRVDataCleanup						  = 366,
		DataImportProcessStart						  = 367,
		DataImportProcessThread						  = 368,
		DataImportProcess							  = 369,
		DataImportProcessLaunch						  = 370,
		DBImportSRVDataSelectionError				  = 371,
		DataMigrationError							  = 372,
		AuthServerSynchronisationStart				  = 373,
		AuthServerSynchronisationFailed				  = 374,
		AuthServerRemoveUser_failed					  = 375,
		ExternalSystemsAdd							  = 376,
		ExternalSystemsUpdate						  = 377,
		ExternalSystemsDelete						  = 378,
		AuthTypesAdd								  = 379,
		AuthTypesEdit								  = 380,
		DeviceIssued								  = 381,
		DeviceCancelled								  = 382,
		LogonDeviceSuccess							  = 383,
		LogonDeviceFailure							  = 384,
		RemovedDeviceKeyset							  = 385,
		AddDeviceBatch								  = 386,
		LogoffUser									  = 387,
		UserExportKey								  = 388,
		ScheduledJobProcessed						  = 389,
		JobProcessorCreationError					  = 390,
		ImportVascoTokens							  = 391,
		ImportEmvTokens								  = 392,
		ImportOathTokens							  = 393,
		BiometricAdjudication                         = 394,
		BiometricAdjudicationResponseReceived         = 395,
		BiometricAdjudicationFailed                   = 396,
		BiometricAdjudicationCancelled                = 397,
		BureauSRVJobUpdateError						  = 398,
		ImportRSATokens								  = 399,
		AmagConnectorAudit							  = 400,
		TwicCardsDelivered							  = 401,
		GEConnectorAudit							  = 402,
		TwicReplacementCardRequested				  = 403,
		TwicCardTransfer							  = 404,
		GEFCConnectorAudit							  = 405,
		TwicCardActivate							  = 406,
		UFConnectorAudit							  = 407,
		OnGuardConnectorAudit                         = 408,
		LDAPPublishAudit							  = 409,
		DTLogonProviderError						  = 410,
		CBConnectorAudit							  = 411,
		TLInstallDateCalculated						  = 421,
		TLLastActivityCalculated					  = 422,
		TLDateTamperClockSetback					  = 423,
		TLDateTamperPriorToSystemInstall			  = 424,
		TLInstallDateUnknown						  = 425,
		AuthTypesDelete								  = 426,
		LogonSuccessLogonProvider					  = 427,
		LogonFailureLogonProvider					  = 428,
		ExternalNotificationFailed                    = 429,
		ExternalNotificationCompletelyFailed          = 430,
		ExternalNotificationError                     = 431,
		UserOTP										  = 432,
		UserDataRetrieved							  = 433,
		ValidateQuestionsValid						  = 434,
		ValidateQuestionsInvalid					  = 435,
		ValidateQuestionsLocked						  = 436,
		ValidateQuestionsInvalidParam				  = 437,
		ValidateQuestionsLockedParam				  = 438,
		IncomingMessageError                          = 439,
		PurgedUserData                                = 442,
		LogonCode									  = 443,
		BureauJobBatchNoticket						  = 444,
		BureauJobBatchExecuted						  = 445,
		BureauSRVHeartbeat							  = 446,
		NotificationSuppressed						  = 447,
		OrphanedImageFileDeleted					  = 448,
		OrphanedImagesDeleteError					  = 449,
		ExternalCertificateManagement				  = 450,
		XMLImportCardUpdate							  = 451,
		ImportActividTokens							  = 452,
		BureauPrepareData							  = 453,
		SupersededCertificatePolicy					  = 454,
		ValidateEnvelopeExSuccess					  = 455,
		AddJobSuccessNoTarget						  = 456,
		AddJobJobSupersededSuccessNoTarget			  = 457,
		JobServerThreadFailed						  = 458,
		RecoveredKeys								  = 459,
		XMLImportCertificate						  = 460,
		RBACViolation								  = 461,
		AppletExtradited							  = 462,
		AddDeviceBatchNoJob							  = 463,
		AssetAddedOrUpdated							  = 464,
		AssetDNSAlreadyExists						  = 465,
		AssetDatabaseRecordNotFound					  = 466,
		AssetIDNotFound								  = 467,
		BiometricAdjudicationNoBiosamples			  = 468,
		ExternalSystemFailure						  = 469,
		CreatedVirtualSmartCard						  = 470,
		DeletedVirtualSmartCard						  = 471,
		AddExternalNotification						  = 472,
		DeleteExternalNotification					  = 473,
		UpdateExternalNotification					  = 474,
		AddEmailTemplates							  = 475,
		UpdateEmailTemplates						  = 476,
		LogonSuccessBiometric						  = 477,
		LogonFailureBiometric						  = 478,
		IdentifyBioLogonSuitable					  = 479,
		IdentifyBioLogonUnsuitable					  = 480,
		IdentifyBioLogonNotFound					  = 481,
		IdentifyBioLogonMatched						  = 482,
		IdentifyBioLogonNotMatched					  = 483,
		ProcessFileImport							  = 484,
		AddListenersAdd								  = 485,
		AddListenersUpdate							  = 486,
		UpdateListenersAdd							  = 487,
		UpdateListenersUpdate						  = 488,
		DeleteListeners								  = 489,
		DeviceProcessStatusAdd						  = 490,
		DeviceProcessStatusUpdate					  = 491,
		LDAPDeletionSync							  = 492,
		IdentifyBiographicLogonNotFound				  = 493,
		IdentifyBiographicLogonMatched				  = 494,
		DeviceIssuanceNotAllowed					  = 495,
		DeviceIssuanceSystemNotConfigured			  = 496,
		UpdateConfigurationDeviceTypeOverride		  = 497,
		UserLogonNameChanging                         = 498,
		UserLogonNameChanged                          = 499,
		UpdateGroupsMoveSuccess						  = 500,
		UpdateGroupsMoveFailure						  = 501,
		UpdateGroupsMoveUsersSuccess				  = 502,
		UpdateGroupsMoveUsersFailure				  = 503,
		LogOffSelf									  = 504,
		JobBasedOTPRequestOTPSuccess				  = 505,
		JobBasedOTPValidateOTPSuccess				  = 506,
		GetLogonMessagesSuccess						  = 507,
		GenericUpdateJobSuccess						  = 508,
		NotificationListenerError                     = 509,
		NotificationListenerSuccess                   = 510,
		CertificateRenewalUserSuspended    			  = 511,
		ResendInProgressNotificationSuccess	  		  = 512,
		ResendCompletedNotificationSuccess	  		  = 513,
		DTNotificationsPlugInError                    = 514,
		CertInstancesCertForDeviceEnabled			  = 515,
		CertInstancesCertForDeviceDisabled			  = 516,
		AssetCancelled								  = 517,
		AddJobDevice								  = 518,
		ValidateJobDeviceSuccess					  = 519,
		UpdateJobDeviceSuccess					  	  = 520,
		UserRelationshipAdded						  = 521,
		UserRelationshipDeleted						  = 522,
		UserRelationshipUpdatedStatus				  = 523,
		UserRelationshipUpdatedOther				  = 524,
		LicenceApproachingLimit						  = 525,
		LicenceExceedsLimit						  	  = 526,
		LicenceReachedLimit						  	  = 527,
		WorkflowEngineOperation                       = 528,
		WorkflowEngineOperationError                  = 529,
		UserDNChanged							      = 530,
		CertificateRemovalRequired           		  = 531,
		UserRelationshipUpdatedStatusIA				  = 532,
		UserRelationshipDeletedIA					  = 533,
		DervivedCredentialCheckSuccess				  = 534,
		DervivedCredentialCheckFailed				  = 535,
		PKIAuthCheckSuccess							  = 536,
		PKIAuthCheckFailed							  = 537,
		AuthenticatePersonComplete			 		  = 538,
		ECSRVAutoRestart						      = 539,
		ECSRVProcessingFailure				          = 540,
		CertificateRenewalProcessorStarted            = 541,
		CertificateRenewalProcessorCompleted          = 542,
		CertificateRenewalProcessorError              = 543,
		LogonFailurePassphraseLockedOut               = 544,
		ECAP_RevokedCertificate                       = 545,	// -
		ECAP_Started                                  = 546,	// --
		ECAP_Statistics                               = 547,	// --- ECAP =
		ECAP_Success                                  = 548,	// ---  Expired Card Activation Processor
		ECAP_Failure                                  = 549,	// --
		ECAP_Exception                                = 550,	// -

		// Expired Machine Identity Processor log codes
		EMIP_CANCELLED							      = 551,
		EMIP_ISSUED                                   = 552,
		EMIP_EXPIRED                                  = 553,
		EMIP_FAILURE                                  = 554,
		EMIP_EXCEPTION                                = 555,
		EMIP_PROCESSJOB                               = 556,

		// derived credential log codes
		DerviedCredentialWhitelistFailure			  = 557,
		DerivedCredentialWhitelistSuccess	 		  = 558,
		DerivedCredentialBioCaptured				  = 559,
		DerivedCredentialUserAdded					  = 560,
		DerivedCredentialUserExists					  = 561,

		BDP_LostDevice                                = 562,	// -
		BDP_Started                                   = 563,	// --
		BDP_Statistics                                = 564,	// --- BDP =
		BDP_Success                                   = 565,	// ---  Badge Disposal Processor
		BDP_Failure                                   = 566,	// --
		BDP_Exception                                 = 567,	// -

		DerivedCredentialUserDisabled				  = 568,

		// TAM Project Log Codes
		TAM_ContainerRegisterNotification             = 569,
		TAM_ContainerUnregisterNotification           = 570,

		LicenceLimit								  = 571,

		DerivedCredentialFacialDataError			  = 572,
		DerivedCredentialDeviceLicenceExceeded     	  = 573,
		DerivedCredentialUserLicenceExceeded 	  	  = 574,

		// TAM Project Log Codes
		TAM_ReturnLicence							  = 575,		// Reserved licence returned to free pool
		TAM_ReserveLicence							  = 576,		// Licence reserved
		TAM_ConsumeLicence							  = 577,		// Licence permanently consumed (occurs at point of key exchange)
		TAM_InstallApp								  = 578,		// Root level message code for install process
		TAM_DeleteApp								  = 579,		// Root level message code for delete process
		TAM_ContainerRegisterRequest				  = 580,		// Container registration request sent to trustonic
		TAM_ContainerUnregisterRequest  			  = 581,		// Container unregistration request sent to trustonic
		TAM_ProcessCompleted						  = 582,		// TAM process (install or delete) completed

		// Biometric sample added/removed log codes
		BioSampleAdded                                = 583,
		BioSampleRemoved                              = 584,

		// TAM Project Log Codes
		TAM_ReceiptValidation       				  = 585,		// Audit record of a receipt validation attempt

		// SCEP
        SCEP_CERT_CONFIGURATION_ERROR		          = 586,		// SCEP certificate configuration error

        // DC Notification Listener
        DC_LISTENER_CESSATION_OF_TRUST		          = 587,
        DC_LISTENER_TRANSFER_OF_TRUST			      = 588,
        DC_LISTENER_CHANGE_OF_DETAILS			      = 589,

    	// Certificate validation
	    CERTIFICATE_VALIDATED					      = 590,

        // SCEP - Part 2
        SCEP_CERT_FAILED_OTP_VALIDATION		          = 591,		// SCEP failed to validate the supplied challenge OTP
        SCEP_CERT_FAILED_TO_ISSUE				      = 592,		// SCEP certificate failed to issue
        SCEP_CERT_ISSUED						      = 593,		// SCEP certificate successfully issued

		// Cancel unactive cards/certs processor log codes
		CUCCP_PROCESSJOB                              = 594,
		CUCCP_STATISTICS                              = 595,
		CUCCP_EXCEPTION                               = 596,

		// Document purge processor log codes
		DPP_PROCESSJOB                                = 597,
		DPP_STATISTICS                                = 598,
		DPP_EXCEPTION                                 = 599,

		// Batch LDAP SYNC
		LDAPSYNC_BATCH_PROCESS_ABORTED				  = 600,
		LDAPSYNC_BATCH_PROCESS_USER					  = 601,

		// Unable to generate Server side PIN
		SERVER_SIDE_PIN_GENERATION_FAILED			  = 602,

		// Make MobileSetup Certificate Processor Log Codes
		MakeMobileSetupCertSumbit                     = 603,
		MakeMobileSetupCertException                  = 604,

		// Cancel Expired Cards processor log codes
		CECP_PROCESSJOB                      		  = 605,
		CECP_STATISTICS                       		  = 606,
		CECP_EXCEPTION                        		  = 607,
		CECP_CARDCANCELLED                    		  = 608,

		// Cancel unactive cards/certs processor log codes - Part 2
		CUCCP_CARDCANCELLED                   		  = 609,
		CUCCP_CERTREVOKED                     		  = 610,

		// Document export utility log codes
		DOCEXPORT_STARTED                     		  = 611,

		// active devices per person device disabled/cancelled
		ACTIVE_DEVICES_PER_PERSON_DEVICE_DISABLED	  = 612,
		ACTIVE_DEVICES_PER_PERSON_DEVICE_CANCELLED 	  = 613,

        // Additional TAM Project Log Codes
    	TAM_REGISTER_SPID                             = 614,
        TAM_ONBOARDING_TAMAPP_ACTION                  = 615,
        TAM_ONBOARDING_TAMAPPVERSION_ACTION           = 616,
        TAM_ONBOARDING_TAMAPPCUSTOMER_ACTION          = 617,

		// additional identities
		ADDITIONAL_IDENTITY_ADDED					  = 618,
		ADDITIONAL_IDENTITY_REMOVED					  = 619,
		ADDITIONAL_IDENTITY_CERT_REVOKED			  = 620,

        // Additional TAM Project Log Codes
    	TAM_ONBOARDING_TRUSTEDAPP_ACTION              = 621,
        TAM_ONBOARDING_TRUSTEDAPP_IMPORT              = 622,

	    LICENCE_LIMIT_WARNING_EMAIL_SENT              = 623,

        // Enroll Identity Agent
        ENROLL_IDENTITY_AGENT_START                   = 624,
        ENROLL_IDENTITY_AGENT_ADD_DEVICE              = 625,
        ENROLL_IDENTITY_AGENT_UPDATE_DEVICE           = 626,

		CS_CERT_REVOCATIONREQUESTCOMPLETE			  = 627,

        // Ts & Cs
        TERMS_AND_CONDITIONS_ACCEPTED                 = 628,
		
		JOB_PROCESSOR_WATCHDOG_EVENT                  = 629,

        // More Derived credential log codes
	    DERIVEDCREDENTIAL_ARCHIVE_NOT_PRESENT         = 630,
	    DERIVEDCREDENTIAL_ARCHIVE_CERT_IMPORTED	      = 631,
		
		// Additional log codes for UpdateDevices to cover assignment of a device to a user
		UPDATEDEVICES_SUCCESS_ASSIGNED                = 632,
		UPDATEDEVICES_ENABLE_ASSIGNED                 = 633,
		UPDATEDEVICES_ISSUE_ASSIGNED                  = 634,

	    // More for EnrollIdentityAgent
	    ENROLL_IDENTITY_AGENT_DEVICE_IN_USE           = 635,
	    ENROLL_IDENTITY_AGENT_UNKNOWN_DEVICE          = 636,
	    ENROLL_IDENTITY_AGENT_DEVICE_NOT_ASSIGNED_TO_USER = 637,
	    ENROLL_IDENTITY_AGENT_INCORRECT_DEVICE        = 638,

		// logon failures extended
		LOGON_FAILURE_DEVICE_REQUIRES_ASSISTED_ACTIVATION = 639,
		
		// Log code used by MyIDMailer
		EMAIL_SIGNING_CERTIFICATE_INVALID = 640,

		// This log code is used by LogonEx when activation is attempted on a smart card
		// for which there is currently no activation job in the system
		LOGON_FAILURE_DEVICE_NOT_ELIGIBLE_FOR_ACTIVATION = 641,
        
	    // User's authentication has been validated OK
	    AUTHENTICATION_VALIDATION_SUCCESS = 642,
	
        // EnrollIdentityAgent, specified job is not in the correct state to be collected
	    ENROLL_IDENTITY_AGENT_JOB_WRONG_STATUS = 643,

		// TAM Project Log Codes
		TAM_TDIR_OPERATION_DURATION_EXCEEDED_THRESHOLD = 644,		// A call to Trustonic from MyTAM took longer than the configured "long running" operation threshold
		
		LOGON_DEVICE_NOT_FOUND_FOR_USER = 645,
		
		LDAP_AUTOMATIC_UPDATE_EXLUDED                 = 646,
		LDAP_AUTOMATIC_UPDATE                         = 647,
		
		UNLOCKCODE_NOPASSWORDREQUEST                  = 648,
		UNLOCKCODE_PASSWORDERROR                      = 649,
		UNLOCKCODE_SOPINERROR                         = 650,
		UNLOCKCODE_PASSWORDANSWERFAIL                 = 651,
		UNLOCKCODE_ATTACKLOCKTRIGGERED                = 652,
        UNLOCKCODE_CARDOUTOFDATE                      = 653,
        UNLOCKCODE_CARDDISABLED                       = 654,

        // EVSC Unlock Code Log code
        GENERATE_VSC_UNLOCK_PSK                       = 655,

		// User's authentication has not been validated
		AUTHENTICATION_VALIDATION_FAILURE             = 656,
		
		// eJobMaintenanceProcessor
		JOB_MAINTENANCE_PROCESS_RUN                   = 657,
		
		GETOBJECTDATA_VIEW_NOT_FOUND				  = 658,
		GETOBJECTDATA_VIEW_NO_ID					  = 659,

		UNMANAGED_CERTIFICATE_NOT_REVOKED			  = 660,
		NO_UNMANAGED_CERTIFICATES_AVAILABLE			  = 661,
		BASF_MIGRATION_JOBS_TIDY					  = 662,
		
		LOGON_FAILURE_CERTIFICATE_SUSPENDED			  = 663,
		LDAPSYNC_BATCH_ROLES_REMOVED                  = 664,
		LDAPSYNC_BATCH_ROLES_ADDED                    = 665,
		
		LOGON_FAILURE_USER_DISABLED					  = 666,

		LOGON_FAILURE_DEVICE_USER_DISABLED			  = 667,
		
		LOGON_SUCCESS_LOGON_CODE                      = 668,
		
		LOGON_FAILURE_LOGON_CODE					  = 669,

        CANCEL_CREDENTIAL_COMPLETE			          = 670,

        LOGON_SUCCESS_AUTH_CODE                       = 671,
        LOGON_FAILURE_AUTH_CODE                       = 672,
		DELETECARDSTOCK                               = 673,

		WEBCONNECTOR_SUSPENDREQUEST					  = 674,
		WEBCONNECTOR_UNSUSPENDREQUEST				  = 675,

        CS_SUSPENDREQUESTCOMPLETE                     = 676,
        CS_UNSUSPENDREQUESTCOMPLETE                   = 677,		
		
		USER_VALIDATION_FAILURE						  = 678,
		USER_CARD_VALIDATION_FAILURE				  = 679,
		CARD_VALIDATION_FAILURE						  = 680,

		BATCH_ISSUE_SUMMARY							  = 681,		

        CARDPROFILE_VALIDATION_FAILURE                = 682,
		
		LOGON_FAILURE_CERTIFICATE_REVOKED			  = 683,
		
		ISSUANCE_TOKEN_REPLAY_DETECTED				  = 684,

        // DisableExpiredUsersProcessor LogCodes
	    DEUP_PROCESSJOB						          = 685,
	    DEUP_STATISTICS						          = 686,
	    DEUP_EXCEPTION						          = 687,
	    DEUP_USERDISABLED						      = 688,

		// More OnlineUnlock LogCodes
		UNLOCKCODE_NO_SECURITY_QUESTIONS			  = 689,
		UNLOCKCODE_SECURITY_QUESTIONS_LOCKED		  = 690,
		UNLOCKCODE_INVALID_CHALLENGE				  = 691,
		UNLOCKCODE_GET_QUESTIONS_SUCCESS			  = 692,
		
		// custom project error codes
		AccreditationCheckRun                         = 90001,
		AccreditationEnded                            = 90002,
		OnyxSchemaFailure                             = 90003,
		TwicRequestFailure							  = 90004,
		twicRequestProcess							  = 90005,
		GPOMessageConnectorSendMessage				  = 90006,
		GPOMessageConnectorMessageUpdateStatusNoID	  = 90007,
		GPOMessageConnectorMessageUpdateStatus		  = 90008,
	    DEVICE_CANCELLED_AUTO_CANCEL_USER             = 90009,	// LMAI vNext
	    DOCUMENT_AUTO_PURGED                          = 90010,	// LMAI vNext
	    SPONSOR_USER_UNIQUEID_REPLACED                = 90011,	// LMAI vNext
	    SPONSOR_USER_LOGONNAME_IN_USE                 = 90012,	// LMAI vNext

		StartWorkflow								  = 100000,
        // generic message indicating a workflow has failed to begin initially due to useraccount being disabled MYIDENT-5670
	    START_WORKFLOW_ERROR					      = 100001
	}

	public enum StatusMappingCodes
	{
		Unspecified                            = 0,
		TooManySuspensions                     = -1,
		RemovedFromLDAP                        = -2,
		DisabledInLDAP                         = -3,
		IssuanceTimeout                        = -4,
		DeferredIssuanceTimeout                = -5,
		OtherDeviceIssued                      = -6,
		DisabledViaLifeCycleAPI                = -7,
		RevokedViaLifeCycleAPI                 = -8
	}
}
