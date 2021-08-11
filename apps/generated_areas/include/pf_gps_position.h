#ifndef __PF_GPS_POSITION_H_INCLUDED__
#define __PF_GPS_POSITION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_gps_position
mal_float_t pf_gps_position_get_latitude(pf_gps_position_t * self);
void pf_gps_position_set_latitude(pf_gps_position_t * self, mal_float_t f_latitude);
mal_float_t pf_gps_position_get_longitude(pf_gps_position_t * self);
void pf_gps_position_set_longitude(pf_gps_position_t * self, mal_float_t f_longitude);
mal_float_t pf_gps_position_get_altitude(pf_gps_position_t * self);
void pf_gps_position_set_altitude(pf_gps_position_t * self, mal_float_t f_altitude);
pf_gps_positionextradetails_t * pf_gps_position_get_extradetails(pf_gps_position_t * self);
void pf_gps_position_set_extradetails(pf_gps_position_t * self, pf_gps_positionextradetails_t * f_extradetails);

// default constructor
pf_gps_position_t * pf_gps_position_new(void);

// encoding functions related to transport malbinary
int pf_gps_position_add_encoding_length_malbinary(pf_gps_position_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_position_encode_malbinary(pf_gps_position_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_position_decode_malbinary(pf_gps_position_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_gps_position_destroy(pf_gps_position_t ** self_p);

// test function
void pf_gps_position_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_GPS_POSITION_H_INCLUDED__
