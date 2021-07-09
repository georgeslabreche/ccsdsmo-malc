#ifndef __MC_ALERT_ALERTEVENTDETAILS_H_INCLUDED__
#define __MC_ALERT_ALERTEVENTDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_alert_alerteventdetails
mc_attributevalue_list_t * mc_alert_alerteventdetails_get_argumentvalues(mc_alert_alerteventdetails_t * self);
void mc_alert_alerteventdetails_set_argumentvalues(mc_alert_alerteventdetails_t * self, mc_attributevalue_list_t * f_argumentvalues);
mal_identifier_list_t * mc_alert_alerteventdetails_get_argumentids(mc_alert_alerteventdetails_t * self);
void mc_alert_alerteventdetails_set_argumentids(mc_alert_alerteventdetails_t * self, mal_identifier_list_t * f_argumentids);

// default constructor
mc_alert_alerteventdetails_t * mc_alert_alerteventdetails_new(void);

// encoding functions related to transport malbinary
int mc_alert_alerteventdetails_add_encoding_length_malbinary(mc_alert_alerteventdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alerteventdetails_encode_malbinary(mc_alert_alerteventdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alerteventdetails_decode_malbinary(mc_alert_alerteventdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_alert_alerteventdetails_destroy(mc_alert_alerteventdetails_t ** self_p);

// test function
void mc_alert_alerteventdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ALERT_ALERTEVENTDETAILS_H_INCLUDED__
