#ifndef __MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationparametervalue
mc_parameter_parametervalue_t * mc_aggregation_aggregationparametervalue_get_value(mc_aggregation_aggregationparametervalue_t * self);
void mc_aggregation_aggregationparametervalue_set_value(mc_aggregation_aggregationparametervalue_t * self, mc_parameter_parametervalue_t * f_value);
bool mc_aggregation_aggregationparametervalue_paramdefinstid_is_present(mc_aggregation_aggregationparametervalue_t * self);
void mc_aggregation_aggregationparametervalue_paramdefinstid_set_present(mc_aggregation_aggregationparametervalue_t * self, bool is_present);
mal_long_t mc_aggregation_aggregationparametervalue_get_paramdefinstid(mc_aggregation_aggregationparametervalue_t * self);
void mc_aggregation_aggregationparametervalue_set_paramdefinstid(mc_aggregation_aggregationparametervalue_t * self, mal_long_t f_paramdefinstid);

// default constructor
mc_aggregation_aggregationparametervalue_t * mc_aggregation_aggregationparametervalue_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationparametervalue_add_encoding_length_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationparametervalue_encode_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationparametervalue_decode_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationparametervalue_destroy(mc_aggregation_aggregationparametervalue_t ** self_p);

// test function
void mc_aggregation_aggregationparametervalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_H_INCLUDED__
