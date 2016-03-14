#ifndef __MAL_ELEMENT_HOLDER_H_INCLUDED__
#define __MAL_ELEMENT_HOLDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_element_holder_t *mal_element_holder_new(void);

void mal_element_holder_destroy(mal_element_holder_t **self_p);

bool mal_element_holder_get_presence_flag(mal_element_holder_t *self);

void mal_element_holder_set_presence_flag(mal_element_holder_t *self,
    bool presence_flag);

long mal_element_holder_get_short_form(mal_element_holder_t *self);

void mal_element_holder_set_short_form(mal_element_holder_t *self,
    long short_form);

union mal_element_t mal_element_holder_get_value(mal_element_holder_t *self);

void mal_element_holder_set_value(mal_element_holder_t *self,
    union mal_element_t value);

void mal_element_holder_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif

