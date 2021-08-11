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

/*
 */

#include "clog.h"
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>

FILE* out;

static void init_streams(void) __attribute__((constructor));
static void init_streams(void) {
  out = stdout;
}

// Set stream to receive log traffic. By default, log traffic is sent to stdout.
// If you set the stream to NULL, no stream will receive the log traffic.
void clog_set_logstream(FILE *stream) {
  out = stream;
}

// Set the log level. By default WARN.
void clog_set_level(clog_logger_t *logger, int l) {
  *logger = l;
}

int clog_get_level(clog_logger_t logger) {
  return logger;
}

bool clog_is_loggable(clog_logger_t logger, int l) {
  return (l <= logger);
}

void clog_print_header(char *fmt) {
  struct tm* now_tm;
  struct timeval now_tv;

  gettimeofday(&now_tv, NULL);
  now_tm = localtime(&now_tv.tv_sec);

//  strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
//  printf("%s.%03d\n", buffer, millisec);
//  time_t t = time(NULL);
//  struct tm tm = *localtime(&t);

  fprintf(out, fmt, now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday, now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec, now_tv.tv_usec/1000);
}

//  Log error condition - highest priority
void clog_fatal(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_FATAL_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("F %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log error condition - high priority
void clog_error(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_ERROR_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("E %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log warning condition - low priority
void clog_warning(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_WARN_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("W %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log normal, but significant, condition - normal priority
void clog_notice(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_NOTICE_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("N %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log informational message - low priority
void clog_info(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_INFO_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("I %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log debug-level message - lowest priority
void clog_debug(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_DEBUG_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  clog_print_header("D %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

//  Log debug-level message - no header - lowest priority
void clog_debug_no_header(clog_logger_t logger, const char *fmt, ...) {
  if ((out == NULL) || (logger > CLOG_DEBUG_LEVEL))
    return;

  va_list argptr;
  va_start(argptr, fmt);
  //clog_print_header("D %d/%02d/%02d %02d:%02d:%02d.%03d ");
  vfprintf(out, fmt, argptr);
  va_end(argptr);
  fflush(out);
}

void clog_test(bool verbose) {
  printf(" * mal_test: ");

  clog_logger_t logger = CLOG_WARN_LEVEL;

  clog_set_level(&logger, CLOG_DEBUG_LEVEL);
  clog_error(logger, "error: %s %d %d\n", "message d'erreur",10, 20);
  clog_debug(logger, "debug: %s\n", "trace de debug");

//  @selftest
// ...
//  @end
  printf("OK\n");
}

