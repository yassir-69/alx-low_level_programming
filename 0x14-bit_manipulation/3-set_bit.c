#include "main.h"

/**
 * set_bit - Modifying a specific bit at a provided index to a value of 1.
 * @n: Rephrase reference to the digit for modification.
 * @index: Reword the position of the bit to be switched to 1.
 *
 * Return: 1 indicates success, while -1 indicates failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    	if (index > 63)
    		return -1;

    *n = ((1UL << index) | *n);
    	return 1;
}
