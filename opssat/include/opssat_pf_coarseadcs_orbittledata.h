#ifndef __OPSSAT_PF_COARSEADCS_ORBITTLEDATA_H_INCLUDED__
#define __OPSSAT_PF_COARSEADCS_ORBITTLEDATA_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite opssat_pf_coarseadcs_orbittledata
mal_string_t * opssat_pf_coarseadcs_orbittledata_get_firstline(opssat_pf_coarseadcs_orbittledata_t * self);
void opssat_pf_coarseadcs_orbittledata_set_firstline(opssat_pf_coarseadcs_orbittledata_t * self, mal_string_t * f_firstline);
mal_string_t * opssat_pf_coarseadcs_orbittledata_get_secondline(opssat_pf_coarseadcs_orbittledata_t * self);
void opssat_pf_coarseadcs_orbittledata_set_secondline(opssat_pf_coarseadcs_orbittledata_t * self, mal_string_t * f_secondline);

// default constructor
opssat_pf_coarseadcs_orbittledata_t * opssat_pf_coarseadcs_orbittledata_new(void);

// encoding functions related to transport malbinary
int opssat_pf_coarseadcs_orbittledata_add_encoding_length_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_pf_coarseadcs_orbittledata_encode_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_pf_coarseadcs_orbittledata_decode_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void opssat_pf_coarseadcs_orbittledata_destroy(opssat_pf_coarseadcs_orbittledata_t ** self_p);

// test function
void opssat_pf_coarseadcs_orbittledata_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_PF_COARSEADCS_ORBITTLEDATA_H_INCLUDED__
