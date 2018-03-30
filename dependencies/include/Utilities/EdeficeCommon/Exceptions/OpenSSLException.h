#pragma once

#include "LocalisedException.h"

namespace myid
{

class OpenSSLException : public myid::LocalisedException
{
	typedef myid::LocalisedException inherited;

public:
	OpenSSLException(_In_ myid::Localisation const& location, _In_ std::wstring const& info);
	virtual ~OpenSSLException() throw() {};

	static std::wstring ErrorText(void);

protected:
	virtual std::wstring buildErrorMessage() const;
};

}

