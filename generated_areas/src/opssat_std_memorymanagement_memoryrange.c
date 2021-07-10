#include "opssat_std.h"


// structure definition for composite opssat_std_memorymanagement_memoryrange
struct _opssat_std_memorymanagement_memoryrange_t {
  mal_uinteger_t f_startaddress;
  mal_uinteger_t f_blocklength;
};

// fields accessors for composite opssat_std_memorymanagement_memoryrange
mal_uinteger_t opssat_std_memorymanagement_memoryrange_get_startaddress(opssat_std_memorymanagement_memoryrange_t * self)
{
  return self->f_startaddress;
}
void opssat_std_memorymanagement_memoryrange_set_startaddress(opssat_std_memorymanagement_memoryrange_t * self, mal_uinteger_t f_startaddress)
{
  self->f_startaddress = f_startaddress;
}
mal_uinteger_t opssat_std_memorymanagement_memoryrange_get_blocklength(opssat_std_memorymanagement_memoryrange_t * self)
{
  return self->f_blocklength;
}
void opssat_std_memorymanagement_memoryrange_set_blocklength(opssat_std_memorymanagement_memoryrange_t * self, mal_uinteger_t f_blocklength)
{
  self->f_blocklength = f_blocklength;
}

// default constructor
opssat_std_memorymanagement_memoryrange_t * opssat_std_memorymanagement_memoryrange_new(void)
{
  opssat_std_memorymanagement_memoryrange_t *self = (opssat_std_memorymanagement_memoryrange_t *) calloc(1, sizeof(opssat_std_memorymanagement_memoryrange_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int opssat_std_memorymanagement_memoryrange_add_encoding_length_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_startaddress, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_blocklength, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_memorymanagement_memoryrange_encode_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_startaddress);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_blocklength);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_memorymanagement_memoryrange_decode_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_startaddress);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_blocklength);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void opssat_std_memorymanagement_memoryrange_destroy(opssat_std_memorymanagement_memoryrange_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void opssat_std_memorymanagement_memoryrange_test(bool verbose)
{
  printf(" * OPSSAT_STD:MemoryManagement:MemoryRange: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
