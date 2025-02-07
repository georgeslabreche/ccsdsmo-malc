#include "com.h"


// structure definition for composite com_objecttype
struct _com_objecttype_t {
  mal_ushort_t f_area;
  mal_ushort_t f_service;
  mal_uoctet_t f_version;
  mal_ushort_t f_number;
};

// fields accessors for composite com_objecttype
mal_ushort_t com_objecttype_get_area(com_objecttype_t * self)
{
  return self->f_area;
}
void com_objecttype_set_area(com_objecttype_t * self, mal_ushort_t f_area)
{
  self->f_area = f_area;
}
mal_ushort_t com_objecttype_get_service(com_objecttype_t * self)
{
  return self->f_service;
}
void com_objecttype_set_service(com_objecttype_t * self, mal_ushort_t f_service)
{
  self->f_service = f_service;
}
mal_uoctet_t com_objecttype_get_version(com_objecttype_t * self)
{
  return self->f_version;
}
void com_objecttype_set_version(com_objecttype_t * self, mal_uoctet_t f_version)
{
  self->f_version = f_version;
}
mal_ushort_t com_objecttype_get_number(com_objecttype_t * self)
{
  return self->f_number;
}
void com_objecttype_set_number(com_objecttype_t * self, mal_ushort_t f_number)
{
  self->f_number = f_number;
}

// default constructor
com_objecttype_t * com_objecttype_new(void)
{
  com_objecttype_t *self = (com_objecttype_t *) calloc(1, sizeof(com_objecttype_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_objecttype_add_encoding_length_malbinary(com_objecttype_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_area, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_service, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uoctet_encoding_length(encoder, self->f_version, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_number, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objecttype_encode_malbinary(com_objecttype_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_area);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_service);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uoctet(encoder, cursor, self->f_version);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_number);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objecttype_decode_malbinary(com_objecttype_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_area);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_service);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uoctet(decoder, cursor, &self->f_version);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_number);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_objecttype_destroy(com_objecttype_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_objecttype_test(bool verbose)
{
  printf(" * COM:ObjectType: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
