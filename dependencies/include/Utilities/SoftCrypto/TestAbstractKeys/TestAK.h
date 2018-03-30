#pragma once

#include "Utilities/SoftCrypto/AbstractKeys/SoftwareKeyFactory.h"

using namespace AbstractKeys;

namespace
{
	// NOTE - The arguments are written in this order to highlight that this is the order that they must be processed in.
	// The argument with the largest number of characters must be checked for first otherwise /SN could be read as /S, etc.
	std::wstring const g_wstrPWDArg = L"/PWD:";
	std::wstring const g_wstrSNArg = L"/SN:";
	std::wstring const g_wstrThreadsArg = L"/T:";
	std::wstring const g_wstrNCipherArg = L"/N:";
	std::wstring const g_wstrLunaArg = L"/L:";
	std::wstring const g_wstrIterationsArg = L"/I:";
	std::wstring const g_wstrReportPassed = L"/RP";
	std::wstring const g_wstrReportFailures = L"/RF";
	std::wstring const g_wstrSoftCryptoArg = L"/S";
	std::wstring const g_wstrSaveResults = L"/O";
	std::wstring const g_wstrCallbacksArg = L"/C";
	std::wstring const g_wstrHelpArg = L"/H";
	std::wstring const g_wstrVersionArg = L"/V";
	std::wstring const g_wstrHelpArg2 = L"/?";

	std::wstring const g_wstrSeparatorLine = L"************************";
}

void TestAESKeyDerive(AbstractKeyFactoryPtr pFactory);
void TestAESEncryptThenDecrypt(AbstractKeyFactoryPtr pFactory);
void TestAESKnownVector(AbstractKeyFactoryPtr pFactory, const std::wstring &wstrKeyPlaintext, const std::wstring &wstrCipher, const std::wstring &wstrDecipher);
void TestAESKnownVectors(AbstractKeyFactoryPtr pFactory);
void TestAESClearExportThenImport(AbstractKeyFactoryPtr pFactoryExport, AbstractKeyFactoryPtr pFactoryImport, AESKeyParameters::AESKeyType typeAES, bool bTestKCV = false);

void Test3DESEncryptThenDecrypt(AbstractKeyFactoryPtr pFactory);
void Test2DESKeyDerive(AbstractKeyFactoryPtr pFactory);
void Test2DESClearExportThenImport(AbstractKeyFactoryPtr pFactoryExport, AbstractKeyFactoryPtr pFactoryImport, bool bTestKCV = false);
void Test3DESWrapUnwrapWith2DES(AbstractKeyFactoryPtr pFactoryKeyToExport, AbstractKeyFactoryPtr pFactoryTransportKey, AbstractKeyFactoryPtr pFactoryReImportKey);

void TestHMACKeyImportExport(AbstractKeyFactoryPtr pFactory);
void TestHKDFAlgorithm_TC1(AbstractKeyFactoryPtr pFactory);
void TestHKDFAlgorithm_TC4(AbstractKeyFactoryPtr pFactory);

void TestRNG(AbstractKeyFactoryPtr pFactory);

void TestRSA_PKCS8ToCSPConversion(const std::wstring &wstrCSPPrivateKey, const std::wstring &wstrPKCS8PrivateKey);

void TestRSA(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestRSA_SignVerifySHA1Raw(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestRSA_SignVerifySHA1OID(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestRSA_SignVerifySHA256Raw(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestRSA_SignVerifySHA256OID(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);

void TestECC(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestECCRoundtrip(_In_ unsigned long size = 256, _In_ bool dsa = true);
//void TestECC_PKCS1(AbstractKeyFactoryPtr pFactory, AbstractKeyFactoryPtr pWrapkeyFactory);
void TestECCSign(const VectorOfByte& hash, MyCrypto::EccKey& key, const AbstractKeys::ECCCryptParameters& crypt);
void TestECCPKCS10Request(AbstractKeyFactoryPtr pFactory, long lKeyPairSizeBits = 256, bool bReverseDN=false);

void TestSP800_108(AbstractKeyFactoryPtr pFactory);
void TestSP800_38B(AbstractKeyFactoryPtr pFactory);

void TestSymmetricWrapUnwrap(AbstractKeyFactoryPtr pFactoryKeyToExport, AbstractKeyFactoryPtr pFactoryTransportKey, AbstractKeyFactoryPtr pFactoryReImportKey, KeyParametersPtr pParamKeyToExport, KeyParametersPtr pParamTransportKey);
void TestAESWrapUnwrapWithAES(AbstractKeyFactoryPtr pFactoryKeyToExport, AbstractKeyFactoryPtr pFactoryTransportKey, AbstractKeyFactoryPtr pFactoryReImportKey, AESKeyParameters::AESKeyType typeKeyToExport, AESKeyParameters::AESKeyType typeTransportKey);

bool VectorsEqual(const VectorOfByte &vec1, const VectorOfByte &vec2);
