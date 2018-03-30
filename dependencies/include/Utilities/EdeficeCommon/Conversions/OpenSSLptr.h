#pragma once

#include <openssl/x509.h>
#include <openssl/pkcs12.h>
#include <openssl/rsa.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <boost/noncopyable.hpp>

/// \file
/// Defines classes to ease manipulation and memory management of OpenSSL structures.
///
/// * `OpenSSL::PTR::X509` creates an owning pointer to an OpenSSL `X509` object.
/// * `OpenSSL::PTR::STACK_OF_X509` creates an owning pointer to an OpenSSL `STACK_OF_X509` list.
/// * `OpenSSL::PTR::STACK_REF_X509` creates a reference wrapper to OpenSSL `STACK_OF_X509` list managed elsewhere.
///
/// Replace `X509` with your favourite OpenSSL structure.
///
/// Both the owning pointers can be constructed in three ways:
/// * With an existing pointer: the wrapper takes ownership
/// * With the default constructor: a new object is created
/// * With nullptr: the wrapper is deemed to be null.
///
/// Both the owning pointers will free their object when they themselves are destroyed.
///
/// The stack wrapping pointers provide simple manipulation of the list via
/// * OpenSSL::PTR::arr::push
/// * OpenSSL::PTR::arr::num
/// * \ref OpenSSL::PTR::arr::operator[]

namespace OpenSSL
{

/// OpenSSL pointer classes
namespace PTR
{

/// OpenSSL semi smart pointer
/// It does not do any freeing of the pointer, but gives standard full access
template <class C>
class ptr
{
public:
	operator C*() { return p; }
	operator const C*() const { return p; }
	operator bool() const {return p != nullptr;}
	bool operator!() const { return p == nullptr; }
	C& operator*() { return &p; }
	C* operator->() { return p; }
	const C* operator->() const { return p; }
	C** operator&() { return &p; }
	C* get() { return p; }
	const C* get() const { return p; }

protected:
	ptr() : p(nullptr) {}
	ptr(C* rhs) : p(rhs) {}
	ptr operator=(C* rhs) { p = rhs; return *this; }
	void reset() { p = nullptr; }

	C*	p;			///< The pointer being wrapped
};

/// Adds a free function
template <class C, void F(C*)>
class ptrfree : public ptr<C>, private boost::noncopyable
{
	typedef ptr<C> inherited;
public:
	ptrfree() {}
	ptrfree(C* rhs) : inherited(rhs) {}
	ptrfree& operator=(C* rhs) { F(inherited::p); inherited::operator=(rhs); return *this; }
	~ptrfree() { reset(); }
	/// free pointer
	void reset() { F(inherited::p); inherited::reset(); }
	/// pointer has been freed by OpenSSL
	void freed() { inherited::reset(); }
	operator bool() const { return inherited::operator bool(); }
};

/// Wraps an OpenSLL stack pointer
template <class S, class C>
class arr
{
public:
	arr() : sk(nullptr) {}
	arr(stack_st* _sk) : sk(_sk) {}
	arr(const arr& rhs) : sk(rhs.sk) {}
	arr(S* rhs) { if (rhs) sk = &rhs->stack; }
	arr& operator=(const arr& rhs) { sk = rhs.sk; return *this; }
	arr& operator=(stack_st* rhs) { sk = rhs; return *this; }
	arr& operator=(S* rhs) { if (rhs) sk = &rhs->stack; return *this; }

	operator bool() const {return sk != nullptr;}
	bool operator!() const { return sk == nullptr; }

	operator stack_st*() { return sk; }
	int push(C* rhs) { return sk_push(sk, rhs); }
	int num() const { return sk_num(sk); }
	C* operator[](int pos) { return (C*)sk_value(sk, pos); }

protected:
	stack_st*	sk;					///< OpenSSL safestack weak pointer (_STACK)
};

/// Handles allocated stacks
template <class S, class C>
class ptrstack : public ptr<S>, private boost::noncopyable
{
	typedef ptr<S> inherited;
public:
	ptrstack() : inherited((S*)sk_new_null()) {}
	ptrstack(S* rhs) : inherited(rhs) {}
	ptrstack& operator=(S* rhs) { sk_free(&inherited::p->stack); inherited::operator=(rhs); return *this; }
	~ptrstack() { reset(); }
	/// free pointer
	void reset() { sk_free(&inherited::p->stack); inherited::reset(); }
	/// pointer has been freed by OpenSSL
	void freed() { inherited::reset(); }

	operator stack_st*() { return &inherited::p->stack; }
	/// add to stack
	int push(C* rhs) { return sk_push(&inherited::p->stack, rhs); }
	/// number of items in the stack
	int num() const { return sk_num(&inherited::p->stack); }
	/// classic [] implementation
	C* operator[](int pos) { return (C*)sk_value(&inherited::p->stack, pos); }
};

} // namespace PTR

//======================================================================================================================================
// define boilerplate classes
#define OPENSSL_FREE_CLASS_NF(C, N, F)			\
class C : public PTR::ptrfree< ::C, F>			\
{												\
	typedef PTR::ptrfree< ::C, F> inherited;	\
public:											\
	C() : inherited(N) {}						\
	C(::C* rhs) : inherited(rhs) {}				\
	C& operator=(::C* rhs) {inherited::operator=(rhs); return *this;}	\
	void create() {inherited::reset(); inherited::operator=(N);}		\
};
#define OPENSSL_FREE_CLASS(C) OPENSSL_FREE_CLASS_NF(C, C##_new(), C##_free)

#define OPENSSL_FREE_CLASS_SK(C)							\
class STACK_OF_##C : public PTR::ptrstack<STACK_OF(C), ::C>	\
{															\
	typedef PTR::ptrstack<STACK_OF(C), ::C> inherited;		\
public:														\
	STACK_OF_##C() {}										\
	STACK_OF_##C(STACK_OF(C)* rhs) : inherited(rhs) {}		\
	STACK_OF_##C& operator=(STACK_OF(C)* rhs) {inherited::operator=(rhs); return *this;}	\
};

#define OPENSSL_REF_CLASS_SK(C)								\
class STACK_REF_##C : public PTR::arr<STACK_OF(C), ::C>		\
{															\
	typedef PTR::arr<STACK_OF(C), ::C> inherited;			\
public:														\
	STACK_REF_##C() {}										\
	STACK_REF_##C(STACK_OF(C)* rhs) : inherited(rhs) {}		\
	STACK_REF_##C& operator=(STACK_OF(C)* rhs) {inherited::operator=(rhs); return *this;}	\
};

//======================================================================================================================================

OPENSSL_FREE_CLASS(X509)
OPENSSL_FREE_CLASS(X509_REQ)
OPENSSL_FREE_CLASS(X509_CRL)
OPENSSL_FREE_CLASS(PKCS7)
OPENSSL_FREE_CLASS(PKCS12)
OPENSSL_FREE_CLASS(EVP_PKEY)
OPENSSL_FREE_CLASS(RSA)
OPENSSL_FREE_CLASS(EC_KEY)
OPENSSL_FREE_CLASS(ASN1_OBJECT)
OPENSSL_FREE_CLASS(ASN1_BIT_STRING)
OPENSSL_FREE_CLASS(ASN1_INTEGER)
OPENSSL_FREE_CLASS(ASN1_STRING)
OPENSSL_FREE_CLASS(ASN1_TIME)
OPENSSL_FREE_CLASS(ASN1_TYPE)
OPENSSL_FREE_CLASS_NF(EVP_PKEY_CTX, nullptr, EVP_PKEY_CTX_free)
OPENSSL_FREE_CLASS_NF(BIO, BIO_new(BIO_s_mem()), BIO_vfree)
OPENSSL_FREE_CLASS_NF(BIGNUM, BN_new(), BN_clear_free)
OPENSSL_FREE_CLASS_SK(X509)
OPENSSL_REF_CLASS_SK(ASN1_INTEGER)
OPENSSL_REF_CLASS_SK(X509)

} // namespace OpenSSL
