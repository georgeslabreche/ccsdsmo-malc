#ifndef __MC_ARGUMENTDEFINITIONDETAILS_H_INCLUDED__
#define __MC_ARGUMENTDEFINITIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_argumentdefinitiondetails
mal_identifier_t * mc_argumentdefinitiondetails_get_argid(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_argid(mc_argumentdefinitiondetails_t * self, mal_identifier_t * f_argid);
mal_string_t * mc_argumentdefinitiondetails_get_description(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_description(mc_argumentdefinitiondetails_t * self, mal_string_t * f_description);
mal_octet_t mc_argumentdefinitiondetails_get_rawtype(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_rawtype(mc_argumentdefinitiondetails_t * self, mal_octet_t f_rawtype);
mal_string_t * mc_argumentdefinitiondetails_get_rawunit(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_rawunit(mc_argumentdefinitiondetails_t * self, mal_string_t * f_rawunit);
mc_conditionalconversion_list_t * mc_argumentdefinitiondetails_get_conditionalconversions(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_conditionalconversions(mc_argumentdefinitiondetails_t * self, mc_conditionalconversion_list_t * f_conditionalconversions);
bool mc_argumentdefinitiondetails_convertedtype_is_present(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_convertedtype_set_present(mc_argumentdefinitiondetails_t * self, bool is_present);
mal_octet_t mc_argumentdefinitiondetails_get_convertedtype(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_convertedtype(mc_argumentdefinitiondetails_t * self, mal_octet_t f_convertedtype);
mal_string_t * mc_argumentdefinitiondetails_get_convertedunit(mc_argumentdefinitiondetails_t * self);
void mc_argumentdefinitiondetails_set_convertedunit(mc_argumentdefinitiondetails_t * self, mal_string_t * f_convertedunit);

// default constructor
mc_argumentdefinitiondetails_t * mc_argumentdefinitiondetails_new(void);

// encoding functions related to transport malbinary
int mc_argumentdefinitiondetails_add_encoding_length_malbinary(mc_argumentdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinitiondetails_encode_malbinary(mc_argumentdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinitiondetails_decode_malbinary(mc_argumentdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_argumentdefinitiondetails_destroy(mc_argumentdefinitiondetails_t ** self_p);

// test function
void mc_argumentdefinitiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ARGUMENTDEFINITIONDETAILS_H_INCLUDED__
