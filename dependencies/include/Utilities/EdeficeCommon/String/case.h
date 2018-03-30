template <typename C>
struct case_insensitive_equal
{
	bool operator()(C a, C b) const {
		return tolower(a) == tolower(b);
	}
};


// iequal - case insensitive equal
template<class T>
bool iequal( T const& lhs, T const& rhs )
{
	return iequal<T>( lhs.begin(), lhs.end(), rhs.begin() );
}

template<class T>
bool iequal( typename T::const_iterator lhBegin, typename T::const_iterator lhEnd, typename T::const_iterator rhBegin )
{
	return std::equal(
		lhBegin,
		lhEnd,
		rhBegin,
		case_insensitive_equal<T::value_type>()
	);
}