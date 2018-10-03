#include "invert.h"

void invert_fn(char *addr, char *size, char *dummy)
{
	t = clock();
	valid_op=0;
	err=0;

	if(dummy == NULL)
	{
		if(strncmp(addr,"addr",4)==0)
		{
			address=strtol(addr+4,NULL,16);
			addr_diff = address -(long)mem_ptr;
			off = addr_diff/4;
			if(addr_diff%4 == 0 && addr_diff/4 < mem_size)
			{
				valid_op=1;		
			}
			else
			{
				printf("Address out of allocated range !!!\n");
				err=1;
			}
		}
		else if(strncmp(addr,"offset",6)==0)
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
		else if(strcmp(addr,"help")==0)
		{
			help_fn("invert",NULL,NULL);
			size="abc";
			err=1;
		}

		if(strncmp(size,"size",4)==0 && valid_op==1)
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
			while(sz)
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
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%f seconds taken to execute\n", time_taken);
}
