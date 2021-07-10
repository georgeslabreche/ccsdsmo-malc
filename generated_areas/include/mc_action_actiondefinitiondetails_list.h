#ifndef __MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_H_INCLUDED__
#define __MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mc_action_actiondefinitiondetails_list_t * mc_action_actiondefinitiondetails_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mc_action_actiondefinitiondetails_list_destroy(mc_action_actiondefinitiondetails_list_t ** self_p);

// fields accessors for composite list mc_action_actiondefinitiondetails_list
unsigned int mc_action_actiondefinitiondetails_list_get_element_count(mc_action_actiondefinitiondetails_list_t * self);
mc_action_actiondefinitiondetails_t ** mc_action_actiondefinitiondetails_list_get_content(mc_action_actiondefinitiondetails_list_t * self);

// encoding functions related to transport malbinary
int mc_action_actiondefinitiondetails_list_add_encoding_length_malbinary(mc_action_actiondefinitiondetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actiondefinitiondetails_list_encode_malbinary(mc_action_actiondefinitiondetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_action_actiondefinitiondetails_list_decode_malbinary(mc_action_actiondefinitiondetails_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mc_action_actiondefinitiondetails_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_H_INCLUDED__
