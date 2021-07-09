#ifndef __MC_STATISTIC_STATISTICFUNCTIONDETAILS_H_INCLUDED__
#define __MC_STATISTIC_STATISTICFUNCTIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticfunctiondetails
mal_identifier_t * mc_statistic_statisticfunctiondetails_get_name(mc_statistic_statisticfunctiondetails_t * self);
void mc_statistic_statisticfunctiondetails_set_name(mc_statistic_statisticfunctiondetails_t * self, mal_identifier_t * f_name);
mal_string_t * mc_statistic_statisticfunctiondetails_get_description(mc_statistic_statisticfunctiondetails_t * self);
void mc_statistic_statisticfunctiondetails_set_description(mc_statistic_statisticfunctiondetails_t * self, mal_string_t * f_description);

// default constructor
mc_statistic_statisticfunctiondetails_t * mc_statistic_statisticfunctiondetails_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticfunctiondetails_add_encoding_length_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticfunctiondetails_encode_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticfunctiondetails_decode_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticfunctiondetails_destroy(mc_statistic_statisticfunctiondetails_t ** self_p);

// test function
void mc_statistic_statisticfunctiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICFUNCTIONDETAILS_H_INCLUDED__
