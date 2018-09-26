#include <stdio.h>
#include "help.h"

void help_fn(char *dummy_h)
{
 printf("\nYou are in help function.\n");
 printf("These are some common Memory Fun commands:\n\n");
 printf("allocate	Allocate a block of memory\n");
 printf("free		Release previously allocated block\n");
 printf("display		Display contents of memory\n");
 printf("write		Write at indicated memory location\n");
 printf("invert		Invert all memory bits\n\n");
 printf("Functionality of above in progress\n");
 printf("Sorry to not be of any more help.\n");
}
