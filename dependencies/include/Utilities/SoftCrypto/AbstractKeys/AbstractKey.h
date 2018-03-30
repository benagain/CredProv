#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"
#include <string>
#include <boost/shared_ptr.hpp>
#include "AbstractKeyParameters.h"

/** Define abstract base classes which are flexible enough to allow concrete implementations
in either software or HSM.*/
namespace AbstractKeys
{
class AbstractKey;
typedef boost::shared_ptr<AbstractKey> AbstractKeyPtr;


/** Because HSM will depend on session/login state, an AbstractKey should never be directly
creatable. It should only be creatable via an AbstractKeyFactory*/
class AbstractKeyFactory
{
public:
	AbstractKeyFactory(void) {}
	virtual ~AbstractKeyFactory(void) {}

	/// Create empty AbstractKey object. Throws exception if KeyType is not supported
	virtual AbstractKeyPtr Create(_In_ const KeyFamily &family) = 0;

	/// we need to know if keys can be exported
	virtual bool AreExportableKeysAvailable() = 0;
};
typedef boost::shared_ptr<AbstractKeyFactory> AbstractKeyFactoryPtr;



/** Keys should inherit off this
For overview see /file:AbstractKeys.doc
Design Goals of AbstractKey class
- Both software and HSM implementations can implement this class.
- Only difference in usage of keys (as far as calling program is concerned) is
the factory class that was used to instantiate the key class.
- HSM keys can interact with Software keys (and class implementation will concern itself
about how to make the fundamentally different keytypes interact successfully
*/
class AbstractKey
{
protected:
	AbstractKey(void) {} // protected constructor - must be created by appropriate AbstractKeyFactory
public:
	// void AbstractKey(AbstractKeyFactoryPtr &factory); --concrete implementations will most likely need to maintain a backptr to the factory
	virtual ~AbstractKey(void) {}

	virtual void Generate(_In_ KeyParametersPtr pKeyParameters) = 0;

	virtual VectorOfBytePtr Encrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters) = 0;
	virtual VectorOfBytePtr Decrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters) = 0;
	virtual VectorOfBytePtr Sign(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters) = 0;
	virtual bool Verify(_In_ const VectorOfByte &data, _In_ const VectorOfByte &signature, _In_ CryptParameters &Parameters) = 0;

	/// Import vecKeyData (unwrapping with UnwrappingKey) into this object
	virtual void Import(_In_ const std::wstring &wstrKeyData,
		_In_ const KeyFormat &format,
		_In_ CryptParameters &unwrapParameters,
		_In_ KeyParametersPtr importedKeyParameters, // Parameters (attributes) this key will have once imported
		_In_ AbstractKeyPtr &UnwrappingKey) = 0;

	/// Export this key (wrapped by WrappingKey)
	virtual std::wstring Export(_In_ const KeyFormat &format, _In_ CryptParameters &wrapParameters, _In_ AbstractKeyPtr &WrappingKey) = 0;

	/// Destroy this key. If it is persisted (e.g. in HSM), key will be permanently destroyed. return true for success
	virtual bool DestroyKey() = 0;

	/// derive (and return) a new key object, based on supplied derivation data and derivation parameters (e.g. specifying ECB). The new key returned will have the specified newKeyParameters (if supplied)
	virtual AbstractKeyPtr DeriveKey(_In_ const VectorOfByte &vecDerivationData, _In_ CryptParameters &deriveParams, _In_ KeyParametersPtr &newKeyParameters) = 0;

	virtual KeyParametersPtr GetKeyParameters() const = 0;

	/// Import wstrKeyData (unwrapping with UnwrappingKey) into this object
	virtual void ImportEx(_In_ const VectorOfByte &vecKeyData,
		_In_ const KeyFormat &format,
		_In_ CryptParameters &unwrapParameters,
		_In_ KeyParametersPtr importedKeyParameters, // Parameters (attributes) this key will have once imported
		_In_ AbstractKeyPtr &UnwrappingKey) = 0;

	/// Export this key (wrapped by WrappingKey)
	virtual VectorOfBytePtr ExportEx(_In_ const KeyFormat &format, _In_ CryptParameters &wrapParameters, _In_ AbstractKeyPtr &WrappingKey) = 0;
};

/** DESKeys (DES/2DES/3DES) should inherit off this. Standard AbstractKey
methods Encrypt, etc... are used for DES operations*/
class DESKey
{
public:
	virtual ~DESKey(void) {} // define virtual destructor in case some code has a ptr to this class, then calls delete
};

/** AESKeys (AES128/AES192/AES256) should inherit off this.*/
class AESKey
{
public:
	virtual ~AESKey(void) {} // define virtual destructor in case some code has a ptr to this class, then calls delete
};

/** HMACKey implementations should inherit off this.*/
class HMACKey
{
public:
	virtual ~HMACKey(void) {} // define virtual destructor in case some code has a ptr to this class, then calls delete
};

class RSAKey
{
public:
	virtual ~RSAKey(void) {}
};

/** ECCKeys (256/384/521) should inherit off this.*/
class ECCKey
{
public:
	virtual ~ECCKey(void) {} // define virtual destructor in case some code has a ptr to this class, then calls delete
};


/** Random Number Generation. Not a key as such - more a mechanism to allow generation of
random data.
Is to be used by Generating random data, and then Exporting data.
This class should be inherited off*/
class RNG : public AbstractKey
{
protected:
	RNG(void) {} // protected constructor - must be created by appropriate AbstractKeyFactory

public:
	// following methods are implemented to throw exception, because they are not needed
	virtual VectorOfBytePtr Encrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters);
	virtual VectorOfBytePtr Decrypt(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters);
	virtual VectorOfBytePtr Sign(_In_ const VectorOfByte &data, _In_ CryptParameters &Parameters);
	virtual bool Verify(_In_ const VectorOfByte &data, _In_ const VectorOfByte &signature, _In_ CryptParameters &Parameters);

	virtual void Import(_In_ const std::wstring &wstrKeyData, _In_ const KeyFormat &format, _In_ CryptParameters &unwrapParameters, _In_ KeyParametersPtr importedKeyParameters, _In_ AbstractKeyPtr &UnwrappingKey);

	virtual bool DestroyKey();
	virtual AbstractKeyPtr DeriveKey(_In_ const VectorOfByte &vecDerivationData, _In_ CryptParameters &deriveParams, _In_ KeyParametersPtr &newKeyParameters);
	virtual KeyParametersPtr GetKeyParameters() const { return KeyParametersPtr(); }

	virtual void ImportEx(_In_ const VectorOfByte &vecKeyData, _In_ const KeyFormat &format, _In_ CryptParameters &unwrapParameters, _In_ KeyParametersPtr importedKeyParameters, _In_ AbstractKeyPtr &UnwrappingKey);

	// therefore inherited class must implement Generate, Export and ExportEx
};


/** Implementations which use Hardware (HSM) should also inherit of this to denote their
status as HSM.
Note that since HSM (e.g. Pkcs11) will most likely support and enforce attributes natively,
attribute checking will be implicit in the Pkcs11 calls*/
class HardKey {};

}

