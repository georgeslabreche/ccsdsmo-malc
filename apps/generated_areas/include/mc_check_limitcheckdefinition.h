#ifndef __MC_CHECK_LIMITCHECKDEFINITION_H_INCLUDED__
#define __MC_CHECK_LIMITCHECKDEFINITION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_limitcheckdefinition
mal_string_t * mc_check_limitcheckdefinition_get_description(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_description(mc_check_limitcheckdefinition_t * self, mal_string_t * f_description);
mc_severity_t mc_check_limitcheckdefinition_get_checkseverity(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_checkseverity(mc_check_limitcheckdefinition_t * self, mc_severity_t f_checkseverity);
mal_duration_t mc_check_limitcheckdefinition_get_maxreportinginterval(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_maxreportinginterval(mc_check_limitcheckdefinition_t * self, mal_duration_t f_maxreportinginterval);
mal_uinteger_t mc_check_limitcheckdefinition_get_nominalcount(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_nominalcount(mc_check_limitcheckdefinition_t * self, mal_uinteger_t f_nominalcount);
mal_duration_t mc_check_limitcheckdefinition_get_nominaltime(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_nominaltime(mc_check_limitcheckdefinition_t * self, mal_duration_t f_nominaltime);
mal_uinteger_t mc_check_limitcheckdefinition_get_violationcount(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_violationcount(mc_check_limitcheckdefinition_t * self, mal_uinteger_t f_violationcount);
mal_duration_t mc_check_limitcheckdefinition_get_violationtime(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_violationtime(mc_check_limitcheckdefinition_t * self, mal_duration_t f_violationtime);
mal_boolean_t mc_check_limitcheckdefinition_get_violateinrange(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_set_violateinrange(mc_check_limitcheckdefinition_t * self, mal_boolean_t f_violateinrange);
bool mc_check_limitcheckdefinition_lowerlimit_is_present(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_lowerlimit_set_present(mc_check_limitcheckdefinition_t * self, bool is_present);
unsigned char mc_check_limitcheckdefinition_lowerlimit_get_attribute_tag(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_lowerlimit_set_attribute_tag(mc_check_limitcheckdefinition_t * self, unsigned char attribute_tag);
bool mc_check_limitcheckdefinition_upperlimit_is_present(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_upperlimit_set_present(mc_check_limitcheckdefinition_t * self, bool is_present);
unsigned char mc_check_limitcheckdefinition_upperlimit_get_attribute_tag(mc_check_limitcheckdefinition_t * self);
void mc_check_limitcheckdefinition_upperlimit_set_attribute_tag(mc_check_limitcheckdefinition_t * self, unsigned char attribute_tag);

// default constructor
mc_check_limitcheckdefinition_t * mc_check_limitcheckdefinition_new(void);

// encoding functions related to transport malbinary
int mc_check_limitcheckdefinition_add_encoding_length_malbinary(mc_check_limitcheckdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_limitcheckdefinition_encode_malbinary(mc_check_limitcheckdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_limitcheckdefinition_decode_malbinary(mc_check_limitcheckdefinition_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_limitcheckdefinition_destroy(mc_check_limitcheckdefinition_t ** self_p);

// test function
void mc_check_limitcheckdefinition_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_LIMITCHECKDEFINITION_H_INCLUDED__
