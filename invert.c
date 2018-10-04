/***********************************************************************************
* @invert.c
* @This file contains the logic used to invert a particular number of bits at a
* specified memory location for a specified number of 32-bit words. The address to
* be written to and size are pulled from the input string using strtol function.
* Checks are added to see if input address + size/offset are greater than the memory
* size allocated. If so, error is displayed, or pattern is written till memory
* boundary. If less than two parameters are entered, the program displays invalid
* number of arguments error.If a different option than address or size is entered,
* an error of invalid option is displayed. In the main logic, program processes
* entered address and size to invert the bits at  address mentioned above. The
* program also measures the time taken to execute function.
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "invert.h"

void invert_fn(char *addr, char *size, char *dummy)
{
	t = clock();		//time measured before function
	valid_op=0;
	err=0;

	if(dummy == NULL)		//check for both options present
	{
		if(strncmp(addr,"addr",4)==0)
		{
			address=strtol(addr+4,NULL,16);		//address processed
			addr_diff = address -(long)mem_ptr;
			off = addr_diff/4;
			if(addr_diff%4 == 0 && addr_diff/4 < mem_size)		//check for out of bounds performed
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err=1;
			}
		}
		else if(strncmp(addr,"offset",6)==0)		//offset processed
		{
			off=atoi(addr+6);
			if(off<mem_size)
			{
				valid_op=1;
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err=1;
			}
		}
		else if(strcmp(addr,"help")==0)		//address processed
		{
			help_fn("invert",NULL,NULL);
			size="abc";
			err=1;
		}

		if(strncmp(size,"size",4)==0 && valid_op==1)		//size processed
		{
			sz=atoi(size+4);
			if(off+sz > mem_size)
			{
				printf("Range exceeds allocated memory so pattern written till allocation boundary...\n");
				sz = mem_size - off;
			}
		}
		else if(err==0)
		{
			printf("Invalid option for invert !!!\n");
		}

		if(valid_op==1)
		{
			tmp = (__uint32_t *)mem_ptr + off;
			while(sz)		//invert logic
			{
				*tmp ^= 0xffffffff;
				tmp+=1;
				sz-=1;
			}
			printf("Scpecified Address data inverted...\n");		
		}
	}
	else
	{
		printf("More then two options not allowed for this command\n");	
	}
	t = clock() - t;		//time measured after execution
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}
