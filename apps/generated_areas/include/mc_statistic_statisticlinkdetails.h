#ifndef __MC_STATISTIC_STATISTICLINKDETAILS_H_INCLUDED__
#define __MC_STATISTIC_STATISTICLINKDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticlinkdetails
mal_duration_t mc_statistic_statisticlinkdetails_get_samplinginterval(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_samplinginterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_samplinginterval);
mal_duration_t mc_statistic_statisticlinkdetails_get_reportinginterval(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_reportinginterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_reportinginterval);
mal_duration_t mc_statistic_statisticlinkdetails_get_collectioninterval(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_collectioninterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_collectioninterval);
mal_boolean_t mc_statistic_statisticlinkdetails_get_reseteverycollection(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_reseteverycollection(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_reseteverycollection);
mal_boolean_t mc_statistic_statisticlinkdetails_get_reportingenabled(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_reportingenabled(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_reportingenabled);
mal_boolean_t mc_statistic_statisticlinkdetails_get_useconverted(mc_statistic_statisticlinkdetails_t * self);
void mc_statistic_statisticlinkdetails_set_useconverted(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_useconverted);

// default constructor
mc_statistic_statisticlinkdetails_t * mc_statistic_statisticlinkdetails_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticlinkdetails_add_encoding_length_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticlinkdetails_encode_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticlinkdetails_decode_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticlinkdetails_destroy(mc_statistic_statisticlinkdetails_t ** self_p);

// test function
void mc_statistic_statisticlinkdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICLINKDETAILS_H_INCLUDED__
