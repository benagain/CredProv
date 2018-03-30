#pragma once

/// Atomic loading of OpenSSL digests and ciphers
/// Also sets FIPS mode
class LoadOpenSSL
{
public:
	LoadOpenSSL(void);

	static void Load(_In_ bool fips = true);
	static bool FipsMode(void);
	static void FipsMode(_In_ bool fips);
	static void LogFipsMode(void);
};
