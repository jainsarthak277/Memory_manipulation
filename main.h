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

typedef struct 
{ 
	char *com; 
	void (*com_call)(char *, char *, char *);
} __attribute__((packed))decode;

void call_command(char *command, char *option1, char *option2, char *option3);

void quit(char *dummy1, char *dummy2, char *dummy3);

char *remove_spaces(char *ip);

