/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __MALATTRIBUTES_H_INCLUDED__
#define __MALATTRIBUTES_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//- Standard ANSI include files ---------------------------------------------

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define MALATTRIBUTES_VERSION_MAJOR 1
#define MALATTRIBUTES_VERSION_MINOR 2
#define MALATTRIBUTES_VERSION_PATCH 1

#define MALATTRIBUTES_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALATTRIBUTES_VERSION \
    MAL_MAKE_VERSION(MALATTRIBUTES_VERSION_MAJOR, MALATTRIBUTES_VERSION_MINOR, MALATTRIBUTES_VERSION_PATCH)

//- Inevitable macros -------------------------------------------------------
#define streq(s1,s2)    (!strcmp ((s1), (s2)))
#define strneq(s1,s2)   (strcmp ((s1), (s2)))

// Prefix is 'mal' even if defined in 'malattributes'
typedef struct _mal_blob_t mal_blob_t;
typedef bool mal_boolean_t;
typedef float mal_float_t;
typedef double mal_double_t;
typedef char mal_octet_t;
typedef unsigned char mal_uoctet_t;
typedef int16_t mal_short_t;
typedef uint16_t mal_ushort_t;
typedef int32_t mal_integer_t;
typedef uint32_t mal_uinteger_t;
typedef int64_t mal_long_t;
typedef uint64_t mal_ulong_t;
typedef char mal_string_t;
typedef char mal_identifier_t;
typedef char mal_uri_t;
typedef uint64_t mal_time_t;
typedef uint64_t mal_finetime_t;
// TODO: Be careful, during MAL/ZMTP interop duration was defined as a float (fixed by Guilhem).
// typedef float mal_duration_t;
typedef double mal_duration_t;

#define MAL_BLOB_SHORT_FORM INT64_C(0x1000001000001)
#define MAL_BOOLEAN_SHORT_FORM INT64_C(0x1000001000002)
#define MAL_DURATION_SHORT_FORM INT64_C(0x1000001000003)
#define MAL_FLOAT_SHORT_FORM INT64_C(0x1000001000004)
#define MAL_DOUBLE_SHORT_FORM INT64_C(0x1000001000005)
#define MAL_IDENTIFIER_SHORT_FORM INT64_C(0x1000001000006)
#define MAL_OCTET_SHORT_FORM INT64_C(0x1000001000007)
#define MAL_UOCTET_SHORT_FORM INT64_C(0x1000001000008)
#define MAL_SHORT_SHORT_FORM INT64_C(0x1000001000009)
#define MAL_USHORT_SHORT_FORM INT64_C(0x100000100000A)
#define MAL_INTEGER_SHORT_FORM INT64_C(0x100000100000B)
#define MAL_UINTEGER_SHORT_FORM INT64_C(0x100000100000C)
#define MAL_LONG_SHORT_FORM INT64_C(0x100000100000D)
#define MAL_ULONG_SHORT_FORM INT64_C(0x100000100000E)
#define MAL_STRING_SHORT_FORM INT64_C(0x100000100000F)
#define MAL_TIME_SHORT_FORM INT64_C(0x1000001000010)
#define MAL_FINETIME_SHORT_FORM INT64_C(0x1000001000011)
#define MAL_URI_SHORT_FORM INT64_C(0x1000001000012)

#define MAL_BLOB_LIST_SHORT_FORM INT64_C(0x1000001FFFFFF)
#define MAL_BOOLEAN_LIST_SHORT_FORM INT64_C(0x1000001FFFFFE)
#define MAL_DURATION_LIST_SHORT_FORM INT64_C(0x1000001FFFFFD)
#define MAL_FLOAT_LIST_SHORT_FORM INT64_C(0x1000001FFFFFC)
#define MAL_DOUBLE_LIST_SHORT_FORM INT64_C(0x1000001FFFFFB)
#define MAL_IDENTIFIER_LIST_SHORT_FORM INT64_C(0x1000001FFFFFA)
#define MAL_OCTET_LIST_SHORT_FORM INT64_C(0x1000001FFFFF9)
#define MAL_UOCTET_LIST_SHORT_FORM INT64_C(0x1000001FFFFF8)
#define MAL_SHORT_LIST_SHORT_FORM INT64_C(0x1000001FFFFF7)
#define MAL_USHORT_LIST_SHORT_FORM INT64_C(0x1000001FFFFF6)
#define MAL_INTEGER_LIST_SHORT_FORM INT64_C(0x1000001FFFFF5)
#define MAL_UINTEGER_LIST_SHORT_FORM INT64_C(0x1000001FFFFF4)
#define MAL_LONG_LIST_SHORT_FORM INT64_C(0x1000001FFFFF3)
#define MAL_ULONG_LIST_SHORT_FORM INT64_C(0x1000001FFFFF2)
#define MAL_STRING_LIST_SHORT_FORM INT64_C(0x1000001FFFFF1)
#define MAL_TIME_LIST_SHORT_FORM INT64_C(0x1000001FFFFF0)
#define MAL_FINETIME_LIST_SHORT_FORM INT64_C(0x1000001FFFFEF)
#define MAL_URI_LIST_SHORT_FORM INT64_C(0x1000001FFFFEE)

// There's a difference between attribute short form values and tag values that seems to be mixed up in the NanoSat MO Framework (NMF).
// Some responses to a request interaction includes the attribute types' short form values which are then decoded as if they were tag values.
// The decoding in question happens in the malbinary project's malbinary_decoder_decode_attribute function.
// It could be that NMF is MAL response messages includes the attribute short form values instead of the tag values.
// As a workaround, defining this macro name will increment all tag values by one thus decoding them as short form values instead of tags.
//
// See section 5.2.1. of document CCSDS 524.2-R-1 or the GitHub Issue discussed here: https://github.com/CNES/ccsdsmo-malc/issues/56
// This is a workaround and by no means a permanent fix.
#define MAL_ATTRIBUTES_NMF_TAG_HOTFIX 1

//  Public API classes
#include "mal_blob.h"
#include "mal_string.h"
#include "mal_identifier.h"
#include "mal_uri.h"
#include "mal_attribute.h"

#ifdef __cplusplus
}
#endif

#endif /* MALATTRIBUTES_H_ */
