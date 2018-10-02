#include <stdio.h>
#include <string.h>

#define allocate_h "allocate\tAllocate a block of memory as: allocate - <size>\n"
#define free_h "free\t\tRelease previously allocated block\n"
#define display_h "display\t\tDisplay contents of memory\n"
#define write_h "write\t\tWrite at indicated memory location\n"
#define invert_h "invert\t\tInvert all memory bits\n"
#define pattern_h "pattern\t\tWrite pseudo-random pattern to address as: pattern - <address> - <size> - <seed value>\n"
#define verify_h "verify\t\tVerify pseudo-random pattern at specified address as: verify - <address> - <size> - <seed value>\n"

void help_fn(char* option, char *dummy1, char *dummy2);
