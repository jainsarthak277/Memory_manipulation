#include <stdio.h>
#include <string.h>

#define allocate_h "allocate\tAllocate a block of memory\n"
#define free_h "free\t\tRelease previously allocated block\n"
#define display_h "display\t\tDisplay contents of memory\n"
#define write_h "write\t\tWrite at indicated memory location\n"
#define invert_h "invert\t\tInvert all memory bits\n"

void help_fn(char* option, char *dummy);
