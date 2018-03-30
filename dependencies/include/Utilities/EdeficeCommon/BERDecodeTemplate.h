#pragma once

/** \file
 * Definition of BERDecodeTemplate
 */

namespace TLV				/// Contains BER decoding
{

template <class Collection>
class DecodeParent
{
public:
	DecodeParent()
		: m_Parent(nullptr)
	{}

	explicit DecodeParent(_In_ const Collection* parent)
		: m_Parent(parent)
	{}

	void SetCollection(_In_ const Collection* parent)
	{
		m_Parent = parent;
	}

protected:
	const Collection*	m_Parent;
};

//==========================================================================================================================

template <class Decode, class Collection>
class TagParent
{
public:
	explicit TagParent(_In_ const Decode* parent)
		: m_Parent(parent)
	{}

protected:
	void SetCollection(_In_ const Collection* collection)
	{
		m_Decode.SetCollection(collection);
	}

	Decode m_Decode;						///< decoder for nested tags
	const Decode* m_Parent;					///< parent of collection
};

//==========================================================================================================================

template <class Tag, class Decode>
class BERIteratorFind : public Iterator<Tag, Decode>
{
	typedef Iterator<Tag, Decode> inherited;

public:
	BERIteratorFind()
	{}

	explicit BERIteratorFind(_In_ const Decode& decode)
		: inherited(decode)
	{}

	/// Find a tag
	/// \retval nullptr if the tag is not found, and current tag is invalidated
	const Tag* Find(
		_In_ unsigned long tagType,		///< tag type to look for
		_In_ byte tagFlags,				///< tag flags to look for
		_In_ bool next = false,			///< \li true next \li false first
		_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tagType, tagFlags))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

	/// Find a tag and value
	/// \retval nullptr if the tag is not found, and current tag is invalidated
	const Tag* Find(
		_In_ unsigned long tagType,		///< tag type to look for
		_In_ byte tagFlags,				///< tag flags to look for
		_In_ const VectorOfByte& value,	///< value to look for
		_In_ bool next = false,			///< \li true next \li false first
		_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		const Tag* tag = FindStart(next, forwards);
		while (tag != nullptr)
		{
			if (tag->Compare(tagType, tagFlags, value))
				return tag;

			tag = Traverse(forwards);
		}

		return nullptr;
	}

	/// Find a tag and value
	/// \retval nullptr if the tag is not found, and current tag is invalidated
	const Tag* Find(
		_In_ unsigned long tagType,		///< tag type to look for
		_In_ byte tagFlags,				///< tag flags to look for
		_In_ byte value1,				///< value to look for
		_In_ bool next = false,			///< \li true next \li false first
		_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		VectorOfByte value;
		value.push_back(value1);
		return Find(tagType, tagFlags, value, next, forwards);
	}

	/// \note Required by some compilers
	virtual const Tag* Traverse(_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		return inherited::Traverse(forwards);
	}

protected:
	/// \note Required by some compilers
	virtual const Tag* FindStart(
		_In_ bool next,		///< \li true next \li false first
		_In_ bool forwards)	///< direction \li true forwards \li false backwards
	{
		return inherited::FindStart(next, forwards);
	}
};

//==========================================================================================================================

template <class Tag, class Decode, class Collection>
class IteratorCollection : public BERIteratorFind<Tag, Decode>
{
	typedef BERIteratorFind<Tag, Decode> inherited;

public:
	IteratorCollection()
	{}

	explicit IteratorCollection(_In_ const Decode& decode)
		: inherited(decode)
	{}

	explicit IteratorCollection(_In_ const Iterator<Tag, Decode>& rhs)
		: inherited(rhs.m_Decode)
	{}

	/// Gets the depth of the current node
	/// \retval 0 for the root node
	size_t Depth(void) const
	{
		size_t depth = 0;

		const Decode* decode = inherited::m_Decode;
		for (;; depth++)
		{
			if (decode == nullptr)
				break;

			const Collection* parent = decode->m_Parent;
			if (parent == nullptr)
				break;						// on the root

			decode = parent->m_Parent;
		}

		return depth;
	}

	/// Has the node a parent?
	/// \return true if it has a parent
	bool HasParent(void) const
	{
		return (inherited::m_Decode != nullptr) && (inherited::m_Decode->m_Parent != nullptr);
	}

	/// Has the node a child?
	/// \return true if it has a child
	bool HasChild(void) const
	{
		if (!inherited::m_TagValid)
			return false;

		const Collection* child = dynamic_cast<const Collection*>(*inherited::m_Tag);
		if (child == nullptr)
			return false;

		return !child->m_Decode.m_TagList.empty();
	}

	/// Get the number of children
	/// \return the number of children
	size_t Children(void) const
	{
		if (!inherited::m_TagValid)
			return 0;

		const Collection* child = dynamic_cast<const Collection*>(*inherited::m_Tag);
		if (child == nullptr)
			return 0;

		return child->m_Decode.m_TagList.size();
	}

	/// Move to the root node
	/// \return The very first node
	const Tag* Root(void)
	{
		for (;;)
		{
			if (inherited::m_Decode == nullptr)
				break;

			const Collection* parent = inherited::m_Decode->m_Parent;
			if (parent == nullptr)
				break;						// on the root

			inherited::m_Decode = parent->m_Parent;
		}

		return inherited::First();
	}

	/// Move to the parent tag
	/// \retval nullptr if there is no parent tag (ie current tag is the root), and current tag remains unchanged and valid
	const Tag* Parent(void)
	{
		if (inherited::m_Decode == nullptr)
			return nullptr;

		const Collection* parent = inherited::m_Decode->m_Parent;
		if (parent == nullptr)
			return nullptr;				// on root of decode object

		inherited::m_Decode = parent->m_Parent;

		// locate parent in m_Decode tagList
		const TLV::TagList& tagList = inherited::m_Decode->Tags();
		inherited::m_TagValid = true;
		for (inherited::m_Tag = tagList.begin(); inherited::m_Tag != tagList.end(); ++inherited::m_Tag)
		{
			if (*inherited::m_Tag == parent)
				return parent;
		}

		// should never happen
		inherited::m_Tag = tagList.end();
		inherited::m_TagValid = false;
		return nullptr;
	}

	/// Move to the first child tag
	/// \note If the current tag is invalid it will get the child of the first tag at the current level
	/// \retval nullptr if there is no child tag, and current tag remains unchanged and valid
	const Tag* Child(void)
	{
		if (!inherited::m_TagValid && (inherited::First() == nullptr))
			return nullptr;					// no first node

		const Collection* child = dynamic_cast<const Collection*>(*inherited::m_Tag);
		if (child == nullptr)
			return nullptr;					// not a collection class

		if (child->m_Decode.m_TagList.empty())
			return nullptr;					// no children

		inherited::m_Decode = &child->m_Decode;
		inherited::m_Tag = inherited::m_Decode->m_TagList.begin();
		inherited::m_TagValid = true;

		return static_cast<const Tag*>(*inherited::m_Tag);
	}

	/// Move down a number of child tags
	/// \retval nullptr if there are insufficient child tags
	const Tag* Child(_In_ int count)
	{
		const Tag* tag = nullptr;
		for (int c = 0; c < count; c++)
		{
			tag = Child();
			if (tag == nullptr)
				break;
		}

		return tag;
	}

	/// Move to the last sibling of the child and descend down as far as required
	/// \retval nullptr if there are no children
	const Tag* LastChild(_In_ bool last = false)
	{
		const Tag* tag = last ? inherited::Last() : nullptr;
		for (;;)
		{
			if (Child() == nullptr)
				break;
			tag = inherited::Last();
		}

		return tag;
	}

	/// Traverse the tag tree
	/// \retval nullptr if the end of the tree has been reached, and current tag is invalidated
	virtual const Tag* Traverse(_In_ bool forwards = true)		///< direction \li true forwards \li false backwards
	{
		const Tag* tag;
		if (forwards)
		{
			tag = Child();
			if (tag != nullptr)
				return tag;
			do
			{
				tag = inherited::Next();
				if (tag != nullptr)
					return tag;

				tag = Parent();
			}
			while (tag != nullptr);
			return nullptr;
		}

		tag = inherited::Previous();
		if (tag == nullptr)
			return Parent();

		while (HasChild())
		{
			Child();
			inherited::Last();
		}
		return Current();
	}

protected:
	/// Move through a series of tags
	virtual const Tag* MoveOne(_In_ char move)			///< one of RUCTBructb or FNPLfnpl
	{
		switch (move)
		{
		case 'R':
		case 'r':
			return Root();

		case 'U':
		case 'u':
			return Parent();

		case 'C':
		case 'c':
			return Child();

		case 'T':
		case 't':
			return Traverse(true);

		case 'B':
		case 'b':
			return Traverse(false);
		}

		return inherited::MoveOne(move);
	}

	virtual const Tag* FindStart(
		_In_ bool next,		///< \li true next \li false first
		_In_ bool forwards)	///< direction \li true forwards \li false backwards
	{
		if (next)
			return Traverse(forwards);
		if (forwards)
			return Root();
		Root();
		return LastChild(true);
	}
};

} // namespace TLV
