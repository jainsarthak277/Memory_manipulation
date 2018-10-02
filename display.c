#include "display.h"

void display_fn(char *addr, char *size, char *dummy)
{
	tmp = (__uint32_t *)malloc(4);
	valid_op=0;
	bypass=0;
	err=0;

	if(addr==NULL && size==NULL && dummy==NULL)
	{
		off = 0;
		sz = mem_size;
		valid_op=1;
		bypass=1;
	}

	if(dummy == NULL && bypass==0)
	{
		if(strncmp(addr,"addr",4)==0)
		{			
			address=strtol(addr+4,&addr,16);
			addr_diff = address-(long)mem_ptr;
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
			help_fn("display",size,dummy);
		}

		if(strncmp(size,"size",4)==0 && valid_op==1)
		{
			sz=atoi(size+4);
			if(off+sz > mem_size)
			{
				printf("Range exceeds allocated memory so displayed till allocation boundary...\n");
				sz = mem_size - off;
			}
		}
		else if(err==0)
		{
			printf("Invalid option for display !!!\n");
		}
	}
	else if(bypass=0)
	{
		printf("More then two option not allowed for this command !!!\n");
	}

	if(valid_op==1)	
	{
		tmp = (__uint32_t *)mem_ptr + off;
		while(sz)
		{
			printf("Address: %p\tData: %x\n",tmp,*tmp);
			tmp+=1;
			sz-=1;
		}
	}
}
