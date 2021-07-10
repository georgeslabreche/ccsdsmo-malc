#include "opssat_std.h"


// structure definition for composite opssat_std_schedulemanagement_scheduleentry
struct _opssat_std_schedulemanagement_scheduleentry_t {
  opssat_std_schedulemanagement_schedule_t f_schedule;
  mal_time_t f_exectime;
  mal_blob_t * f_encop;
};

// fields accessors for composite opssat_std_schedulemanagement_scheduleentry
opssat_std_schedulemanagement_schedule_t opssat_std_schedulemanagement_scheduleentry_get_schedule(opssat_std_schedulemanagement_scheduleentry_t * self)
{
  return self->f_schedule;
}
void opssat_std_schedulemanagement_scheduleentry_set_schedule(opssat_std_schedulemanagement_scheduleentry_t * self, opssat_std_schedulemanagement_schedule_t f_schedule)
{
  self->f_schedule = f_schedule;
}
mal_time_t opssat_std_schedulemanagement_scheduleentry_get_exectime(opssat_std_schedulemanagement_scheduleentry_t * self)
{
  return self->f_exectime;
}
void opssat_std_schedulemanagement_scheduleentry_set_exectime(opssat_std_schedulemanagement_scheduleentry_t * self, mal_time_t f_exectime)
{
  self->f_exectime = f_exectime;
}
mal_blob_t * opssat_std_schedulemanagement_scheduleentry_get_encop(opssat_std_schedulemanagement_scheduleentry_t * self)
{
  return self->f_encop;
}
void opssat_std_schedulemanagement_scheduleentry_set_encop(opssat_std_schedulemanagement_scheduleentry_t * self, mal_blob_t * f_encop)
{
  self->f_encop = f_encop;
}

// default constructor
opssat_std_schedulemanagement_scheduleentry_t * opssat_std_schedulemanagement_scheduleentry_new(void)
{
  opssat_std_schedulemanagement_scheduleentry_t *self = (opssat_std_schedulemanagement_scheduleentry_t *) calloc(1, sizeof(opssat_std_schedulemanagement_scheduleentry_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int opssat_std_schedulemanagement_scheduleentry_add_encoding_length_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_schedule, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_time_encoding_length(encoder, self->f_exectime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_blob_encoding_length(encoder, self->f_encop, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_schedulemanagement_scheduleentry_encode_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_schedule);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_time(encoder, cursor, self->f_exectime);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_blob(encoder, cursor, self->f_encop);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_schedulemanagement_scheduleentry_decode_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_schedule = (opssat_std_schedulemanagement_schedule_t) enumerated_value;
  rc = mal_decoder_decode_time(decoder, cursor, &self->f_exectime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_blob(decoder, cursor, &self->f_encop);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void opssat_std_schedulemanagement_scheduleentry_destroy(opssat_std_schedulemanagement_scheduleentry_t ** self_p)
{
  if ((*self_p)->f_encop != NULL)
  {
    mal_blob_destroy(& (*self_p)->f_encop);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void opssat_std_schedulemanagement_scheduleentry_test(bool verbose)
{
  printf(" * OPSSAT_STD:ScheduleManagement:ScheduleEntry: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
