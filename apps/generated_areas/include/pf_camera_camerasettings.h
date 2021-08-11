#ifndef __PF_CAMERA_CAMERASETTINGS_H_INCLUDED__
#define __PF_CAMERA_CAMERASETTINGS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_camera_camerasettings
pf_camera_pixelresolution_t * pf_camera_camerasettings_get_resolution(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_resolution(pf_camera_camerasettings_t * self, pf_camera_pixelresolution_t * f_resolution);
pf_camera_pictureformat_t pf_camera_camerasettings_get_format(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_format(pf_camera_camerasettings_t * self, pf_camera_pictureformat_t f_format);
mal_duration_t pf_camera_camerasettings_get_exposuretime(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_exposuretime(pf_camera_camerasettings_t * self, mal_duration_t f_exposuretime);
mal_float_t pf_camera_camerasettings_get_gainred(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_gainred(pf_camera_camerasettings_t * self, mal_float_t f_gainred);
mal_float_t pf_camera_camerasettings_get_gaingreen(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_gaingreen(pf_camera_camerasettings_t * self, mal_float_t f_gaingreen);
mal_float_t pf_camera_camerasettings_get_gainblue(pf_camera_camerasettings_t * self);
void pf_camera_camerasettings_set_gainblue(pf_camera_camerasettings_t * self, mal_float_t f_gainblue);

// default constructor
pf_camera_camerasettings_t * pf_camera_camerasettings_new(void);

// encoding functions related to transport malbinary
int pf_camera_camerasettings_add_encoding_length_malbinary(pf_camera_camerasettings_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_camerasettings_encode_malbinary(pf_camera_camerasettings_t * self, mal_encoder_t * encoder, void * cursor);
int pf_camera_camerasettings_decode_malbinary(pf_camera_camerasettings_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_camera_camerasettings_destroy(pf_camera_camerasettings_t ** self_p);

// test function
void pf_camera_camerasettings_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_CAMERA_CAMERASETTINGS_H_INCLUDED__
