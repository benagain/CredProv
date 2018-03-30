#pragma once
#ifndef NO_MSXML
#include <boost/iterator/iterator_facade.hpp>

namespace eXML
{
	class XmlIterator : public boost::iterator_facade<XmlIterator, MSXML::IXMLDOMNodePtr, boost::bidirectional_traversal_tag, MSXML::IXMLDOMNodePtr>
	{
	public:
		XmlIterator(MSXML::IXMLDOMNodeListPtr nodeList = nullptr, difference_type pos = 0) : base_(nodeList), position_(pos) {};

		MSXML::IXMLDOMNode* dereference() const
		{
			if(position_ > base_->length)
				throw std::out_of_range("Index out of bounds.");

			return base_->Getitem(static_cast<long>(position_));
		}

		MSXML::IXMLDOMNodePtr operator*()
		{
			return base_->Getitem(static_cast<long>(position_));
		}

		MSXML::IXMLDOMNodePtr operator->()
		{
			return operator*();
		}

		bool equal(XmlIterator const& other) const
		{
			return (this->position_ == other.position_);
		}

		void decrement()
		{
			if(position_ <= 0)
				throw std::out_of_range("Index out of bound");

			position_--;
		}

		void increment()
		{
			position_++;
		}

	protected:

		MSXML::IXMLDOMNodeListPtr base_;

		difference_type position_;
	};

	struct NodeList
	{
		static XmlIterator begin( MSXML::IXMLDOMNodeListPtr& nodeList )
		{
			return XmlIterator( nodeList );
		}

		static XmlIterator end( MSXML::IXMLDOMNodeListPtr& nodeList )
		{
			return XmlIterator( nodeList, nodeList->length );
		}
	};
}
#endif
