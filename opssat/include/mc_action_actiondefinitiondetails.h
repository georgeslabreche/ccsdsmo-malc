#ifndef __MC_ACTION_ACTIONDEFINITIONDETAILS_H_INCLUDED__
#define __MC_ACTION_ACTIONDEFINITIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_action_actiondefinitiondetails
mal_identifier_t * mc_action_actiondefinitiondetails_get_name(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_name(mc_action_actiondefinitiondetails_t * self, mal_identifier_t * f_name);
mal_string_t * mc_action_actiondefinitiondetails_get_description(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_description(mc_action_actiondefinitiondetails_t * self, mal_string_t * f_description);
mc_severity_t mc_action_actiondefinitiondetails_get_category(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_category(mc_action_actiondefinitiondetails_t * self, mc_severity_t f_category);
mal_ushort_t mc_action_actiondefinitiondetails_get_progressstepcount(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_progressstepcount(mc_action_actiondefinitiondetails_t * self, mal_ushort_t f_progressstepcount);
mc_argumentdefinition_list_t * mc_action_actiondefinitiondetails_get_arguments(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_arguments(mc_action_actiondefinitiondetails_t * self, mc_argumentdefinition_list_t * f_arguments);
mal_identifier_list_t * mc_action_actiondefinitiondetails_get_argumentids(mc_action_actiondefinitiondetails_t * self);
void mc_action_actiondefinitiondetails_set_argumentids(mc_action_actiondefinitiondetails_t * self, mal_identifier_list_t * f_argumentids);

// default constructor
mc_action_actiondefinitiondetails_t * mc_action_actiondefinitiondetails_new(void);

// encoding functions related to transport malbinary
int mc_action_actiondefinitiondetails_add_encoding_length_malbinary(mc_action_actiondefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actiondefinitiondetails_encode_malbinary(mc_action_actiondefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actiondefinitiondetails_decode_malbinary(mc_action_actiondefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_action_actiondefinitiondetails_destroy(mc_action_actiondefinitiondetails_t ** self_p);

// test function
void mc_action_actiondefinitiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ACTION_ACTIONDEFINITIONDETAILS_H_INCLUDED__
