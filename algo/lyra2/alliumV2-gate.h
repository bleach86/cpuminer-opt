#ifndef ALLIUMV2_GATE_H__
#define ALLIUMV2_GATE_H__ 1

#include "algo-gate-api.h"
#include <stdint.h>
#include "lyra2.h"

#if defined(__AVX2__) && defined(__AES__)
  #define ALLIUMV2_4WAY
#endif

bool register_alliumV2_algo( algo_gate_t* gate );

#if defined(ALLIUMV2_4WAY)

void alliumV2_4way_hash( void *state, const void *input );
int scanhash_alliumV2_4way( int thr_id, struct work *work, uint32_t max_nonce,
                          uint64_t *hashes_done );
bool init_alliumV2_4way_ctx();

#endif

void alliumV2_hash( void *state, const void *input );
int scanhash_alliumV2( int thr_id, struct work *work, uint32_t max_nonce,
                     uint64_t *hashes_done );
bool init_alliumV2_ctx();

#endif