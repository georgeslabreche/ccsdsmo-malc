#ifndef __MC_ARGUMENTDEFINITION_H_INCLUDED__
#define __MC_ARGUMENTDEFINITION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_argumentdefinition
mal_octet_t mc_argumentdefinition_get_rawtype(mc_argumentdefinition_t * self);
void mc_argumentdefinition_set_rawtype(mc_argumentdefinition_t * self, mal_octet_t f_rawtype);
mal_string_t * mc_argumentdefinition_get_rawunit(mc_argumentdefinition_t * self);
void mc_argumentdefinition_set_rawunit(mc_argumentdefinition_t * self, mal_string_t * f_rawunit);
mc_conditionalreference_list_t * mc_argumentdefinition_get_conversioncondition(mc_argumentdefinition_t * self);
void mc_argumentdefinition_set_conversioncondition(mc_argumentdefinition_t * self, mc_conditionalreference_list_t * f_conversioncondition);
bool mc_argumentdefinition_convertedtype_is_present(mc_argumentdefinition_t * self);
void mc_argumentdefinition_convertedtype_set_present(mc_argumentdefinition_t * self, bool is_present);
mal_octet_t mc_argumentdefinition_get_convertedtype(mc_argumentdefinition_t * self);
void mc_argumentdefinition_set_convertedtype(mc_argumentdefinition_t * self, mal_octet_t f_convertedtype);
mal_string_t * mc_argumentdefinition_get_convertedunit(mc_argumentdefinition_t * self);
void mc_argumentdefinition_set_convertedunit(mc_argumentdefinition_t * self, mal_string_t * f_convertedunit);

// default constructor
mc_argumentdefinition_t * mc_argumentdefinition_new(void);

// encoding functions related to transport malbinary
int mc_argumentdefinition_add_encoding_length_malbinary(mc_argumentdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinition_encode_malbinary(mc_argumentdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinition_decode_malbinary(mc_argumentdefinition_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_argumentdefinition_destroy(mc_argumentdefinition_t ** self_p);

// test function
void mc_argumentdefinition_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ARGUMENTDEFINITION_H_INCLUDED__
