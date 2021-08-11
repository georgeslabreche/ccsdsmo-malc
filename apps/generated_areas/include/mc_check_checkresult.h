#ifndef __MC_CHECK_CHECKRESULT_H_INCLUDED__
#define __MC_CHECK_CHECKRESULT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checkresult
mc_check_checkstate_t mc_check_checkresult_get_previouscheckstate(mc_check_checkresult_t * self);
void mc_check_checkresult_set_previouscheckstate(mc_check_checkresult_t * self, mc_check_checkstate_t f_previouscheckstate);
mc_check_checkstate_t mc_check_checkresult_get_currentcheckstate(mc_check_checkresult_t * self);
void mc_check_checkresult_set_currentcheckstate(mc_check_checkresult_t * self, mc_check_checkstate_t f_currentcheckstate);
bool mc_check_checkresult_paramdefinstid_is_present(mc_check_checkresult_t * self);
void mc_check_checkresult_paramdefinstid_set_present(mc_check_checkresult_t * self, bool is_present);
mal_long_t mc_check_checkresult_get_paramdefinstid(mc_check_checkresult_t * self);
void mc_check_checkresult_set_paramdefinstid(mc_check_checkresult_t * self, mal_long_t f_paramdefinstid);
bool mc_check_checkresult_checkedvalue_is_present(mc_check_checkresult_t * self);
void mc_check_checkresult_checkedvalue_set_present(mc_check_checkresult_t * self, bool is_present);
unsigned char mc_check_checkresult_checkedvalue_get_attribute_tag(mc_check_checkresult_t * self);
void mc_check_checkresult_checkedvalue_set_attribute_tag(mc_check_checkresult_t * self, unsigned char attribute_tag);

// default constructor
mc_check_checkresult_t * mc_check_checkresult_new(void);

// encoding functions related to transport malbinary
int mc_check_checkresult_add_encoding_length_malbinary(mc_check_checkresult_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresult_encode_malbinary(mc_check_checkresult_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checkresult_decode_malbinary(mc_check_checkresult_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checkresult_destroy(mc_check_checkresult_t ** self_p);

// test function
void mc_check_checkresult_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKRESULT_H_INCLUDED__
