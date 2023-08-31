#include "main.h"

/**
 * print_binary - Outputs the binary representation of a decimal number.
 * @n: Decimal number to be printed in binary form.
 */
void print_binary(unsigned long int n)
{
	int o, co_ount = 0;
	unsigned long int hpoo;

	    for (o = 63; o >= 0; o--)
	    {
	    	hpoo = n >> o;

	    	if ( hpoo & 1)
	    	{
	    		_putchar('1');
	    		co_ount++;
	    	}
	    	else if (co_ount)
	    		_putchar('0');
	    }
	    if (!co_ount)
	    	_putchar('0');
}   

