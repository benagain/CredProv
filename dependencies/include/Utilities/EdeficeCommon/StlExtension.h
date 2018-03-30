#pragma once

namespace std_ext
{
	template<class _T, class _OI> inline
	_OI copy_all(_T const& _C, _OI _X)
	{
		for ( _T::const_iterator i = _C.begin(); i != _C.end(); ++_X, ++i)
			*_X = *i;
		return (_X);
	}

	template<class _T, class _OI> inline
	_OI copy_all_ptr(_T const* _C, _OI _X)
	{
		for ( _T::const_iterator i = _C->begin(); i != _C->end(); ++_X, ++i)
			*_X = *i;
		return (_X);
	}

	template<class _I, class _Ty> inline
	_Ty accumulate_all(_I _C, _Ty _V)
	{
		for ( _I::const_iterator i = _C.begin(); i != _C.end(); ++i)
			_V = _V + *iF;
		return (_V);
	}

	template<class _I, class _Ty, class _Bop> inline
	_Ty accumulate_all(_I _C, _Ty _V, _Bop _B)
	{
		for ( _I::const_iterator i = _C.begin(); i != _C.end(); ++i)
			_V = _B(_V, *i);
		return (_V);
	}

	template<class _Container, class _Ty> inline
	typename _Container::const_iterator find(_Container const & _container, const _Ty& _Val)
    {
		return find(_container.begin(), _container.end(), _Val);
	}
}
