#ifndef __MALBINARY_DECODER_H_INCLUDED__
#define __MALBINARY_DECODER_H_INCLUDED__

#include "clog.h"

#ifdef __cplusplus
extern "C" {
#endif

mal_decoder_t *malbinary_decoder_new(bool varint_supported);
void malbinary_init_decode_functions(mal_decoder_t *decoder);

void malbinary_decoder_set_log_level(mal_decoder_t *self, int level);
clog_logger_t malbinary_decoder_get_logger(mal_decoder_t *self);

short malbinary_read16(void *cursor);

int malbinary_read32(void *cursor);

long malbinary_read64(void *cursor);

int malbinary_decoder_decode_string(mal_decoder_t *self, void *cursor, mal_string_t **result);

int malbinary_decoder_decode_presence_flag(mal_decoder_t *self,
    void *cursor, bool *result);

int malbinary_decoder_decode_short_form(mal_decoder_t *self, void *cursor, long *result);

int malbinary_decoder_decode_small_enum(mal_decoder_t *self, void *cursor, int *result);

int malbinary_decoder_decode_medium_enum(mal_decoder_t *self, void *cursor, int *result);

int malbinary_decoder_decode_large_enum(mal_decoder_t *self, void *cursor, int *result);

int malbinary_decoder_decode_integer(mal_decoder_t *self, void *cursor, mal_integer_t *result);

int malbinary_decoder_decode_list_size(mal_decoder_t *self, void *cursor, unsigned int *result);

int malbinary_decoder_decode_uri(mal_decoder_t *self, void *cursor, mal_uri_t **result);

int malbinary_decoder_decode_blob(mal_decoder_t *self, void *cursor, mal_blob_t **result);

int malbinary_decoder_decode_time(mal_decoder_t *self, void *cursor, mal_time_t *result);

int malbinary_decoder_decode_uinteger(mal_decoder_t *self, void *cursor, mal_uinteger_t *result);

int malbinary_decoder_decode_identifier(mal_decoder_t *self, void *cursor, mal_identifier_t **result);

int malbinary_decoder_decode_uoctet(mal_decoder_t *self, void *cursor, mal_uoctet_t *result);

int malbinary_decoder_decode_long(mal_decoder_t *self, void *cursor, mal_long_t *result);

int malbinary_decoder_decode_ushort(mal_decoder_t *self, void *cursor, mal_ushort_t *result);

int malbinary_decoder_decode_boolean(mal_decoder_t *self, void *cursor, mal_boolean_t *result);

short malbinary_read16(void *cursor);

int malbinary_read32(void *cursor);

long malbinary_read64(void *cursor);

int malbinary_decoder_decode_duration(mal_decoder_t *self, void *cursor, mal_duration_t *result);

int malbinary_decoder_decode_float(mal_decoder_t *self, void *cursor, mal_float_t *result);

int malbinary_decoder_decode_double(mal_decoder_t *self, void *cursor, mal_double_t *result);

int malbinary_decoder_decode_octet(mal_decoder_t *self, void *cursor, mal_octet_t *result);

int malbinary_decoder_decode_short(mal_decoder_t *self, void *cursor, mal_short_t *result);

int malbinary_decoder_decode_ulong(mal_decoder_t *self, void *cursor, mal_ulong_t *result);

int malbinary_decoder_decode_finetime(mal_decoder_t *self, void *cursor, mal_finetime_t *result);

int malbinary_decoder_decode_attribute(mal_decoder_t *decoder, void *cursor,
    unsigned char attribute_tag, union mal_attribute_t self);

int malbinary_decoder_decode_attribute_tag(mal_decoder_t *self, void *cursor, unsigned char *result);

/*
 * Test
 */
 
void malbinary_decoder_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
