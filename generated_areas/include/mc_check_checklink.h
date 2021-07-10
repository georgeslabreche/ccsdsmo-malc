#ifndef __MC_CHECK_CHECKLINK_H_INCLUDED__
#define __MC_CHECK_CHECKLINK_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checklink
mal_boolean_t mc_check_checklink_get_checkenabled(mc_check_checklink_t * self);
void mc_check_checklink_set_checkenabled(mc_check_checklink_t * self, mal_boolean_t f_checkenabled);
mal_boolean_t mc_check_checklink_get_checkonchange(mc_check_checklink_t * self);
void mc_check_checklink_set_checkonchange(mc_check_checklink_t * self, mal_boolean_t f_checkonchange);
mal_boolean_t mc_check_checklink_get_useconverted(mc_check_checklink_t * self);
void mc_check_checklink_set_useconverted(mc_check_checklink_t * self, mal_boolean_t f_useconverted);
mal_duration_t mc_check_checklink_get_checkinterval(mc_check_checklink_t * self);
void mc_check_checklink_set_checkinterval(mc_check_checklink_t * self, mal_duration_t f_checkinterval);
mc_parameterexpression_t * mc_check_checklink_get_condition(mc_check_checklink_t * self);
void mc_check_checklink_set_condition(mc_check_checklink_t * self, mc_parameterexpression_t * f_condition);

// default constructor
mc_check_checklink_t * mc_check_checklink_new(void);

// encoding functions related to transport malbinary
int mc_check_checklink_add_encoding_length_malbinary(mc_check_checklink_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checklink_encode_malbinary(mc_check_checklink_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checklink_decode_malbinary(mc_check_checklink_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checklink_destroy(mc_check_checklink_t ** self_p);

// test function
void mc_check_checklink_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKLINK_H_INCLUDED__
