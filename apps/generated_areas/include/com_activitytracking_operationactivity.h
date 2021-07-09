#ifndef __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__
#define __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_activitytracking_operationactivity
mal_interactiontype_t com_activitytracking_operationactivity_get_interactiontype(com_activitytracking_operationactivity_t * self);
void com_activitytracking_operationactivity_set_interactiontype(com_activitytracking_operationactivity_t * self, mal_interactiontype_t f_interactiontype);

// default constructor
com_activitytracking_operationactivity_t * com_activitytracking_operationactivity_new(void);

// encoding functions related to transport malbinary
int com_activitytracking_operationactivity_add_encoding_length_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_operationactivity_encode_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_operationactivity_decode_malbinary(com_activitytracking_operationactivity_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_activitytracking_operationactivity_destroy(com_activitytracking_operationactivity_t ** self_p);

// test function
void com_activitytracking_operationactivity_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__
