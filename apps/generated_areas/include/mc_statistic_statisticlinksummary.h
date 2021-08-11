#ifndef __MC_STATISTIC_STATISTICLINKSUMMARY_H_INCLUDED__
#define __MC_STATISTIC_STATISTICLINKSUMMARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticlinksummary
mal_long_t mc_statistic_statisticlinksummary_get_funcid(mc_statistic_statisticlinksummary_t * self);
void mc_statistic_statisticlinksummary_set_funcid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_funcid);
mal_long_t mc_statistic_statisticlinksummary_get_linkid(mc_statistic_statisticlinksummary_t * self);
void mc_statistic_statisticlinksummary_set_linkid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_linkid);
mal_long_t mc_statistic_statisticlinksummary_get_linkdefid(mc_statistic_statisticlinksummary_t * self);
void mc_statistic_statisticlinksummary_set_linkdefid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_linkdefid);
mal_boolean_t mc_statistic_statisticlinksummary_get_reportingenabled(mc_statistic_statisticlinksummary_t * self);
void mc_statistic_statisticlinksummary_set_reportingenabled(mc_statistic_statisticlinksummary_t * self, mal_boolean_t f_reportingenabled);
com_objectkey_t * mc_statistic_statisticlinksummary_get_parameterid(mc_statistic_statisticlinksummary_t * self);
void mc_statistic_statisticlinksummary_set_parameterid(mc_statistic_statisticlinksummary_t * self, com_objectkey_t * f_parameterid);

// default constructor
mc_statistic_statisticlinksummary_t * mc_statistic_statisticlinksummary_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticlinksummary_add_encoding_length_malbinary(mc_statistic_statisticlinksummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticlinksummary_encode_malbinary(mc_statistic_statisticlinksummary_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticlinksummary_decode_malbinary(mc_statistic_statisticlinksummary_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticlinksummary_destroy(mc_statistic_statisticlinksummary_t ** self_p);

// test function
void mc_statistic_statisticlinksummary_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICLINKSUMMARY_H_INCLUDED__
