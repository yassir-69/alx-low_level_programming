#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - function that prints numbers, followed by a new line.
 * @Separator: Prints the string between numbers
 * @n: The sum of integers passed to the function
 * @...: A variable number of numbers to be printed
 */ 

void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list goo;
    unsigned int i;

    va_start(goo, n);

    for (i = 0; i < n; i++) {
        printf("%d", va_arg(goo, int));

        if (separator != NULL && i != n - 1) {
            printf("%s", separator);
        }
    }

    va_end(goo);

    printf("\n");
}

