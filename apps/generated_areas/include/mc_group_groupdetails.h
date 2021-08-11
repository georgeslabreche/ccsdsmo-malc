#ifndef __MC_GROUP_GROUPDETAILS_H_INCLUDED__
#define __MC_GROUP_GROUPDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_group_groupdetails
mal_string_t * mc_group_groupdetails_get_description(mc_group_groupdetails_t * self);
void mc_group_groupdetails_set_description(mc_group_groupdetails_t * self, mal_string_t * f_description);
com_objecttype_t * mc_group_groupdetails_get_objecttype(mc_group_groupdetails_t * self);
void mc_group_groupdetails_set_objecttype(mc_group_groupdetails_t * self, com_objecttype_t * f_objecttype);
mal_identifier_list_t * mc_group_groupdetails_get_domain(mc_group_groupdetails_t * self);
void mc_group_groupdetails_set_domain(mc_group_groupdetails_t * self, mal_identifier_list_t * f_domain);
mal_long_list_t * mc_group_groupdetails_get_instanceids(mc_group_groupdetails_t * self);
void mc_group_groupdetails_set_instanceids(mc_group_groupdetails_t * self, mal_long_list_t * f_instanceids);

// default constructor
mc_group_groupdetails_t * mc_group_groupdetails_new(void);

// encoding functions related to transport malbinary
int mc_group_groupdetails_add_encoding_length_malbinary(mc_group_groupdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_group_groupdetails_encode_malbinary(mc_group_groupdetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_group_groupdetails_decode_malbinary(mc_group_groupdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_group_groupdetails_destroy(mc_group_groupdetails_t ** self_p);

// test function
void mc_group_groupdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_GROUP_GROUPDETAILS_H_INCLUDED__
