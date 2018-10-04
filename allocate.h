/***********************************************************************************
* @allocate.h
* @This header file includes help header file and it has variable and function 
* declaration used in allocate.c Allocate header is further included in all other files
* as it has global variable for memory
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include <stdlib.h>
#include "help.h"

char *mem_ptr;			//Allocated memory pointer
__uint32_t mem_status;		//Memory status is asserted on memory allocation and deasserted on free.
__uint32_t mem_size;		//Allocated memory size

void allocate_fn(char *option, char *dummy1, char *dummy2);
