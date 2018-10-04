/***********************************************************************************
* @verify.c
* @This file contains the logic for verification. The address to be checked, size 
* and seed are pulled from the input string using strtol function. Checks are added 
* to see if input address + size/offset are greater than the memory size allocated.
* If so, error is displayed, or pattern is checked till memory boundary. If less
* than three parameters are entered, the program displays invalid number of
* arguments error.If a different option than address, size of seed is entered, an
* error of invalid option is displayed. In the main logic, program processes entered
* address, size and seed to check if it is the same as those already written in
* writepattern function. If not, a discrepancy found message is displayed with the
* address of discrepancy, actual pattern value and expected pattern value. If no
* discrepancies, a verification passed message is displayed. The program also
* measures the time taken to execute function.
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "verify.h"

void verify_fn(char* addr_v, char* siz_v, char* sd_v)
{
	t = clock();		//time measured before function
	tmp_v = (__uint32_t *)malloc(4);
	valid_op=0;
	err=0;
	if (addr_v != NULL && siz_v != NULL && sd_v != NULL)		//check for all three options present
	{
		if(strncmp(addr_v,"addr",4)==0)
		{
			address_v=strtol(addr_v+4,NULL,16);		//address processed
			addr_diff_v = address_v-(long)mem_ptr;
			off = addr_diff_v/4;
			if(addr_diff_v%4 == 0 && addr_diff_v/4 < mem_size)		//addres check performed for out of bounds
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err = 1;
			}
		}
		else if(strncmp(addr_v,"offset",6)==0)		//option for offset
		{
			off=atoi(addr_v+6);
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
		if(strncmp(siz_v,"size",4)==0 && valid_op == 1)		//size processed
		{
			size_v=atoi(siz_v+4);
			if (off + size_v > mem_size)		//out of bounds check
			{
				printf("Range exceeds allocated memory so pattern checked till allocation boundary...\n");
				size_v = mem_size - off;
			}
		}
		else if (err == 0) 		//option other than address, size, seed entered
		{
			printf("Invalid option for pattern !!!\n");
		}
		else		//few options entered
		{
			printf("Incomplete option for this command !!!\n");
		}
		if (valid_op == 1)
		{
			tmp_v=(__uint32_t *)mem_ptr + off;
			if(strncmp(sd_v,"seed",4)==0)		//seed processed
			{
				seed_v=atoi(sd_v+4);
				check = 0;
				x_1 = (__uint32_t*)malloc(10);
				x_0 = seed_v;
				{
					for (__uint32_t i = 0;i < size_v;i++)
					{
						x_1 = prng_fn(x_0);		//pseudo random generating function called
						if (*tmp_v != *x_1)
						{
							if(check==0)
							{
								printf("Discrepancy found\n");		//Discrepancy notification
							}
							check++;
							printf("Address: %p   Actual: %x          Expected: %x\n", tmp_v,*tmp_v,*x_1);	
						}
						tmp_v+=1;
						x_0 = *x_1;
					}
					free(x_1);
					if (check == 0)
					{
						printf("Verification Passed !!!\n");
					}
				}
			}
		}
	}
	else if(strcmp(addr_v,"help")==0)
	{
		help_fn("verify",NULL,NULL);
	}
	t = clock() - t;		//time measured after execution
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}

