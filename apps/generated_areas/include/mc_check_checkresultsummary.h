#ifndef __MC_CHECK_CHECKRESULTSUMMARY_H_INCLUDED__
#define __MC_CHECK_CHECKRESULTSUMMARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checkresultsummary
mal_long_t mc_check_checkresultsummary_get_linkid(mc_check_checkresultsummary_t * self);
void mc_check_checkresultsummary_set_linkid(mc_check_checkresultsummary_t * self, mal_long_t f_linkid);
mal_boolean_t mc_check_checkresultsummary_get_checkenabled(mc_check_checkresultsummary_t * self);
void mc_check_checkresultsummary_set_checkenabled(mc_check_checkresultsummary_t * self, mal_boolean_t f_checkenabled);
com_objectkey_t * mc_check_checkresultsummary_get_parameterid(mc_check_checkresultsummary_t * self);
void mc_check_checkresultsummary_set_parameterid(mc_check_checkresultsummary_t * self, com_objectkey_t * f_parameterid);
mal_time_t mc_check_checkresultsummary_get_evaluationtime(mc_check_checkresultsummary_t * self);
void mc_check_checkresultsummary_set_evaluationtime(mc_check_checkresultsummary_t * self, mal_time_t f_evaluationtime);
mc_check_checkresult_t * mc_check_checkresultsummary_get_result(mc_check_checkresultsummary_t * self);
void mc_check_checkresultsummary_set_result(mc_check_checkresultsummary_t * self, mc_check_checkresult_t * f_result);

// default constructor
mc_check_checkresultsummary_t * mc_check_checkresultsummary_new(void);

// encoding functions related to transport malbinary
int mc_check_checkresultsummary_add_encoding_length_malbinary(mc_check_checkresultsummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresultsummary_encode_malbinary(mc_check_checkresultsummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresultsummary_decode_malbinary(mc_check_checkresultsummary_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checkresultsummary_destroy(mc_check_checkresultsummary_t ** self_p);

// test function
void mc_check_checkresultsummary_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKRESULTSUMMARY_H_INCLUDED__
