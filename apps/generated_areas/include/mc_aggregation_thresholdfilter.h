#ifndef __MC_AGGREGATION_THRESHOLDFILTER_H_INCLUDED__
#define __MC_AGGREGATION_THRESHOLDFILTER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_thresholdfilter
mc_aggregation_thresholdtype_t mc_aggregation_thresholdfilter_get_thresholdtype(mc_aggregation_thresholdfilter_t * self);
void mc_aggregation_thresholdfilter_set_thresholdtype(mc_aggregation_thresholdfilter_t * self, mc_aggregation_thresholdtype_t f_thresholdtype);
unsigned char mc_aggregation_thresholdfilter_thresholdvalue_get_attribute_tag(mc_aggregation_thresholdfilter_t * self);
void mc_aggregation_thresholdfilter_thresholdvalue_set_attribute_tag(mc_aggregation_thresholdfilter_t * self, unsigned char attribute_tag);

// default constructor
mc_aggregation_thresholdfilter_t * mc_aggregation_thresholdfilter_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_thresholdfilter_add_encoding_length_malbinary(mc_aggregation_thresholdfilter_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_thresholdfilter_encode_malbinary(mc_aggregation_thresholdfilter_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_thresholdfilter_decode_malbinary(mc_aggregation_thresholdfilter_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_thresholdfilter_destroy(mc_aggregation_thresholdfilter_t ** self_p);

// test function
void mc_aggregation_thresholdfilter_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_THRESHOLDFILTER_H_INCLUDED__
