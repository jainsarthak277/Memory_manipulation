/***********************************************************************************
* @writepattern.c
* @This file contains the logic for writing pattern to a specified address. The 
* address to be written to, size and seed are pulled from the input string using
* strtol function. Checks are added to see if input address + size/offset are
* greater than the memory size allocated. If so, error is displayed, or pattern is
* written till memory boundary. If less than three parameters are entered, the
* program displays invalid number of arguments error.If a different option than
* address, size of seed is entered, an error of invalid option is displayed. In the
* main logic, program processes entered address, size and seed to write to the
* address mentioned above. The program also measures the time taken to execute
* function.
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../inc/writepattern.h"

void write_pattern_fn(char* addr_wp, char* siz, char* sd)
{
	tmp_wp = (__uint32_t *)malloc(4);
	valid_op=0;
	err=0;
	t = clock();		//time measured before function

	if (addr_wp != NULL && siz != NULL && sd != NULL)		//check for all three options present
	{
		if(strncmp(addr_wp,"addr",4)==0)
		{
			address_wp=strtol(addr_wp+4,NULL,16);		//address processed
			addr_diff_wp = address_wp-(long)mem_ptr;
			off = addr_diff_wp/4;
			if(addr_diff_wp%4 == 0 && addr_diff_wp/4 < mem_size)		//addres check performed for out of bounds
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err=1;
			}
		}
		else if(strncmp(addr_wp,"offset",6)==0)		//option for offset
		{
			off=atoi(addr_wp+6);
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
		if(strncmp(siz,"size",4)==0 && valid_op==1)		//size processed
		{
			size=atoi(siz+4);
			if(off+size > mem_size)		//out of bounds check
			{
				printf("Range exceeds allocated memory so pattern written till allocation boundary...\n");
				size = mem_size - off;
			}
		}
		else if(err==0)			//option other than address, size, seed entered
		{
			printf("Invalid option for pattern !!!\n");
		}
	}
	else if(strcmp(addr_wp,"help")==0)
	{
		help_fn("pattern",NULL,NULL);
	}
	else
	{
		printf("Incomplete option for this command !!!\n");		//few options entered
	}

	if(valid_op==1)
	{
		tmp_wp = (__uint32_t *)mem_ptr + off;
		if(strncmp(sd,"seed",4)==0)		//seed processed
		{
			seed=atoi(sd+4);
			x_1 = (__uint32_t*)malloc(10);
			x_0 = seed;
			for (__uint32_t i = 0;i < size;i++)
			{
				x_1 = prng_fn(x_0);		//pseudo random generating function called
				*tmp_wp = *x_1;
				tmp_wp++;
				x_0 = *x_1;
			}
			printf("Random data written to specified memory location\n");
			free(x_1);
		}
	}
	t = clock() - t;		//time measured after execution
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}
