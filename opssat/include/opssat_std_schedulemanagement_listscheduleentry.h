#ifndef __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_H_INCLUDED__
#define __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite opssat_std_schedulemanagement_listscheduleentry
mal_time_t opssat_std_schedulemanagement_listscheduleentry_get_exectime(opssat_std_schedulemanagement_listscheduleentry_t * self);
void opssat_std_schedulemanagement_listscheduleentry_set_exectime(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_time_t f_exectime);
mal_ushort_t opssat_std_schedulemanagement_listscheduleentry_get_ssc(opssat_std_schedulemanagement_listscheduleentry_t * self);
void opssat_std_schedulemanagement_listscheduleentry_set_ssc(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_ushort_t f_ssc);

// default constructor
opssat_std_schedulemanagement_listscheduleentry_t * opssat_std_schedulemanagement_listscheduleentry_new(void);

// encoding functions related to transport malbinary
int opssat_std_schedulemanagement_listscheduleentry_add_encoding_length_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_listscheduleentry_encode_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_listscheduleentry_decode_malbinary(opssat_std_schedulemanagement_listscheduleentry_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void opssat_std_schedulemanagement_listscheduleentry_destroy(opssat_std_schedulemanagement_listscheduleentry_t ** self_p);

// test function
void opssat_std_schedulemanagement_listscheduleentry_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_H_INCLUDED__
