#ifndef __PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_attitudetelemetry
pf_autonomousadcs_quaternion_t * pf_autonomousadcs_attitudetelemetry_get_attitude(pf_autonomousadcs_attitudetelemetry_t * self);
void pf_autonomousadcs_attitudetelemetry_set_attitude(pf_autonomousadcs_attitudetelemetry_t * self, pf_autonomousadcs_quaternion_t * f_attitude);
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_angularvelocity(pf_autonomousadcs_attitudetelemetry_t * self);
void pf_autonomousadcs_attitudetelemetry_set_angularvelocity(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_angularvelocity);
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_sunvector(pf_autonomousadcs_attitudetelemetry_t * self);
void pf_autonomousadcs_attitudetelemetry_set_sunvector(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_sunvector);
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_magneticfield(pf_autonomousadcs_attitudetelemetry_t * self);
void pf_autonomousadcs_attitudetelemetry_set_magneticfield(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_magneticfield);
mal_boolean_t pf_autonomousadcs_attitudetelemetry_get_statetarget(pf_autonomousadcs_attitudetelemetry_t * self);
void pf_autonomousadcs_attitudetelemetry_set_statetarget(pf_autonomousadcs_attitudetelemetry_t * self, mal_boolean_t f_statetarget);

// default constructor
pf_autonomousadcs_attitudetelemetry_t * pf_autonomousadcs_attitudetelemetry_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudetelemetry_add_encoding_length_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudetelemetry_encode_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_attitudetelemetry_decode_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_attitudetelemetry_destroy(pf_autonomousadcs_attitudetelemetry_t ** self_p);

// test function
void pf_autonomousadcs_attitudetelemetry_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_H_INCLUDED__
