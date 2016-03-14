/*
 */

#ifndef __MAL_ENUM_LIST_H_INCLUDED__
#define __MAL_ENUM_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_enum_list_t *mal_enum_list_new(unsigned int element_count,
    bool *presence_flags, int *content);

unsigned int mal_enum_list_get_element_count(mal_enum_list_t *self);

bool *mal_enum_list_get_presence_flags(mal_enum_list_t *self);

int *mal_enum_list_get_content(mal_enum_list_t *self);

//  Self test of this class
void mal_enum_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
