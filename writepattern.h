#include "allocate.h"
#include "prng.h"
#include <time.h>

void write_pattern_fn(char* addr_wp, char* siz, char* sd);

clock_t t;
double time_taken;
long address_wp, addr_diff_wp;
__uint32_t* tmp_wp, size, seed, valid_op, err, off;
