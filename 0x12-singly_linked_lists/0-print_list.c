#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints the contents of a linked list, displaying all its elements
 * @h: the pointer to the list_t list to print
 *
 * Return: Count of printed nodes or number of nodes printed
 */
size_t print_list(const list_t *h)
{
    size_t y = 0;

    while (h)
    {
        if (!h->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        h = h->next;
        y++;
    }

    return (y);
}

