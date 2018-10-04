/***********************************************************************************
* @prng.c
* @This file contains the formula for generating the pseudo random pattern from
* initial seed value. Reference for logic is given to geeksfor geeks, the link being
* https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/. The
* algorithm multiplies seed by a prime number, 1013, added to a second prime number,
* 9901 and then the modulus with respect to 2^32 - 1 is done. This algorithm is
* repeated for as many times as the size entered by user in write pattern function.
* Output of one level is used as seed for next.
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "prng.h"

__uint32_t* prng_fn(__uint32_t x_0)
{
	mod = pow(2, 32) - 1;
	*x_1 = ((x_0 * 1013) + 9901) % mod;
	return x_1;
}
