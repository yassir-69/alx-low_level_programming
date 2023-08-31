#include "main.h"

/**
 * clear_bit - Changes the value of a specified bit to 0.
 * @n: A reference to the number for which the bit needs to be reset.
 * @index: The position of the bit that should be set to 0..
 *
 * Return: Returns 1 upon success, or -1 if an issue arises.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	   if (index > 63)
	       	  return (-1);

	   *n = (~(1UL << index) & *n);
	          return (1);
}

