MessageIdTypedef=DWORD

SeverityNames=(Success=0x0:STATUS_SEVERITY_SUCCESS
	Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
	Warning=0x2:STATUS_SEVERITY_WARNING
	Error=0x3:STATUS_SEVERITY_ERROR
	)

FacilityNames=(System=0x0:FACILITY_SYSTEM
	Runtime=0x2:FACILITY_RUNTIME
	Stubs=0x3:FACILITY_STUBS
	Io=0x4:FACILITY_IO_ERROR_CODE
	)

LanguageNames=(English=0x409:MSG00409)

; // The following are message definitions.

MessageId=0
Severity=Success
SymbolicName=MYID_MSG_SUCCESS
Language=English
%1
.

MessageId=+1
Severity=Informational
SymbolicName=MYID_CFG_CREATE
Language=English
Created 'MyID Virtual Smart Card' %2, card type '%1'
.

MessageId=+1
Severity=Informational
SymbolicName=MYID_CFG_REMOVE
Language=English
Deleted 'MyID Virtual Smart Card' %1
.

MessageId=+1
Severity=Error
SymbolicName=MYID_EXCEPTION
Language=English
Error in MyID Virtual Smart Card %1 %2, exception %3
.

MessageId=+1
Severity=Error
SymbolicName=MYID_CERTIFICATE_RESET
Language=English
MyID Virtual Smart Card %1 : Key containers and certificates have been reset due to data integrity violation
.

MessageId=+1
Severity=Error
SymbolicName=MYID_FACTORY_RESET
Language=English
MyID Virtual Smart Card %1 : Factory reset due to data integrity violation
.
