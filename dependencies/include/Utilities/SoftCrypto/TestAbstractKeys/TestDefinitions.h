#pragma once

#include "Utilities\SoftCrypto\AbstractKeys\abstractkey.h"

#include <list>
#include <string>

// basic details about a test
class CTest
{
public:
	CTest(std::wstring const & strCryptoName, std::wstring const & strTestName)
		: m_strCryptoName(strCryptoName)
		, m_strTestName(strTestName)
	{}

	std::wstring const & CryptoName() const { return m_strCryptoName; }
	std::wstring const & TestName() const { return m_strTestName; }

private:
	std::wstring const m_strCryptoName;	// either "SoftCrypto" or the name of the HSM
	std::wstring const m_strTestName;	// the test name
};

// display information about a test to std::cout
inline void DisplayTestInfo(CTest const & test)
{
	std::wcerr << test.CryptoName() << L"\t" << test.TestName() << std::endl;
}



typedef std::list<CTest> TListTest;

// details about a failed test
class CFailedTest : public CTest
{
public:
	CFailedTest(std::wstring const & strCryptoName, std::wstring const & strTestName, std::wstring const & strFailure)
		: CTest(strCryptoName, strTestName)
		, m_strFailure( strFailure) 
	{}

	std::wstring const & Failure() const { return m_strFailure; }

private:
	std::wstring const m_strFailure;	// the failure
};

typedef std::list<CFailedTest> TListFailedTest;

// display information about a failed test
// display information about a test to std::cout
inline void DisplayFailedTestInfo(CFailedTest const & test)
{
	std::wcerr << L"FAILED: " << test.CryptoName() << L"\t" << test.TestName() << L"\t" << test.Failure() << std::endl;
}

// wrapper to call a test function with the supplied AbstractKeyFactoryPtr
// if the test throws (i.e. fails) test info and the failure is added to the listFailedTests list
// if the test succeeds test info is added to the listPassedTests list 
inline void DoTest( std::wstring const & strCryptoName, std::wstring const & strTestName, TListTest & listPassedTests, TListFailedTest & listFailedTests, void (*fnTest)(AbstractKeys::AbstractKeyFactoryPtr), AbstractKeys::AbstractKeyFactoryPtr pKeyFactory)
{
	try
	{
		(*fnTest)( pKeyFactory );

		listPassedTests.push_back(CTest(strCryptoName, strTestName));
	}
	catch(const std::exception & e)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, myid::ToWstr(e.what())));
	}
	catch(...)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, L"Unknown error"));
	}
}

// wrapper to call a test function with the supplied AbstractKeyFactoryPtr and 1 generic argument
// if the test throws (i.e. fails) test info and the failure is added to the listFailedTests list
// if the test succeeds test info is added to the listPassedTests list 
template<typename T_P1> inline void 
	DoTest(std::wstring const & strCryptoName, std::wstring const & strTestName, TListTest & listPassedTests, TListFailedTest & listFailedTests, void (*fnTest)(AbstractKeys::AbstractKeyFactoryPtr, T_P1), AbstractKeys::AbstractKeyFactoryPtr pKeyFactory, T_P1 p1)
{
	try
	{
		(*fnTest)( pKeyFactory, p1);

		listPassedTests.push_back(CTest(strCryptoName, strTestName));
	}
	catch(const std::exception & e)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, myid::ToWstr(e.what())));
	}
	catch(...)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, L"Unknown error"));
	}
}

// wrapper to call a test function with the supplied AbstractKeyFactoryPtr and 2 generic arguments
// if the test throws (i.e. fails) test info and the failure is added to the listFailedTests list
// if the test succeeds test info is added to the listPassedTests list 
template<typename T_P1, typename T_P2> inline void 
	DoTest(std::wstring const & strCryptoName, std::wstring const & strTestName, TListTest & listPassedTests, TListFailedTest & listFailedTests, void (*fnTest)(AbstractKeys::AbstractKeyFactoryPtr, T_P1, T_P2), AbstractKeys::AbstractKeyFactoryPtr pKeyFactory, T_P1 p1, T_P2 p2)
{
	try
	{
		(*fnTest)( pKeyFactory, p1, p2);

		listPassedTests.push_back(CTest(strCryptoName, strTestName));
	}
	catch(const std::exception & e)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, myid::ToWstr(e.what())));
	}
	catch(...)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, L"Unknown error"));
	}
}

// wrapper to call a test function with the supplied AbstractKeyFactoryPtr and 3 generic arguments
// if the test throws (i.e. fails) test info and the failure is added to the listFailedTests list
// if the test succeeds test info is added to the listPassedTests list 
template<typename T_P1, typename T_P2, typename T_P3> inline void 
	DoTest(std::wstring const & strCryptoName, std::wstring const & strTestName, TListTest & listPassedTests, TListFailedTest & listFailedTests, void (*fnTest)(AbstractKeys::AbstractKeyFactoryPtr, T_P1, T_P2, T_P3), AbstractKeys::AbstractKeyFactoryPtr pKeyFactory, T_P1 p1, T_P2 p2, T_P3 p3)
{
	try
	{
		(*fnTest)( pKeyFactory, p1, p2, p3);

		listPassedTests.push_back(CTest(strCryptoName, strTestName));
	}
	catch(const std::exception & e)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, myid::ToWstr(e.what())));
	}
	catch(...)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, L"Unknown error"));
	}
}

// wrapper to call a test function with the supplied AbstractKeyFactoryPtr and 4 generic arguments
// if the test throws (i.e. fails) test info and the failure is added to the listFailedTests list
// if the test succeeds test info is added to the listPassedTests list 
template<typename T_P1, typename T_P2, typename T_P3, typename T_P4> inline void 
	DoTest(std::wstring const & strCryptoName, std::wstring const & strTestName, TListTest & listPassedTests, TListFailedTest & listFailedTests, void (*fnTest)(AbstractKeys::AbstractKeyFactoryPtr, T_P1, T_P2, T_P3, T_P4), AbstractKeys::AbstractKeyFactoryPtr pKeyFactory, T_P1 p1, T_P2 p2, T_P3 p3, T_P4 p4)
{
	try
	{
		(*fnTest)( pKeyFactory, p1, p2, p3, p4);

		listPassedTests.push_back(CTest(strCryptoName, strTestName));
	}
	catch(const std::exception & e)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, myid::ToWstr(e.what())));
	}
	catch(...)
	{
		listFailedTests.push_back(CFailedTest(strCryptoName, strTestName, L"Unknown error"));
	}
}

