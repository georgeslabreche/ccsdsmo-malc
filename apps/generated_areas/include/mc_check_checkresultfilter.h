#ifndef __MC_CHECK_CHECKRESULTFILTER_H_INCLUDED__
#define __MC_CHECK_CHECKRESULTFILTER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checkresultfilter
mal_boolean_t mc_check_checkresultfilter_get_checkfilterviagroups(mc_check_checkresultfilter_t * self);
void mc_check_checkresultfilter_set_checkfilterviagroups(mc_check_checkresultfilter_t * self, mal_boolean_t f_checkfilterviagroups);
mal_long_list_t * mc_check_checkresultfilter_get_checkfilter(mc_check_checkresultfilter_t * self);
void mc_check_checkresultfilter_set_checkfilter(mc_check_checkresultfilter_t * self, mal_long_list_t * f_checkfilter);
mal_boolean_t mc_check_checkresultfilter_get_parameterfilterviagroups(mc_check_checkresultfilter_t * self);
void mc_check_checkresultfilter_set_parameterfilterviagroups(mc_check_checkresultfilter_t * self, mal_boolean_t f_parameterfilterviagroups);
mal_long_list_t * mc_check_checkresultfilter_get_parameterfilter(mc_check_checkresultfilter_t * self);
void mc_check_checkresultfilter_set_parameterfilter(mc_check_checkresultfilter_t * self, mal_long_list_t * f_parameterfilter);
mc_check_checkstate_list_t * mc_check_checkresultfilter_get_statefilter(mc_check_checkresultfilter_t * self);
void mc_check_checkresultfilter_set_statefilter(mc_check_checkresultfilter_t * self, mc_check_checkstate_list_t * f_statefilter);

// default constructor
mc_check_checkresultfilter_t * mc_check_checkresultfilter_new(void);

// encoding functions related to transport malbinary
int mc_check_checkresultfilter_add_encoding_length_malbinary(mc_check_checkresultfilter_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresultfilter_encode_malbinary(mc_check_checkresultfilter_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresultfilter_decode_malbinary(mc_check_checkresultfilter_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checkresultfilter_destroy(mc_check_checkresultfilter_t ** self_p);

// test function
void mc_check_checkresultfilter_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKRESULTFILTER_H_INCLUDED__
