// although we are defining this NET value, based on the underlying _MSC_VER value, we might in the future need sp1 level (non 100s) checks
#if NET == 1800
#	define VSVER VC12
#	define FILEVERSION_MAJOR_HI	7
#elif NET == 1700
#	define VSVER VC11
#	define FILEVERSION_MAJOR_HI	6
#elif NET == 1600
#	define VSVER VC10
#	define FILEVERSION_MAJOR_HI	5
#elif NET == 1500
#	define VSVER VC9
#	define FILEVERSION_MAJOR_HI	4
#elif NET == 1400
#	define VSVER VC8
#	define FILEVERSION_MAJOR_HI	3
#elif NET
#	define VSVER VC7
#	define FILEVERSION_MAJOR_HI	2
#else
#	define VSVER .
#	define FILEVERSION_MAJOR_HI	1
#endif
