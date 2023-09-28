#include "main.h"

/**
 * clear_bit - Assigns a value of 0 to a specified bit.
 * @n: Referring to the number for modification.
 * @index: Indicate the position of the bit to reset.
 *
 * Return: Assign 1 to signify success and -1 to indicate failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63 || !n)
return (-1);
*n &= ~(1UL << index);
return (1);
}
