#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * @separator: function that prints strings, followed by a new line.
 * @n: The string to be printed between the strings.
 * @...: The number of strings that the function should contain.
 *
 * note: In case if one of the strings is empty, (none) will be printed instead.
 */ 

void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list goo;
    unsigned int i;
    char *str;

    va_start(goo, n);

    for (i = 0; i < n; i++) {
        str = va_arg(goo, char *);

        if (str == NULL) {
            printf("(nil)");
        } else {
            printf("%s", str);
        }

        if (separator != NULL && i != n - 1) {
            printf("%s", separator);
        }
    }

    va_end(goo);

    printf("\n");
} 
/* function that prints strings, followed by a new line. */

