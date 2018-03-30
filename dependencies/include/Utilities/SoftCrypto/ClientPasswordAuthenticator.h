#pragma once

#include <map>
#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"


namespace myidPassword
{
/*!
* Generates authentication strings for a session using the persons passwords and provided person
* and salt values. Supports multiple modes of operation to allow transition between different
* password algorithms
*/
class ClientPasswordAuthenticator
{
public:
	enum ePasswordAlgorithm
	{
		Pwd1,		///< generated authentication string will be "Password v1 Full Combined Mode" algorithm
		Pwd2and1,	///< generated authentication string will be "Password v2" and "Password v1 Full Combined Mode" (underscore separated, so Passwordv2_Passwordv1FullCombined)
		Pwd2,		///< generated authentication string will be "Password v2" algorithm
		PwdTN1,		///< generated authentication string will be "PasswordTN v1 " algorithm
		PwdTN2and1,	///< generated authentication string will be "PasswordTN v2" and "PasswordTN v1" (underscore separated, so PasswordTNv2_PasswordTNv1)
		PwdTN2		///< generated authentication string will be "PasswordTN v2" algorithm
			};

			/*! construct the object, setting the algorithm type to use */
	ClientPasswordAuthenticator(_In_ ePasswordAlgorithm pwdAlgorithm);

			/*!
			* Set the person salt to be used when calculating password hashes, this must be called
			* before AddPassword(). This salt will be provided by the server.
			*/
	void SetPersonSalt(_In_ const std::wstring &wstrPersonSalt);

			/*!
			* Set the session salt to be used when generating the authentication string, this must
			* be called before GetAuthenticationString(). This salt will be provided by the server.
			*/
	void SetSessionSalt(_In_ const std::wstring &wstrSessionSalt);

			/*!
			* Adds an additional password to be used when generating the authentication string, this
			* must be called once for each password used to login. It is the responsibility of the
			* caller to canonicalise the password prior to calling this function.
			*/
	void AddPassword(_In_z_ const wchar_t *pwszPassword);

			/*!
			* Generates and returns the final authentication string based on the selected algorithm,
			* the salt values and the set of passwords supplied to this class. Where more than one
			* algorithm is in use (as in the case of ePasswordAlgorithm::Pwd2and1) the authentication
			* string for each algorithm will be separated by an _ token.
			*/
			std::wstring GetAuthenticationString();

private:
			ePasswordAlgorithm m_algorithm;
			std::wstring m_personSalt;
			std::wstring m_sessionSalt;

			/*!
			* A map of hashed passwords for each enabled authentication algorithm, indexed by version
			* number. The key data is the concatenated binary representation of each password passed
			* to the AddPassword() function
			*/
	typedef std::map<int, VectorOfBytePtr> hashedPasswords;
	hashedPasswords m_hashedPasswords;

			/*!
			* An internal helper function to generate a V1 full combined auth string, which is an
			* SHA1 hash of the concatenated PasswordHash_V1 hashes of each of the provided passwords
			* followed by the numeric session ID
			*/
			std::wstring GenerateV1FullAuthenticationString();
			
			/*!
			* An internal helper function to generate a V2 auth string, which is an SHA256 hash of
			* the concatenated PasswordHash_V2 hashes of each of the provided passwords followed by
			* the numeric session ID
			*/
			std::wstring GenerateV2AuthenticationString();

			/*!
			* An internal helper function to generate a raw, unhashed authentication string for the
			* specified password protocol version
			*/
	std::wstring GenerateRawAuthenticationString(_In_ int version);

			/*!
			* Internal helper function to check if the specified password protocol version 1 is used by the
			* currently selected algorithm
			*/
	bool IsPasswordVersionInUse(_In_ int version);

			/*!
			* Internal helper function to check if the TN session salting mode is in use
			*/
			bool UsingTNMode();
};
}