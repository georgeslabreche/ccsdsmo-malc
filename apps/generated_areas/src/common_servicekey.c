#include "common.h"


// structure definition for composite common_servicekey
struct _common_servicekey_t {
  mal_ushort_t f_keyarea;
  mal_ushort_t f_keyservice;
  mal_uoctet_t f_keyareaversion;
};

// fields accessors for composite common_servicekey
mal_ushort_t common_servicekey_get_keyarea(common_servicekey_t * self)
{
  return self->f_keyarea;
}
void common_servicekey_set_keyarea(common_servicekey_t * self, mal_ushort_t f_keyarea)
{
  self->f_keyarea = f_keyarea;
}
mal_ushort_t common_servicekey_get_keyservice(common_servicekey_t * self)
{
  return self->f_keyservice;
}
void common_servicekey_set_keyservice(common_servicekey_t * self, mal_ushort_t f_keyservice)
{
  self->f_keyservice = f_keyservice;
}
mal_uoctet_t common_servicekey_get_keyareaversion(common_servicekey_t * self)
{
  return self->f_keyareaversion;
}
void common_servicekey_set_keyareaversion(common_servicekey_t * self, mal_uoctet_t f_keyareaversion)
{
  self->f_keyareaversion = f_keyareaversion;
}

// default constructor
common_servicekey_t * common_servicekey_new(void)
{
  common_servicekey_t *self = (common_servicekey_t *) calloc(1, sizeof(common_servicekey_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_servicekey_add_encoding_length_malbinary(common_servicekey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_keyarea, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_keyservice, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uoctet_encoding_length(encoder, self->f_keyareaversion, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_servicekey_encode_malbinary(common_servicekey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_keyarea);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_keyservice);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uoctet(encoder, cursor, self->f_keyareaversion);
  if (rc < 0)
    return rc;
  return rc;
}
int common_servicekey_decode_malbinary(common_servicekey_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_keyarea);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_keyservice);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uoctet(decoder, cursor, &self->f_keyareaversion);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_servicekey_destroy(common_servicekey_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_servicekey_test(bool verbose)
{
  printf(" * Common:ServiceKey: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
