#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a linked list
 * @hoo: the pointer to the list_t list to print
 *
 * Return: number of nodes printed
 */
size_t print_list(const list_t *hoo)
{
    size_t y = 0;

    while (hoo)
    {
        if (!hoo->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", hoo->len, hoo->str);
        hoo = hoo->next;
        y++;
    }

    return (y);
}
