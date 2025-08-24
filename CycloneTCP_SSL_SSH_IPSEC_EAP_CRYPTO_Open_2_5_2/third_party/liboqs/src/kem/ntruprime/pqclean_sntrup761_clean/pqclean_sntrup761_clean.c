#include "crypto_sort_int32.c"
#undef uint32_divmod_uint14
#define uint32_divmod_uint14 uint32_divmod_uint14_1
#undef uint32_mod_uint14
#define uint32_mod_uint14 uint32_mod_uint14_1
#include "crypto_decode_761x1531.c"
#undef uint32_divmod_uint14
#define uint32_divmod_uint14 uint32_divmod_uint14_2
#undef uint32_mod_uint14
#define uint32_mod_uint14 uint32_mod_uint14_2
#include "crypto_decode_761x4591.c"
#undef int16_nonzero_mask
#define int16_nonzero_mask int16_nonzero_mask_1
#undef int16_negative_mask
#define int16_negative_mask int16_negative_mask_1
#undef F3_freeze
#define F3_freeze F3_freeze_1
#include "crypto_core_inv3sntrup761.c"
#undef int16_nonzero_mask
#define int16_nonzero_mask int16_nonzero_mask_2
#undef int16_negative_mask
#define int16_negative_mask int16_negative_mask_2
#include "crypto_core_invsntrup761.c"
#undef F3_freeze
#define F3_freeze F3_freeze_2
#include "crypto_core_mult3sntrup761.c"
#include "crypto_core_multsntrup761.c"
#include "crypto_core_scale3sntrup761.c"
#include "crypto_core_weightsntrup761.c"
#undef int16_nonzero_mask
#define int16_nonzero_mask int16_nonzero_mask_3
#include "crypto_core_wforcesntrup761.c"
#include "crypto_decode_761x3.c"
#include "crypto_decode_761xint16.c"
#include "crypto_decode_761xint32.c"
#include "crypto_encode_761x1531.c"
#include "crypto_encode_761x1531round.c"
#include "crypto_encode_761x3.c"
#include "crypto_encode_761x4591.c"
#undef F3_freeze
#define F3_freeze F3_freeze_3
#include "crypto_encode_761xfreeze3.c"
#include "crypto_encode_761xint16.c"
#include "crypto_encode_int16.c"
#include "crypto_sort_uint32.c"
#include "crypto_verify_1039.c"
#include "kem.c"
