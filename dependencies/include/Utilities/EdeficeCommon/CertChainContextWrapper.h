#pragma once

#include <boost/noncopyable.hpp>
#include <boost/iterator/iterator_facade.hpp>

// wrapper class for a CCERT_CHAIN_CONTEXT pointer
// so that is gets destroyed properly when the class goes
// out of scope

class CertChainContextIterator : public boost::iterator_facade<CertChainContextIterator, PCCERT_CONTEXT, boost::bidirectional_traversal_tag, PCCERT_CONTEXT>
{
public:
	explicit CertChainContextIterator(bool forward = true) : certChainContext(nullptr), forward(forward), position(0) {};

	CertChainContextIterator(PCCERT_CHAIN_CONTEXT certChain, difference_type pos = 0, bool forward = true) : certChainContext(certChain), forward(forward), position(pos) {};

private:
	friend class boost::iterator_core_access;

	void advance(difference_type n)
	{
		position += n;
	}

	void decrement()
	{
		if(position == 0)
			throw std::out_of_range("Index out of bound");

		position -= forward ? 1 : -1;
	}

	void increment()
	{
		position += forward ? 1 : -1;
	}

	bool equal(CertChainContextIterator const& other) const
	{
		return (this->position == other.position);
	}

	PCCERT_CONTEXT dereference() const
	{
		if ( certChainContext == 0 )
			throw myid::LocalisedException(L"ChainContext not initialised");
		if(position > static_cast<difference_type>(certChainContext->rgpChain[0]->cElement))
			throw std::out_of_range("Index out of bounds.");

		return certChainContext->rgpChain[0]->rgpElement[position]->pCertContext;
	}

	PCCERT_CHAIN_CONTEXT certChainContext;

	bool forward;

	difference_type position;
};

class CertChainContextWrapper : private boost::noncopyable
{
public:
	CertChainContextWrapper(void);
	virtual ~CertChainContextWrapper(void);

	// create a certificate chain
	// certStore allows the check for root certificates to be restricted to the specified store
	void CreateCertChain( PCCERT_CONTEXT const pCertContext, HCERTSTORE certStore = 0 );

	operator PCCERT_CHAIN_CONTEXT() { return m_pChainContext; }

	std::wstring GetChainInfoXML();

	// check to see if the chain is trusted
	bool IsTrusted() const;

	// return all trust errors
	std::vector< std::wstring > TrustErrors();

	CertChainContextIterator begin()
	{
		return CertChainContextIterator(m_pChainContext);
	};

	CertChainContextIterator end()
	{
		if ( m_pChainContext == 0 )
			throw myid::LocalisedException(L"ChainContext not initialised");
		return CertChainContextIterator(m_pChainContext, m_pChainContext->rgpChain[0]->cElement);
	};

	CertChainContextIterator rbegin()
	{
		if ( m_pChainContext == 0 )
			throw myid::LocalisedException(L"ChainContext not initialised");
		DWORD end = m_pChainContext->rgpChain[0]->cElement;
		if(end > 0) end--;
		return CertChainContextIterator(m_pChainContext, end, false);
	};

	CertChainContextIterator rend()
	{
		return CertChainContextIterator(m_pChainContext, -1, false);
	};

	typedef CertChainContextIterator iterator;

protected:
	static void ParseTrustStatus( CERT_TRUST_STATUS const status, std::vector<std::wstring> & errorStatus, std::vector<std::wstring> & infoStatus );

private:
	PCCERT_CHAIN_CONTEXT m_pChainContext;
};

