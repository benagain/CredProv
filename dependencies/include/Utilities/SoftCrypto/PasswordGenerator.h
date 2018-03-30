#pragma once

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

/// Interface to a random number generator.  Mainly so that automated tests can implement their own "random"
/// implementation to ensure the same sequence every time
template<typename T>
class RandomNumberGenerator
{
public:
	RandomNumberGenerator(_In_ T min, _In_ T max)
		: m_min(min)
		, m_max(max)
	{}

	virtual T generate() = 0;

protected:
	T minimum() const { return m_min; }
	T maximum() const { return m_max; }

private:
	T m_min;			///< minimum number to generate
	T m_max;			///< maximum number to generate
};


typedef RandomNumberGenerator<unsigned long> RandomUnsignedLongGenerator;
typedef boost::shared_ptr<RandomUnsignedLongGenerator> RandomNumberGeneratorPtr;

/// Allows a random number generator to be embedded in a class
class PasswordRandom
{
protected:
	void createRandomiser(_In_ unsigned long min, _In_ unsigned long max);
	unsigned long generate_random();

private:
	RandomNumberGeneratorPtr m_random;	///< random number generator
};

/// A simple list of characters and criteria governing their occurrences in the password
class PasswordTrait : protected PasswordRandom
{
public:
	PasswordTrait(_In_z_ const wchar_t* chars, _In_ size_t minOccurrences = 0);
	PasswordTrait(_In_ std::wstring const & chars, _In_ size_t minOccurrences = 0);

	size_t minimumOccurrences() const;
	size_t size() const;
	wchar_t randomChar();

private:
	std::wstring m_chars;				///< characters for password
	size_t m_minimum;					///< minimum occurrences
};



/// A list of traits with the ability to generate a password from them
class PasswordGenerator : protected PasswordRandom
{
private:
	typedef std::vector<PasswordTrait> PasswordTraitList;
	PasswordTraitList m_list;			///< list of traits
	size_t	m_minLength;				///< minimum length

public:
	PasswordGenerator();

	void push_back(_In_ PasswordTrait const & trait);

	std::wstring generate(_In_ size_t len);

protected:
	typedef std::vector<int> TraitLayout;
	TraitLayout buildPasswordLayout(_In_ size_t length);

	wchar_t characterFromTrait(_In_ int trait);
};

/// Provides OpenSSL RNG functionality.
class OpensslGeneratorWrapper
{
public:
	unsigned long generate(_In_ unsigned long min, _In_ unsigned long max);
};

