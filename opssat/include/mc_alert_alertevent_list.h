#ifndef __MC_ALERT_ALERTEVENT_LIST_H_INCLUDED__
#define __MC_ALERT_ALERTEVENT_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mc_alert_alertevent_list_t * mc_alert_alertevent_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mc_alert_alertevent_list_destroy(mc_alert_alertevent_list_t ** self_p);

// fields accessors for composite list mc_alert_alertevent_list
unsigned int mc_alert_alertevent_list_get_element_count(mc_alert_alertevent_list_t * self);
mc_alert_alertevent_t ** mc_alert_alertevent_list_get_content(mc_alert_alertevent_list_t * self);

// encoding functions related to transport malbinary
int mc_alert_alertevent_list_add_encoding_length_malbinary(mc_alert_alertevent_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertevent_list_encode_malbinary(mc_alert_alertevent_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_alert_alertevent_list_decode_malbinary(mc_alert_alertevent_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mc_alert_alertevent_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ALERT_ALERTEVENT_LIST_H_INCLUDED__
