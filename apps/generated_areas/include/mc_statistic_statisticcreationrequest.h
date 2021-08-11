#ifndef __MC_STATISTIC_STATISTICCREATIONREQUEST_H_INCLUDED__
#define __MC_STATISTIC_STATISTICCREATIONREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_statistic_statisticcreationrequest
mal_long_t mc_statistic_statisticcreationrequest_get_statfuncinstid(mc_statistic_statisticcreationrequest_t * self);
void mc_statistic_statisticcreationrequest_set_statfuncinstid(mc_statistic_statisticcreationrequest_t * self, mal_long_t f_statfuncinstid);
com_objectkey_t * mc_statistic_statisticcreationrequest_get_parameterid(mc_statistic_statisticcreationrequest_t * self);
void mc_statistic_statisticcreationrequest_set_parameterid(mc_statistic_statisticcreationrequest_t * self, com_objectkey_t * f_parameterid);
mc_statistic_statisticlinkdetails_t * mc_statistic_statisticcreationrequest_get_linkdetails(mc_statistic_statisticcreationrequest_t * self);
void mc_statistic_statisticcreationrequest_set_linkdetails(mc_statistic_statisticcreationrequest_t * self, mc_statistic_statisticlinkdetails_t * f_linkdetails);

// default constructor
mc_statistic_statisticcreationrequest_t * mc_statistic_statisticcreationrequest_new(void);

// encoding functions related to transport malbinary
int mc_statistic_statisticcreationrequest_add_encoding_length_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticcreationrequest_encode_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_statistic_statisticcreationrequest_decode_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_statistic_statisticcreationrequest_destroy(mc_statistic_statisticcreationrequest_t ** self_p);

// test function
void mc_statistic_statisticcreationrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_STATISTIC_STATISTICCREATIONREQUEST_H_INCLUDED__
