#include "free.h"

void free_fn(char *dummy1, char *dummy2)
{
	if(dummy1 == NULL && dummy2 == NULL)
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
	else
	{
		printf("Option not allowed for this command !!!\n");
	}
}
