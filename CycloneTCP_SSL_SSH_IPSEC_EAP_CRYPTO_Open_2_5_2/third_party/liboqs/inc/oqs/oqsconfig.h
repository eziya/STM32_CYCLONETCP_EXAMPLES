#ifndef OQS_CONFIG_H
#define OQS_CONFIG_H

#include <stdint.h>
#include <string.h>
//#include "core/crypto.h"
//#include "hash/sha512.h"

/*#define sha512(h, in, inlen) \
{ \
   Sha512Context sha512Context; \
   sha512Init(&sha512Context); \
   sha512Update(&sha512Context, in, inlen); \
   sha512Final(&sha512Context, h); \
}*/

int sha512Compute(const void *data, size_t length, uint8_t *digest);
#define sha512(h, in, inlen) sha512Compute(in, inlen, h);

//#define OQS_API
#define OQS_ENABLE_KEM_NTRUPRIME
#define OQS_ENABLE_KEM_ntruprime_sntrup761
#define OQS_ENABLE_KEM_KYBER
#define OQS_ENABLE_KEM_kyber_512
#define OQS_ENABLE_KEM_kyber_768
#define OQS_ENABLE_KEM_kyber_1024
#define OQS_ENABLE_KEM_ML_KEM
#define OQS_ENABLE_KEM_ml_kem_512
#define OQS_ENABLE_KEM_ml_kem_768
#define OQS_ENABLE_KEM_ml_kem_1024

#endif
