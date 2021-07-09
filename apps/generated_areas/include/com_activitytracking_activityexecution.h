#ifndef __COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_H_INCLUDED__
#define __COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_activitytracking_activityexecution
mal_boolean_t com_activitytracking_activityexecution_get_success(com_activitytracking_activityexecution_t * self);
void com_activitytracking_activityexecution_set_success(com_activitytracking_activityexecution_t * self, mal_boolean_t f_success);
mal_uinteger_t com_activitytracking_activityexecution_get_executionstage(com_activitytracking_activityexecution_t * self);
void com_activitytracking_activityexecution_set_executionstage(com_activitytracking_activityexecution_t * self, mal_uinteger_t f_executionstage);
mal_uinteger_t com_activitytracking_activityexecution_get_stagecount(com_activitytracking_activityexecution_t * self);
void com_activitytracking_activityexecution_set_stagecount(com_activitytracking_activityexecution_t * self, mal_uinteger_t f_stagecount);

// default constructor
com_activitytracking_activityexecution_t * com_activitytracking_activityexecution_new(void);

// encoding functions related to transport malbinary
int com_activitytracking_activityexecution_add_encoding_length_malbinary(com_activitytracking_activityexecution_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activityexecution_encode_malbinary(com_activitytracking_activityexecution_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_activityexecution_decode_malbinary(com_activitytracking_activityexecution_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_activitytracking_activityexecution_destroy(com_activitytracking_activityexecution_t ** self_p);

// test function
void com_activitytracking_activityexecution_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_H_INCLUDED__
