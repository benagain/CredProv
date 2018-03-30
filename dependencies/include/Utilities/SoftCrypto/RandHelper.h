#pragma once
class RandHelper
{
public:
	RandHelper(void);
	virtual ~RandHelper(void);

	long GetRandomNum();
private:
	HCRYPTPROV m_hDefaultCSP;
	bool m_bCSP;
};

