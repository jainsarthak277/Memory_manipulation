#include "write.h"

void write_fn(char *addr, char *val, char *dummy)
{
	tmp = (__uint32_t *)malloc(4);
	if(dummy==NULL)
	{
		if(addr!=NULL && val!=NULL && mem_status==1)
		{
			if(strncmp(addr,"addr",4)==0 || strncmp(addr,"offset",6)==0)
			{
				if(strncmp(addr,"addr",4)==0)
				{				
					address=strtol(addr+4,&addr,16);
					addr_diff = address-(long)mem_ptr;
					if(addr_diff%4 == 0 && addr_diff/4 < mem_size)
					{
						tmp=(__uint32_t *)address;		
					}
					else
					{
						printf("Address out of allocated range !!!\n");
					}
				}
				else if(strncmp(addr,"offset",6)==0)
				{
					off=atoi(addr+6);
					if(off<mem_size)
					{
						tmp = (__uint32_t *)mem_ptr + off;
					}
					else
					{
						printf("Address out of allocated range !!!\n");
					}
				}
				if(strncmp(val,"val",3)==0)
				{
					if(strlen(val+3)<=8)
					{				
						value=strtol(val+3,&val,16);
						*tmp=(__uint32_t)value;
					}
					else
					{
						printf("Value greater then 32 bits\n");
					}
				}
				else
				{
					printf("Invalid option for write !!!\n");
				}
			}
			else
			{
				printf("Invalid option for write !!!\n");
			}
		}
		else if(strcmp(addr,"help")==0)
		{
			help_fn("write",val,dummy);
		}
		else if(mem_status==0)
		{
			printf("First allocate memory...\n");
		}
		else
		{
			printf("Incomplete option for this command !!!\n");
		}
	}
	else
	{
		printf("More then two option not allowed for this command !!!\n");
	}
}
