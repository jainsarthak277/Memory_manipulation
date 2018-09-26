#include <stdio.h>
#include <string.h>

#define close 1
#define help 2

typedef struct { char *com; __uint32_t val;} __attribute__((packed))decode;

__uint32_t find_command(char *command);

