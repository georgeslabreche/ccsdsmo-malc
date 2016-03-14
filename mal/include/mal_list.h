/*
 */

#ifndef __MAL_LIST_H_INCLUDED__
#define __MAL_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_list_t *mal_list_new(unsigned int element_count);

unsigned int mal_list_get_element_count(mal_list_t *self);

void **mal_list_get_content(mal_list_t *self);

//  Self test of this class
void mal_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
