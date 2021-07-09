#ifndef __OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_H_INCLUDED__
#define __OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite opssat_std_schedulemanagement_scheduleentry
opssat_std_schedulemanagement_schedule_t opssat_std_schedulemanagement_scheduleentry_get_schedule(opssat_std_schedulemanagement_scheduleentry_t * self);
void opssat_std_schedulemanagement_scheduleentry_set_schedule(opssat_std_schedulemanagement_scheduleentry_t * self, opssat_std_schedulemanagement_schedule_t f_schedule);
mal_time_t opssat_std_schedulemanagement_scheduleentry_get_exectime(opssat_std_schedulemanagement_scheduleentry_t * self);
void opssat_std_schedulemanagement_scheduleentry_set_exectime(opssat_std_schedulemanagement_scheduleentry_t * self, mal_time_t f_exectime);
mal_blob_t * opssat_std_schedulemanagement_scheduleentry_get_encop(opssat_std_schedulemanagement_scheduleentry_t * self);
void opssat_std_schedulemanagement_scheduleentry_set_encop(opssat_std_schedulemanagement_scheduleentry_t * self, mal_blob_t * f_encop);

// default constructor
opssat_std_schedulemanagement_scheduleentry_t * opssat_std_schedulemanagement_scheduleentry_new(void);

// encoding functions related to transport malbinary
int opssat_std_schedulemanagement_scheduleentry_add_encoding_length_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_scheduleentry_encode_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_scheduleentry_decode_malbinary(opssat_std_schedulemanagement_scheduleentry_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void opssat_std_schedulemanagement_scheduleentry_destroy(opssat_std_schedulemanagement_scheduleentry_t ** self_p);

// test function
void opssat_std_schedulemanagement_scheduleentry_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_H_INCLUDED__
