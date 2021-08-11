#ifndef __MC_CHECK_CHECKLINKSUMMARY_H_INCLUDED__
#define __MC_CHECK_CHECKLINKSUMMARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checklinksummary
mal_long_t mc_check_checklinksummary_get_checkid(mc_check_checklinksummary_t * self);
void mc_check_checklinksummary_set_checkid(mc_check_checklinksummary_t * self, mal_long_t f_checkid);
mal_long_t mc_check_checklinksummary_get_linkid(mc_check_checklinksummary_t * self);
void mc_check_checklinksummary_set_linkid(mc_check_checklinksummary_t * self, mal_long_t f_linkid);
mal_long_t mc_check_checklinksummary_get_linkdefinitionid(mc_check_checklinksummary_t * self);
void mc_check_checklinksummary_set_linkdefinitionid(mc_check_checklinksummary_t * self, mal_long_t f_linkdefinitionid);
mal_boolean_t mc_check_checklinksummary_get_checkenabled(mc_check_checklinksummary_t * self);
void mc_check_checklinksummary_set_checkenabled(mc_check_checklinksummary_t * self, mal_boolean_t f_checkenabled);
com_objectkey_t * mc_check_checklinksummary_get_parameterid(mc_check_checklinksummary_t * self);
void mc_check_checklinksummary_set_parameterid(mc_check_checklinksummary_t * self, com_objectkey_t * f_parameterid);

// default constructor
mc_check_checklinksummary_t * mc_check_checklinksummary_new(void);

// encoding functions related to transport malbinary
int mc_check_checklinksummary_add_encoding_length_malbinary(mc_check_checklinksummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checklinksummary_encode_malbinary(mc_check_checklinksummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checklinksummary_decode_malbinary(mc_check_checklinksummary_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checklinksummary_destroy(mc_check_checklinksummary_t ** self_p);

// test function
void mc_check_checklinksummary_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKLINKSUMMARY_H_INCLUDED__
