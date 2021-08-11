#include "com.h"


// structure definition for composite com_archivesync_dictionaryentry
struct _com_archivesync_dictionaryentry_t {
  bool f_id_is_present;
  mal_uinteger_t f_id;
  mal_string_t * f_string;
};

// fields accessors for composite com_archivesync_dictionaryentry
bool com_archivesync_dictionaryentry_id_is_present(com_archivesync_dictionaryentry_t * self)
{
  return self->f_id_is_present;
}
void com_archivesync_dictionaryentry_id_set_present(com_archivesync_dictionaryentry_t * self, bool is_present)
{
  self->f_id_is_present = is_present;
}
mal_uinteger_t com_archivesync_dictionaryentry_get_id(com_archivesync_dictionaryentry_t * self)
{
  return self->f_id;
}
void com_archivesync_dictionaryentry_set_id(com_archivesync_dictionaryentry_t * self, mal_uinteger_t f_id)
{
  self->f_id = f_id;
}
mal_string_t * com_archivesync_dictionaryentry_get_string(com_archivesync_dictionaryentry_t * self)
{
  return self->f_string;
}
void com_archivesync_dictionaryentry_set_string(com_archivesync_dictionaryentry_t * self, mal_string_t * f_string)
{
  self->f_string = f_string;
}

// default constructor
com_archivesync_dictionaryentry_t * com_archivesync_dictionaryentry_new(void)
{
  com_archivesync_dictionaryentry_t *self = (com_archivesync_dictionaryentry_t *) calloc(1, sizeof(com_archivesync_dictionaryentry_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archivesync_dictionaryentry_add_encoding_length_malbinary(com_archivesync_dictionaryentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_id_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_id_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_id, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_string != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_string != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_string, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_dictionaryentry_encode_malbinary(com_archivesync_dictionaryentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_id_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_id);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_string != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_string);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_dictionaryentry_decode_malbinary(com_archivesync_dictionaryentry_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_id);
    if (rc < 0)
      return rc;
  }
  self->f_id_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_string);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_string = NULL;
  }
  return rc;
}

// destructor
void com_archivesync_dictionaryentry_destroy(com_archivesync_dictionaryentry_t ** self_p)
{
  if ((*self_p)->f_string != NULL)
  {
    mal_string_destroy(& (*self_p)->f_string);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archivesync_dictionaryentry_test(bool verbose)
{
  printf(" * COM:ArchiveSync:DictionaryEntry: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
