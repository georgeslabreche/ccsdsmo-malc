#ifndef __MC_AGGREGATION_THRESHOLDTYPE_LIST_H_INCLUDED__
#define __MC_AGGREGATION_THRESHOLDTYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mc_aggregation_thresholdtype_list_t * mc_aggregation_thresholdtype_list_new(unsigned int element_count);

// destructor, free the list and its content
void mc_aggregation_thresholdtype_list_destroy(mc_aggregation_thresholdtype_list_t ** self_p);

// fields accessors for enumeration list mc_aggregation_thresholdtype_list
unsigned int mc_aggregation_thresholdtype_list_get_element_count(mc_aggregation_thresholdtype_list_t * self);
bool * mc_aggregation_thresholdtype_list_get_presence_flags(mc_aggregation_thresholdtype_list_t * self);
mc_aggregation_thresholdtype_t * mc_aggregation_thresholdtype_list_get_content(mc_aggregation_thresholdtype_list_t * self);

// encoding functions related to transport malbinary
int mc_aggregation_thresholdtype_list_add_encoding_length_malbinary(mc_aggregation_thresholdtype_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_thresholdtype_list_encode_malbinary(mc_aggregation_thresholdtype_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_thresholdtype_list_decode_malbinary(mc_aggregation_thresholdtype_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mc_aggregation_thresholdtype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_THRESHOLDTYPE_LIST_H_INCLUDED__
