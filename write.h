/***********************************************************************************
* @write.h
* @This header file includes help and allocate header files and it has variable and 
* function declaration used in write.c 
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "allocate.h"

long address;
__uint32_t value, addr_diff, *tmp, off, valid_op, err;
void write_fn(char *addr, char *val, char *dummy);
