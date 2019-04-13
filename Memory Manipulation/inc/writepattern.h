/***********************************************************************************
* @writepattern.h
* @This header file includes all the function header files and it has variable and
* function declaration used in writepattern.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "allocate.h"
#include "prng.h"
#include <time.h>

void write_pattern_fn(char* addr_wp, char* siz, char* sd);

clock_t t;
double time_taken;
long address_wp, addr_diff_wp;
__uint32_t* tmp_wp, size, seed, valid_op, err, off;
