#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character 'h' to standard output.
 * @h: The character to be outputted.
 *
 * Return: - If successful, the result is 1.
 * - In case of an error, the function returns -1,
 * and the error code (errno) is appropriately set.
 */
int _putchar(char h)
{
	return (write(1, &h, 1));
}
