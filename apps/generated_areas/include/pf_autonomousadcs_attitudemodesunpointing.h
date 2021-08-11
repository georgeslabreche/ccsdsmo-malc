#ifndef __PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudemodesunpointing

// default constructor
pf_autonomousadcs_attitudemodesunpointing_t * pf_autonomousadcs_attitudemodesunpointing_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodesunpointing_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodesunpointing_encode_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodesunpointing_decode_malbinary(pf_autonomousadcs_attitudemodesunpointing_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudemodesunpointing_destroy(pf_autonomousadcs_attitudemodesunpointing_t ** self_p);

// test function
void pf_autonomousadcs_attitudemodesunpointing_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_H_INCLUDED__
