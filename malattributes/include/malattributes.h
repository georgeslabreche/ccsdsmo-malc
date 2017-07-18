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

#define MALATTRIBUTES_VERSION_MAJOR 1
#define MALATTRIBUTES_VERSION_MINOR 0
#define MALATTRIBUTES_VERSION_PATCH 0

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
typedef short mal_short_t;
typedef unsigned short mal_ushort_t;
typedef int mal_integer_t;
typedef unsigned int mal_uinteger_t;
typedef long mal_long_t;
typedef unsigned long mal_ulong_t;
typedef char mal_string_t;
typedef char mal_identifier_t;
typedef char mal_uri_t;
typedef unsigned long mal_time_t;
typedef unsigned long mal_finetime_t;
// TODO: Be careful, during MAL/ZMTP interop duration was defined as a float (fixed by Guilhem).
// typedef float mal_duration_t;
typedef double mal_duration_t;

#define MAL_BLOB_SHORT_FORM 0x1000001000001L
#define MAL_BOOLEAN_SHORT_FORM 0x1000001000002L
#define MAL_DURATION_SHORT_FORM 0x1000001000003L
#define MAL_FLOAT_SHORT_FORM 0x1000001000004L
#define MAL_DOUBLE_SHORT_FORM 0x1000001000005L
#define MAL_IDENTIFIER_SHORT_FORM 0x1000001000006L
#define MAL_OCTET_SHORT_FORM 0x1000001000007L
#define MAL_UOCTET_SHORT_FORM 0x1000001000008L
#define MAL_SHORT_SHORT_FORM 0x1000001000009L
#define MAL_USHORT_SHORT_FORM 0x100000100000AL
#define MAL_INTEGER_SHORT_FORM 0x100000100000BL
#define MAL_UINTEGER_SHORT_FORM 0x100000100000CL
#define MAL_LONG_SHORT_FORM 0x100000100000DL
#define MAL_ULONG_SHORT_FORM 0x100000100000EL
#define MAL_STRING_SHORT_FORM 0x100000100000FL
#define MAL_TIME_SHORT_FORM 0x1000001000010L
#define MAL_FINETIME_SHORT_FORM 0x1000001000011L
#define MAL_URI_SHORT_FORM 0x1000001000012L

#define MAL_BLOB_LIST_SHORT_FORM 0x1000001FFFFFFL
#define MAL_BOOLEAN_LIST_SHORT_FORM 0x1000001FFFFFEL
#define MAL_DURATION_LIST_SHORT_FORM 0x1000001FFFFFDL
#define MAL_FLOAT_LIST_SHORT_FORM 0x1000001FFFFFCL
#define MAL_DOUBLE_LIST_SHORT_FORM 0x1000001FFFFFBL
#define MAL_IDENTIFIER_LIST_SHORT_FORM 0x1000001FFFFFAL
#define MAL_OCTET_LIST_SHORT_FORM 0x1000001FFFFF9L
#define MAL_UOCTET_LIST_SHORT_FORM 0x1000001FFFFF8L
#define MAL_SHORT_LIST_SHORT_FORM 0x1000001FFFFF7L
#define MAL_USHORT_LIST_SHORT_FORM 0x1000001FFFFF6L
#define MAL_INTEGER_LIST_SHORT_FORM 0x1000001FFFFF5L
#define MAL_UINTEGER_LIST_SHORT_FORM 0x1000001FFFFF4L
#define MAL_LONG_LIST_SHORT_FORM 0x1000001FFFFF3L
#define MAL_ULONG_LIST_SHORT_FORM 0x1000001FFFFF2L
#define MAL_STRING_LIST_SHORT_FORM 0x1000001FFFFF1L
#define MAL_TIME_LIST_SHORT_FORM 0x1000001FFFFF0L
#define MAL_FINETIME_LIST_SHORT_FORM 0x1000001FFFFEFL
#define MAL_URI_LIST_SHORT_FORM 0x1000001FFFFEEL

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
