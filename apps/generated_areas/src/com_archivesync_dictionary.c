#include "com.h"


// structure definition for composite com_archivesync_dictionary
struct _com_archivesync_dictionary_t {
  com_archivesync_dictionaryentry_list_t * f_entries;
};

// fields accessors for composite com_archivesync_dictionary
com_archivesync_dictionaryentry_list_t * com_archivesync_dictionary_get_entries(com_archivesync_dictionary_t * self)
{
  return self->f_entries;
}
void com_archivesync_dictionary_set_entries(com_archivesync_dictionary_t * self, com_archivesync_dictionaryentry_list_t * f_entries)
{
  self->f_entries = f_entries;
}

// default constructor
com_archivesync_dictionary_t * com_archivesync_dictionary_new(void)
{
  com_archivesync_dictionary_t *self = (com_archivesync_dictionary_t *) calloc(1, sizeof(com_archivesync_dictionary_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archivesync_dictionary_add_encoding_length_malbinary(com_archivesync_dictionary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_entries != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_entries != NULL))
  {
    rc = com_archivesync_dictionaryentry_list_add_encoding_length_malbinary(self->f_entries, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_dictionary_encode_malbinary(com_archivesync_dictionary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_entries != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = com_archivesync_dictionaryentry_list_encode_malbinary(self->f_entries, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_dictionary_decode_malbinary(com_archivesync_dictionary_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_entries = com_archivesync_dictionaryentry_list_new(0);
    if (self->f_entries == NULL) return -1;
    rc = com_archivesync_dictionaryentry_list_decode_malbinary(self->f_entries, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_entries = NULL;
  }
  return rc;
}

// destructor
void com_archivesync_dictionary_destroy(com_archivesync_dictionary_t ** self_p)
{
  if ((*self_p)->f_entries != NULL)
  {
    com_archivesync_dictionaryentry_list_destroy(& (*self_p)->f_entries);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archivesync_dictionary_test(bool verbose)
{
  printf(" * COM:ArchiveSync:Dictionary: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
