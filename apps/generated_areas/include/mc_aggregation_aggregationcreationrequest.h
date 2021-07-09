#ifndef __MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationcreationrequest
mal_identifier_t * mc_aggregation_aggregationcreationrequest_get_name(mc_aggregation_aggregationcreationrequest_t * self);
void mc_aggregation_aggregationcreationrequest_set_name(mc_aggregation_aggregationcreationrequest_t * self, mal_identifier_t * f_name);
mc_aggregation_aggregationdefinitiondetails_t * mc_aggregation_aggregationcreationrequest_get_aggdefdetails(mc_aggregation_aggregationcreationrequest_t * self);
void mc_aggregation_aggregationcreationrequest_set_aggdefdetails(mc_aggregation_aggregationcreationrequest_t * self, mc_aggregation_aggregationdefinitiondetails_t * f_aggdefdetails);

// default constructor
mc_aggregation_aggregationcreationrequest_t * mc_aggregation_aggregationcreationrequest_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationcreationrequest_add_encoding_length_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationcreationrequest_encode_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationcreationrequest_decode_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationcreationrequest_destroy(mc_aggregation_aggregationcreationrequest_t ** self_p);

// test function
void mc_aggregation_aggregationcreationrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_H_INCLUDED__
