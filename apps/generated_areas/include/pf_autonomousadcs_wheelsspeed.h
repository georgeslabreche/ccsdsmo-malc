#ifndef __PF_AUTONOMOUSADCS_WHEELSSPEED_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_WHEELSSPEED_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_wheelsspeed
mal_float_list_t * pf_autonomousadcs_wheelsspeed_get_rotationalspeed(pf_autonomousadcs_wheelsspeed_t * self);
void pf_autonomousadcs_wheelsspeed_set_rotationalspeed(pf_autonomousadcs_wheelsspeed_t * self, mal_float_list_t * f_rotationalspeed);

// default constructor
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_wheelsspeed_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_wheelsspeed_add_encoding_length_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_wheelsspeed_encode_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_wheelsspeed_decode_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_wheelsspeed_destroy(pf_autonomousadcs_wheelsspeed_t ** self_p);

// test function
void pf_autonomousadcs_wheelsspeed_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_WHEELSSPEED_H_INCLUDED__
