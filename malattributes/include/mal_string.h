#ifndef __MAL_STRING_H_INCLUDED__
#define __MAL_STRING_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_string_t *mal_string_new(char *char_content);

void mal_string_destroy(mal_string_t **self_p);

size_t mal_string_get_char_count(mal_string_t *self);

void mal_string_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
