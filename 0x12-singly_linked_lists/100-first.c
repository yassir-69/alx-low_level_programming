#include <stdio.h>

void pre_main_message(void) __attribute__ ((constructor));

/**
 * pre_main_message - prints a sentence before the main
 * function is executed
 */
void pre_main_message(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
