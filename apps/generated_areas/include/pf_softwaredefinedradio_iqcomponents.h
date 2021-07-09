#ifndef __PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_H_INCLUDED__
#define __PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite pf_softwaredefinedradio_iqcomponents
mal_float_list_t * pf_softwaredefinedradio_iqcomponents_get_inphase(pf_softwaredefinedradio_iqcomponents_t * self);
void pf_softwaredefinedradio_iqcomponents_set_inphase(pf_softwaredefinedradio_iqcomponents_t * self, mal_float_list_t * f_inphase);
mal_float_list_t * pf_softwaredefinedradio_iqcomponents_get_quadrature(pf_softwaredefinedradio_iqcomponents_t * self);
void pf_softwaredefinedradio_iqcomponents_set_quadrature(pf_softwaredefinedradio_iqcomponents_t * self, mal_float_list_t * f_quadrature);

// default constructor
pf_softwaredefinedradio_iqcomponents_t * pf_softwaredefinedradio_iqcomponents_new(void);

// encoding functions related to transport malbinary
int pf_softwaredefinedradio_iqcomponents_add_encoding_length_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_encoder_t * encoder, void * cursor);
int pf_softwaredefinedradio_iqcomponents_encode_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_encoder_t * encoder, void * cursor);
int pf_softwaredefinedradio_iqcomponents_decode_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void pf_softwaredefinedradio_iqcomponents_destroy(pf_softwaredefinedradio_iqcomponents_t ** self_p);

// test function
void pf_softwaredefinedradio_iqcomponents_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_H_INCLUDED__
