#ifndef __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudemodetargettracking
mal_float_t pf_autonomousadcs_attitudemodetargettracking_get_latitude(pf_autonomousadcs_attitudemodetargettracking_t * self);
void pf_autonomousadcs_attitudemodetargettracking_set_latitude(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_float_t f_latitude);
mal_float_t pf_autonomousadcs_attitudemodetargettracking_get_longitude(pf_autonomousadcs_attitudemodetargettracking_t * self);
void pf_autonomousadcs_attitudemodetargettracking_set_longitude(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_float_t f_longitude);

// default constructor
pf_autonomousadcs_attitudemodetargettracking_t * pf_autonomousadcs_attitudemodetargettracking_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodetargettracking_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodetargettracking_encode_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodetargettracking_decode_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudemodetargettracking_destroy(pf_autonomousadcs_attitudemodetargettracking_t ** self_p);

// test function
void pf_autonomousadcs_attitudemodetargettracking_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_H_INCLUDED__
