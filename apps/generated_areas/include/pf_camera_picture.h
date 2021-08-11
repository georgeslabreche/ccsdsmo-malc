#ifndef __PF_CAMERA_PICTURE_H_INCLUDED__
#define __PF_CAMERA_PICTURE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_camera_picture
bool pf_camera_picture_timestamp_is_present(pf_camera_picture_t * self);
void pf_camera_picture_timestamp_set_present(pf_camera_picture_t * self, bool is_present);
mal_time_t pf_camera_picture_get_timestamp(pf_camera_picture_t * self);
void pf_camera_picture_set_timestamp(pf_camera_picture_t * self, mal_time_t f_timestamp);
pf_camera_camerasettings_t * pf_camera_picture_get_settings(pf_camera_picture_t * self);
void pf_camera_picture_set_settings(pf_camera_picture_t * self, pf_camera_camerasettings_t * f_settings);
mal_blob_t * pf_camera_picture_get_content(pf_camera_picture_t * self);
void pf_camera_picture_set_content(pf_camera_picture_t * self, mal_blob_t * f_content);

// default constructor
pf_camera_picture_t * pf_camera_picture_new(void);

// encoding functions related to transport malbinary
int pf_camera_picture_add_encoding_length_malbinary(pf_camera_picture_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_picture_encode_malbinary(pf_camera_picture_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_picture_decode_malbinary(pf_camera_picture_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_camera_picture_destroy(pf_camera_picture_t ** self_p);

// test function
void pf_camera_picture_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_CAMERA_PICTURE_H_INCLUDED__
