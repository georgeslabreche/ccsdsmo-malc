#include "mal.h"


// structure definition for composite mal_idbooleanpair
struct _mal_idbooleanpair_t {
  mal_identifier_t * id;
  bool value_is_present;
  mal_boolean_t value;
};

// fields accessors for composite mal_idbooleanpair
mal_identifier_t * mal_idbooleanpair_get_id(mal_idbooleanpair_t * self)
{
  return self->id;
}
void mal_idbooleanpair_set_id(mal_idbooleanpair_t * self, mal_identifier_t * id)
{
  self->id = id;
}
bool mal_idbooleanpair_value_is_present(mal_idbooleanpair_t * self)
{
  return self->value_is_present;
}
void mal_idbooleanpair_value_set_present(mal_idbooleanpair_t * self, bool is_present)
{
  self->value_is_present = is_present;
}
mal_boolean_t mal_idbooleanpair_get_value(mal_idbooleanpair_t * self)
{
  return self->value;
}
void mal_idbooleanpair_set_value(mal_idbooleanpair_t * self, mal_boolean_t value)
{
  self->value = value;
}

// default constructor
mal_idbooleanpair_t * mal_idbooleanpair_new(void)
{
  mal_idbooleanpair_t *self = (mal_idbooleanpair_t *) calloc(1, sizeof(mal_idbooleanpair_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_idbooleanpair_add_encoding_length_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->id != NULL)
  {
    rc = malbinary_encoder_add_identifier_encoding_length(mal_encoder, self->id, cursor);
    if (rc < 0)
      return rc;
  }
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->value_is_present)
  {
    rc = malbinary_encoder_add_boolean_encoding_length(mal_encoder, self->value, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_idbooleanpair_encode_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->id != NULL);
  rc = malbinary_encoder_encode_presence_flag(mal_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_identifier(mal_encoder, cursor, self->id);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->value_is_present;
  rc = malbinary_encoder_encode_presence_flag(mal_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_boolean(mal_encoder, cursor, self->value);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_idbooleanpair_decode_malbinary(mal_idbooleanpair_t * self, mal_decoder_t * mal_decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = malbinary_decoder_decode_presence_flag(mal_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_identifier(mal_decoder, cursor, &self->id);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->id = NULL;
  }
  rc = malbinary_decoder_decode_presence_flag(mal_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_boolean(mal_decoder, cursor, &self->value);
    if (rc < 0)
      return rc;
  }
  self->value_is_present = presence_flag;
  return rc;
}

// destructor
void mal_idbooleanpair_destroy(mal_idbooleanpair_t ** self_p)
{
  if ((*self_p)->id != NULL)
  {
    mal_identifier_destroy(& (*self_p)->id);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_idbooleanpair_test(bool verbose)
{
  printf(" * MAL:IdBooleanPair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
