#include "verify.h"

void verify_fn(char* addr_v, char* siz_v, char* sd_v)
{
	t = clock();
	tmp_v = (__uint32_t *)malloc(4);
	valid_op=0;
	err=0;
	if (addr_v != NULL && siz_v != NULL && sd_v != NULL)
	{
		if(strncmp(addr_v,"addr",4)==0)
		{
			address_v=strtol(addr_v+4,NULL,16);
			addr_diff_v = address_v-(long)mem_ptr;
			off = addr_diff_v/4;
			if(addr_diff_v%4 == 0 && addr_diff_v/4 < mem_size)
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err = 1;
			}
		}
		else if(strncmp(addr_v,"offset",6)==0)
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
		if(strncmp(siz_v,"size",4)==0 && valid_op == 1)
		{
			size_v=atoi(siz_v+4);
			if (off + size_v > mem_size)
			{
				printf("Range exceeds allocated memory so pattern written till allocation boundary...\n");
				size_v = mem_size - off;
			}
		}
		else if (err == 0) 
		{
			printf("Invalid option for pattern !!!\n");
		}
		else if(strcmp(addr_v,"help")==0)
		{
			help_fn("verify",NULL,NULL);
		}
		else
		{
			printf("Incomplete option for this command !!!\n");
		}
		if (valid_op == 1)
		{
			tmp_v=(__uint32_t *)mem_ptr + off;
			if(strncmp(sd_v,"seed",4)==0)
			{
				seed_v=atoi(sd_v+4);
				check = 0;
				x_1 = (__uint32_t*)malloc(10);
				x_0 = seed_v;
				{
					for (__uint32_t i = 0;i < size_v;i++)
					{
						x_1 = prng_fn(x_0);
						if (*tmp_v != *x_1)
						{
							if(check==0)
							{
								printf("Discrepancy found\n");
							}
							check++;
							printf("Address: %p   Actual: %d          Expected: %d\n", tmp_v,*tmp_v,*x_1);	
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
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}

