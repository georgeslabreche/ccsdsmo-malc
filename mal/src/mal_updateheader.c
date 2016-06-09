#include "mal.h"


// structure definition for composite mal_updateheader
struct _mal_updateheader_t {
  mal_time_t timestamp;
  mal_uri_t * sourceuri;
  mal_updatetype_t updatetype;
  mal_entitykey_t * key;
};

// fields accessors for composite mal_updateheader
mal_time_t mal_updateheader_get_timestamp(mal_updateheader_t * self)
{
  return self->timestamp;
}
void mal_updateheader_set_timestamp(mal_updateheader_t * self, mal_time_t timestamp)
{
  self->timestamp = timestamp;
}
mal_uri_t * mal_updateheader_get_sourceuri(mal_updateheader_t * self)
{
  return self->sourceuri;
}
void mal_updateheader_set_sourceuri(mal_updateheader_t * self, mal_uri_t * sourceuri)
{
  self->sourceuri = sourceuri;
}
mal_updatetype_t mal_updateheader_get_updatetype(mal_updateheader_t * self)
{
  return self->updatetype;
}
void mal_updateheader_set_updatetype(mal_updateheader_t * self, mal_updatetype_t updatetype)
{
  self->updatetype = updatetype;
}
mal_entitykey_t * mal_updateheader_get_key(mal_updateheader_t * self)
{
  return self->key;
}
void mal_updateheader_set_key(mal_updateheader_t * self, mal_entitykey_t * key)
{
  self->key = key;
}

// default constructor
mal_updateheader_t * mal_updateheader_new(void)
{
  mal_updateheader_t *self = (mal_updateheader_t *) calloc(1, sizeof(mal_updateheader_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_updateheader_add_encoding_length_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_time_encoding_length(mal_encoder, self->timestamp, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uri_encoding_length(mal_encoder, self->sourceuri, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(mal_encoder, self->updatetype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_entitykey_add_encoding_length_malbinary(self->key, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_updateheader_encode_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_time(mal_encoder, cursor, self->timestamp);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uri(mal_encoder, cursor, self->sourceuri);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(mal_encoder, cursor, self->updatetype);
  if (rc < 0)
    return rc;
  rc = mal_entitykey_encode_malbinary(self->key, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_updateheader_decode_malbinary(mal_updateheader_t * self, mal_decoder_t * mal_decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_time(mal_decoder, cursor, &self->timestamp);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uri(mal_decoder, cursor, &self->sourceuri);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->updatetype = (mal_updatetype_t) enumerated_value;
  self->key = mal_entitykey_new();
  if (self->key == NULL) return -1;
  rc = mal_entitykey_decode_malbinary(self->key, mal_decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mal_updateheader_destroy(mal_updateheader_t ** self_p)
{
  if ((*self_p)->sourceuri != NULL)
  {
    mal_uri_destroy(& (*self_p)->sourceuri);
  }
  if ((*self_p)->key != NULL)
  {
    mal_entitykey_destroy(& (*self_p)->key);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_updateheader_test(bool verbose)
{
  printf(" * MAL:UpdateHeader: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
