#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "allocate.h"
#include "free.h"

typedef struct 
{ 
	char *com; 
	void (*com_call)(char *, char *);
} __attribute__((packed))decode;

void call_command(char *command, char *option1, char *option2);

void quit(char *dummy1, char *dummy2);

char *remove_spaces(char *ip);

