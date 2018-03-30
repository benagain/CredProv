#pragma once

#include <boost/noncopyable.hpp>

// wrapper class for a HCERTCHAINENGINE handle
// so that it is cleaned up properly on destruction

class CertChainEngineWrapper : private boost::noncopyable
{
public:
	CertChainEngineWrapper(void);
	virtual ~CertChainEngineWrapper(void);

	operator HCERTCHAINENGINE() { return m_certChainEngine; }
	operator HCERTCHAINENGINE*() { return &m_certChainEngine; }

private:

	HCERTCHAINENGINE m_certChainEngine;
};

