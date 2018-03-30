#pragma once

namespace myid
{
	enum TaskTypeID
	{
		IssueCard							=  1
	  , CancelCard							=  2
	  , UpdateCard							=  3
	  , RequestSoftCertificate				=  4
	  , IssueToken							=  5
	  , BureauRequest						=  6
	  , BureauBatch							=  7
	  , UpdateApplets						=  8
	  , IssueReplacementCard				=  9
	  , XMLExport							= 10
	  , XMLImport							= 11
	  , JobBatch							= 12
	  , UploadDataFile						= 13
	  , RSImportTokens						= 14
//	  , VSImportTokens						= 15
	  , CLImportTokens						= 16
	  , EMVImportTokens						= 17
	  , OATHImportTokens					= 18
	  , VASCOImportTokens					= 19
	  , ActivateDevice						= 20
	  , Adjudication						= 21
	  , HIDImportDevice						= 22
	  , ExternalNotification				= 23
	  , ReplaceSoftCertificates				= 24
	  , DataPurge							= 25
	  , RecoverCertificates					= 26
	  , GenericImportDevices				= 27
	  , PrintPINMailer						= 28
	  , DelayedDeviceRevocation				= 29
	  , OrphanedImages						= 30
	  , ACTIVIDImportTokens					= 31
	  , CardRenewal							= 32
	  , CancelStaleJobs						= 33
	  , RecoverCertMobile					= 34
	  , TPMProcess							= 35
	  , IssueMobileSoftCert					= 36
	  , CertificateRenewal					= 38
	  , JobMaintenanceProcessor				= 39
	  , IssueMachineIdentity				= 40
	  , UnlockCard							= 41
	  , CancelMachineIdentity				= 42
	  , RelationshipManagement				= 43
	  , AdditionalCertRecovery				= 44
	  , AdditionalCertUpdate				= 45
	  , AdditionalCertRemoval				= 46
	  , ExpiredMachineIdentity				= 50
	  , ExpiredCardActivationProcessor		= 51
	  , MigrateCard							= 52
	  , BadgeDisposalProcessor				= 53
	  , TAMProcessor						= 54
	  , ReprovisionCard                     = 55
	  , CancelExpiredCard                   = 56
	  , DocumentPurge                       = 57
      , CancelUnactiveCardsCerts            = 58
	  , MakeMobileSetupCertificate          = 59
      , CredentialSync                      = 60
	  , LockCard							= 61
	  , ResetUnlockCode						= 62
	  , DisableExpiredUsers					= 63
	  , IdemiaImportDevice					= 64
	};
}
