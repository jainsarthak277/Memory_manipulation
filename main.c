#include "main.h"

char *prompt;
char *command, *option[2], *op;
__uint32_t e;

static decode lookup[] = { {"q",&quit}, {"Q",&quit}, {"help",&help_fn} }; 
#define N (sizeof(lookup))/(sizeof(decode))

void main()
{
	prompt = (char*)malloc(20);	
	command = (char*)malloc(10);	
	option[0] = (char*)malloc(10);
	option[1] = (char*)malloc(10);
	op = (char*)malloc(20);
	e=0;
	printf("Hi there\nPress \"help\" for help !!!\nPress q or Q to exit\n");
	while(!e)
	{
		if(*fgets(prompt,20,stdin) != '\n')
		{
			prompt=remove_spaces(prompt);
			command = strtok(prompt,"-");	
			option[0] = strtok(NULL,"-");	
			option[1] = strtok(NULL,"-");
			call_command(command,option[0],option[1]);	
		}
	}
}

void call_command(char *command, char *option1, char *option2)
{
	__uint32_t invalid=1;	
	for(__uint32_t i=0; i<N; i++)
	{
		if(strcmp(lookup[i].com,command)==0)
		{
			invalid=0;			
			(*lookup[i].com_call)(option1, option2);
		}
				
	}
	if(invalid==1)
	{
		printf("Invalid command !!!\n");
	}
}

void quit(char *dummy1, char *dummy2)
{
	dummy1 = (char*)malloc(3);
	dummy1 = (char*)malloc(3);	
	e=1;
}


char *remove_spaces(char *ip)
{
	__uint32_t cnt=0;
	for(__uint32_t i=0; ip[i]!='\0'; i++)
	{
		if(ip[i]!=' ' && ip[i]!='\n')
		{
			op[cnt++]=ip[i];
		}
	}
	op[cnt++]='-';
	op[cnt]='\0';
	return op;
}
