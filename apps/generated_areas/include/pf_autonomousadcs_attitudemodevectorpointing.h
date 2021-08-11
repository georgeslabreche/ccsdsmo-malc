#ifndef __PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudemodevectorpointing
pf_vectorf3d_t * pf_autonomousadcs_attitudemodevectorpointing_get_target(pf_autonomousadcs_attitudemodevectorpointing_t * self);
void pf_autonomousadcs_attitudemodevectorpointing_set_target(pf_autonomousadcs_attitudemodevectorpointing_t * self, pf_vectorf3d_t * f_target);
mal_float_t pf_autonomousadcs_attitudemodevectorpointing_get_margin(pf_autonomousadcs_attitudemodevectorpointing_t * self);
void pf_autonomousadcs_attitudemodevectorpointing_set_margin(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_float_t f_margin);

// default constructor
pf_autonomousadcs_attitudemodevectorpointing_t * pf_autonomousadcs_attitudemodevectorpointing_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodevectorpointing_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodevectorpointing_encode_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudemodevectorpointing_decode_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudemodevectorpointing_destroy(pf_autonomousadcs_attitudemodevectorpointing_t ** self_p);

// test function
void pf_autonomousadcs_attitudemodevectorpointing_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_H_INCLUDED__
