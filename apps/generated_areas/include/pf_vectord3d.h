#ifndef __PF_VECTORD3D_H_INCLUDED__
#define __PF_VECTORD3D_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_vectord3d
bool pf_vectord3d_x_is_present(pf_vectord3d_t * self);
void pf_vectord3d_x_set_present(pf_vectord3d_t * self, bool is_present);
mal_double_t pf_vectord3d_get_x(pf_vectord3d_t * self);
void pf_vectord3d_set_x(pf_vectord3d_t * self, mal_double_t f_x);
bool pf_vectord3d_y_is_present(pf_vectord3d_t * self);
void pf_vectord3d_y_set_present(pf_vectord3d_t * self, bool is_present);
mal_double_t pf_vectord3d_get_y(pf_vectord3d_t * self);
void pf_vectord3d_set_y(pf_vectord3d_t * self, mal_double_t f_y);
bool pf_vectord3d_z_is_present(pf_vectord3d_t * self);
void pf_vectord3d_z_set_present(pf_vectord3d_t * self, bool is_present);
mal_double_t pf_vectord3d_get_z(pf_vectord3d_t * self);
void pf_vectord3d_set_z(pf_vectord3d_t * self, mal_double_t f_z);

// default constructor
pf_vectord3d_t * pf_vectord3d_new(void);

// encoding functions related to transport malbinary
int pf_vectord3d_add_encoding_length_malbinary(pf_vectord3d_t * self, mal_encoder_t * encoder, void * cursor);
int pf_vectord3d_encode_malbinary(pf_vectord3d_t * self, mal_encoder_t * encoder, void * cursor);
int pf_vectord3d_decode_malbinary(pf_vectord3d_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_vectord3d_destroy(pf_vectord3d_t ** self_p);

// test function
void pf_vectord3d_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_VECTORD3D_H_INCLUDED__
