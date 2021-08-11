#ifndef __MC_AGGREGATION_AGGREGATIONVALUEDETAILS_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONVALUEDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationvaluedetails
mal_long_t mc_aggregation_aggregationvaluedetails_get_aggid(mc_aggregation_aggregationvaluedetails_t * self);
void mc_aggregation_aggregationvaluedetails_set_aggid(mc_aggregation_aggregationvaluedetails_t * self, mal_long_t f_aggid);
mal_long_t mc_aggregation_aggregationvaluedetails_get_defid(mc_aggregation_aggregationvaluedetails_t * self);
void mc_aggregation_aggregationvaluedetails_set_defid(mc_aggregation_aggregationvaluedetails_t * self, mal_long_t f_defid);
mal_time_t mc_aggregation_aggregationvaluedetails_get_timestamp(mc_aggregation_aggregationvaluedetails_t * self);
void mc_aggregation_aggregationvaluedetails_set_timestamp(mc_aggregation_aggregationvaluedetails_t * self, mal_time_t f_timestamp);
mc_aggregation_aggregationvalue_t * mc_aggregation_aggregationvaluedetails_get_value(mc_aggregation_aggregationvaluedetails_t * self);
void mc_aggregation_aggregationvaluedetails_set_value(mc_aggregation_aggregationvaluedetails_t * self, mc_aggregation_aggregationvalue_t * f_value);

// default constructor
mc_aggregation_aggregationvaluedetails_t * mc_aggregation_aggregationvaluedetails_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationvaluedetails_add_encoding_length_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationvaluedetails_encode_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationvaluedetails_decode_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationvaluedetails_destroy(mc_aggregation_aggregationvaluedetails_t ** self_p);

// test function
void mc_aggregation_aggregationvaluedetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONVALUEDETAILS_H_INCLUDED__
