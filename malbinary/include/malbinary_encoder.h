#ifndef __MALBINARY_ENCODER_H_INCLUDED__
#define __MALBINARY_ENCODER_H_INCLUDED__

#include "clog.h"

#ifdef __cplusplus
extern "C" {
#endif

mal_encoder_t *malbinary_encoder_new(bool varint_supported);
void malbinary_init_encode_functions(mal_encoder_t *encoder);

/*
 * Encoding length functions.
 */

int malbinary_encoder_add_string_encoding_length(mal_encoder_t *self,
    mal_string_t *to_encode, void *cursor);

int malbinary_encoder_add_presence_flag_encoding_length(
    mal_encoder_t *self, void *cursor);

int malbinary_encoder_add_short_form_encoding_length(mal_encoder_t *self,
    long to_encode, void *cursor);

int malbinary_encoder_add_integer_encoding_length(mal_encoder_t *self,
    mal_integer_t to_encode, void *cursor);

int malbinary_encoder_add_identifier_encoding_length(mal_encoder_t *self,
    mal_identifier_t *to_encode, void *cursor);

int malbinary_encoder_add_uinteger_encoding_length(mal_encoder_t *self,
    mal_uinteger_t to_encode, void *cursor);

int malbinary_encoder_add_uri_encoding_length(mal_encoder_t *self,
    mal_uri_t *to_encode, void *cursor);

int malbinary_encoder_add_time_encoding_length(mal_encoder_t *self,
    mal_time_t to_encode, void *cursor);

int malbinary_encoder_add_uoctet_encoding_length(mal_encoder_t *self,
    mal_uoctet_t to_encode, void *cursor);

int malbinary_encoder_add_long_encoding_length(mal_encoder_t *self,
    mal_long_t to_encode, void *cursor);

int malbinary_encoder_add_ushort_encoding_length(mal_encoder_t *self,
    mal_ushort_t to_encode, void *cursor);

int malbinary_encoder_add_boolean_encoding_length(mal_encoder_t *self,
    mal_boolean_t to_encode, void *cursor);

int malbinary_encoder_add_blob_encoding_length(mal_encoder_t *self,
    mal_blob_t *to_encode, void *cursor);

int malbinary_encoder_add_list_size_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor);

int malbinary_encoder_add_small_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor);

int malbinary_encoder_add_medium_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor);

int malbinary_encoder_add_large_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor);

int malbinary_encoder_add_duration_encoding_length(mal_encoder_t *self, mal_duration_t to_encode, void *cursor);

int malbinary_encoder_add_float_encoding_length(mal_encoder_t *self, mal_float_t to_encode, void *cursor);

int malbinary_encoder_add_double_encoding_length(mal_encoder_t *self, mal_double_t to_encode, void *cursor);

int malbinary_encoder_add_octet_encoding_length(mal_encoder_t *self, mal_octet_t to_encode, void *cursor);

int malbinary_encoder_add_short_encoding_length(mal_encoder_t *self, mal_short_t to_encode, void *cursor);

int malbinary_encoder_add_ulong_encoding_length(mal_encoder_t *self, mal_ulong_t to_encode, void *cursor);

int malbinary_encoder_add_finetime_encoding_length(mal_encoder_t *self, mal_finetime_t to_encode, void *cursor);

int malbinary_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor);

/*
 * Encoding functions.
 */

int malbinary_encoder_encode_string(mal_encoder_t *self, void *cursor, mal_string_t *to_encode);

int malbinary_encoder_encode_presence_flag(mal_encoder_t *self, void *cursor, bool to_encode);

int malbinary_encoder_encode_short_form(mal_encoder_t *self, void *cursor, long to_encode);

int malbinary_encoder_encode_small_enum(mal_encoder_t *self, void *cursor, int to_encode);

int malbinary_encoder_encode_medium_enum(mal_encoder_t *self, void *cursor, int to_encode);

int malbinary_encoder_encode_large_enum(mal_encoder_t *self, void *cursor, int to_encode);

int malbinary_encoder_encode_integer(mal_encoder_t *self, void *cursor, mal_integer_t to_encode);

int malbinary_encoder_encode_list_size(mal_encoder_t *self, void *cursor, unsigned int to_encode);

int malbinary_encoder_encode_uri(mal_encoder_t *self, void *cursor, mal_uri_t *to_encode);

int malbinary_encoder_encode_blob(mal_encoder_t *self, void *cursor, mal_blob_t *to_encode);

int malbinary_encoder_encode_time(mal_encoder_t *self, void *cursor, mal_time_t to_encode);

int malbinary_encoder_encode_uinteger(mal_encoder_t *self, void *cursor, mal_uinteger_t to_encode);

int malbinary_encoder_encode_identifier(mal_encoder_t *self, void *cursor, mal_identifier_t *to_encode);

int malbinary_encoder_encode_uoctet(mal_encoder_t *self, void *cursor, mal_uoctet_t to_encode);

int malbinary_encoder_encode_long(mal_encoder_t *self, void *cursor, mal_long_t to_encode);

int malbinary_encoder_encode_ushort(mal_encoder_t *self, void *cursor, mal_ushort_t to_encode);

int malbinary_encoder_encode_boolean(mal_encoder_t *self, void *cursor, mal_boolean_t to_encode);

void malbinary_write16(int int_value, void *cursor);

void malbinary_write32(int int_value, void *cursor);

void malbinary_write64(long long_value, void *cursor);

int malbinary_encoder_encode_duration(mal_encoder_t *self, void *cursor, mal_duration_t to_encode);

int malbinary_encoder_encode_float(mal_encoder_t *self, void *cursor, mal_float_t to_encode);

int malbinary_encoder_encode_double(mal_encoder_t *self, void *cursor, mal_double_t to_encode);

int malbinary_encoder_encode_octet(mal_encoder_t *self, void *cursor, mal_octet_t to_encode);

int malbinary_encoder_encode_short(mal_encoder_t *self, void *cursor, mal_short_t to_encode);

int malbinary_encoder_encode_ulong(mal_encoder_t *self, void *cursor, mal_ulong_t to_encode);

int malbinary_encoder_encode_finetime(mal_encoder_t *self, void *cursor, mal_finetime_t to_encode);

int malbinary_encoder_encode_attribute(mal_encoder_t *encoder, void *cursor,
    unsigned char attribute_tag, union mal_attribute_t self);

int malbinary_encoder_encode_attribute_tag(mal_encoder_t *encoder, void *cursor, unsigned char to_encode);

/*
 * Test
 */

void malbinary_encoder_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
