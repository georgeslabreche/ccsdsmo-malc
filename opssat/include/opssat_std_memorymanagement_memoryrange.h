#ifndef __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_H_INCLUDED__
#define __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite opssat_std_memorymanagement_memoryrange
mal_uinteger_t opssat_std_memorymanagement_memoryrange_get_startaddress(opssat_std_memorymanagement_memoryrange_t * self);
void opssat_std_memorymanagement_memoryrange_set_startaddress(opssat_std_memorymanagement_memoryrange_t * self, mal_uinteger_t f_startaddress);
mal_uinteger_t opssat_std_memorymanagement_memoryrange_get_blocklength(opssat_std_memorymanagement_memoryrange_t * self);
void opssat_std_memorymanagement_memoryrange_set_blocklength(opssat_std_memorymanagement_memoryrange_t * self, mal_uinteger_t f_blocklength);

// default constructor
opssat_std_memorymanagement_memoryrange_t * opssat_std_memorymanagement_memoryrange_new(void);

// encoding functions related to transport malbinary
int opssat_std_memorymanagement_memoryrange_add_encoding_length_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_memorymanagement_memoryrange_encode_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_memorymanagement_memoryrange_decode_malbinary(opssat_std_memorymanagement_memoryrange_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void opssat_std_memorymanagement_memoryrange_destroy(opssat_std_memorymanagement_memoryrange_t ** self_p);

// test function
void opssat_std_memorymanagement_memoryrange_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_H_INCLUDED__
