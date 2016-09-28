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

#ifndef __MAL_ATTRIBUTE_H_INCLUDED__
#define __MAL_ATTRIBUTE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif


#define MAL_BLOB_ATTRIBUTE_TAG 0
#define MAL_BOOLEAN_ATTRIBUTE_TAG 1
#define MAL_DURATION_ATTRIBUTE_TAG 2
#define MAL_FLOAT_ATTRIBUTE_TAG 3
#define MAL_DOUBLE_ATTRIBUTE_TAG 4
#define MAL_IDENTIFIER_ATTRIBUTE_TAG 5
#define MAL_OCTET_ATTRIBUTE_TAG 6
#define MAL_UOCTET_ATTRIBUTE_TAG 7
#define MAL_SHORT_ATTRIBUTE_TAG 8
#define MAL_USHORT_ATTRIBUTE_TAG 9
#define MAL_INTEGER_ATTRIBUTE_TAG 10
#define MAL_UINTEGER_ATTRIBUTE_TAG 11
#define MAL_LONG_ATTRIBUTE_TAG 12
#define MAL_ULONG_ATTRIBUTE_TAG 13
#define MAL_STRING_ATTRIBUTE_TAG 14
#define MAL_TIME_ATTRIBUTE_TAG 15
#define MAL_FINETIME_ATTRIBUTE_TAG 16
#define MAL_URI_ATTRIBUTE_TAG 17

union mal_attribute_t {
  mal_blob_t *blob_value;
  mal_boolean_t boolean_value;
  mal_double_t double_value;
  mal_float_t float_value;
  mal_octet_t octet_value;
  mal_uoctet_t uoctet_value;
  mal_short_t short_value;
  mal_ushort_t ushort_value;
  mal_integer_t integer_value;
  mal_uinteger_t uinteger_value;
  mal_long_t long_value;
  mal_ulong_t ulong_value;
  mal_string_t *string_value;
  mal_identifier_t *identifier_value;
  mal_uri_t *uri_value;
  mal_time_t time_value;
  mal_finetime_t finetime_value;
  mal_duration_t duration_value;
};


void mal_attribute_destroy(union mal_attribute_t *self_p, unsigned char attribute_tag);
void mal_attribute_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif /* MAL_ATTRIBUTE_H_ */
