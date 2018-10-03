#include "writepattern.h"

void write_pattern_fn(char* addr_wp, char* siz, char* sd)
{
	tmp_wp = (__uint32_t *)malloc(4);
	valid_op=0;
	err=0;
	clock_t t;
	t = clock();

	if (addr_wp != NULL && siz != NULL && sd != NULL)
	{
		if(strncmp(addr_wp,"addr",4)==0)
		{
			address_wp=strtol(addr_wp+4,&addr_wp,16);
			addr_diff_wp = address_wp-(long)mem_ptr;
			off = addr_diff_wp/4;
			if(addr_diff_wp%4 == 0 && addr_diff_wp/4 < mem_size)
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err=1;
			}
		}
		else if(strncmp(addr_wp,"offset",6)==0)
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
		if(strncmp(siz,"size",4)==0 && valid_op==1)
		{
			size=atoi(siz+4);
			if(off+size > mem_size)
			{
				printf("Range exceeds allocated memory so pattern written till allocation boundary...\n");
				size = mem_size - off;
			}
		}
		else if(err==0)
		{
			printf("Invalid option for pattern !!!\n");
		}
	}
	else if(strcmp(addr_wp,"help")==0)
	{
		help_fn("pattern",siz,sd);
	}
	else
	{
		printf("Incomplete option for this command !!!\n");
	}

	if(valid_op==1)
	{
		tmp_wp = (__uint32_t *)mem_ptr + off;
		if(strncmp(sd,"seed",4)==0)
		{
			seed=atoi(sd+4);
			x_1 = (__uint32_t*)malloc(10);
			x_0 = seed;
			for (__uint32_t i = 0;i < size;i++)
			{
				x_1 = prng_fn(x_0);
				*tmp_wp = *x_1;
				tmp_wp++;
				x_0 = *x_1;
			}
			printf("Random data written to specified memory location\n");
			free(x_1);
		}
	}
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}
