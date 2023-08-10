#define MAIN_H  // Include guards to prevent multiple inclusion 
#ifndef MAIN_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int _putchar(char c);

// Prototype:

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void errors(void);

// This function calculates and returns the length of a string. It takes a pointer to a character (a C-style string) as its argument and counts the number of characters in the string until it reaches the null-terminator ('\0') that marks the end of the string. It returns the length of the string as an integer.

int _strlen(char *s);

// This function checks whether the given string represents a digit or not. It takes a pointer to a character (a C-style string) as its argument and examines each character in the string. If all characters in the string are digits (0-9), the function returns 1 (true), indicating that the string is a numeric value. Otherwise, it returns 0 (false).

int is_digit(char *s);


#endif // MAIN_H
