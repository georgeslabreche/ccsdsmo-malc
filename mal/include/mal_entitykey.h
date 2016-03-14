#include "mal.h"

mal_entitykey_t *mal_entitykey_new(void);

void mal_entitykey_destroy(mal_entitykey_t **self_p);

int mal_entitykey_add_encoding_length_malbinary(mal_entitykey_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length);

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entitykey_encode_malbinary(mal_entitykey_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset);

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entitykey_decode_malbinary(mal_entitykey_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset);

mal_identifier_t *mal_entitykey_get_firstsubkey(mal_entitykey_t *self);

void mal_entitykey_set_firstsubkey(mal_entitykey_t *self,
    mal_identifier_t *firstsubkey);

mal_long_t mal_entitykey_secondsubkey_is_present(mal_entitykey_t *self);

void mal_entitykey_secondsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present);

mal_long_t mal_entitykey_get_secondsubkey(mal_entitykey_t *self);

void mal_entitykey_set_secondsubkey(mal_entitykey_t *self,
    mal_long_t secondsubkey);

mal_long_t mal_entitykey_thirdsubkey_is_present(mal_entitykey_t *self);

void mal_entitykey_thirdsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present);

mal_long_t mal_entitykey_get_thirdsubkey(mal_entitykey_t *self);

void mal_entitykey_set_thirdsubkey(mal_entitykey_t *self,
    mal_long_t thirdsubkey);

mal_long_t mal_entitykey_fourthsubkey_is_present(mal_entitykey_t *self);

void mal_entitykey_fourthsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present);

mal_long_t mal_entitykey_get_fourthsubkey(mal_entitykey_t *self);

void mal_entitykey_set_fourthsubkey(mal_entitykey_t *self,
    mal_long_t fourthsubkey);

void mal_entitykey_test(bool verbose);

