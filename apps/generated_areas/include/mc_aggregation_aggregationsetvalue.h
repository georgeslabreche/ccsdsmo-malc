#ifndef __MC_AGGREGATION_AGGREGATIONSETVALUE_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONSETVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationsetvalue
bool mc_aggregation_aggregationsetvalue_deltatime_is_present(mc_aggregation_aggregationsetvalue_t * self);
void mc_aggregation_aggregationsetvalue_deltatime_set_present(mc_aggregation_aggregationsetvalue_t * self, bool is_present);
mal_duration_t mc_aggregation_aggregationsetvalue_get_deltatime(mc_aggregation_aggregationsetvalue_t * self);
void mc_aggregation_aggregationsetvalue_set_deltatime(mc_aggregation_aggregationsetvalue_t * self, mal_duration_t f_deltatime);
bool mc_aggregation_aggregationsetvalue_intervaltime_is_present(mc_aggregation_aggregationsetvalue_t * self);
void mc_aggregation_aggregationsetvalue_intervaltime_set_present(mc_aggregation_aggregationsetvalue_t * self, bool is_present);
mal_duration_t mc_aggregation_aggregationsetvalue_get_intervaltime(mc_aggregation_aggregationsetvalue_t * self);
void mc_aggregation_aggregationsetvalue_set_intervaltime(mc_aggregation_aggregationsetvalue_t * self, mal_duration_t f_intervaltime);
mc_aggregation_aggregationparametervalue_list_t * mc_aggregation_aggregationsetvalue_get_values(mc_aggregation_aggregationsetvalue_t * self);
void mc_aggregation_aggregationsetvalue_set_values(mc_aggregation_aggregationsetvalue_t * self, mc_aggregation_aggregationparametervalue_list_t * f_values);

// default constructor
mc_aggregation_aggregationsetvalue_t * mc_aggregation_aggregationsetvalue_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationsetvalue_add_encoding_length_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationsetvalue_encode_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationsetvalue_decode_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationsetvalue_destroy(mc_aggregation_aggregationsetvalue_t ** self_p);

// test function
void mc_aggregation_aggregationsetvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONSETVALUE_H_INCLUDED__
