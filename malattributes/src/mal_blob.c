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

//clog_logger_t logger = CLOG_DEBUG_LEVEL;

struct _mal_blob_t {
  unsigned int length;
  char *content;
};

mal_blob_t *mal_blob_new(unsigned int length) {
  mal_blob_t *self = (mal_blob_t *) calloc(1, sizeof(mal_blob_t));
  if (!self)
    return NULL;
  self->content = (char *) calloc(length, sizeof(char));
  self->length = length;
  return self;
}

mal_blob_t *mal_blob_create(char *content, unsigned int length) {
  mal_blob_t *self = (mal_blob_t *) calloc(1, sizeof(mal_blob_t));
  if (!self)
    return NULL;
  self->content = content;
  self->length = length;
  return self;
}

void mal_blob_destroy(mal_blob_t **self_p) {
  if (self_p && *self_p) {
    mal_blob_t *self = *self_p;
    free(self->content);
    self->content = NULL;
    free((*self_p));
    *self_p = NULL;
  }
}

unsigned int mal_blob_get_length(mal_blob_t *self) {
  return self->length;
}

char *mal_blob_get_content(mal_blob_t *self) {
  return self->content;
}

// TODO: Needs better integration with logging subsystem.
void mal_blob_print(mal_blob_t *self) {
  //clog_debug(logger, "mal_blob(");
  //clog_debug(logger, "length=%d", self->length);
  if (self->length < 0) {
    //clog_debug(logger, ",content=nil)\n");
    return;
  } else if (self->length == 0) {
    //clog_debug(logger, ",content=)\n");
    return;
  }
  //clog_debug(logger, ",content=");
  for (int i = 0; i < self->length; i++) {
    //clog_debug(logger, "%#02x,", self->content[i]);
  }
  //clog_debug(logger, ")\n");
}

void mal_blob_test(bool verbose) {
  printf(" * mal_blob: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

