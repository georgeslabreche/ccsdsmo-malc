#ifndef __COMMON_LOGIN_PROFILE_H_INCLUDED__
#define __COMMON_LOGIN_PROFILE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_login_profile
mal_identifier_t * common_login_profile_get_username(common_login_profile_t * self);
void common_login_profile_set_username(common_login_profile_t * self, mal_identifier_t * f_username);
bool common_login_profile_role_is_present(common_login_profile_t * self);
void common_login_profile_role_set_present(common_login_profile_t * self, bool is_present);
mal_long_t common_login_profile_get_role(common_login_profile_t * self);
void common_login_profile_set_role(common_login_profile_t * self, mal_long_t f_role);

// default constructor
common_login_profile_t * common_login_profile_new(void);

// encoding functions related to transport malbinary
int common_login_profile_add_encoding_length_malbinary(common_login_profile_t * self, mal_encoder_t * encoder, void * cursor);
int common_login_profile_encode_malbinary(common_login_profile_t * self, mal_encoder_t * encoder, void * cursor);
int common_login_profile_decode_malbinary(common_login_profile_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_login_profile_destroy(common_login_profile_t ** self_p);

// test function
void common_login_profile_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_LOGIN_PROFILE_H_INCLUDED__
