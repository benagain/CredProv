#pragma once

#pragma warning(disable:4512)

#include <string>
#include <tchar.h>
#include <comdef.h>

namespace myid
{


	/// this is the basics of converting between string encodings
	/**
	  this class can never be used as it has a private constructor that doesn't have an
	  implementation.  the class is here to provide the template for the actual classes.
	 */
	template<class From, class To>
	class StringEncodingConverter
	{
	private:
		StringEncodingConverter();
	};




	/// return a guaranteed unicode string
	/**
	  this is the function to use when you want to guarantee that you end up with a unicode
	  string no matter what the encoding of the original. using this function hides all of
	  the details of the StringEncodingConverter suite and lets you focus on just getting
	  the unicode string.  it also keeps you code clean and readable whilst acutally improving
	  meaning.
	 */
	template<class From>
	StringEncodingConverter<From, wchar_t> toWstr(std::basic_string<From> const & input)
	{
		return makeConverter<From, wchar_t>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, wchar_t> toWstr(From const * input)
	{
		return makeConverter<From, wchar_t>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, wchar_t> toWstr(From const & input)
	{
		return makeConverter<From, wchar_t>(StringRef<From>(input));
	}


	template<class From>
	StringEncodingConverter<From, TCHAR> toTstr(std::basic_string<From> const& input)
	{
		return makeConverter<From, TCHAR>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, TCHAR> toTstr(From const * input)
	{
		return makeConverter<From, TCHAR>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, TCHAR> toTstr(From const & input)
	{
		return makeConverter<From, TCHAR>(StringRef<From>(input));
	}

	/// return a guaranteed ascii string
	/**
	  this is the function to use when you want to guarantee that you end up with an ascii
	  string no matter what the encoding of the original. using this function hides all of
	  the details of the StringEncodingConverter suite and lets you focus on just getting
	  the ascii string.  it also keeps you code clean and readable whilst acutally improving
	  meaning.
	*/
	template<class From>
	StringEncodingConverter<From, char> toAstr(std::basic_string<From> const& input)
	{
		return makeConverter<From, char>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, char> toAstr(From const * input)
	{
		return makeConverter<From, char>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, char> toAstr(From const & input)
	{
		return makeConverter<From, char>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, _bstr_t> toBstr(std::basic_string<From> const& input)
	{
		return makeConverter<From, _bstr_t>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, _bstr_t> toBstr(From const * input)
	{
		return makeConverter<From, _bstr_t>(StringRef<From>(input));
	}

	template<class From>
	StringEncodingConverter<From, _bstr_t> toBstr(From const & input)
	{
		return makeConverter<From, _bstr_t>(StringRef<From>(input));
	}
}

using myid::toWstr;
using myid::toAstr;
using myid::toTstr;
using myid::toBstr;

namespace myid
{
	/// operator to extract the basic_string from the StringEncodingConverter for an ostream
	/**
	  this operator allows you to use the StringEncodingConverter classes, or for better readability
	  the toAstr and toWstr functions, inline with stream operators, for example

		stream << "The following is now ASCII: " << makeAscii(L"I was Unicode before") << endl;
	 */
	template<class From, class To>
	std::basic_ostream<To>& operator<<(std::basic_ostream<To>& os, StringEncodingConverter<From, To> const& rhs)
	{
		os << static_cast<std::basic_string<To> >(rhs);
		return os;
	}



	/// unicode encoding converter
	/**
	 converter class that understands how to convert between ASCII and UTF-16 unicode.  this
	 is probably the only encoding conversion you will ever need, but there is the potential
	 to provider converters for more esoteric conversions.

	 ideally the inheritance should be reversed, with this class deriving from a ConvertHolder
	 class, but we need to have this at the top of the hierarchy as it isn't templates, and
	 deriving from any templated class would mean having the implementation visible to clients.

	 efforts are made to keep memory allocation and copying to a minimum.  for strings that
	 actually need to be converted there should only be one memory allocation to create the new
	 string.  this is much better than using the ATL macros to do
	   string ascii = string(W2A(unicode.c_str());
	 which at best will do 2 allocations
	*/
	class StringWidth
	{
	public:
		/// construct a wide string from a narrow string
		std::wstring widen(std::string const& rhs) const;

		/// construct a narrow string from a wide string
		std::string narrow(std::wstring const& rhs) const;
	};


	/// stores a reference to a string or raw character array
	/**
	to make sure we do as little copying as possible, and that conversions between the same encoding
	types don't do any copying at all, we store strings as references.  this can cause problems when
	our input isn't actually a string object but a char* or wchar_t*.

	this class helps resolve that by storing a string for the conversion classes.  if the string
	was originally a std::string (or any other string object) then a pointer to the original is stored.
	if the string was originally a character array then a new string is created and that is stored, along
	with a flag to delete the string when we are done.

	very basic referencing "counting" is used to ensure that there is no memory leak when we are
	dealing with raw char arrays.
	*/
	template<class S>
	// cppcheck-suppress copyCtorAndEqOperator
	class HolderBase
	{
	public:
		/// this is the std string type we will be storing
		typedef S StringType;

		HolderBase<S>() : m_string(0), m_delOnExit(false) { }

		/**
		if we are given a reference to a proper object then we just store the pointer to that.  this does mean that
		it is possible to end up with a dangling reference if the original string object is destroyed before we are.
		this should mostly not happen as the design of the conversion classes is such that they are used in place as
		shim objects. see the test shimInline for an example
		\param str actual string object we will point to
		\see shimInline
		 */
		explicit HolderBase<S>(StringType const& str) : m_string(&str), m_delOnExit(false) {}

		/**
		the semantics here are similar to the std::auto_ptr, which means that only one StringRef class
		can refer to the string at any one time.  copying the StringRef will result in the originating
		StringRef being robbed of its reference.  this is not ideal but will suffice for now.  if you
		intend to use this class for any other purpose you probably want to extend it to have proper
		boost::shared_ptr like semantics.
		*/
		explicit HolderBase<S>(StringType const* str) : m_string(str), m_delOnExit(true) {}

		/**
		 copy constructor object that "steals" the reference to the string object.
		 whilst we do not rob the other HolderBase of it's reference, we do rob it of it's right to delete the pointer
		 if it wanted to.  this guarantees that we will still have access to the string object if the other HolderBase
		 destructs before we do.  as we are not completely reference counted it also means that if we are destructed
		 before the other HolderBase then it is left with a dangling pointer.
		 */
		explicit HolderBase<S>(HolderBase<S> const& rhs) : m_string(rhs.m_string), m_delOnExit(rhs.m_delOnExit) { rhs.m_delOnExit = false; }

		/**
		assignment operator that steals the string object.
		 */
		HolderBase<S> const& operator=(HolderBase<S> const& rhs)
		{
			cleanup();
			m_string = rhs.m_string;
			m_delOnExit = rhs.m_delOnExit;
			rhs.m_delOnExit = false;
			return *this;
		}

		virtual ~HolderBase() {
			cleanup();
		}

		/**
		return a reference to the string object we are pointing to.
		performs a basic safety check to make sure we actually have a pointer.
		\throw runtime_error
		 */
		operator StringType const& () const {
			if( !m_string )
				throw std::runtime_error("null string object");
			return *m_string;
		}

	private:
		StringType const* m_string;
		mutable bool m_delOnExit;

		void cleanup()
		{
			if(m_delOnExit)
				delete m_string;
		}
	};

	/// reference object for non-standard string objects (i.e. _bstr_t)
	template<class S>
	class StringRef : public HolderBase<S>
	{
	public:
		StringRef<S>() : HolderBase<S>() { }
		explicit StringRef<S>(StringType const& str) : HolderBase<S>(str) {}
	};


	/// reference object for standard narrow strings
	template<>
	class StringRef<char> : public HolderBase<std::string>
	{
	public:
		StringRef<char>() : HolderBase<std::string>() { }
		explicit StringRef<char>(StringType const& str) : HolderBase<std::string>(str) {}
		explicit StringRef<char>(char const* str) : HolderBase<std::string>(new std::string(str)) {}
	};

	/// reference object for standard wide strings
	template<>
	class StringRef<wchar_t> : public HolderBase<std::wstring>
	{
	public:
		StringRef<wchar_t>() : HolderBase<std::wstring>() { }
		explicit StringRef<wchar_t>(StringType const& str) : HolderBase<std::wstring>(str) {}
		explicit StringRef<wchar_t>(wchar_t const* str) : HolderBase<std::wstring>(new std::wstring(str)) {}
	};




	/**
	construct a StringEncodingConverter.
	this helper object is merely here as we don't provide constructors to StringEncodingConverter.  this is because
	it would mean duplication of those constructors for every StringEncodingConverter specialisation, whereas we can
	provide the needed functionality in a base class via the put function.
	 */
	template<class From, class To>
	StringEncodingConverter<From, To> makeConverter( StringRef<From> const& from )
	{
		StringEncodingConverter<From, To> x;
		x.put( from );
		return x;
	}



	/// stores a string to be converted
	/**
	  this is a basic holder class that stores one string of the type to be converted From
	  until the conversion happens.  this is only really to save us a few lines in the template
	  specialisations, but also serves to keep those specialisations clean.
	 */
	template<class From>
	class StringReferenceConverter
	{
	public:
		/// this is the type of string we are converting from
		typedef StringRef<From> FromStringType;

		void put( FromStringType const & input ) { _input = input; }

	protected:
		FromStringType _input;
	};


	/// conversion class specialisation that handles unicode to ascii
	template<>
	class StringEncodingConverter<wchar_t, char> : public StringReferenceConverter<wchar_t>
	{
	public:
		operator std::string() const {
			return StringWidth().narrow(_input);
		}
	};

	/// conversion class specialisation that handles ascii to unicode
	template<>
	class StringEncodingConverter<char, wchar_t> : public StringReferenceConverter<char>
	{
	public:
		operator std::wstring() const {
			return StringWidth().widen(_input);
		}
	};


	/// conversion class specialisation that handles ascii to ascii
	/**
	  this seemingly unnecessary specialisation means that an ascii string will not be copied when
	  converting to an ascii string.  it also makes the whole StringEncoderConverter transparent
	  as otherwise you wouldn't be able to use it to guarantee that an ascii string really was an
	  ascii string.
	 */
	template<>
	class StringEncodingConverter<char, char> : public StringReferenceConverter<char>
	{
	public:
		operator std::string const& () const {
			return _input;
		}
	};

	/// conversion class specialisation that handles unicode to unicode
	/**
	  this seemingly unnecessary specialisation means that an unicode string will not be copied when
	  converting to an unicode string.  it also makes the whole StringEncoderConverter transparent
	  as otherwise you wouldn't be able to use it to guarantee that an unicode string really was an
	  unicode string.
	*/
	template<>
	class StringEncodingConverter<wchar_t, wchar_t> : public StringReferenceConverter<wchar_t>
	{
	public:
		operator std::wstring const& () const {
			return _input;
		}
	};

#if _MSC_VER > 1300
	/// conversion class specialisation that handles _bstr_t to std::basic_string
	template<class T>
	class StringEncodingConverter<_bstr_t, T> : public StringReferenceConverter<_bstr_t>
	{
	public:
		operator std::basic_string<T>() const {
			_bstr_t y(_input);
			return y.length() == 0 ? std::basic_string<T>() : std::basic_string<T>( y );
		}
	};

	/// conversion class specialisation that handles BSTR to std::basic_string
	template<class T>
	class StringEncodingConverter<BSTR, T> : public StringReferenceConverter<BSTR>
	{
	public:
		operator std::basic_string<T>() const {
			_bstr_t y(_input);
			return y.length() == 0 ? std::basic_string<T>() : std::basic_string<T>( y );
		}
	};

	template<class T>
	class StringEncodingConverter<T, _bstr_t> : public StringReferenceConverter<T>
	{
	public:
		operator _bstr_t() const {
			std::basic_string<T> const& x = _input;
			return _bstr_t( x.c_str() );
		}

		operator BSTR() const {
			return operator _bstr_t().Detach();
		}
	};

	template<>
	class StringEncodingConverter<_bstr_t, _bstr_t> : public StringReferenceConverter<_bstr_t>
	{
	public:
		operator _bstr_t const&() const {
			return _input;
		}

		operator BSTR const() const {
			const _bstr_t & i = _input;
			_bstr_t & j = const_cast< _bstr_t & >( i );
			return j.Detach();
		}
	};
#endif

}
