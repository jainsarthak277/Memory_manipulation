#include "help.h"
#include "allocate.h"

__uint32_t *tmp, valid_op, off, addr_diff, sz, bypass;
long address;

void display_fn(char *addr, char *size, char *dummy);
