#ifndef __PF_CAMERA_PIXELRESOLUTION_H_INCLUDED__
#define __PF_CAMERA_PIXELRESOLUTION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_camera_pixelresolution
mal_uinteger_t pf_camera_pixelresolution_get_width(pf_camera_pixelresolution_t * self);
void pf_camera_pixelresolution_set_width(pf_camera_pixelresolution_t * self, mal_uinteger_t f_width);
mal_uinteger_t pf_camera_pixelresolution_get_height(pf_camera_pixelresolution_t * self);
void pf_camera_pixelresolution_set_height(pf_camera_pixelresolution_t * self, mal_uinteger_t f_height);

// default constructor
pf_camera_pixelresolution_t * pf_camera_pixelresolution_new(void);

// encoding functions related to transport malbinary
int pf_camera_pixelresolution_add_encoding_length_malbinary(pf_camera_pixelresolution_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_pixelresolution_encode_malbinary(pf_camera_pixelresolution_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_pixelresolution_decode_malbinary(pf_camera_pixelresolution_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_camera_pixelresolution_destroy(pf_camera_pixelresolution_t ** self_p);

// test function
void pf_camera_pixelresolution_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_CAMERA_PIXELRESOLUTION_H_INCLUDED__
