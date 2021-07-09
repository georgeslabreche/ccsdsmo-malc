#ifndef __PF_GPS_POSITIONEXTRADETAILS_H_INCLUDED__
#define __PF_GPS_POSITIONEXTRADETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_gps_positionextradetails
bool pf_gps_positionextradetails_utc_is_present(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_utc_set_present(pf_gps_positionextradetails_t * self, bool is_present);
mal_time_t pf_gps_positionextradetails_get_utc(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_set_utc(pf_gps_positionextradetails_t * self, mal_time_t f_utc);
bool pf_gps_positionextradetails_fixquality_is_present(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_fixquality_set_present(pf_gps_positionextradetails_t * self, bool is_present);
mal_integer_t pf_gps_positionextradetails_get_fixquality(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_set_fixquality(pf_gps_positionextradetails_t * self, mal_integer_t f_fixquality);
bool pf_gps_positionextradetails_numberofsatellites_is_present(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_numberofsatellites_set_present(pf_gps_positionextradetails_t * self, bool is_present);
mal_integer_t pf_gps_positionextradetails_get_numberofsatellites(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_set_numberofsatellites(pf_gps_positionextradetails_t * self, mal_integer_t f_numberofsatellites);
bool pf_gps_positionextradetails_hdop_is_present(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_hdop_set_present(pf_gps_positionextradetails_t * self, bool is_present);
mal_float_t pf_gps_positionextradetails_get_hdop(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_set_hdop(pf_gps_positionextradetails_t * self, mal_float_t f_hdop);
bool pf_gps_positionextradetails_undulation_is_present(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_undulation_set_present(pf_gps_positionextradetails_t * self, bool is_present);
mal_float_t pf_gps_positionextradetails_get_undulation(pf_gps_positionextradetails_t * self);
void pf_gps_positionextradetails_set_undulation(pf_gps_positionextradetails_t * self, mal_float_t f_undulation);

// default constructor
pf_gps_positionextradetails_t * pf_gps_positionextradetails_new(void);

// encoding functions related to transport malbinary
int pf_gps_positionextradetails_add_encoding_length_malbinary(pf_gps_positionextradetails_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_positionextradetails_encode_malbinary(pf_gps_positionextradetails_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_positionextradetails_decode_malbinary(pf_gps_positionextradetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_gps_positionextradetails_destroy(pf_gps_positionextradetails_t ** self_p);

// test function
void pf_gps_positionextradetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_GPS_POSITIONEXTRADETAILS_H_INCLUDED__
