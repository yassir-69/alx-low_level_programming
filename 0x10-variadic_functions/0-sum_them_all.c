#include <stdarg.h>
#include "variadic_functions.h"

/**
 * Sum_them_all - Returns the sum of all its paramters.
 *
 * @n: The number of the sum of the numbers passed to the function.
 * @...: A variable number of parameters to calculate the sum of.
 *
 * Return: If n == 0 - 0.
 *  Otherwise - the sum of all parameters.
 */  

int sum_them_all(const unsigned int n, ...)
{
    va_list goo;
    unsigned int i;
    int sum = 0;

    if (n == 0)
        return 0;

    va_start(goo, n);

    for (i = 0; i < n; i++) {
        sum += va_arg(goo, int);
    }

    va_end(goo);

    return sum;
}

