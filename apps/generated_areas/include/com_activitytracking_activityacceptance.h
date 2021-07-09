#ifndef __COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_H_INCLUDED__
#define __COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_activitytracking_activityacceptance
mal_boolean_t com_activitytracking_activityacceptance_get_success(com_activitytracking_activityacceptance_t * self);
void com_activitytracking_activityacceptance_set_success(com_activitytracking_activityacceptance_t * self, mal_boolean_t f_success);

// default constructor
com_activitytracking_activityacceptance_t * com_activitytracking_activityacceptance_new(void);

// encoding functions related to transport malbinary
int com_activitytracking_activityacceptance_add_encoding_length_malbinary(com_activitytracking_activityacceptance_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activityacceptance_encode_malbinary(com_activitytracking_activityacceptance_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activityacceptance_decode_malbinary(com_activitytracking_activityacceptance_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_activitytracking_activityacceptance_destroy(com_activitytracking_activityacceptance_t ** self_p);

// test function
void com_activitytracking_activityacceptance_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_H_INCLUDED__
