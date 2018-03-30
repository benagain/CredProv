#pragma once

/** \file
 * Definition of BuilderValue template
 */

#include "BERBuilder.h"
#include "SimpleTLVBuilder.h"

namespace myid
{
namespace TLV
{

/// Generates arrays with separate TL and V parts
template <class T>
class BuilderValue : public T
{
	typedef T inherited;

public:
	BuilderValue()
	{
	}

	BuilderValue<T>& operator=(_In_ const BuilderValue<T>& rhs)
	{
		inherited::operator=(rhs);

		m_Value = rhs.m_Value;

		return *this;
	}

	/// Extract the value part
	VectorOfByte Value(void) const
	{
		return m_Value;
	}

protected:
	/// Append to value part
	virtual void AppendValue(_In_ size_t ValueLength, _In_ const VectorOfByte& Value)
	{
		if (ValueLength > 0)
		{
			m_Value += Value;
		}
	}

	/// Reserve space
	void Reserve(_In_ size_t Tag, _In_ size_t Length, _In_ size_t Value)
	{
		this->reserve(this->size() + Tag + Length);
		m_Value.reserve(m_Value.size() + Value);
	}

	VectorOfByte	m_Value;			///< separate value array
};

typedef BuilderValue<TLVBuilder> TLVBuilderValue;
typedef BuilderValue<BERBuilder> BERBuilderValue;
typedef BuilderValue<SimpleTLVBuilder> SimpleTLVBuilderValue;

} // namespace TLV

} // namespace myid