#include "main.h"

/**
 * get_endianness - Determines whether a system follows little endian or big endian order..
 *
 * Return: Returns 0 for big endian and 1 for little endian.
 */
int get_endianness(void)
{
    unsigned int num_ber = 1;
    char *endianCheck = (char *)&num_ber;

        if (*endianCheck == 1)
            return 1; 
        else
            return 0;
}
