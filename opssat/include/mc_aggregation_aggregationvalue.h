#ifndef __MC_AGGREGATION_AGGREGATIONVALUE_H_INCLUDED__
#define __MC_AGGREGATION_AGGREGATIONVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_aggregation_aggregationvalue
mc_aggregation_generationmode_t mc_aggregation_aggregationvalue_get_generationmode(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_generationmode(mc_aggregation_aggregationvalue_t * self, mc_aggregation_generationmode_t f_generationmode);
mal_boolean_t mc_aggregation_aggregationvalue_get_filtered(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_filtered(mc_aggregation_aggregationvalue_t * self, mal_boolean_t f_filtered);
bool mc_aggregation_aggregationvalue_deltatime_is_present(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_deltatime_set_present(mc_aggregation_aggregationvalue_t * self, bool is_present);
mal_duration_t mc_aggregation_aggregationvalue_get_deltatime(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_deltatime(mc_aggregation_aggregationvalue_t * self, mal_duration_t f_deltatime);
bool mc_aggregation_aggregationvalue_intervaltime_is_present(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_intervaltime_set_present(mc_aggregation_aggregationvalue_t * self, bool is_present);
mal_duration_t mc_aggregation_aggregationvalue_get_intervaltime(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_intervaltime(mc_aggregation_aggregationvalue_t * self, mal_duration_t f_intervaltime);
bool mc_aggregation_aggregationvalue_setintervaltime_is_present(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_setintervaltime_set_present(mc_aggregation_aggregationvalue_t * self, bool is_present);
mal_duration_t mc_aggregation_aggregationvalue_get_setintervaltime(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_setintervaltime(mc_aggregation_aggregationvalue_t * self, mal_duration_t f_setintervaltime);
mc_parameter_parametervalue_list_t * mc_aggregation_aggregationvalue_get_values(mc_aggregation_aggregationvalue_t * self);
void mc_aggregation_aggregationvalue_set_values(mc_aggregation_aggregationvalue_t * self, mc_parameter_parametervalue_list_t * f_values);

// default constructor
mc_aggregation_aggregationvalue_t * mc_aggregation_aggregationvalue_new(void);

// encoding functions related to transport malbinary
int mc_aggregation_aggregationvalue_add_encoding_length_malbinary(mc_aggregation_aggregationvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationvalue_encode_malbinary(mc_aggregation_aggregationvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_aggregation_aggregationvalue_decode_malbinary(mc_aggregation_aggregationvalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_aggregation_aggregationvalue_destroy(mc_aggregation_aggregationvalue_t ** self_p);

// test function
void mc_aggregation_aggregationvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_AGGREGATION_AGGREGATIONVALUE_H_INCLUDED__
