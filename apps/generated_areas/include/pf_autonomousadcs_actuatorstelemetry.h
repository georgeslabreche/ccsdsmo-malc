#ifndef __PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_H_INCLUDED__
#define __PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_autonomousadcs_actuatorstelemetry
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_actuatorstelemetry_get_targetwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self);
void pf_autonomousadcs_actuatorstelemetry_set_targetwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_wheelsspeed_t * f_targetwheelspeed);
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_actuatorstelemetry_get_currentwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self);
void pf_autonomousadcs_actuatorstelemetry_set_currentwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_wheelsspeed_t * f_currentwheelspeed);
pf_vectorf3d_t * pf_autonomousadcs_actuatorstelemetry_get_mtqdipolemoment(pf_autonomousadcs_actuatorstelemetry_t * self);
void pf_autonomousadcs_actuatorstelemetry_set_mtqdipolemoment(pf_autonomousadcs_actuatorstelemetry_t * self, pf_vectorf3d_t * f_mtqdipolemoment);
pf_autonomousadcs_magnetorquersstate_t pf_autonomousadcs_actuatorstelemetry_get_mtqstate(pf_autonomousadcs_actuatorstelemetry_t * self);
void pf_autonomousadcs_actuatorstelemetry_set_mtqstate(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_magnetorquersstate_t f_mtqstate);

// default constructor
pf_autonomousadcs_actuatorstelemetry_t * pf_autonomousadcs_actuatorstelemetry_new(void);

// encoding functions related to transport malbinary
int pf_autonomousadcs_actuatorstelemetry_add_encoding_length_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_actuatorstelemetry_encode_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_encoder_t * encoder, void * cursor);
int pf_autonomousadcs_actuatorstelemetry_decode_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_autonomousadcs_actuatorstelemetry_destroy(pf_autonomousadcs_actuatorstelemetry_t ** self_p);

// test function
void pf_autonomousadcs_actuatorstelemetry_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_H_INCLUDED__
