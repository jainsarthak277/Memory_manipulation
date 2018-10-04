/***********************************************************************************
* @invert.h
* @This headerr file includes all the function header files and it had variable and
* function declaration used in invert.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "allocate.h"
#include <time.h>

clock_t t;
double time_taken;
long address;
__uint32_t valid_op, err, off, *tmp, sz, addr_diff;

void invert_fn(char *addr, char *size, char *dummy);
