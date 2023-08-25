#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Inserts a fresh node at the tail of a linked list
 * @str: The string to place within the newly created node.
 * @head: The pointer that references another pointer pointing to the list t list
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *hoo_list;
    list_t *yoo_list = *head;
    unsigned int len = 0;

    while (str[len])
        len++;

     hoo_list = malloc(sizeof(list_t));
    if (!hoo_list)
        return NULL;

    hoo_list->str = strdup(str);
    hoo_list->len = len;
    hoo_list->next = NULL;

    if (yoo_list == NULL) 
    {
        *head = hoo_list;
        return hoo_list;
    }

    while (yoo_list->next)
        yoo_list = yoo_list->next;

    yoo_list->next = hoo_list;

    return hoo_list;
}


