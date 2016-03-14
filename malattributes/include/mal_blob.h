#ifndef __MAL_BLOB_H_INCLUDED__
#define __MAL_BLOB_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_blob_t *mal_blob_new(unsigned int length);

void mal_blob_destroy(mal_blob_t **self_p);

unsigned int mal_blob_get_length(mal_blob_t *self);

char *mal_blob_get_content(mal_blob_t *self);

void mal_blob_print(mal_blob_t *self);

void mal_blob_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif

