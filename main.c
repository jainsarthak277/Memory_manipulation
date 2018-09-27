#include "main.h"

char *prompt;
char *command, *option;
__uint32_t e;

static decode lookup[] = { {"q",&quit}, {"Q",&quit}, {"help",&help_fn} }; 
#define N (sizeof(lookup))/(sizeof(decode))

void main()
{
	prompt = (char*)malloc(20);	
	command = (char*)malloc(10);	
	option = (char*)malloc(10);
	e=0;
	printf("Hi there\n");
	while(!e)
	{
		if(*fgets(prompt,10,stdin) != '\n')
		{
			prompt=remove_spaces(prompt);
			command = strtok(prompt,"-");	
			option = strtok(NULL,"\n");		
			call_command(command,option);	
		}
	}
}

void call_command(char *command, char *option)
{
	for(__uint32_t i=0; i<N; i++)
	{
		if(strcmp(lookup[i].com,command)==0)
		{
			(*lookup[i].com_call)(option);
		}
				
	}
}

void quit(char *dummy)
{
	e=1;
}

char *remove_spaces(char *ip)
{
	__uint32_t cnt=0;
	char *op;	
	for(__uint32_t i=0; ip[i]; i++)
	{
		if(ip[i]!=' ' && ip[i]!='\n')
		{
			op[cnt++]=ip[i];
		}
	}
	op[cnt]='\0';
	return op;
}
