#include "stdafx.h"
#include "VscMiniDriver.h"
#include "Utilities\SoftCrypto\WinCrypt\CNGCrypt.h"
#include "Utilities\SoftCrypto\WinCrypt\CNGSymKey.h"

namespace VscMD
{

/// Read the container map file, checking the cache counter
bool MiniDriver::ReadCMap(void)
{
	const VectorOfByte& data = ReadFile(szBASE_CSP_DIR, szCONTAINER_MAP_FILE);
	if (Success())
	{
		size_t count = data.size() / sizeof(CONTAINER_MAP_RECORD);
		m_Map.resize(count);
		if (count)
			memcpy(&m_Map[0], &data[0], count * sizeof(CONTAINER_MAP_RECORD));
		return true;
	}

	return false;
}

/// Load certificate data
void MiniDriver::LoadCertificate(bool signature)			///< include signature certs
{
	try
	{
		m_Cert.clear();

		if (ReadCMap())
		{
			// sequence:
			// default AT_KEYEXCHANGE
			// not default AT_KEYEXCHANGE
			// default AT_SIGNATURE
			// not default AT_SIGNATURE

			size_t count = m_Map.size();
			certData data;
			data.keySpec = AT_KEYEXCHANGE;
			for (BYTE c = 0; c < count; c++)
			{
				if (((m_Map[c].bFlags & CONTAINER_MAP_VALID_CONTAINER) == 0) ||
					(m_Map[c].wKeyExchangeKeySizeBits == 0) ||
					((m_Map[c].bFlags & CONTAINER_MAP_DEFAULT_CONTAINER) == 0) )
					continue;

				sprintf_s(data.name, "%s%02d", szUSER_KEYEXCHANGE_CERT_PREFIX, c);
				data.container = m_Map[c].wszGuid;
				data.index = c;
				m_Cert.push_back(data);
			}
			for (BYTE c = 0; c < count; c++)
			{
				if (((m_Map[c].bFlags & CONTAINER_MAP_VALID_CONTAINER) == 0) ||
					(m_Map[c].wKeyExchangeKeySizeBits == 0) ||
					((m_Map[c].bFlags & CONTAINER_MAP_DEFAULT_CONTAINER) != 0))
					continue;

				sprintf_s(data.name, "%s%02d", szUSER_KEYEXCHANGE_CERT_PREFIX, c);
				data.container = m_Map[c].wszGuid;
				data.index = c;
				m_Cert.push_back(data);
			}

			if (signature)
			{
				data.keySpec = AT_SIGNATURE;
				for (BYTE c = 0; c < count; c++)
				{
					if (((m_Map[c].bFlags & CONTAINER_MAP_VALID_CONTAINER) == 0) ||
						(m_Map[c].wSigKeySizeBits == 0) ||
						((m_Map[c].bFlags & CONTAINER_MAP_DEFAULT_CONTAINER) == 0))
						continue;

					sprintf_s(data.name, "%s%02d", szUSER_SIGNATURE_CERT_PREFIX, c);
					data.container = m_Map[c].wszGuid;
					data.index = c;
					m_Cert.push_back(data);
				}
				for (BYTE c = 0; c < count; c++)
				{
					if (((m_Map[c].bFlags & CONTAINER_MAP_VALID_CONTAINER) == 0) ||
						(m_Map[c].wSigKeySizeBits == 0) ||
						((m_Map[c].bFlags & CONTAINER_MAP_DEFAULT_CONTAINER) != 0))
						continue;

					sprintf_s(data.name, "%s%02d", szUSER_SIGNATURE_CERT_PREFIX, c);
					data.container = m_Map[c].wszGuid;
					data.index = c;
					m_Cert.push_back(data);
				}
			}
		}
	}
	catch (...)
	{
	}
}

/// Perform a test sign, this is to force a PIN popup before being passed to LSASS so it does not cause a popup.
/// LSASS cannot handle the cancel or blocked PIN response.
/// This allows the Cancel button to work.
DWORD MiniDriver::TestSign(DWORD keySpec, const std::wstring& container) const
{
	CARD_SIGNING_INFO info{};
	info.dwVersion = CARD_SIGNING_INFO_BASIC_VERSION;
	info.dwKeySpec = keySpec;
	info.bContainerIndex = 255;

	for (const auto& cert : m_Cert)
	{
		if (cert.container == container)
		{
			info.bContainerIndex = cert.index;
			break;
		}
	}
	if (info.bContainerIndex == 255)
		return false;

	info.aiHashAlg = CALG_SHA1;

	VectorOfByte data = CngCrypt::Random::Generate(20);
	info.cbData = data.lsize();
	info.pbData = data.ptr();

	if (SignData(info))
		return SCARD_S_SUCCESS;

	return m_rc;
}

/// Derive the response to a challenge given the key
bool MiniDriver::DeriveResponse(const VectorOfByte& challenge,		///< challenge from card
	const VectorOfByte& key,			///< 24 byte admin key
	VectorOfByte& response)				///< response
{
	if (challenge.size() % 8 != 0)
		return false;

	if (key.size() != 24)
		return false;

	try
	{
			CngCrypt::DES des;
			if (des.importKey(key))
			{
				VectorOfByte ivc;
				response = des.cbc_encrypt(challenge, ivc);
				return true;
			}
	}
	catch (...) {}

	response.clear();
	return false;
}

} // namespace VscMD
