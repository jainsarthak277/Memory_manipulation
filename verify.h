//#include "writepattern.h"
#include "allocate.h"
#include "prng.h"
#include <time.h>

void verify_fn(char* addr_v, char* siz_v, char* sd_v);

long address_v, addr_diff_v;
__uint32_t *tmp_v, size_v, seed_v, off, valid_op, err, check;

