/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
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

#ifndef UTIL_INCLUDE_CLOG_H_
#define UTIL_INCLUDE_CLOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CLOG_VERSION_MAJOR 1
#define CLOG_VERSION_MINOR 0
#define CLOG_VERSION_PATCH 0

#define CLOG_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define CLOG_VERSION \
    CLOG_MAKE_VERSION(CLOG_VERSION_MAJOR, CLOG_VERSION_MINOR, CLOG_VERSION_PATCH)

#define CLOG_DEBUG_LEVEL 500
#define CLOG_INFO_LEVEL   800
#define CLOG_NOTICE_LEVEL 800
#define CLOG_WARN_LEVEL   900
#define CLOG_ERROR_LEVEL  1000
#define CLOG_FATAL_LEVEL  2000

typedef int clog_logger_t;

// Set the output stream to print the log traffic.
// By default, log traffic is sent to stdout. If you set the stream to NULL, no stream
// will receive the log traffic.
void clog_set_logstream(FILE* stream);

// Set the logging level.
void clog_set_level(clog_logger_t *logger, int level);

// Get the logging level.
int clog_get_level(clog_logger_t logger);

// Return true if this logging level is activated.
bool clog_is_loggable(clog_logger_t logger, int l);

//  Log error condition - highest priority
void clog_fatal(clog_logger_t logger, const char *fmt, ...);

// Log error message - high priority
void clog_error (clog_logger_t logger, const char *format, ...);

//  Log warning message - low priority
void clog_warning (clog_logger_t logger, const char *format, ...);

//  Log normal, but significant, message - normal priority
void clog_notice (clog_logger_t logger, const char *format, ...);

//  Log informational message - low priority
void clog_info (clog_logger_t logger, const char *format, ...);

//  Log debug-level message - lowest priority
void clog_debug (clog_logger_t logger, const char *format, ...);

//  Log debug-level message - no header - lowest priority
void clog_debug_no_header(clog_logger_t logger, const char *fmt, ...);

//- Inevitable macros -------------------------------------------------------
#define streq(s1,s2)    (!strcmp ((s1), (s2)))
#define strneq(s1,s2)   (strcmp ((s1), (s2)))

void clog_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif /* UTIL_INCLUDE_CLOG_H_ */
