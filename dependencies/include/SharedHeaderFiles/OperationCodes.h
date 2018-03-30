#pragma once

// NOTE to Developer: When editing this file it is important to consider that some of the entries may only
// be used in certain branches of MyID, so please **do not remove** them if they are not referenced in the branch
// that you are working on.

/// Operation codes
namespace OPCODES
{
	const int COMPONENTS				= -2;
	const int MESSAGING					= -21;

	const int BUREAU					= -4;
	const int JOBBATCH					= -41;
	const int BUREAUSRV					= -42;

	const int PKI						= -5;
	const int CERTIFICATESRV			= -51;
	const int CERTIFICATE_SERVICE		= -510;
	const int CERTIFICATE_POLICY		= -511;
	const int CERTIFICATE_RENEWAL		= -512;

	const int BALTIMOREARM				= -52;
	const int BALTIMOREARM_REQ			= -520;
	const int BALTIMOREARM_REV			= -521;

	const int CSAuditOperationID		= -53;

	const int IMPORT_EXPORT				= -6;
	const int XML_EXPORT				= -61;
	const int XML_IMPORT				= -62;
	const int XML_IMPORT_UPDATE_CARD	= -620;
	const int XML_IMPORT_USER_ADD		= -621;
	const int XML_IMPORT_USER_UPDATE	= -622;
	const int XML_IMPORT_USER_ENABLE	= -623;
	const int XML_IMPORT_USER_DISABLE	= -624;
	const int XML_IMPORT_USER_REMOVE	= -625;
	const int XML_IMPORT_REVOKE_CERT	= -626;
	const int XML_IMPORT_CANCEL_DEVICE	= -627;
	const int XML_IMPORT_CANCEL_JOB		= -628;
	const int XML_IMPORT_REQUEST_CARD	= -629;
	const int DATABASE_IMPORT			= -63;
	const int WEBSERVICE_IMPORT			= -64;
	const int TOKEN_IMPORT				= -65;
	const int TWICREQUEST				= -66;

	const int BATCH_PROCESSES			= -7;
	const int BATCH_LDAPSYNC			= -71;
	const int BATCH_DOTCARDSTATUSUPDATE	= -72;
	const int BATCH_JOBPROCESSOR		= -73;
	const int BATCH_TAM					= -74;
	const int BATCH_TAM_INSTALL			= -740;
	const int BATCH_TAM_DELETE			= -741;

	const int BOLEVENTLISTENER			= -8;
	const int AMAGLISTENER				= -81;
	const int TWICLISTENER				= -82;
	const int GELISTENER				= -83;	
	const int GEFCLISTENER				= -84;
	const int UFLISTENER				= -85;
	const int ONGUARDLISTENER			= -86;
	const int WORKFLOWENGINE			= -88;
	const int CBLISTENER				= -89;

	const int SCEP_REQUEST				= -90;
	
	const int ENROLL_IDENTITY_AGENT		= -91;

	const int FULLACCESS_TO_MANAGERLISTS= 10000;	///< Intelligent fields - access to this operation allows selection of any item in a Manager-controlled selectlist
	const int GETAUDIT_FULL				= 10001;	///< is this operator allowed to view any audit details
	const int GETAUDIT_SINGLEUSER		= 10002;	///< is this operator allowed to view audits for a single user within his scope?
};
