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
