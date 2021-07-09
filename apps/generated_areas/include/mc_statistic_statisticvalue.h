#ifndef __MC_STATISTIC_STATISTICVALUE_H_INCLUDED__
#define __MC_STATISTIC_STATISTICVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticvalue
mal_long_t mc_statistic_statisticvalue_get_paramdefinstid(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_set_paramdefinstid(mc_statistic_statisticvalue_t * self, mal_long_t f_paramdefinstid);
bool mc_statistic_statisticvalue_starttime_is_present(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_starttime_set_present(mc_statistic_statisticvalue_t * self, bool is_present);
mal_time_t mc_statistic_statisticvalue_get_starttime(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_set_starttime(mc_statistic_statisticvalue_t * self, mal_time_t f_starttime);
bool mc_statistic_statisticvalue_endtime_is_present(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_endtime_set_present(mc_statistic_statisticvalue_t * self, bool is_present);
mal_time_t mc_statistic_statisticvalue_get_endtime(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_set_endtime(mc_statistic_statisticvalue_t * self, mal_time_t f_endtime);
bool mc_statistic_statisticvalue_valuetime_is_present(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_valuetime_set_present(mc_statistic_statisticvalue_t * self, bool is_present);
mal_time_t mc_statistic_statisticvalue_get_valuetime(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_set_valuetime(mc_statistic_statisticvalue_t * self, mal_time_t f_valuetime);
bool mc_statistic_statisticvalue_value_is_present(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_value_set_present(mc_statistic_statisticvalue_t * self, bool is_present);
unsigned char mc_statistic_statisticvalue_value_get_attribute_tag(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_value_set_attribute_tag(mc_statistic_statisticvalue_t * self, unsigned char attribute_tag);
mal_uinteger_t mc_statistic_statisticvalue_get_samplecount(mc_statistic_statisticvalue_t * self);
void mc_statistic_statisticvalue_set_samplecount(mc_statistic_statisticvalue_t * self, mal_uinteger_t f_samplecount);

// default constructor
mc_statistic_statisticvalue_t * mc_statistic_statisticvalue_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticvalue_add_encoding_length_malbinary(mc_statistic_statisticvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticvalue_encode_malbinary(mc_statistic_statisticvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticvalue_decode_malbinary(mc_statistic_statisticvalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticvalue_destroy(mc_statistic_statisticvalue_t ** self_p);

// test function
void mc_statistic_statisticvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICVALUE_H_INCLUDED__
