/***********************************************************************************
* @main.h
* @This headerr file includes all the function header files and it had variable and
* function declaration used in main.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "allocate.h"
#include "free.h"
#include "write.h"
#include "writepattern.h"
#include "display.h"
#include "verify.h"
#include "invert.h"

char *prompt;
char *command, *option[3], *op;
__uint32_t e;

typedef struct					//Lookup table  
{ 
	char *com; 
	void (*com_call)(char *, char *, char *);
} __attribute__((packed))decode;

void call_command(char *command, char *option1, char *option2, char *option3);

void quit(char *dummy1, char *dummy2, char *dummy3);

char *remove_spaces(char *ip);

