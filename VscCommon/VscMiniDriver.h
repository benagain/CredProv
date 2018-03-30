#pragma once

#include "VscMiniDriverBase.h"

namespace VscMD
{

typedef char filename[9];					///< filename spec

/// Mini driver with support functions
class MiniDriver : public MiniDriverBase
{
	typedef MiniDriverBase inherited;

public:
	struct certData
	{
		filename name;
		DWORD keySpec;
		std::wstring container;
		byte index;
	};

	virtual bool ReadCMap(void);
	virtual void LoadCertificate(bool signature);
	virtual DWORD TestSign(DWORD keySpec, const std::wstring& container) const;

	static bool DeriveResponse(const VectorOfByte& challenge, const VectorOfByte& key, VectorOfByte& response);

	typedef std::vector<CONTAINER_MAP_RECORD> vecCardMap;
	vecCardMap				m_Map;					///< container map file
	std::list<certData>		m_Cert;					///< list of cert data
};

} // namespace VscMD
