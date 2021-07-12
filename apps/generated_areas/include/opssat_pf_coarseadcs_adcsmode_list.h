#ifndef __OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_H_INCLUDED__
#define __OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
opssat_pf_coarseadcs_adcsmode_list_t * opssat_pf_coarseadcs_adcsmode_list_new(unsigned int element_count);

// destructor, free the list and its content
void opssat_pf_coarseadcs_adcsmode_list_destroy(opssat_pf_coarseadcs_adcsmode_list_t ** self_p);

// fields accessors for enumeration list opssat_pf_coarseadcs_adcsmode_list
unsigned int opssat_pf_coarseadcs_adcsmode_list_get_element_count(opssat_pf_coarseadcs_adcsmode_list_t * self);
bool * opssat_pf_coarseadcs_adcsmode_list_get_presence_flags(opssat_pf_coarseadcs_adcsmode_list_t * self);
opssat_pf_coarseadcs_adcsmode_t * opssat_pf_coarseadcs_adcsmode_list_get_content(opssat_pf_coarseadcs_adcsmode_list_t * self);

// encoding functions related to transport malbinary
int opssat_pf_coarseadcs_adcsmode_list_add_encoding_length_malbinary(opssat_pf_coarseadcs_adcsmode_list_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_pf_coarseadcs_adcsmode_list_encode_malbinary(opssat_pf_coarseadcs_adcsmode_list_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_pf_coarseadcs_adcsmode_list_decode_malbinary(opssat_pf_coarseadcs_adcsmode_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void opssat_pf_coarseadcs_adcsmode_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_H_INCLUDED__
