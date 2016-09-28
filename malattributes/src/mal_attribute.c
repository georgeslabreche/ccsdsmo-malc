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

/*
 */

#include "malattributes.h"

void mal_attribute_destroy(union mal_attribute_t *self_p, unsigned char attribute_tag) {
  if (self_p != NULL) {
    switch (attribute_tag) {
    case MAL_BLOB_ATTRIBUTE_TAG: {
      free(self_p->blob_value);
      self_p->blob_value = NULL;
      break;
    }
    case MAL_IDENTIFIER_ATTRIBUTE_TAG: {
      free(self_p->identifier_value);
      self_p->identifier_value = NULL;
      break;
    }
    case MAL_STRING_ATTRIBUTE_TAG: {
      free(self_p->string_value);
      self_p->string_value = NULL;
      break;
    }
    case MAL_URI_ATTRIBUTE_TAG: {
      free(self_p->uri_value);
      self_p->uri_value = NULL;
      break;
    }
    default: {
      //nothing to do
      break;
    }
    }
  }
}

void mal_attribute_test(bool verbose) {
  printf(" * mal_attribute: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
