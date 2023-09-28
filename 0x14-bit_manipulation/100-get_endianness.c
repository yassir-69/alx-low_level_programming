#include "main.h"

/**
 * get_endianness - Examines whether a machine follows little-endian or
 * big-endian architecture.
 * Return: Use 0 to denote big and 1 to signify little.
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *h = (char *) &x;

	return (*h);
}
