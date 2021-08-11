#ifndef __MC_OBJECTINSTANCEPAIR_H_INCLUDED__
#define __MC_OBJECTINSTANCEPAIR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_objectinstancepair
mal_long_t mc_objectinstancepair_get_objidentityinstanceid(mc_objectinstancepair_t * self);
void mc_objectinstancepair_set_objidentityinstanceid(mc_objectinstancepair_t * self, mal_long_t f_objidentityinstanceid);
mal_long_t mc_objectinstancepair_get_objdefinstanceid(mc_objectinstancepair_t * self);
void mc_objectinstancepair_set_objdefinstanceid(mc_objectinstancepair_t * self, mal_long_t f_objdefinstanceid);

// default constructor
mc_objectinstancepair_t * mc_objectinstancepair_new(void);

// encoding functions related to transport malbinary
int mc_objectinstancepair_add_encoding_length_malbinary(mc_objectinstancepair_t * self, mal_encoder_t * encoder, void * cursor);
int mc_objectinstancepair_encode_malbinary(mc_objectinstancepair_t * self, mal_encoder_t * encoder, void * cursor);
int mc_objectinstancepair_decode_malbinary(mc_objectinstancepair_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_objectinstancepair_destroy(mc_objectinstancepair_t ** self_p);

// test function
void mc_objectinstancepair_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_OBJECTINSTANCEPAIR_H_INCLUDED__
