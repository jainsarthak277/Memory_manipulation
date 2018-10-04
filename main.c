/***********************************************************************************
* @main.c
* @This file contains main commands and option decode logic. Commands are checked
* against a lookup table and corresponding function pointer is used to call function.
* Options are passed as arguments to this function andn further decode takes place
* inside respective functions.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/
#include "main.h"

static decode lookup[] = { {"q",&quit}, {"Q",&quit}, {"help",&help_fn}, {"allocate",&allocate_fn}, {"free",&free_fn}, {"write",&write_fn}, {"pattern",&write_pattern_fn}, {"display",display_fn}, {"verify",&verify_fn}, {"invert",&invert_fn}}; 

#define N (sizeof(lookup))/(sizeof(decode))

void main()
{	
	prompt = (char*)malloc(70);	
	command = (char*)malloc(10);	
	option[0] = (char*)malloc(20);
	option[1] = (char*)malloc(20);
	option[3] = (char *)malloc(20);
	op = (char*)malloc(70);
	e=1;
	printf("Hi there\nPress \"help\" for help !!!\nPress q or Q to exit\n");
	while(e)
	{
		if(*fgets(prompt,70,stdin) != '\n')
		{	
			prompt=remove_spaces(prompt);
			command = strtok(prompt,"-");	
			option[0] = strtok(NULL,"-");	
			option[1] = strtok(NULL,"-");
			option[2] = strtok(NULL,"-");
			call_command(command,option[0],option[1],option[2]);	
		}
	}
	printf("Bye !!!\n");
}

void call_command(char *command, char *option1, char *option2, char *option3)
{
	__uint32_t invalid=1;	
	for(__uint32_t i=0; i<N; i++)
	{
		if(strcmp(lookup[i].com,command)==0)
		{
			invalid=0;			
			(*lookup[i].com_call)(option1, option2, option3);
		}
				
	}
	if(invalid==1)
	{
		printf("Invalid command !!!\n");
	}
}

void quit(char *dummy1, char *dummy2, char *dummy3)
{
	dummy1 = (char*)malloc(3);
	dummy1 = (char*)malloc(3);	
	e=0;
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
