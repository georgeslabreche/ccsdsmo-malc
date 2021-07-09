#include "opssat_std.h"


// structure definition for composite opssat_std_schedulemanagement_listscheduleentry
struct _opssat_std_schedulemanagement_listscheduleentry_t {
  mal_time_t f_exectime;
  mal_ushort_t f_ssc;
};

// fields accessors for composite opssat_std_schedulemanagement_listscheduleentry
mal_time_t opssat_std_schedulemanagement_listscheduleentry_get_exectime(opssat_std_schedulemanagement_listscheduleentry_t * self)
{
  return self->f_exectime;
}
void opssat_std_schedulemanagement_listscheduleentry_set_exectime(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_time_t f_exectime)
{
  self->f_exectime = f_exectime;
}
mal_ushort_t opssat_std_schedulemanagement_listscheduleentry_get_ssc(opssat_std_schedulemanagement_listscheduleentry_t * self)
{
  return self->f_ssc;
}
void opssat_std_schedulemanagement_listscheduleentry_set_ssc(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_ushort_t f_ssc)
{
  self->f_ssc = f_ssc;
}

// default constructor
opssat_std_schedulemanagement_listscheduleentry_t * opssat_std_schedulemanagement_listscheduleentry_new(void)
{
  opssat_std_schedulemanagement_listscheduleentry_t *self = (opssat_std_schedulemanagement_listscheduleentry_t *) calloc(1, sizeof(opssat_std_schedulemanagement_listscheduleentry_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int opssat_std_schedulemanagement_listscheduleentry_add_encoding_length_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_time_encoding_length(encoder, self->f_exectime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_ssc, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_schedulemanagement_listscheduleentry_encode_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_time(encoder, cursor, self->f_exectime);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_ssc);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_std_schedulemanagement_listscheduleentry_decode_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_time(decoder, cursor, &self->f_exectime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_ssc);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void opssat_std_schedulemanagement_listscheduleentry_destroy(opssat_std_schedulemanagement_listscheduleentry_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void opssat_std_schedulemanagement_listscheduleentry_test(bool verbose)
{
  printf(" * OPSSAT_STD:ScheduleManagement:ListScheduleEntry: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
