#pragma once

/*
	The sample code from Products\Common\openssl\openssl-1.0.1g\crypto\threads\mttest.c
	uses WaitForSingleObject which is proving to be unreliable (or a source of deadlocks)
	when called from com+ components.
	The alternative boost mutex used by the mobile team also uses that same object behind the scenes
*/

#include <boost/noncopyable.hpp>

void OpenSSL_setup(void);
void OpenSSL_cleanup(void);
void OpenSSL_thread_setup(void);
void OpenSSL_thread_cleanup(void);


class OpenSSLWrapper : private boost::noncopyable
{
public:
	OpenSSLWrapper()
	{
		OpenSSL_setup();
	}

	~OpenSSLWrapper()
	{
		OpenSSL_cleanup();
	}
};
