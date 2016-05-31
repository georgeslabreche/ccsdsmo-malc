#include "mal.h"


// structure definition for composite mal_file
struct _mal_file_t {
  mal_identifier_t * name;
  mal_string_t * mimetype;
  bool creationdate_is_present;
  mal_time_t creationdate;
  bool modificationdate_is_present;
  mal_time_t modificationdate;
  bool size_is_present;
  mal_ulong_t size;
  mal_blob_t * content;
  mal_namedvalue_list_t * metadata;
};

// fields accessors for composite mal_file
mal_identifier_t * mal_file_get_name(mal_file_t * self)
{
  return self->name;
}
void mal_file_set_name(mal_file_t * self, mal_identifier_t * name)
{
  self->name = name;
}
mal_string_t * mal_file_get_mimetype(mal_file_t * self)
{
  return self->mimetype;
}
void mal_file_set_mimetype(mal_file_t * self, mal_string_t * mimetype)
{
  self->mimetype = mimetype;
}
bool mal_file_creationdate_is_present(mal_file_t * self)
{
  return self->creationdate_is_present;
}
void mal_file_creationdate_set_present(mal_file_t * self, bool is_present)
{
  self->creationdate_is_present = is_present;
}
mal_time_t mal_file_get_creationdate(mal_file_t * self)
{
  return self->creationdate;
}
void mal_file_set_creationdate(mal_file_t * self, mal_time_t creationdate)
{
  self->creationdate = creationdate;
}
bool mal_file_modificationdate_is_present(mal_file_t * self)
{
  return self->modificationdate_is_present;
}
void mal_file_modificationdate_set_present(mal_file_t * self, bool is_present)
{
  self->modificationdate_is_present = is_present;
}
mal_time_t mal_file_get_modificationdate(mal_file_t * self)
{
  return self->modificationdate;
}
void mal_file_set_modificationdate(mal_file_t * self, mal_time_t modificationdate)
{
  self->modificationdate = modificationdate;
}
bool mal_file_size_is_present(mal_file_t * self)
{
  return self->size_is_present;
}
void mal_file_size_set_present(mal_file_t * self, bool is_present)
{
  self->size_is_present = is_present;
}
mal_ulong_t mal_file_get_size(mal_file_t * self)
{
  return self->size;
}
void mal_file_set_size(mal_file_t * self, mal_ulong_t size)
{
  self->size = size;
}
mal_blob_t * mal_file_get_content(mal_file_t * self)
{
  return self->content;
}
void mal_file_set_content(mal_file_t * self, mal_blob_t * content)
{
  self->content = content;
}
mal_namedvalue_list_t * mal_file_get_metadata(mal_file_t * self)
{
  return self->metadata;
}
void mal_file_set_metadata(mal_file_t * self, mal_namedvalue_list_t * metadata)
{
  self->metadata = metadata;
}

// default constructor
mal_file_t * mal_file_new(void)
{
  mal_file_t *self = (mal_file_t *) calloc(1, sizeof(mal_file_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_file_add_encoding_length_malbinary(mal_file_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  rc = malbinary_encoder_add_identifier_encoding_length(malbinary_encoder, self->name, cursor);
  if (rc < 0)
    return rc;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->mimetype != NULL)
  {
    rc = malbinary_encoder_add_string_encoding_length(malbinary_encoder, self->mimetype, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->creationdate_is_present)
  {
    rc = malbinary_encoder_add_time_encoding_length(malbinary_encoder, self->creationdate, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->modificationdate_is_present)
  {
    rc = malbinary_encoder_add_time_encoding_length(malbinary_encoder, self->modificationdate, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->size_is_present)
  {
    rc = malbinary_encoder_add_ulong_encoding_length(malbinary_encoder, self->size, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->content != NULL)
  {
    rc = malbinary_encoder_add_blob_encoding_length(malbinary_encoder, self->content, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->metadata != NULL)
  {
    rc = mal_namedvalue_list_add_encoding_length_malbinary(self->metadata, malbinary_encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_file_encode_malbinary(mal_file_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = malbinary_encoder_encode_identifier(malbinary_encoder, cursor, self->name);
  if (rc < 0)
    return rc;
  presence_flag = (self->mimetype != NULL);
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_string(malbinary_encoder, cursor, self->mimetype);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->creationdate_is_present;
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_time(malbinary_encoder, cursor, self->creationdate);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->modificationdate_is_present;
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_time(malbinary_encoder, cursor, self->modificationdate);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->size_is_present;
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_ulong(malbinary_encoder, cursor, self->size);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->content != NULL);
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_blob(malbinary_encoder, cursor, self->content);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->metadata != NULL);
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_namedvalue_list_encode_malbinary(self->metadata, malbinary_encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_file_decode_malbinary(mal_file_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = malbinary_decoder_decode_identifier(malbinary_decoder, cursor, &self->name);
  if (rc < 0)
    return rc;
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_string(malbinary_decoder, cursor, &self->mimetype);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->mimetype = NULL;
  }
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_time(malbinary_decoder, cursor, &self->creationdate);
    if (rc < 0)
      return rc;
  }
  self->creationdate_is_present = presence_flag;
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_time(malbinary_decoder, cursor, &self->modificationdate);
    if (rc < 0)
      return rc;
  }
  self->modificationdate_is_present = presence_flag;
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_ulong(malbinary_decoder, cursor, &self->size);
    if (rc < 0)
      return rc;
  }
  self->size_is_present = presence_flag;
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_blob(malbinary_decoder, cursor, &self->content);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->content = NULL;
  }
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->metadata = mal_namedvalue_list_new(0);
    if (self->metadata == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary(self->metadata, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->metadata = NULL;
  }
  return rc;
}

// destructor
void mal_file_destroy(mal_file_t ** self_p)
{
  if ((*self_p)->name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->name);
  }
  if ((*self_p)->mimetype != NULL)
  {
    mal_string_destroy(& (*self_p)->mimetype);
  }
  if ((*self_p)->content != NULL)
  {
    mal_blob_destroy(& (*self_p)->content);
  }
  if ((*self_p)->metadata != NULL)
  {
    mal_namedvalue_list_destroy(& (*self_p)->metadata);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_file_test(bool verbose)
{
  printf(" * MAL:File: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
