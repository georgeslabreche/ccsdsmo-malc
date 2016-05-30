#include "mal.h"

struct _mal_updateheader_t {
  mal_time_t timestamp;
  mal_uri_t *source_uri;
  mal_updatetype_t updatetype;
  mal_entitykey_t *entitykey;
};

mal_updateheader_t *mal_updateheader_new(void) {
  mal_updateheader_t *self = (mal_updateheader_t *) malloc(
      sizeof(mal_updateheader_t));
  if (!self)
    return NULL;
  return self;
}

void mal_updateheader_destroy(mal_updateheader_t **self_p) {
  if (*self_p) {
    mal_updateheader_t *self = *self_p;
    if (self->source_uri) {
      mal_uri_destroy(&(self->source_uri));
    }
    if (self->entitykey) {
      mal_entitykey_destroy(&(self->entitykey));
    }
    free(self);
    *self_p = NULL;
  }
}

int mal_updateheader_add_encoding_length_malbinary(mal_updateheader_t *self,
    malbinary_encoder_t *encoder, void *cursor) {
  int rc = 0;
  if (self == NULL) {
    rc = -1;
    return rc;
  }
  // timestamp
  rc = malbinary_encoder_add_time_encoding_length(encoder, self->timestamp, cursor);
  if (rc < 0)
    return rc;
  // source_uri
  rc = malbinary_encoder_add_uri_encoding_length(encoder, self->source_uri, cursor);
  if (rc < 0)
    return rc;
  // enum updatetype
  malbinary_add_length((malbinary_cursor_t *) cursor, 1);
  // entitykey
  rc = mal_entitykey_add_encoding_length_malbinary(self->entitykey, encoder, cursor);
  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_updateheader_encode_malbinary(mal_updateheader_t *self,
    malbinary_encoder_t *encoder, void *cursor) {
  int rc = 0;
  // encode timestamp
  rc = malbinary_encoder_encode_time(encoder, cursor, self->timestamp);
  if (rc < 0)
    return rc;
  // encode source_uri
  rc = malbinary_encoder_encode_uri(encoder, cursor, self->source_uri);
  if (rc < 0)
    return rc;
  // encode updatetype
  rc = malbinary_encoder_encode_small_enum(encoder, cursor, self->updatetype);
  if (rc < 0)
    return rc;
  // encode entitykey
  rc = mal_entitykey_encode_malbinary(self->entitykey, encoder, cursor);
  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_updateheader_decode_malbinary(mal_updateheader_t *self,
    malbinary_decoder_t *decoder, void *cursor) {
  int rc = 0;
  // decode timestamp
  rc = malbinary_decoder_decode_time(decoder, cursor, &self->timestamp);
  if (rc < 0)
    return rc;
  // decode source_uri
  rc = malbinary_decoder_decode_uri(decoder, cursor, &self->source_uri);
  if (rc < 0)
    return rc;
  // decode updatetype
  int result;
  rc = malbinary_decoder_decode_small_enum(decoder, cursor, &result);
  self->updatetype = (mal_updatetype_t) result;
  if (rc < 0)
    return rc;
  // decode entitykey
  self->entitykey = mal_entitykey_new();
  rc = mal_entitykey_decode_malbinary(self->entitykey, decoder, cursor);
  return rc;
}

void mal_updateheader_set_source_uri(mal_updateheader_t *self, mal_uri_t *source_uri) {
  self->source_uri = source_uri;
}

mal_uri_t *mal_updateheader_get_source_uri(mal_updateheader_t *self) {
  return self->source_uri;
}

void mal_updateheader_set_entitykey(mal_updateheader_t *self, mal_entitykey_t *entitykey) {
  self->entitykey = entitykey;
}

mal_entitykey_t *mal_updateheader_get_entitykey(mal_updateheader_t *self) {
  return self->entitykey;
}

void mal_updateheader_set_timestamp(mal_updateheader_t *self, mal_time_t timestamp) {
  self->timestamp = timestamp;
}

mal_time_t mal_updateheader_get_timestamp(mal_updateheader_t *self) {
  return self->timestamp;
}

void mal_updateheader_set_updatetype(mal_updateheader_t *self, mal_updatetype_t updatetype) {
  self->updatetype = updatetype;
}

mal_updatetype_t mal_updateheader_get_updatetype(mal_updateheader_t *self) {
  return self->updatetype;
}

void mal_updateheader_test(bool verbose) {
  printf(" * mal_updateheader: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

