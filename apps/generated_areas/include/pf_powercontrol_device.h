#ifndef __PF_POWERCONTROL_DEVICE_H_INCLUDED__
#define __PF_POWERCONTROL_DEVICE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_powercontrol_device
mal_boolean_t pf_powercontrol_device_get_enabled(pf_powercontrol_device_t * self);
void pf_powercontrol_device_set_enabled(pf_powercontrol_device_t * self, mal_boolean_t f_enabled);
bool pf_powercontrol_device_unitobjinstid_is_present(pf_powercontrol_device_t * self);
void pf_powercontrol_device_unitobjinstid_set_present(pf_powercontrol_device_t * self, bool is_present);
mal_long_t pf_powercontrol_device_get_unitobjinstid(pf_powercontrol_device_t * self);
void pf_powercontrol_device_set_unitobjinstid(pf_powercontrol_device_t * self, mal_long_t f_unitobjinstid);
mal_identifier_t * pf_powercontrol_device_get_name(pf_powercontrol_device_t * self);
void pf_powercontrol_device_set_name(pf_powercontrol_device_t * self, mal_identifier_t * f_name);
pf_powercontrol_devicetype_t pf_powercontrol_device_get_devicetype(pf_powercontrol_device_t * self);
void pf_powercontrol_device_set_devicetype(pf_powercontrol_device_t * self, pf_powercontrol_devicetype_t f_devicetype);

// default constructor
pf_powercontrol_device_t * pf_powercontrol_device_new(void);

// encoding functions related to transport malbinary
int pf_powercontrol_device_add_encoding_length_malbinary(pf_powercontrol_device_t * self, mal_encoder_t * encoder, void * cursor);
int pf_powercontrol_device_encode_malbinary(pf_powercontrol_device_t * self, mal_encoder_t * encoder, void * cursor);
int pf_powercontrol_device_decode_malbinary(pf_powercontrol_device_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_powercontrol_device_destroy(pf_powercontrol_device_t ** self_p);

// test function
void pf_powercontrol_device_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_POWERCONTROL_DEVICE_H_INCLUDED__
