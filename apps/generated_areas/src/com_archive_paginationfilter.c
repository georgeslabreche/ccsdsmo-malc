#include "com.h"


// structure definition for composite com_archive_paginationfilter
struct _com_archive_paginationfilter_t {
  mal_uinteger_t f_limit;
  mal_uinteger_t f_offset;
};

// fields accessors for composite com_archive_paginationfilter
mal_uinteger_t com_archive_paginationfilter_get_limit(com_archive_paginationfilter_t * self)
{
  return self->f_limit;
}
void com_archive_paginationfilter_set_limit(com_archive_paginationfilter_t * self, mal_uinteger_t f_limit)
{
  self->f_limit = f_limit;
}
mal_uinteger_t com_archive_paginationfilter_get_offset(com_archive_paginationfilter_t * self)
{
  return self->f_offset;
}
void com_archive_paginationfilter_set_offset(com_archive_paginationfilter_t * self, mal_uinteger_t f_offset)
{
  self->f_offset = f_offset;
}

// default constructor
com_archive_paginationfilter_t * com_archive_paginationfilter_new(void)
{
  com_archive_paginationfilter_t *self = (com_archive_paginationfilter_t *) calloc(1, sizeof(com_archive_paginationfilter_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archive_paginationfilter_add_encoding_length_malbinary(com_archive_paginationfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_limit, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_offset, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archive_paginationfilter_encode_malbinary(com_archive_paginationfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_limit);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_offset);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archive_paginationfilter_decode_malbinary(com_archive_paginationfilter_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_limit);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_offset);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_archive_paginationfilter_destroy(com_archive_paginationfilter_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archive_paginationfilter_test(bool verbose)
{
  printf(" * COM:Archive:PaginationFilter: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
