/***********************************************************************************
* @write.c
* @This file contains write_fn() which is used to write a word at a particular address
* from previously allocate memory. User can provide either address or offset and value.
* It contains error handling in case memory was not allocated, if user passes more than
* 2 option, if invalid option is passed and user can also invoke this command's help from here.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../inc/write.h"

void write_fn(char *addr, char *val, char *dummy)
{
	tmp = (__uint32_t *)malloc(4);
	valid_op=0;
	err=0;

	if(dummy==NULL)
	{
		if(addr!=NULL && val!=NULL && mem_status==1)
		{
			if(strncmp(addr,"addr",4)==0)
			{
				address=strtol(addr+4,NULL,16);
				addr_diff = address-(long)mem_ptr;
				if(addr_diff%4 == 0 && addr_diff/4 < mem_size)	//Address boundary and range check
				{
					tmp=(__uint32_t *)address;
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
				if(off<mem_size)			//Offset boundary check
				{
					tmp = (__uint32_t *)mem_ptr + off;
					valid_op=1;
				}
				else
				{
					printf("Address out of allocated range !!!\n");
					err=1;
				}
			}
						
			if(strncmp(val,"val",3)==0 && valid_op==1)
			{
				if(strlen(val+3)<=8)		//Value check for 32bit number
				{				
					value=strtol(val+3,&val,16);
					*tmp=(__uint32_t)value;
				}
				else
				{
					printf("Value greater then 32 bits\n");
					err=1;
				}
			}
			else if(err==0)
			{
				printf("Invalid option for write !!!\n");
			}
		}
		else if(strcmp(addr,"help")==0)				//Invoke help on "help" option
		{
			help_fn("write",NULL,NULL);
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
