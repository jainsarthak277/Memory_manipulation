#include "allocate.h"

void allocate_fn(char *option, char *dummy)
{	
	if(dummy == NULL)
	{
		if(strncmp(option,"size",4)==0)
		{
			mem_ptr = (char *)malloc(atoi(option+4)*4);
			printf("Memory allocated from address : %p\n",mem_ptr);
		}
		else if(strcmp(option,"help")==0)
		{
			help_fn("allocate",dummy);
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
