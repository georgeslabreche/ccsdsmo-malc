#ifndef __PF_GPS_TWOLINEELEMENTSET_H_INCLUDED__
#define __PF_GPS_TWOLINEELEMENTSET_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_gps_twolineelementset
bool pf_gps_twolineelementset_catalogno_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_catalogno_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_catalogno(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_catalogno(pf_gps_twolineelementset_t * self, mal_integer_t f_catalogno);
mal_string_t * pf_gps_twolineelementset_get_classification(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_classification(pf_gps_twolineelementset_t * self, mal_string_t * f_classification);
bool pf_gps_twolineelementset_idyear_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_idyear_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_idyear(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_idyear(pf_gps_twolineelementset_t * self, mal_integer_t f_idyear);
bool pf_gps_twolineelementset_idlaunchno_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_idlaunchno_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_idlaunchno(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_idlaunchno(pf_gps_twolineelementset_t * self, mal_integer_t f_idlaunchno);
mal_string_t * pf_gps_twolineelementset_get_idpiece(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_idpiece(pf_gps_twolineelementset_t * self, mal_string_t * f_idpiece);
bool pf_gps_twolineelementset_epochyear_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_epochyear_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_epochyear(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_epochyear(pf_gps_twolineelementset_t * self, mal_integer_t f_epochyear);
bool pf_gps_twolineelementset_epochday_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_epochday_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_epochday(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_epochday(pf_gps_twolineelementset_t * self, mal_integer_t f_epochday);
bool pf_gps_twolineelementset_epochsecond_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_epochsecond_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_epochsecond(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_epochsecond(pf_gps_twolineelementset_t * self, mal_double_t f_epochsecond);
bool pf_gps_twolineelementset_meanmotiond1_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_meanmotiond1_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_meanmotiond1(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_meanmotiond1(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotiond1);
bool pf_gps_twolineelementset_meanmotiond2_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_meanmotiond2_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_meanmotiond2(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_meanmotiond2(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotiond2);
bool pf_gps_twolineelementset_dragterm_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_dragterm_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_dragterm(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_dragterm(pf_gps_twolineelementset_t * self, mal_double_t f_dragterm);
bool pf_gps_twolineelementset_id_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_id_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_id(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_id(pf_gps_twolineelementset_t * self, mal_integer_t f_id);
bool pf_gps_twolineelementset_inclination_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_inclination_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_inclination(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_inclination(pf_gps_twolineelementset_t * self, mal_double_t f_inclination);
bool pf_gps_twolineelementset_raan_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_raan_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_raan(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_raan(pf_gps_twolineelementset_t * self, mal_double_t f_raan);
bool pf_gps_twolineelementset_eccentricity_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_eccentricity_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_eccentricity(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_eccentricity(pf_gps_twolineelementset_t * self, mal_double_t f_eccentricity);
bool pf_gps_twolineelementset_argumentofperigee_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_argumentofperigee_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_argumentofperigee(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_argumentofperigee(pf_gps_twolineelementset_t * self, mal_double_t f_argumentofperigee);
bool pf_gps_twolineelementset_meananomaly_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_meananomaly_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_meananomaly(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_meananomaly(pf_gps_twolineelementset_t * self, mal_double_t f_meananomaly);
bool pf_gps_twolineelementset_meanmotion_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_meanmotion_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_double_t pf_gps_twolineelementset_get_meanmotion(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_meanmotion(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotion);
bool pf_gps_twolineelementset_numrevolutions_is_present(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_numrevolutions_set_present(pf_gps_twolineelementset_t * self, bool is_present);
mal_integer_t pf_gps_twolineelementset_get_numrevolutions(pf_gps_twolineelementset_t * self);
void pf_gps_twolineelementset_set_numrevolutions(pf_gps_twolineelementset_t * self, mal_integer_t f_numrevolutions);

// default constructor
pf_gps_twolineelementset_t * pf_gps_twolineelementset_new(void);

// encoding functions related to transport malbinary
int pf_gps_twolineelementset_add_encoding_length_malbinary(pf_gps_twolineelementset_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_twolineelementset_encode_malbinary(pf_gps_twolineelementset_t * self, mal_encoder_t * encoder, void * cursor);
int pf_gps_twolineelementset_decode_malbinary(pf_gps_twolineelementset_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_gps_twolineelementset_destroy(pf_gps_twolineelementset_t ** self_p);

// test function
void pf_gps_twolineelementset_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_GPS_TWOLINEELEMENTSET_H_INCLUDED__
