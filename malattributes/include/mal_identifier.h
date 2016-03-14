#ifndef __MAL_IDENTIFIER_H_INCLUDED__
#define __MAL_IDENTIFIER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_identifier_t *mal_identifier_new(char *char_content);

void mal_identifier_destroy(mal_identifier_t **self_p);

size_t mal_identifier_get_char_count(mal_identifier_t *self);

void mal_identifier_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
