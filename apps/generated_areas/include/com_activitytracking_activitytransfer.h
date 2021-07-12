#ifndef __COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_H_INCLUDED__
#define __COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_activitytracking_activitytransfer
mal_boolean_t com_activitytracking_activitytransfer_get_success(com_activitytracking_activitytransfer_t * self);
void com_activitytracking_activitytransfer_set_success(com_activitytracking_activitytransfer_t * self, mal_boolean_t f_success);
bool com_activitytracking_activitytransfer_estimateduration_is_present(com_activitytracking_activitytransfer_t * self);
void com_activitytracking_activitytransfer_estimateduration_set_present(com_activitytracking_activitytransfer_t * self, bool is_present);
mal_duration_t com_activitytracking_activitytransfer_get_estimateduration(com_activitytracking_activitytransfer_t * self);
void com_activitytracking_activitytransfer_set_estimateduration(com_activitytracking_activitytransfer_t * self, mal_duration_t f_estimateduration);
mal_uri_t * com_activitytracking_activitytransfer_get_nextdestination(com_activitytracking_activitytransfer_t * self);
void com_activitytracking_activitytransfer_set_nextdestination(com_activitytracking_activitytransfer_t * self, mal_uri_t * f_nextdestination);

// default constructor
com_activitytracking_activitytransfer_t * com_activitytracking_activitytransfer_new(void);

// encoding functions related to transport malbinary
int com_activitytracking_activitytransfer_add_encoding_length_malbinary(com_activitytracking_activitytransfer_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activitytransfer_encode_malbinary(com_activitytracking_activitytransfer_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activitytransfer_decode_malbinary(com_activitytracking_activitytransfer_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_activitytracking_activitytransfer_destroy(com_activitytracking_activitytransfer_t ** self_p);

// test function
void com_activitytracking_activitytransfer_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_H_INCLUDED__
