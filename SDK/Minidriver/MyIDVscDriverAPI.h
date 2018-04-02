/// MyID minidriver extra properties
/// This defines extra properties, mostly to do with PIN policy
///
/// Copyright © Intercede Group Plc 2016
#pragma once

/// MyID VSC pin policy card property
/// Permission: Everyone read, admin write
/// \note Used by CardGetProperty() and CardSetProperty()
/// Data type is PinPolicy_Data of some kind
#define CP_VSC_PIN_POLICY L"VSC Pin Policy"

/// Get the internal error of the last key operation
/// Permission: Everyone read, nobody write
/// \note Used by CardGetProperty()
/// Data type is a DWORD
#define CP_VSC_DETAILED_ERROR L"VSC Detailed Error"

#define VSC_PIN_POLICY_VERSION_ONE 1
#define VSC_PIN_POLICY_CURRENT_VERSION VSC_PIN_POLICY_VERSION_ONE
#define VSC_MIN_PIN_LENGTH 4
#define VSC_MAX_PIN_LENGTH 127

namespace MyID_Vsc
{

/// Pin policy character option
enum class PinPolicyOption : unsigned long
{
	Allow = 0,			///< character allowed, may not be present
	Required = 1,		///< character requires at least one
	Disallow = 2,		///< character not allowed
};

/// Pin policy data VSC_PIN_POLICY_VERSION_ONE
/// \note This matches the policy options for Microsoft VSCs on Windows 8.1
class PinPolicy_Data_1
{
public:
	enum PinPolicySelection
	{
		UpperCase = 0,		///< A-Z
		LowerCase = 1,		///< a-z
		Digits = 2,			///< 0-9
		Special = 3,		///< special - all printable characters other than letters or digits
		///< \note ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
		NonPrintable = 4,	///< non-printable - 0x00 - 0x1F and also 0x80 - 0xFF
		NumPinPolicy = 5
	};

	unsigned long	m_version;				///< VSC_PIN_POLICY_CURRENT_VERSION, set on entry
	unsigned long	m_minLength;			///< minimum length, VSC_MIN_PIN_LENGTH - VSC_MAX_PIN_LENGTH
	unsigned long	m_maxLength;			///< maximum length, VSC_MIN_PIN_LENGTH - VSC_MAX_PIN_LENGTH
	PinPolicyOption	m_policy[NumPinPolicy];	///< PinPolicySelection
};
typedef PinPolicy_Data_1 PinPolicy_Data;

} // namespace MyID_Vsc
