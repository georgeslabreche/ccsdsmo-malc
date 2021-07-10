#ifndef __MC_AGGREGATION_AGGREGATIONREFERENCE_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONREFERENCE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationreference
mal_identifier_list_t * mc_aggregation_aggregationreference_get_domain(mc_aggregation_aggregationreference_t * self);
void mc_aggregation_aggregationreference_set_domain(mc_aggregation_aggregationreference_t * self, mal_identifier_list_t * f_domain);
mal_long_list_t * mc_aggregation_aggregationreference_get_parameters(mc_aggregation_aggregationreference_t * self);
void mc_aggregation_aggregationreference_set_parameters(mc_aggregation_aggregationreference_t * self, mal_long_list_t * f_parameters);
mal_duration_t mc_aggregation_aggregationreference_get_sampleinterval(mc_aggregation_aggregationreference_t * self);
void mc_aggregation_aggregationreference_set_sampleinterval(mc_aggregation_aggregationreference_t * self, mal_duration_t f_sampleinterval);
mc_aggregation_thresholdfilter_t * mc_aggregation_aggregationreference_get_periodicfilter(mc_aggregation_aggregationreference_t * self);
void mc_aggregation_aggregationreference_set_periodicfilter(mc_aggregation_aggregationreference_t * self, mc_aggregation_thresholdfilter_t * f_periodicfilter);

// default constructor
mc_aggregation_aggregationreference_t * mc_aggregation_aggregationreference_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationreference_add_encoding_length_malbinary(mc_aggregation_aggregationreference_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationreference_encode_malbinary(mc_aggregation_aggregationreference_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationreference_decode_malbinary(mc_aggregation_aggregationreference_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationreference_destroy(mc_aggregation_aggregationreference_t ** self_p);

// test function
void mc_aggregation_aggregationreference_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONREFERENCE_H_INCLUDED__
