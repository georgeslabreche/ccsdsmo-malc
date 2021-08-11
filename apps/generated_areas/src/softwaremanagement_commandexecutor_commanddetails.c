#include "softwaremanagement.h"


// structure definition for composite softwaremanagement_commandexecutor_commanddetails
struct _softwaremanagement_commandexecutor_commanddetails_t {
  mal_string_t * f_command;
  bool f_pid_is_present;
  mal_long_t f_pid;
  bool f_exitcode_is_present;
  mal_integer_t f_exitcode;
};

// fields accessors for composite softwaremanagement_commandexecutor_commanddetails
mal_string_t * softwaremanagement_commandexecutor_commanddetails_get_command(softwaremanagement_commandexecutor_commanddetails_t * self)
{
  return self->f_command;
}
void softwaremanagement_commandexecutor_commanddetails_set_command(softwaremanagement_commandexecutor_commanddetails_t * self, mal_string_t * f_command)
{
  self->f_command = f_command;
}
bool softwaremanagement_commandexecutor_commanddetails_pid_is_present(softwaremanagement_commandexecutor_commanddetails_t * self)
{
  return self->f_pid_is_present;
}
void softwaremanagement_commandexecutor_commanddetails_pid_set_present(softwaremanagement_commandexecutor_commanddetails_t * self, bool is_present)
{
  self->f_pid_is_present = is_present;
}
mal_long_t softwaremanagement_commandexecutor_commanddetails_get_pid(softwaremanagement_commandexecutor_commanddetails_t * self)
{
  return self->f_pid;
}
void softwaremanagement_commandexecutor_commanddetails_set_pid(softwaremanagement_commandexecutor_commanddetails_t * self, mal_long_t f_pid)
{
  self->f_pid = f_pid;
}
bool softwaremanagement_commandexecutor_commanddetails_exitcode_is_present(softwaremanagement_commandexecutor_commanddetails_t * self)
{
  return self->f_exitcode_is_present;
}
void softwaremanagement_commandexecutor_commanddetails_exitcode_set_present(softwaremanagement_commandexecutor_commanddetails_t * self, bool is_present)
{
  self->f_exitcode_is_present = is_present;
}
mal_integer_t softwaremanagement_commandexecutor_commanddetails_get_exitcode(softwaremanagement_commandexecutor_commanddetails_t * self)
{
  return self->f_exitcode;
}
void softwaremanagement_commandexecutor_commanddetails_set_exitcode(softwaremanagement_commandexecutor_commanddetails_t * self, mal_integer_t f_exitcode)
{
  self->f_exitcode = f_exitcode;
}

// default constructor
softwaremanagement_commandexecutor_commanddetails_t * softwaremanagement_commandexecutor_commanddetails_new(void)
{
  softwaremanagement_commandexecutor_commanddetails_t *self = (softwaremanagement_commandexecutor_commanddetails_t *) calloc(1, sizeof(softwaremanagement_commandexecutor_commanddetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int softwaremanagement_commandexecutor_commanddetails_add_encoding_length_malbinary(softwaremanagement_commandexecutor_commanddetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_command, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_pid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_pid_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_pid, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_exitcode_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_exitcode_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_exitcode, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_commandexecutor_commanddetails_encode_malbinary(softwaremanagement_commandexecutor_commanddetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_command);
  if (rc < 0)
    return rc;
  presence_flag = self->f_pid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_pid);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_exitcode_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_exitcode);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_commandexecutor_commanddetails_decode_malbinary(softwaremanagement_commandexecutor_commanddetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_command);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_pid);
    if (rc < 0)
      return rc;
  }
  self->f_pid_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_exitcode);
    if (rc < 0)
      return rc;
  }
  self->f_exitcode_is_present = presence_flag;
  return rc;
}

// destructor
void softwaremanagement_commandexecutor_commanddetails_destroy(softwaremanagement_commandexecutor_commanddetails_t ** self_p)
{
  if ((*self_p)->f_command != NULL)
  {
    mal_string_destroy(& (*self_p)->f_command);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void softwaremanagement_commandexecutor_commanddetails_test(bool verbose)
{
  printf(" * SoftwareManagement:CommandExecutor:CommandDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
