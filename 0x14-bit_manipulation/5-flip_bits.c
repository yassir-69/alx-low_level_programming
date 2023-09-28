#include "main.h"

/**
 * flip_bits - Tallies the quantity of bits to be modified.
 * To transition from one number to another.
 * @n: Initial numeric value.
 * @m: Subsequent numeric value.
 *
 * Return: Quantity of bits to modify.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, enumerate = 0;
	unsigned long int existing;
	unsigned long int unique = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		existing = unique >> x;
		if (existing & 1)
			enumerate++;
	}
	return (enumerate);
}
