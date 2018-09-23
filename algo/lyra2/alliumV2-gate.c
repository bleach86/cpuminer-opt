#include "alliumV2-gate.h"

int64_t get_max64_0xFFFLLL() { return 0xFFFLLL; }

bool register_alliumV2_algo( algo_gate_t* gate )
{
#if defined (ALLIUMV2_4WAY)
  gate->miner_thread_init = (void*)&init_alliumV2_4way_ctx;
  gate->scanhash  = (void*)&scanhash_alliumV2_4way;
  gate->hash      = (void*)&alliumV2_4way_hash;
#else
  gate->miner_thread_init = (void*)&init_alliumV2_ctx;
  gate->scanhash  = (void*)&scanhash_alliumV2;
  gate->hash      = (void*)&alliumV2_hash;
#endif
  gate->optimizations = SSE2_OPT | AES_OPT | SSE42_OPT | AVX2_OPT;
  gate->set_target        = (void*)&alt_set_target;
  gate->get_max64         = (void*)&get_max64_0xFFFLLL;
  return true;
};
