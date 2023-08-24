#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a linked list
 * @head_yhl: it's the list_t list to be freed
 */

void free_list(list_t *head_yhl)
{
    list_t *temp_yhl;

    while (head_yhl)
    {
        temp_yhl = head_yhl->next;
        free(head_yhl->str);
        free(head_yhl);
        head_yhl = temp_yhl;
    }
}
