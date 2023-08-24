#include "lists.h"
#include <stdlib.h>

/**
 * list_len - returns the number of elements in a linked list
 * @head: the pointer to the list_t list
 *
 * Return: The number of elements in head
 */
size_t list_len(const list_t *head)
{
    size_t y = 0;

    while (head)
    {
        y++;
        head = head->next;
    }
    return (y);
}

