/***********************************************************************************
* @verify.h
* @This header file includes all the function header files and it has variable and
* function declaration used in verify.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "allocate.h"
#include "prng.h"
#include <time.h>

void verify_fn(char* addr_v, char* siz_v, char* sd_v);

clock_t t;
double time_taken;
long address_v, addr_diff_v;
__uint32_t *tmp_v, size_v, seed_v, off, valid_op, err, check;

