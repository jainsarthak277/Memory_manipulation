#include "main.h"

char prompt[10];
__uint32_t e;

static decode lookup[] = { {"q\n",&quit}, {"Q\n",&quit}, {"help\n",&help_fn} }; 
#define N (sizeof(lookup))/(sizeof(decode))

void main()
{
	e=0;
	printf("Hi there\n");
	while(!e)
	{
		if(*fgets(prompt,10,stdin) != '\n')
		{
						
			call_command(prompt);	
		}
	}
}

void call_command(char *command)
{
	for(__uint32_t i=0; i<N; i++)
	{
		if(strcmp(lookup[i].com,command)==0)
		{
			(*lookup[i].com_call)(command);
		}
				
	}
}

void quit(char *dummy)
{
	e=1;
}
