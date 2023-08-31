#include "main.h"

/**
 * get_bit - Provides the value of a bit at a specific index within a decimal number.
 * @n: The number search
 * @index: the index bit
 *
 * Return: the value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	    int v_of_b;

	    if (index > 63)
	    	return (-1);

	v_of_b = (n >> index) & 1;

	    return (v_of_b);
}
