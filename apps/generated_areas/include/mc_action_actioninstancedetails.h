#ifndef __MC_ACTION_ACTIONINSTANCEDETAILS_H_INCLUDED__
#define __MC_ACTION_ACTIONINSTANCEDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_action_actioninstancedetails
mal_long_t mc_action_actioninstancedetails_get_definstid(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_definstid(mc_action_actioninstancedetails_t * self, mal_long_t f_definstid);
mal_boolean_t mc_action_actioninstancedetails_get_stagestartedrequired(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_stagestartedrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stagestartedrequired);
mal_boolean_t mc_action_actioninstancedetails_get_stageprogressrequired(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_stageprogressrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stageprogressrequired);
mal_boolean_t mc_action_actioninstancedetails_get_stagecompletedrequired(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_stagecompletedrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stagecompletedrequired);
mc_attributevalue_list_t * mc_action_actioninstancedetails_get_argumentvalues(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_argumentvalues(mc_action_actioninstancedetails_t * self, mc_attributevalue_list_t * f_argumentvalues);
mal_identifier_list_t * mc_action_actioninstancedetails_get_argumentids(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_argumentids(mc_action_actioninstancedetails_t * self, mal_identifier_list_t * f_argumentids);
mal_boolean_list_t * mc_action_actioninstancedetails_get_israwvalue(mc_action_actioninstancedetails_t * self);
void mc_action_actioninstancedetails_set_israwvalue(mc_action_actioninstancedetails_t * self, mal_boolean_list_t * f_israwvalue);

// default constructor
mc_action_actioninstancedetails_t * mc_action_actioninstancedetails_new(void);

// encoding functions related to transport malbinary
int mc_action_actioninstancedetails_add_encoding_length_malbinary(mc_action_actioninstancedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actioninstancedetails_encode_malbinary(mc_action_actioninstancedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actioninstancedetails_decode_malbinary(mc_action_actioninstancedetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_action_actioninstancedetails_destroy(mc_action_actioninstancedetails_t ** self_p);

// test function
void mc_action_actioninstancedetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ACTION_ACTIONINSTANCEDETAILS_H_INCLUDED__
