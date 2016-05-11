/*
 */

#ifndef __MALBINARY_H_INCLUDED__
#define __MALBINARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "malattributes.h"

//  MALBINARY API version macros for compile-time API detection

#define MALBINARY_VERSION_MAJOR 1
#define MALBINARY_VERSION_MINOR 0
#define MALBINARY_VERSION_PATCH 0

#define MALBINARY_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALBINARY_VERSION \
    MALBINARY_MAKE_VERSION(MALBINARY_VERSION_MAJOR, MALBINARY_VERSION_MINOR, MALBINARY_VERSION_PATCH)

typedef struct _malbinary_encoder_t malbinary_encoder_t;
typedef struct _malbinary_decoder_t malbinary_decoder_t;

struct _malbinary_cursor_t {
  char* body_ptr;
  unsigned int body_length;
  unsigned int body_offset;
};

typedef struct _malbinary_cursor_t malbinary_cursor_t;

void malbinary_cursor_reset(malbinary_cursor_t *cursor);
void malbinary_cursor_init(malbinary_cursor_t *cursor,
    char *bytes, unsigned int length, unsigned int offset);

void malbinary_cursor_assert(malbinary_cursor_t *cursor);

unsigned int malbinary_cursor_get_body_length(malbinary_cursor_t *cursor);

// The format code must be unique among all the available encoding formats
#define MALBINARY_FORMAT_CODE 0

#define MALBINARY_PRESENCE_FLAG_SIZE 1
#define MALBINARY_ATTRIBUTE_TAG_SIZE 1
#define MALBINARY_SHORT_FORM_SIZE 8
#define MALBINARY_SMALL_ENUM_SIZE 1
#define MALBINARY_MEDIUM_ENUM_SIZE 2
#define MALBINARY_LARGE_ENUM_SIZE 4

void malbinary_test(bool verbose);

//  Public API classes
#include "malbinary_encoder.h"
#include "malbinary_decoder.h"

#ifdef __cplusplus
}
#endif

#endif
