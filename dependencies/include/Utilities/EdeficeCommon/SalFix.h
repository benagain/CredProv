#pragma once

// see no_sal.h
#if defined(WIN32) && !defined(DOXYGEN)
#include <sal.h>
#endif

#if defined(MOBILE) || !defined(_SAL_VERSION) || defined(DOXYGEN)
// eliminate SAL 2 for mobile or VS2010
#ifdef _In_reads_
#undef _In_reads_
#endif
#define _In_reads_(s)

#ifdef _In_reads_bytes_
#undef _In_reads_bytes_
#endif
#define _In_reads_bytes_(size)

#ifdef _In_reads_bytes_opt_
#undef _In_reads_bytes_opt_
#endif
#define _In_reads_bytes_opt_(size)

#ifdef _In_reads_opt_z_
#undef _In_reads_opt_z_
#endif
#define _In_reads_opt_z_(size)

#ifdef _Inout_updates_
#undef _Inout_updates_
#endif
#define _Inout_updates_(s)

#ifdef _Inout_updates_bytes_
#undef _Inout_updates_bytes_
#endif
#define _Inout_updates_bytes_(s)

#ifdef _Out_writes_bytes_opt_
#undef _Out_writes_bytes_opt_
#endif
#define _Out_writes_bytes_opt_(size)

#ifdef _Outptr_
#undef _Outptr_
#endif
#define _Outptr_

#ifdef _Always_
#undef _Always_
#endif
#define _Always_(annos)

#ifdef _Maybenull_
#undef _Maybenull_
#endif
#define _Maybenull_

#ifdef _Ret_maybenull_z_
#undef _Ret_maybenull_z_
#endif
#define _Ret_maybenull_z_

#endif

#if defined(MOBILE) || defined(DOXYGEN)
// eliminate SAL 1 & 2 for mobile
#ifdef _In_
#undef _In_
#endif
#define _In_

#ifdef _In_z_
#undef _In_z_
#endif
#define _In_z_

#ifdef _In_opt_
#undef _In_opt_
#endif
#define _In_opt_

#ifdef _In_opt_z_
#undef _In_opt_z_
#endif
#define _In_opt_z_

#ifdef _Inout_
#undef _Inout_
#endif
#define _Inout_

#ifdef _Inout_opt_
#undef _Inout_opt_
#endif
#define _Inout_opt_

#ifdef _Inout_z_
#undef _Inout_z_
#endif
#define _Inout_z_

#ifdef _In_count_
#undef _In_count_
#endif
#define _In_count_(size)

#ifdef _In_z_count_
#undef _In_z_count_
#endif
#define _In_z_count_(size)

#ifdef _Inout_bytecount_
#undef _Inout_bytecount_
#endif
#define _Inout_bytecount_(size)

#ifdef _Out_
#undef _Out_
#endif
#define _Out_

#ifdef _Out_cap_
#undef _Out_cap_
#endif
#define _Out_cap_(size)

#ifdef _Out_opt_
#undef _Out_opt_
#endif
#define _Out_opt_

#ifdef _Printf_format_string_
#undef _Printf_format_string_
#endif
#define _Printf_format_string_

#ifdef _Ret_maybenull_
#undef _Ret_maybenull_
#endif
#define _Ret_maybenull_

#ifdef __analysis_assume
#undef __analysis_assume
#endif
#define __analysis_assume(size)

#define OKBOOL bool
#define UNREFERENCED_PARAMETER(p) (p)

#else

#if defined(DOXYGEN)
#define OKBOOL bool
#else
#define OKBOOL _Success_(return != false) bool
#endif

#endif