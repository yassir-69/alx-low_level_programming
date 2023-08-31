#include "main.h"

/**
 * binary_to_uint - Rewriting changes a binary numeral into an unsigned integer
 * @b: Reword the text that includes the binary numeral.
 *
 * Return: Rewrite the transformed numerical value.
 */
unsigned int binary_to_uint(const char *b)
{
	int o;
	unsigned int the_dec = 0;

	    if (!b)
	    	return 0;

	    for (o = 0; b[o]; o++)
	    {
	    	if (b[o] < '0' || b[o] > '1')
	    		return 0;
		the_dec = 2 * the_dec + (b[o] - '0');
	    }

	return the_dec;
}
