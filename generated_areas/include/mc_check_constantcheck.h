#ifndef __MC_CHECK_CONSTANTCHECK_H_INCLUDED__
#define __MC_CHECK_CONSTANTCHECK_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_constantcheck
mal_identifier_t * mc_check_constantcheck_get_name(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_name(mc_check_constantcheck_t * self, mal_identifier_t * f_name);
mal_string_t * mc_check_constantcheck_get_description(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_description(mc_check_constantcheck_t * self, mal_string_t * f_description);
mc_severity_t mc_check_constantcheck_get_checkseverity(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_checkseverity(mc_check_constantcheck_t * self, mc_severity_t f_checkseverity);
mal_duration_t mc_check_constantcheck_get_maxreportinginterval(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_maxreportinginterval(mc_check_constantcheck_t * self, mal_duration_t f_maxreportinginterval);
mal_uinteger_t mc_check_constantcheck_get_nominalcount(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_nominalcount(mc_check_constantcheck_t * self, mal_uinteger_t f_nominalcount);
mal_uinteger_t mc_check_constantcheck_get_violationcount(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_violationcount(mc_check_constantcheck_t * self, mal_uinteger_t f_violationcount);
com_archive_expressionoperator_t mc_check_constantcheck_get_operator(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_operator(mc_check_constantcheck_t * self, com_archive_expressionoperator_t f_operator);
mc_attributevalue_list_t * mc_check_constantcheck_get_values(mc_check_constantcheck_t * self);
void mc_check_constantcheck_set_values(mc_check_constantcheck_t * self, mc_attributevalue_list_t * f_values);

// default constructor
mc_check_constantcheck_t * mc_check_constantcheck_new(void);

// encoding functions related to transport malbinary
int mc_check_constantcheck_add_encoding_length_malbinary(mc_check_constantcheck_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_constantcheck_encode_malbinary(mc_check_constantcheck_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_constantcheck_decode_malbinary(mc_check_constantcheck_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_constantcheck_destroy(mc_check_constantcheck_t ** self_p);

// test function
void mc_check_constantcheck_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CONSTANTCHECK_H_INCLUDED__
