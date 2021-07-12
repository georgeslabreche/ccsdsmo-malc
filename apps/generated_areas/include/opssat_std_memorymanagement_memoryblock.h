#ifndef __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_H_INCLUDED__
#define __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite opssat_std_memorymanagement_memoryblock
mal_uinteger_t opssat_std_memorymanagement_memoryblock_get_startaddress(opssat_std_memorymanagement_memoryblock_t * self);
void opssat_std_memorymanagement_memoryblock_set_startaddress(opssat_std_memorymanagement_memoryblock_t * self, mal_uinteger_t f_startaddress);
mal_blob_t * opssat_std_memorymanagement_memoryblock_get_data(opssat_std_memorymanagement_memoryblock_t * self);
void opssat_std_memorymanagement_memoryblock_set_data(opssat_std_memorymanagement_memoryblock_t * self, mal_blob_t * f_data);
mal_ushort_t opssat_std_memorymanagement_memoryblock_get_checksum(opssat_std_memorymanagement_memoryblock_t * self);
void opssat_std_memorymanagement_memoryblock_set_checksum(opssat_std_memorymanagement_memoryblock_t * self, mal_ushort_t f_checksum);

// default constructor
opssat_std_memorymanagement_memoryblock_t * opssat_std_memorymanagement_memoryblock_new(void);

// encoding functions related to transport malbinary
int opssat_std_memorymanagement_memoryblock_add_encoding_length_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_memorymanagement_memoryblock_encode_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_encoder_t * encoder, void * cursor);
int opssat_std_memorymanagement_memoryblock_decode_malbinary(opssat_std_memorymanagement_memoryblock_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void opssat_std_memorymanagement_memoryblock_destroy(opssat_std_memorymanagement_memoryblock_t ** self_p);

// test function
void opssat_std_memorymanagement_memoryblock_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_H_INCLUDED__
