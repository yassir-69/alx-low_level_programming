#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - Displays a statement prior to the main function
 * function is carried out
 */
void first(void)
{
	    printf("You're beat! and yet, you must allow,\n");
	    printf("I bore my house upon my back!\n");
}
