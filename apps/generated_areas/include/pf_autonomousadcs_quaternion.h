#ifndef __PF_AUTONOMOUSADCS_QUATERNION_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_QUATERNION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_quaternion
mal_float_t pf_autonomousadcs_quaternion_get_a(pf_autonomousadcs_quaternion_t * self);
void pf_autonomousadcs_quaternion_set_a(pf_autonomousadcs_quaternion_t * self, mal_float_t f_a);
mal_float_t pf_autonomousadcs_quaternion_get_b(pf_autonomousadcs_quaternion_t * self);
void pf_autonomousadcs_quaternion_set_b(pf_autonomousadcs_quaternion_t * self, mal_float_t f_b);
mal_float_t pf_autonomousadcs_quaternion_get_c(pf_autonomousadcs_quaternion_t * self);
void pf_autonomousadcs_quaternion_set_c(pf_autonomousadcs_quaternion_t * self, mal_float_t f_c);
mal_float_t pf_autonomousadcs_quaternion_get_d(pf_autonomousadcs_quaternion_t * self);
void pf_autonomousadcs_quaternion_set_d(pf_autonomousadcs_quaternion_t * self, mal_float_t f_d);

// default constructor
pf_autonomousadcs_quaternion_t * pf_autonomousadcs_quaternion_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_quaternion_add_encoding_length_malbinary(pf_autonomousadcs_quaternion_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_quaternion_encode_malbinary(pf_autonomousadcs_quaternion_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_quaternion_decode_malbinary(pf_autonomousadcs_quaternion_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_quaternion_destroy(pf_autonomousadcs_quaternion_t ** self_p);

// test function
void pf_autonomousadcs_quaternion_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_QUATERNION_H_INCLUDED__
