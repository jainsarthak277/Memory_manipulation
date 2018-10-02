#include "prng.h"

__uint32_t* prng_fn(__uint32_t x_0)
{
	mod = pow(2, 32) - 1;
	*x_1 = ((x_0 * 1013) + 9901) % mod;
	return x_1;
}
