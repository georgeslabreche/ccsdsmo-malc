#ifndef __MC_AGGREGATION_AGGREGATIONPARAMETERSET_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONPARAMETERSET_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationparameterset
mal_identifier_list_t * mc_aggregation_aggregationparameterset_get_domain(mc_aggregation_aggregationparameterset_t * self);
void mc_aggregation_aggregationparameterset_set_domain(mc_aggregation_aggregationparameterset_t * self, mal_identifier_list_t * f_domain);
mal_long_list_t * mc_aggregation_aggregationparameterset_get_parameters(mc_aggregation_aggregationparameterset_t * self);
void mc_aggregation_aggregationparameterset_set_parameters(mc_aggregation_aggregationparameterset_t * self, mal_long_list_t * f_parameters);
mal_duration_t mc_aggregation_aggregationparameterset_get_sampleinterval(mc_aggregation_aggregationparameterset_t * self);
void mc_aggregation_aggregationparameterset_set_sampleinterval(mc_aggregation_aggregationparameterset_t * self, mal_duration_t f_sampleinterval);
mc_aggregation_thresholdfilter_t * mc_aggregation_aggregationparameterset_get_reportfilter(mc_aggregation_aggregationparameterset_t * self);
void mc_aggregation_aggregationparameterset_set_reportfilter(mc_aggregation_aggregationparameterset_t * self, mc_aggregation_thresholdfilter_t * f_reportfilter);

// default constructor
mc_aggregation_aggregationparameterset_t * mc_aggregation_aggregationparameterset_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationparameterset_add_encoding_length_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationparameterset_encode_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationparameterset_decode_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationparameterset_destroy(mc_aggregation_aggregationparameterset_t ** self_p);

// test function
void mc_aggregation_aggregationparameterset_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONPARAMETERSET_H_INCLUDED__
