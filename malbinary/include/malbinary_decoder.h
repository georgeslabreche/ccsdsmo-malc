#ifndef __MALBINARY_DECODER_H_INCLUDED__
#define __MALBINARY_DECODER_H_INCLUDED__

#include "clog.h"

#ifdef __cplusplus
extern "C" {
#endif

malbinary_decoder_t *malbinary_decoder_new(bool varint_supported, bool verbose);

void malbinary_decoder_set_log_level(malbinary_decoder_t *decoder, int level);

clog_logger_t malbinary_decoder_get_logger(malbinary_decoder_t *decoder);

short malbinary_read16(char *bytes, unsigned int *offset);

int malbinary_read32(char *bytes, unsigned int *offset);

long malbinary_read64(char *bytes, unsigned int *offset);

int malbinary_decoder_decode_string(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_string_t **result);

int malbinary_decoder_decode_presence_flag(malbinary_decoder_t *self,
    char *bytes, unsigned int *offset, bool *result);

int malbinary_decoder_decode_short_form(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, long *result);

int malbinary_decoder_decode_small_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result);

int malbinary_decoder_decode_medium_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result);

int malbinary_decoder_decode_large_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result);

int malbinary_decoder_decode_integer(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_integer_t *result);

int malbinary_decoder_decode_list_size(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, unsigned int *result);

int malbinary_decoder_decode_uri(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uri_t **result);

int malbinary_decoder_decode_blob(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_blob_t **result);

int malbinary_decoder_decode_time(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_time_t *result);

int malbinary_decoder_decode_uinteger(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uinteger_t *result);

int malbinary_decoder_decode_identifier(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_identifier_t **result);

int malbinary_decoder_decode_uoctet(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uoctet_t *result);

int malbinary_decoder_decode_long(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_long_t *result);

int malbinary_decoder_decode_ushort(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ushort_t *result);

int malbinary_decoder_decode_boolean(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_boolean_t *result);

short malbinary_read16(char *bytes, unsigned int *offset);

int malbinary_read32(char *bytes, unsigned int *offset);

long malbinary_read64(char *bytes, unsigned int *offset);

bool malbinary_decoder_is_verbose(malbinary_decoder_t *self);

int malbinary_decoder_decode_duration(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_duration_t *result);

int malbinary_decoder_decode_float(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_float_t *result);

int malbinary_decoder_decode_double(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_double_t *result);

int malbinary_decoder_decode_octet(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_octet_t *result);

int malbinary_decoder_decode_short(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_short_t *result);

int malbinary_decoder_decode_ulong(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ulong_t *result);

int malbinary_decoder_decode_finetime(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_finetime_t *result);

int malbinary_decoder_decode_attribute(malbinary_decoder_t *malbinary_decoder, char *bytes,
    unsigned int *offset, unsigned char attribute_tag, union mal_attribute_t self);

int malbinary_decoder_decode_attribute_tag(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, unsigned char *result);

void malbinary_decoder_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
