#include "opssat_std.h"


// structure definition for composite opssat_std_memorymanagement_memoryblock
struct _opssat_std_memorymanagement_memoryblock_t {
  mal_uinteger_t f_startaddress;
  mal_blob_t * f_data;
  mal_ushort_t f_checksum;
};

// fields accessors for composite opssat_std_memorymanagement_memoryblock
mal_uinteger_t opssat_std_memorymanagement_memoryblock_get_startaddress(opssat_std_memorymanagement_memoryblock_t * self)
{
  return self->f_startaddress;
}
void opssat_std_memorymanagement_memoryblock_set_startaddress(opssat_std_memorymanagement_memoryblock_t * self, mal_uinteger_t f_startaddress)
{
  self->f_startaddress = f_startaddress;
}
mal_blob_t * opssat_std_memorymanagement_memoryblock_get_data(opssat_std_memorymanagement_memoryblock_t * self)
{
  return self->f_data;
}
void opssat_std_memorymanagement_memoryblock_set_data(opssat_std_memorymanagement_memoryblock_t * self, mal_blob_t * f_data)
{
  self->f_data = f_data;
}
mal_ushort_t opssat_std_memorymanagement_memoryblock_get_checksum(opssat_std_memorymanagement_memoryblock_t * self)
{
  return self->f_checksum;
}
void opssat_std_memorymanagement_memoryblock_set_checksum(opssat_std_memorymanagement_memoryblock_t * self, mal_ushort_t f_checksum)
{
  self->f_checksum = f_checksum;
}

// default constructor
opssat_std_memorymanagement_memoryblock_t * opssat_std_memorymanagement_memoryblock_new(void)
{
  opssat_std_memorymanagement_memoryblock_t *self = (opssat_std_memorymanagement_memoryblock_t *) calloc(1, sizeof(opssat_std_memorymanagement_memoryblock_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int opssat_std_memorymanagement_memoryblock_add_encoding_length_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_startaddress, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_blob_encoding_length(encoder, self->f_data, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_checksum, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_memorymanagement_memoryblock_encode_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_startaddress);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_blob(encoder, cursor, self->f_data);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_checksum);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_memorymanagement_memoryblock_decode_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_startaddress);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_blob(decoder, cursor, &self->f_data);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_checksum);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void opssat_std_memorymanagement_memoryblock_destroy(opssat_std_memorymanagement_memoryblock_t ** self_p)
{
  if ((*self_p)->f_data != NULL)
  {
    mal_blob_destroy(& (*self_p)->f_data);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void opssat_std_memorymanagement_memoryblock_test(bool verbose)
{
  printf(" * OPSSAT_STD:MemoryManagement:MemoryBlock: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
