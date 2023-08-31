#include "main.h"

/**
 * flip_bits - Calculates the quantity of bits to be altered.
 * To transition between two numbers.
 * @n: Initial number.
 * @m: Subsequent number.
 *
 * Return: Quantity of bits to be modified.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int o, co_ount = 0;
	unsigned long int hpoo;
	unsigned long int excluding = n ^ m;

	    for (o = 63; o >= 0; o--)
	    {
	    	hpoo = excluding >> o;
	    	if (hpoo & 1)
	    		co_ount++;
	    }

	return co_ount;
}

