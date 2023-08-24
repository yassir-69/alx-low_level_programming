#include "lists.h"
#include <stdlib.h>

/**
 * list_len - Returns the count of elements present in a linked list
 * @h: Pointer referring to the list t list
 *
 * Return: The count of elements within the head or The number of elements in head
 */
size_t list_len(const list_t *h);
{
    size_t y = 0;

    while (h)
    {
        y++;
        h = head->next;
    }
    return y;
}
