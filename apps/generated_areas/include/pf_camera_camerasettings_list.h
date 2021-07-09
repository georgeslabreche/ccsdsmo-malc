#ifndef __PF_CAMERA_CAMERASETTINGS_LIST_H_INCLUDED__
#define __PF_CAMERA_CAMERASETTINGS_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
pf_camera_camerasettings_list_t * pf_camera_camerasettings_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void pf_camera_camerasettings_list_destroy(pf_camera_camerasettings_list_t ** self_p);

// fields accessors for composite list pf_camera_camerasettings_list
unsigned int pf_camera_camerasettings_list_get_element_count(pf_camera_camerasettings_list_t * self);
pf_camera_camerasettings_t ** pf_camera_camerasettings_list_get_content(pf_camera_camerasettings_list_t * self);

// encoding functions related to transport malbinary
int pf_camera_camerasettings_list_add_encoding_length_malbinary(pf_camera_camerasettings_list_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_camerasettings_list_encode_malbinary(pf_camera_camerasettings_list_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_camerasettings_list_decode_malbinary(pf_camera_camerasettings_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void pf_camera_camerasettings_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_CAMERA_CAMERASETTINGS_LIST_H_INCLUDED__
