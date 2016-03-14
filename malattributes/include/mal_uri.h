#ifndef __MAL_URI_H_INCLUDED__
#define __MAL_URI_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_uri_t *mal_uri_new(char *char_content);

void mal_uri_destroy(mal_uri_t **self_p);

size_t mal_uri_get_char_count(mal_uri_t *self);

void mal_uri_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
