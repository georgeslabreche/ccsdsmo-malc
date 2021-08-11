#ifndef __PF_GPS_SATELLITEINFO_H_INCLUDED__
#define __PF_GPS_SATELLITEINFO_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_gps_satelliteinfo
bool pf_gps_satelliteinfo_azimuth_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_azimuth_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_float_t pf_gps_satelliteinfo_get_azimuth(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_azimuth(pf_gps_satelliteinfo_t * self, mal_float_t f_azimuth);
bool pf_gps_satelliteinfo_elevation_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_elevation_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_float_t pf_gps_satelliteinfo_get_elevation(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_elevation(pf_gps_satelliteinfo_t * self, mal_float_t f_elevation);
bool pf_gps_satelliteinfo_prn_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_prn_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_integer_t pf_gps_satelliteinfo_get_prn(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_prn(pf_gps_satelliteinfo_t * self, mal_integer_t f_prn);
bool pf_gps_satelliteinfo_almanac_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_almanac_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_float_t pf_gps_satelliteinfo_get_almanac(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_almanac(pf_gps_satelliteinfo_t * self, mal_float_t f_almanac);
bool pf_gps_satelliteinfo_ephemeris_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_ephemeris_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_float_t pf_gps_satelliteinfo_get_ephemeris(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_ephemeris(pf_gps_satelliteinfo_t * self, mal_float_t f_ephemeris);
bool pf_gps_satelliteinfo_recentfix_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_recentfix_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_time_t pf_gps_satelliteinfo_get_recentfix(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_recentfix(pf_gps_satelliteinfo_t * self, mal_time_t f_recentfix);
bool pf_gps_satelliteinfo_svn_is_present(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_svn_set_present(pf_gps_satelliteinfo_t * self, bool is_present);
mal_uinteger_t pf_gps_satelliteinfo_get_svn(pf_gps_satelliteinfo_t * self);
void pf_gps_satelliteinfo_set_svn(pf_gps_satelliteinfo_t * self, mal_uinteger_t f_svn);

// default constructor
pf_gps_satelliteinfo_t * pf_gps_satelliteinfo_new(void);

// encoding functions related to transport malbinary
int pf_gps_satelliteinfo_add_encoding_length_malbinary(pf_gps_satelliteinfo_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_satelliteinfo_encode_malbinary(pf_gps_satelliteinfo_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_satelliteinfo_decode_malbinary(pf_gps_satelliteinfo_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_gps_satelliteinfo_destroy(pf_gps_satelliteinfo_t ** self_p);

// test function
void pf_gps_satelliteinfo_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_GPS_SATELLITEINFO_H_INCLUDED__
