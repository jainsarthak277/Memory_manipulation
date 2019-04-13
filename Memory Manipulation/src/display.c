/***********************************************************************************
* @display.c
* @This file contains display_fn() which is used to display previously allocated memory. 
* It displays entire allocated memory is no option is passed or user can specify 
* start addr or offset and size to display particular portion. It contains error handling 
* in case memory was not allocated, if user passes more than two options, if invalid 
* option is passed and user can also invoke this command's help from here.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../inc/display.h"

void display_fn(char *addr, char *size, char *dummy)
{
	tmp = (__uint32_t *)malloc(4);
	valid_op=0;
	bypass=0;
	err=0;
	if(mem_status==1)					//Memory allocation check
	{
		if(addr==NULL && size==NULL && dummy==NULL)	//In case of no options, set variable and bypass to display entire memory
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
				address=strtol(addr+4,NULL,16);
				addr_diff = address-(long)mem_ptr;
				off = addr_diff/4;
				if(addr_diff%4 == 0 && addr_diff/4 < mem_size)		//32 bit address boundary checks and total range checks
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
				if(off<mem_size)					//offset range check
				{
					valid_op=1;
				}
				else
				{
					printf("Address out of allocated range !!!\n");
					err=1;
				}
			}
			else if(strcmp(addr,"help")==0)				//Call help if user passes "help" option
			{
				help_fn("display",NULL,NULL);
				size="abc";
				err=1;
			}

			if(strncmp(size,"size",4)==0 && valid_op==1)		
			{
				sz=atoi(size+4);
				if(off+sz > mem_size)				//Size boundary checks for given input address or offset
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
			while(sz)						//Read memory and display
			{
				printf("Address: %p\tData: %x\n",tmp,*tmp);
				tmp+=1;
				sz-=1;
			}
		}
	}
	else if(strcmp(addr,"help")==0)			//Help call in case help option is given without memory allocation
	{
		help_fn("display",NULL,NULL);
	}
	else
	{
		printf("No memory allocated...\n");
	}
}
