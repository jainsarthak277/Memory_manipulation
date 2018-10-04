/***********************************************************************************
* @allocate.c
* @This file contains allocate_fn() which is used to allocate memory whose size is 
* specified by user. It contains error handling in case allocation fails, if user 
* passes more than one option, if invalid option is passed and user can also invoke 
* this command's help from here.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "allocate.h"

void allocate_fn(char *option, char *dummy1, char *dummy2)
{	
	if(dummy1 == NULL && dummy2 == NULL)
	{
		if(strncmp(option,"size",4)==0)
		{
			if(mem_status==0)
			{			
				mem_size = atoi(option+4);				//Get user specified size
				if (mem_size != 0)
				{				
					mem_ptr = (char *)malloc(mem_size*4);
					if (mem_ptr != NULL)
					{
						mem_status = 1;
						printf("Memory allocated from address : %p\n",mem_ptr);
					}
					else 
					{
						printf("Malloc failed\n");
					}
				}
				else 
				{
					printf("Error - Size cannot be 0\n");
				}
			}
			else
			{
				printf("Free previously allocated memory. Allocation failed !!!\n");
			}
		}
		else if(strcmp(option,"help")==0)					//Call help if user passes "help" option
		{
			help_fn("allocate",dummy1,dummy2);
		}
		else
		{
			printf("Invalid option for allocate !!!\n");
		}
	}
	else
	{
		printf("More then one option not allowed for this command !!!\n");
	}
}
