#include "main.h"

char prompt[10];
__uint32_t e;
__uint32_t com_key;

static decode lookup[] = { {"q",close}, {"Q",close}, {"help",help} }; 
#define N (sizeof(lookup))/(sizeof(decode))

void main()
{
	while(!e)
	{
		if(*fgets(prompt,10,stdin) != '\n')
		{
			com_key = find_command(prompt);	
			printf("%d\n",com_key);		
			if(com_key!=0)	
			{
				switch(com_key)
				{
					case 1: e=1;
						break;					
					default: break;
				}
			}
		}
	}
}

__uint32_t find_command(char *command)
{
	//printf("%s   %s",command,lookup[0].com);
	for(__uint32_t i=0; i<N; i++)
	{
		//decode *tmp = (lookup + i*sizeof(decode));
		if(strcmp(lookup[i].com,command)==0)
		{
			return lookup[i].val;
		}
				
	}
	return 0;
}
