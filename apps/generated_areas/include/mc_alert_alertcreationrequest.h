#ifndef __MC_ALERT_ALERTCREATIONREQUEST_H_INCLUDED__
#define __MC_ALERT_ALERTCREATIONREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_alert_alertcreationrequest
mal_identifier_t * mc_alert_alertcreationrequest_get_name(mc_alert_alertcreationrequest_t * self);
void mc_alert_alertcreationrequest_set_name(mc_alert_alertcreationrequest_t * self, mal_identifier_t * f_name);
mc_alert_alertdefinitiondetails_t * mc_alert_alertcreationrequest_get_alertdefdetails(mc_alert_alertcreationrequest_t * self);
void mc_alert_alertcreationrequest_set_alertdefdetails(mc_alert_alertcreationrequest_t * self, mc_alert_alertdefinitiondetails_t * f_alertdefdetails);

// default constructor
mc_alert_alertcreationrequest_t * mc_alert_alertcreationrequest_new(void);

// encoding functions related to transport malbinary
int mc_alert_alertcreationrequest_add_encoding_length_malbinary(mc_alert_alertcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertcreationrequest_encode_malbinary(mc_alert_alertcreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertcreationrequest_decode_malbinary(mc_alert_alertcreationrequest_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_alert_alertcreationrequest_destroy(mc_alert_alertcreationrequest_t ** self_p);

// test function
void mc_alert_alertcreationrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ALERT_ALERTCREATIONREQUEST_H_INCLUDED__
