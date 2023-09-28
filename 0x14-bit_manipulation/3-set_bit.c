#include "main.h"

/**
 * set_bit - Assigns the value of 1 to a bit at a specified index.
 * @n: Modify the reference to the numerical value.
 * @index: Rewrite the indication of the bit to be set to 1.
 *
 * Return: Use 1 to indicate success and -1 to denote failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
