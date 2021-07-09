#ifndef __PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudemodesinglespinning
pf_vectorf3d_t * pf_autonomousadcs_attitudemodesinglespinning_get_bodyaxis(pf_autonomousadcs_attitudemodesinglespinning_t * self);
void pf_autonomousadcs_attitudemodesinglespinning_set_bodyaxis(pf_autonomousadcs_attitudemodesinglespinning_t * self, pf_vectorf3d_t * f_bodyaxis);
mal_float_t pf_autonomousadcs_attitudemodesinglespinning_get_angularvelocity(pf_autonomousadcs_attitudemodesinglespinning_t * self);
void pf_autonomousadcs_attitudemodesinglespinning_set_angularvelocity(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_float_t f_angularvelocity);

// default constructor
pf_autonomousadcs_attitudemodesinglespinning_t * pf_autonomousadcs_attitudemodesinglespinning_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodesinglespinning_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodesinglespinning_encode_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodesinglespinning_decode_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudemodesinglespinning_destroy(pf_autonomousadcs_attitudemodesinglespinning_t ** self_p);

// test function
void pf_autonomousadcs_attitudemodesinglespinning_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_H_INCLUDED__
