#pragma once

/** \file
 * Definition of TLVDecodeTemplate
 */

namespace TLV
{

typedef std::list<class TLVTag*> TagList;

/// Decoder with built in vector
/// \tparam T non vector decoder class
template <class T>
class DecodeVector : public T, protected myid::VectorOfByte
{
public:
	/// Empty constructor
	DecodeVector()
	{
		this->m_Decoded = false;
		this->m_Begin = begin();
		this->m_End = end();
	}

	explicit DecodeVector(_In_ const T & rhs)
		: T(rhs)
	{
		this->m_Begin = begin();
		this->m_End = end();
	}

	explicit DecodeVector(_In_ const DecodeVector<T> & rhs)
		: T(rhs)
		, myid::VectorOfByte(rhs)
	{
		this->m_Begin = begin();
		this->m_End = end();
	}

	DecodeVector(_In_ const T & rhs1, _In_ const myid::VectorOfByte& rhs2)
		: T(rhs1)
		, myid::VectorOfByte(rhs2)
	{
		this->m_Begin = begin();
		this->m_End = end();
	}

	/// Copy from vector constructor
	explicit DecodeVector(_In_ const myid::VectorOfByte& rhs)
		: myid::VectorOfByte(rhs)
	{
		this->m_Decoded = false;
		this->m_Begin = begin();
		this->m_End = end();
	}

	DecodeVector(
		_In_ const myid::VectorOfByte::const_iterator& _begin,	///< start of vector
		_In_ const myid::VectorOfByte::const_iterator& _end)	///< end of vector
		: myid::VectorOfByte(_begin, _end)
	{
		this->m_Decoded = false;
		this->m_Begin = begin();
		this->m_End = end();
	}

	/// Copy from hex string constructor
	explicit DecodeVector(_In_ const std::wstring& rhs)		///< hex string
	{
		operator=(rhs);
	}

	/// copy
	DecodeVector<T>& operator=(_In_ const DecodeVector<T>& rhs)
	{
		operator=((myid::VectorOfByte)rhs);

		return *this;
	}

	/// Assign a vector
	DecodeVector<T>& operator=(_In_ const myid::VectorOfByte& rhs)
	{
		myid::VectorOfByte::operator=(rhs);

		this->m_Begin = begin();
		this->m_End = end();

		this->Reset();

		return *this;
	}

	/// Assign a vector as a hex string
	DecodeVector<T>& operator=(_In_ const std::wstring& rhs)
	{
		myid::hex_2_bin(rhs, *this);

		this->m_Begin = begin();
		this->m_End = end();

		this->Reset();

		return *this;
	}

	/// Choose between T and vector
	const TLVTag* operator[](_In_ size_t position) const
	{
		return T::operator[](position);
	}
};

//============================================================================================

/// Decoder with built in vectors for TL and V parts
/// \tparam T non vector decoder class
template <class T>
class DecodeVectorValue : public DecodeVector<T>
{
	typedef DecodeVector<T> inherited;

public:
	DecodeVectorValue(_In_ const myid::VectorOfByte& tl, _In_ const myid::VectorOfByte& value)
		: inherited(tl)
		, m_value(value)
	{
		inherited::SetValue(m_value);
	}

protected:
	myid::VectorOfByte		m_value;			///< value array
};

//============================================================================================

/// Generic TLV iterator class
/// \tparam Tag Tag class
/// \tparam Decode Decoder class
template <class Tag, class Decode>
class Iterator
{
public:
	Iterator()
		: m_Decode(nullptr)
		, m_TagValid(false)
	{}

	explicit Iterator(_In_ const Decode& decode)			///< decoder to iterator over
		: m_Decode(&decode)
		, m_TagValid(false)
	{
		First();
	}

	explicit Iterator(_In_ const Iterator& rhs)			///< copy
		: m_Decode(rhs.m_Decode)
		, m_Tag(rhs.m_Tag)
		, m_TagValid(rhs.m_TagValid)
	{}

	/// Set the decoder
	void SetDecode(_In_ const Decode* decode)	///< decoder to iterator over
	{
		m_Decode = decode;
		m_TagValid = false;
	}

	/// Get the current tag
	const Tag* Current(void) const
	{
		if (!m_TagValid)
			return nullptr;

		return static_cast<Tag*>(*m_Tag);
	}

	/// Determine if the current tag is valid
	bool Valid(void) const
	{
		return m_TagValid;
	}

	/// Return the number of tags
	size_t Count(void) const
	{
		if (m_Decode == nullptr)
			return 0;
		return m_Decode->Count();
	}

	/// Go to the first tag
	/// \retval nullptr if the tag list is empty
	const Tag* First(void)
	{
		if (m_Decode == nullptr)
			return nullptr;

		const TagList& tagList = m_Decode->Tags();
		m_Tag = tagList.begin();

		m_TagValid = m_Tag != tagList.end();
		if (!m_TagValid)
			return nullptr;

		return static_cast<Tag*>(*m_Tag);
	}

	/// Go to the last tag
	/// \retval nullptr if the tag list is empty
	const Tag* Last(void)
	{
		if (m_Decode == nullptr)
			return nullptr;

		const TagList& tagList = m_Decode->Tags();

		if (tagList.empty())
		{
			m_TagValid = false;
			return nullptr;
		}

		m_TagValid = true;
		m_Tag = tagList.end();
		--m_Tag;

		return static_cast<Tag*>(*m_Tag);
	}

	/// Go to the next tag, starts at the first tag
	/// \retval nullptr when the end is reached, or a zero size list
	const Tag* Next(void)
	{
		if (m_Decode == nullptr)
			return nullptr;

		const TagList& tagList = m_Decode->Tags();

		if (!m_TagValid)
			m_Tag = tagList.begin();
		else if (m_Tag != tagList.end())
			++m_Tag;

		// will deal with zero size lists
		m_TagValid = m_Tag != tagList.end();
		if (!m_TagValid)
			return nullptr;

		return static_cast<Tag*>(*m_Tag);
	}

	/// Step forward a number of tags
	const Tag* Next(_In_ int count)			///< number of tags to move
	{
		const Tag* tag = nullptr;
		for (int c = 0; c < count; c++)
		{
			tag = Next();
			if (tag == nullptr)
				break;
		}

		return tag;
	}

	/// Go to the previous tag, starts at the last tag
	/// \retval nullptr when the start is reached, or a zero size list
	const Tag* Previous(void)
	{
		if (m_Decode == nullptr)
			return nullptr;

		const TagList& tagList = m_Decode->Tags();

		if (tagList.empty())
		{
			m_TagValid = false;
		}
		else if (!m_TagValid)
		{
			m_TagValid = true;
			m_Tag = tagList.end();
			--m_Tag;
		}
		else if (m_Tag != tagList.begin())
		{
			m_TagValid = true;
			--m_Tag;
		}
		else
		{	// on begin(), cannot move back
			m_TagValid = false;
		}

		if (!m_TagValid)
			return nullptr;

		return static_cast<Tag*>(*m_Tag);
	}

	/// Step back a number of tags
	const Tag* Previous(_In_ int count)			///< number of tags to move
	{
		const Tag* tag = nullptr;
		for (int c = 0; c < count; c++)
		{
			tag = Previous();
			if (tag == nullptr)
				break;
		}

		return tag;
	}

	/// Traverse the tag tree
	/// \retval nullptr if the end of the tree has been reached, and current tag is invalidated
	virtual const Tag* Traverse(_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		return forwards ? Next() : Previous();
	}

	/// Traverse the tag tree
	/// \retval nullptr when the end of the tree has been reached, and current tag is invalidated
	const Tag* Traverse(
		_In_ int count,						///< number of tags to move
		_In_ bool forwards = true)			///< direction \li true forwards \li false backwards
	{
		const Tag* tag = nullptr;
		for (int c = 0; c < count; c++)
		{
			tag = Traverse(forwards);
			if (tag == nullptr)
				break;
		}

		return tag;
	}

	/// Move through a series of tags
	const Tag* Move(_In_ const char* move)		///> a sequence of FNPL
	{
		const Tag* tag = nullptr;
		for (const char* m = move; *m; ++m)
		{
			tag = MoveOne(*m);

			if (tag == nullptr)
				return nullptr;
		}

		return tag;
	}

	/// \return the tag
	/// Find a one byte tag
	const Tag* Find(
		_In_ byte tg,				///< tag to find
		_In_ bool next = false,		///< \li true next \li false first
		_In_ bool forwards = true)	///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tg))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

	/// Find a full tag
	/// \return the tag
	const Tag* Find(
		_In_ const myid::VectorOfByte& tg,	///< tag to find
		_In_ bool next = false,				///< \li true next \li false first
		_In_ bool forwards = true)			///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tg))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

	/// Find a full tag using hex
	/// \return the tag
	const Tag* Find(
		_In_ const std::wstring& hextag,	///< tag to find
		_In_ bool next = false,				///< \li true next \li false first
		_In_ bool forwards = true)			///< direction \li true forwards \li false backwards
	{
		return Find((myid::VectorOfByte&)*myid::hex_2_bin(hextag), next, forwards);
	}

	/// Find a one byte tag with a given value
	/// \return the tag
	const Tag* Find(
		_In_ byte tg,							///< tag to find
		_In_ const myid::VectorOfByte& value,	///< value to find
		_In_ bool next = false,					///< \li true next \li false first
		_In_ bool forwards = true)				///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tg, value))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

	/// Find a full tag with a given value
	/// \return the tag
	const Tag* Find(
		_In_ const myid::VectorOfByte& tg,		///< tag to find
		_In_ const myid::VectorOfByte& value,	///< value to find
		_In_ bool next = false,					///< \li true next \li false first
		_In_ bool forwards = true)				///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tg, value))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

protected:
	/// Move through a series of tags
	virtual const Tag* MoveOne(_In_ char move)			///< one of FNPLfnpl
	{
		switch (move)
		{
		case 'F':
		case 'f':
			return First();

		case 'N':
		case 'n':
			return Next();

		case 'P':
		case 'p':
			return Previous();

		case 'L':
		case 'l':
			return Last();
		}

		return nullptr;
	}

	virtual const Tag* FindStart(
		_In_ bool next,				///< \li true next \li false first
		_In_ bool forwards)			///< direction \li true forwards \li false backwards
	{
		if (next)
			return Traverse(forwards);
		if (forwards)
			return First();
		return Last();
	}

	const Decode*	m_Decode;					///< current decode processor
	TagList::const_iterator	m_Tag;				///< current tag in tag list of m_Decode
	bool			m_TagValid;					///< is m_Tag valid
};

} // namespace TLV

