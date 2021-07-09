#include "common.h"


// structure definition for composite common_login_profile
struct _common_login_profile_t {
  mal_identifier_t * f_username;
  bool f_role_is_present;
  mal_long_t f_role;
};

// fields accessors for composite common_login_profile
mal_identifier_t * common_login_profile_get_username(common_login_profile_t * self)
{
  return self->f_username;
}
void common_login_profile_set_username(common_login_profile_t * self, mal_identifier_t * f_username)
{
  self->f_username = f_username;
}
bool common_login_profile_role_is_present(common_login_profile_t * self)
{
  return self->f_role_is_present;
}
void common_login_profile_role_set_present(common_login_profile_t * self, bool is_present)
{
  self->f_role_is_present = is_present;
}
mal_long_t common_login_profile_get_role(common_login_profile_t * self)
{
  return self->f_role;
}
void common_login_profile_set_role(common_login_profile_t * self, mal_long_t f_role)
{
  self->f_role = f_role;
}

// default constructor
common_login_profile_t * common_login_profile_new(void)
{
  common_login_profile_t *self = (common_login_profile_t *) calloc(1, sizeof(common_login_profile_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_login_profile_add_encoding_length_malbinary(common_login_profile_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_username, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_role_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_role_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_role, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_login_profile_encode_malbinary(common_login_profile_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_username);
  if (rc < 0)
    return rc;
  presence_flag = self->f_role_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_role);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_login_profile_decode_malbinary(common_login_profile_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_username);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_role);
    if (rc < 0)
      return rc;
  }
  self->f_role_is_present = presence_flag;
  return rc;
}

// destructor
void common_login_profile_destroy(common_login_profile_t ** self_p)
{
  if ((*self_p)->f_username != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_username);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_login_profile_test(bool verbose)
{
  printf(" * Common:Login:Profile: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
