#ifndef __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_H_INCLUDED__
#define __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
opssat_std_schedulemanagement_listscheduleentry_list_t * opssat_std_schedulemanagement_listscheduleentry_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void opssat_std_schedulemanagement_listscheduleentry_list_destroy(opssat_std_schedulemanagement_listscheduleentry_list_t ** self_p);

// fields accessors for composite list opssat_std_schedulemanagement_listscheduleentry_list
unsigned int opssat_std_schedulemanagement_listscheduleentry_list_get_element_count(opssat_std_schedulemanagement_listscheduleentry_list_t * self);
opssat_std_schedulemanagement_listscheduleentry_t ** opssat_std_schedulemanagement_listscheduleentry_list_get_content(opssat_std_schedulemanagement_listscheduleentry_list_t * self);

// encoding functions related to transport malbinary
int opssat_std_schedulemanagement_listscheduleentry_list_add_encoding_length_malbinary(opssat_std_schedulemanagement_listscheduleentry_list_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_listscheduleentry_list_encode_malbinary(opssat_std_schedulemanagement_listscheduleentry_list_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_schedulemanagement_listscheduleentry_list_decode_malbinary(opssat_std_schedulemanagement_listscheduleentry_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void opssat_std_schedulemanagement_listscheduleentry_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_H_INCLUDED__
