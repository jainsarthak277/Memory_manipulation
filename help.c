#include "help.h"

void help_fn(char *option, char* dummy)
{
	if(dummy == NULL)
	{
		if(option == NULL)
		{	
			printf("These are Memory Fun commands:\n\n");
 			printf("%s",allocate_h);
 			printf("%s",free_h);
 			printf("%s",display_h);
 			printf("%s",write_h);
 			printf("%s",invert_h);
 			printf("Press help -command for help on particular command...\n");
		}
		else if(strcmp(option,"allocate")==0)
		{
			printf("%s",allocate_h);
		}
		else if(strcmp(option,"free")==0)
		{
			printf("%s",free_h);
		}
		else if(strcmp(option,"display")==0)
		{
			printf("%s",display_h);
		}
		else if(strcmp(option,"write")==0)
		{
			printf("%s",write_h);
		}
		else if(strcmp(option,"invert")==0)
		{
			printf("%s",invert_h);
		}
		else
		{
			printf("Invalid option for help !!!\n");
		}
	}
	else
	{
		printf("More then one option not allowed for this command !!!\n");
	}	
 }
