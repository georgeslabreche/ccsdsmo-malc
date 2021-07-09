#ifndef __MC_ALERT_ALERTDEFINITIONDETAILS_H_INCLUDED__
#define __MC_ALERT_ALERTDEFINITIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_alert_alertdefinitiondetails
mal_string_t * mc_alert_alertdefinitiondetails_get_description(mc_alert_alertdefinitiondetails_t * self);
void mc_alert_alertdefinitiondetails_set_description(mc_alert_alertdefinitiondetails_t * self, mal_string_t * f_description);
mc_severity_t mc_alert_alertdefinitiondetails_get_severity(mc_alert_alertdefinitiondetails_t * self);
void mc_alert_alertdefinitiondetails_set_severity(mc_alert_alertdefinitiondetails_t * self, mc_severity_t f_severity);
mal_boolean_t mc_alert_alertdefinitiondetails_get_generationenabled(mc_alert_alertdefinitiondetails_t * self);
void mc_alert_alertdefinitiondetails_set_generationenabled(mc_alert_alertdefinitiondetails_t * self, mal_boolean_t f_generationenabled);
mc_argumentdefinitiondetails_list_t * mc_alert_alertdefinitiondetails_get_arguments(mc_alert_alertdefinitiondetails_t * self);
void mc_alert_alertdefinitiondetails_set_arguments(mc_alert_alertdefinitiondetails_t * self, mc_argumentdefinitiondetails_list_t * f_arguments);

// default constructor
mc_alert_alertdefinitiondetails_t * mc_alert_alertdefinitiondetails_new(void);

// encoding functions related to transport malbinary
int mc_alert_alertdefinitiondetails_add_encoding_length_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertdefinitiondetails_encode_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertdefinitiondetails_decode_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_alert_alertdefinitiondetails_destroy(mc_alert_alertdefinitiondetails_t ** self_p);

// test function
void mc_alert_alertdefinitiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ALERT_ALERTDEFINITIONDETAILS_H_INCLUDED__
