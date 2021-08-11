#ifndef __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudemodetargettrackinglinear
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_latitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_latitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_latitudestart);
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_longitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_longitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_longitudestart);
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_latitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_latitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_latitudeend);
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_longitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_longitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_longitudeend);
mal_long_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_startepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_startepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_long_t f_startepoch);
mal_long_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_endepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self);
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_endepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_long_t f_endepoch);

// default constructor
pf_autonomousadcs_attitudemodetargettrackinglinear_t * pf_autonomousadcs_attitudemodetargettrackinglinear_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodetargettrackinglinear_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodetargettrackinglinear_encode_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodetargettrackinglinear_decode_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudemodetargettrackinglinear_destroy(pf_autonomousadcs_attitudemodetargettrackinglinear_t ** self_p);

// test function
void pf_autonomousadcs_attitudemodetargettrackinglinear_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_H_INCLUDED__
