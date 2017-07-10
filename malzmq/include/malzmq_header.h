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

#ifndef __MALZMQ_HEADER_H_INCLUDED__
#define __MALZMQ_HEADER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

typedef int malzmq_md_get_key_fn(char *string, unsigned int *key);
typedef int malzmq_md_get_string_fn(unsigned int key, char **string);
typedef int malzmq_md_put_string_fn(char *string, unsigned int *key);
typedef struct _malzmq_mapping_directory_t malzmq_mapping_directory_t;
struct _malzmq_mapping_directory_t {
  malzmq_md_get_key_fn *get_key_fn;
  malzmq_md_get_string_fn *get_string_fn;
  malzmq_md_put_string_fn *put_string_fn;
};

malzmq_header_t *malzmq_header_new(malzmq_mapping_directory_t *mapping_directory,
    bool priority_flag, mal_uinteger_t priority,
    bool timestamp_flag, mal_identifier_t *network_zone,
    mal_identifier_t *session_name, mal_identifier_list_t *domain,
    mal_blob_t *authentication_id);

unsigned char malzmq_header_get_version(malzmq_header_t *self);

void malzmq_header_set_version(malzmq_header_t *self, unsigned char version);

malzmq_mapping_directory_t *malzmq_header_get_mapping_directory(malzmq_header_t *self);

void malzmq_header_set_mapping_directory(malzmq_header_t *self,
	malzmq_mapping_directory_t *mapping_directory);

bool malzmq_header_is_internal_broker(malzmq_header_t *self);

void malzmq_header_enable_internal_broker(malzmq_header_t *self, bool internal_broker);

bool malzmq_header_get_priority_flag(malzmq_header_t *self);

void malzmq_header_set_priority_flag(malzmq_header_t *self, bool priority_flag);

bool malzmq_header_get_timestamp_flag(malzmq_header_t *self);

void malzmq_header_set_timestamp_flag(malzmq_header_t *self,
    bool timestamp_flag);

bool malzmq_header_get_network_zone_flag(malzmq_header_t *self);

void malzmq_header_set_network_zone_flag(malzmq_header_t *self,
    bool network_zone_flag);

bool malzmq_header_get_session_name_flag(malzmq_header_t *self);

void malzmq_header_set_session_name_flag(malzmq_header_t *self,
    bool session_name_flag);

bool malzmq_header_get_domain_flag(malzmq_header_t *self);

void malzmq_header_set_domain_flag(malzmq_header_t *self, bool domain_flag);

bool malzmq_header_get_authentication_id_flag(malzmq_header_t *self);

void malzmq_header_set_authentication_id_flag(malzmq_header_t *self,
    bool authentication_id_flag);

mal_blob_t *malzmq_header_get_authentication_id(malzmq_header_t *self);

void malzmq_header_set_authentication_id(malzmq_header_t *self,
    mal_blob_t *authentication_id);

mal_uinteger_t malzmq_header_get_priority(malzmq_header_t *self);

void malzmq_header_set_priority(malzmq_header_t *self, mal_uinteger_t priority);

mal_identifier_list_t *malzmq_header_get_domain(malzmq_header_t *self);

void malzmq_header_set_domain(malzmq_header_t *self,
    mal_identifier_list_t *domain);

mal_identifier_t *malzmq_header_get_network_zone(malzmq_header_t *self);

void malzmq_header_set_network_zone(malzmq_header_t *self,
    mal_identifier_t *network_zone);

mal_identifier_t *malzmq_header_get_session_name(malzmq_header_t *self);

void malzmq_header_set_session_name(malzmq_header_t *self,
    mal_identifier_t *session_name);

void malzmq_header_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
