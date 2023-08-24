#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - Inserts a fresh node at the tail of a linked list
 * @str: The string to place within the newly created node.
 * @head: The pointer that references another pointer pointing to the list t list
 *
 * Return: The memory location of the new item, or NULL in case of failure.
 */
list_t *add_node_end(list_t **head, const char *str);
{
    list_t *hoo_list;
    list_t *yoo_list = *head;
    unsigned int new_len = 0;

    while (yhl_str[new_len])
        new_len++;

    hoo_list = malloc(sizeof(list_t));
    if (!hoo_list)
        return NULL;

    hoo_list->str = strdup(str);
    hoo_list->len = new_len;
    hoo_list->next = NULL;

    if (*yoo_list == NULL)
    {
        *yoo_list = hoo_list;
        return (hoo_list);
    }

    while (yoo_list->next)
        yoo_list = yoo_list->next;

    yoo_list->next = hoo_list;

    return (hoo_list);
}

