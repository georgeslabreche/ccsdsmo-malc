#ifndef __MC_STATISTIC_STATISTICEVALUATIONREPORT_H_INCLUDED__
#define __MC_STATISTIC_STATISTICEVALUATIONREPORT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticevaluationreport
mal_long_t mc_statistic_statisticevaluationreport_get_linkid(mc_statistic_statisticevaluationreport_t * self);
void mc_statistic_statisticevaluationreport_set_linkid(mc_statistic_statisticevaluationreport_t * self, mal_long_t f_linkid);
mc_statistic_statisticvalue_t * mc_statistic_statisticevaluationreport_get_value(mc_statistic_statisticevaluationreport_t * self);
void mc_statistic_statisticevaluationreport_set_value(mc_statistic_statisticevaluationreport_t * self, mc_statistic_statisticvalue_t * f_value);

// default constructor
mc_statistic_statisticevaluationreport_t * mc_statistic_statisticevaluationreport_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticevaluationreport_add_encoding_length_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticevaluationreport_encode_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticevaluationreport_decode_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticevaluationreport_destroy(mc_statistic_statisticevaluationreport_t ** self_p);

// test function
void mc_statistic_statisticevaluationreport_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICEVALUATIONREPORT_H_INCLUDED__
