#include "help.h"
#include "allocate.h"

long address;
__uint32_t value, addr_diff, *tmp, off;
void write_fn(char *addr, char *val, char *dummy);
