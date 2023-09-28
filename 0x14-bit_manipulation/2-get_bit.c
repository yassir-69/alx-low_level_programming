#include "main.h"

/**
 * get_bit - Returns value of bit at a specific index in decimal number.
 * @n: The number to be searched.
 * @index: The position of the bit.
 *
 * Return: The state or content of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int value_of_bit;

	if (index > 63)
		return (-1);
	value_of_bit = (n >> index) & 1;
	return (value_of_bit);
}
