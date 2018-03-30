#pragma once

namespace myid
{
	/*!
	* A set of utility methods for dealing with certificate files, this is based on various copies of
	* CertFileUtils which were previously scattered throughout the codebase but never made it into a
	* shared library
	*/
	class CertFileUtils
	{
	public:
		/*!
		* Silently removes PEM headers and footers (-----BEGIN X----- and -----END X-----) from the
		* data content provided.
		*
		* \param[in,out] data
		*   String which may contain PEM headers to be removed
		* \param[in] headerType
		*   The header type to remove, ie: the value of X in the above examples
		*
		* \return
		*   True if PEM headers were removed, false if none were present in the data string
		*/
		static bool RemovePEMHeaderAndFooter(std::wstring& data, const std::wstring& headerType);

		/*!
		* Load a certificate or key from a PEM encoded file and returns it as a base64 encoded string
		*
		* \param[in] filename
		*   Name of the PEM file to read
		* \param[in] headerType
		*   The PEM header type expected to be present in the file
		* \param[out] b64Cert
		*   If successful, the base64 encoded certificate or key
		*
		* \return
		*   True if the file was read successfully & contained the expected PEM header, false otherwise
		*/
		static bool GetCertFromPEMFile(const std::wstring& filename, const std::wstring& headerType, std::wstring& b64Cert);
	};
}