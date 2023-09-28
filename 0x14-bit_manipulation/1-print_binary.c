#include "main.h"

/**
 * print_binary - Outputs the binary representation of a decimal number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int x, quantity = 0;
	unsigned long int existing;

	for (x = 63; x >= 0; x--)
	{
		existing = n >> x;
		if (existing & 1)
		{
			_putchar('1');
			quantity++;
		}
		else if (quantity)
			_putchar('0');
	}
	if (!quantity)
		_putchar('0');
}
