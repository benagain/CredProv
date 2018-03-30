#pragma once

/**
	Understands the padding and hashing schemes used by RSA.
 */
class RsaDataFormatter
{
public:
	enum PaddingType
	{
		pad_type_none,
		pad_type_1,
		pad_type_2
	};

	enum HashingType
	{
		hash_none,
		hash_sha1,
		hash_sha256,
		hash_sha384,
		hash_sha512
	};

	/**
		Remove RSA padding, returning the plain data in a new VectorOfByte.
	 */
	VectorOfByte remove( VectorOfByte const& padded );

	/**
		Remove RSA padding, the contents of padded will be replaced with the unpadded data
	 */
	void removeInPlace( VectorOfByte & padded );

	/**
		Pad or hash the data to depending on the parameters passed.
	 */
	VectorOfBytePtr process( const VectorOfByte& data, size_t paddedSize, PaddingType padType = pad_type_1, HashingType hashType = hash_none );

protected:
	/**
		Remove the first byte from data to be unpadded.
		RSA unpadding algorithms do not expect the first null octet to be present but most
		providers leave it in.  This octet should always be zero.
	 */
	void removeLeadingOctet( VectorOfByte & padded );

	/**
		Remove the padding from padded using the appropriate algorithms depending on the padding type.
	 */
	void removePadding( VectorOfByte & padded );

	/**
		Remove type 1 padding from padded.

		\return the return code from the RSA algorithm
	 */
	int removePaddingType1( VectorOfByte & padded );

	/**
		Remove type 2 padding from padded.

		\return the return code from the RSA algorithm
	 */
	int removePaddingType2( VectorOfByte & padded );

	/**
		Translates rc into an appropriate exception if it indicates an error condition.  Otherwise 
		does nothing.
		\throw std::runtime_error
	 */
	void throwOnUnpadError( int rc );

	/**
		Pad the given data to the paddedSize using the specified padType
	 */
	VectorOfBytePtr padData( VectorOfBytePtr data, size_t paddedSize, PaddingType padType );

	/**
		Hash the data using the specified system.
	 */
	VectorOfBytePtr hashData( VectorOfBytePtr data, HashingType hashType );

	/**
		Create a SHA1 hash of the given data
	 */
	VectorOfBytePtr sha1Hash(const VectorOfByte& data);

	/**
		Create a SHA256 hash of the given data
	 */
	VectorOfBytePtr sha256Hash(const VectorOfByte& data);

	/**
		Create a SHA384 hash of the given data
	 */
	VectorOfBytePtr sha384Hash(const VectorOfByte& data);

	/**
		Create a SHA512 hash of the given data
	 */
	VectorOfBytePtr sha512Hash(const VectorOfByte& data);

};

