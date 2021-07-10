#ifndef __MC_ACTION_ACTIONCREATIONREQUEST_H_INCLUDED__
#define __MC_ACTION_ACTIONCREATIONREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_action_actioncreationrequest
mal_identifier_t * mc_action_actioncreationrequest_get_name(mc_action_actioncreationrequest_t * self);
void mc_action_actioncreationrequest_set_name(mc_action_actioncreationrequest_t * self, mal_identifier_t * f_name);
mc_action_actiondefinitiondetails_t * mc_action_actioncreationrequest_get_actiondefdetails(mc_action_actioncreationrequest_t * self);
void mc_action_actioncreationrequest_set_actiondefdetails(mc_action_actioncreationrequest_t * self, mc_action_actiondefinitiondetails_t * f_actiondefdetails);

// default constructor
mc_action_actioncreationrequest_t * mc_action_actioncreationrequest_new(void);

// encoding functions related to transport malbinary
int mc_action_actioncreationrequest_add_encoding_length_malbinary(mc_action_actioncreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actioncreationrequest_encode_malbinary(mc_action_actioncreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actioncreationrequest_decode_malbinary(mc_action_actioncreationrequest_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_action_actioncreationrequest_destroy(mc_action_actioncreationrequest_t ** self_p);

// test function
void mc_action_actioncreationrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ACTION_ACTIONCREATIONREQUEST_H_INCLUDED__
