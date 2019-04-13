/***********************************************************************************
* @free.c
* @This file contains free_fn() which is used to free previously allocate memory. 
* It contains error handling in case memory was not allocated, if user passes any
* option and user can also invoke this command's help from here.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../inc/free.h"

void free_fn(char *dummy1, char *dummy2, char *dummy3)
{
	if(dummy2 == NULL && dummy3 == NULL)
	{	if(dummy1==NULL)
		{
			if(mem_status==1)
			{
				free(mem_ptr);
				mem_status=0;
				printf("Memory freed !!!\n");
			}
			else
			{
				printf("Memory NOT allocated. Free failed !!! \n");
			}
		}
		else if(strcmp(dummy1,"help")==0)            //Call help if user passes "help" option
		{
			help_fn("free",NULL,NULL);
		}
		else
		{
			printf("Invalid option for free !!!\n");
		}
	}
	else
	{
		printf("More than one option not allowed for this command !!!\n");
	}
}
