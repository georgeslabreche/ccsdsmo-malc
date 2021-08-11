#ifndef __PF_POWERCONTROL_DEVICETYPE_LIST_H_INCLUDED__
#define __PF_POWERCONTROL_DEVICETYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
pf_powercontrol_devicetype_list_t * pf_powercontrol_devicetype_list_new(unsigned int element_count);

// destructor, free the list and its content
void pf_powercontrol_devicetype_list_destroy(pf_powercontrol_devicetype_list_t ** self_p);

// fields accessors for enumeration list pf_powercontrol_devicetype_list
unsigned int pf_powercontrol_devicetype_list_get_element_count(pf_powercontrol_devicetype_list_t * self);
bool * pf_powercontrol_devicetype_list_get_presence_flags(pf_powercontrol_devicetype_list_t * self);
pf_powercontrol_devicetype_t * pf_powercontrol_devicetype_list_get_content(pf_powercontrol_devicetype_list_t * self);

// encoding functions related to transport malbinary
int pf_powercontrol_devicetype_list_add_encoding_length_malbinary(pf_powercontrol_devicetype_list_t * self, mal_encoder_t * encoder, void * cursor);
int pf_powercontrol_devicetype_list_encode_malbinary(pf_powercontrol_devicetype_list_t * self, mal_encoder_t * encoder, void * cursor);
int pf_powercontrol_devicetype_list_decode_malbinary(pf_powercontrol_devicetype_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void pf_powercontrol_devicetype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_POWERCONTROL_DEVICETYPE_LIST_H_INCLUDED__
