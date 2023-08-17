#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * function that prints anything.
 * @format: List all media types that the function contains
 */ 

void print_all(const char * const format, ...)
{
    va_list goo;
    unsigned int i = 0;
    char *separator = "";
    char *str;
    
    va_start(goo, format);

    while (format && format[i])
    {
        switch (format[i])
        {
            case 'c':
                printf("%s%c", separator, va_arg(goo, int));
                break;
            case 'i':
                printf("%s%d", separator, va_arg(goo, int));
                break;
            case 'f':
                printf("%s%f", separator, va_arg(goo, double));
                break;
            case 's':
                str = va_arg(goo, char *);
                if (str == NULL)
                    str = "(nil)";
                printf("%s%s", separator, str);
                break;
            default:
                i++;
                continue;
        }
        separator = ", ";
        i++;
    }

    va_end(goo);
    
    printf("\n");
}
/* function that prints anything. */

