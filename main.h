#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char *com; void (*com_call)(char *);} __attribute__((packed))decode;

void call_command(char *command);

void quit(char *dummy);

