#include "help.h"
#include "allocate.h"

long address;
__uint32_t value, addr_diff, *tmp, off, valid_op, err;
void write_fn(char *addr, char *val, char *dummy);
