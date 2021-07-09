#ifndef __PF_GPS_NEARBYPOSITIONDEFINITION_H_INCLUDED__
#define __PF_GPS_NEARBYPOSITIONDEFINITION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_gps_nearbypositiondefinition
mal_identifier_t * pf_gps_nearbypositiondefinition_get_name(pf_gps_nearbypositiondefinition_t * self);
void pf_gps_nearbypositiondefinition_set_name(pf_gps_nearbypositiondefinition_t * self, mal_identifier_t * f_name);
mal_string_t * pf_gps_nearbypositiondefinition_get_description(pf_gps_nearbypositiondefinition_t * self);
void pf_gps_nearbypositiondefinition_set_description(pf_gps_nearbypositiondefinition_t * self, mal_string_t * f_description);
bool pf_gps_nearbypositiondefinition_distanceboundary_is_present(pf_gps_nearbypositiondefinition_t * self);
void pf_gps_nearbypositiondefinition_distanceboundary_set_present(pf_gps_nearbypositiondefinition_t * self, bool is_present);
mal_float_t pf_gps_nearbypositiondefinition_get_distanceboundary(pf_gps_nearbypositiondefinition_t * self);
void pf_gps_nearbypositiondefinition_set_distanceboundary(pf_gps_nearbypositiondefinition_t * self, mal_float_t f_distanceboundary);
pf_gps_position_t * pf_gps_nearbypositiondefinition_get_position(pf_gps_nearbypositiondefinition_t * self);
void pf_gps_nearbypositiondefinition_set_position(pf_gps_nearbypositiondefinition_t * self, pf_gps_position_t * f_position);

// default constructor
pf_gps_nearbypositiondefinition_t * pf_gps_nearbypositiondefinition_new(void);

// encoding functions related to transport malbinary
int pf_gps_nearbypositiondefinition_add_encoding_length_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_nearbypositiondefinition_encode_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_nearbypositiondefinition_decode_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_gps_nearbypositiondefinition_destroy(pf_gps_nearbypositiondefinition_t ** self_p);

// test function
void pf_gps_nearbypositiondefinition_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_GPS_NEARBYPOSITIONDEFINITION_H_INCLUDED__
