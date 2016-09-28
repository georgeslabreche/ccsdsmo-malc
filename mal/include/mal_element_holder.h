/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __MAL_ELEMENT_HOLDER_H_INCLUDED__
#define __MAL_ELEMENT_HOLDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

struct _mal_element_holder_t {
  bool presence_flag;
  long short_form;
  union mal_element_t value;
};

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

