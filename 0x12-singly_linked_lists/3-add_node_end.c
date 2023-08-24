#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head_yhl: the double pointer to the list_t list
 * @yhl_str: the string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head_yhl, const char *yhl_str)
{
    list_t *goo;
    list_t *temp = *head_yhl;
    unsigned int new_len = 0;

    while (yhl_str[new_len])
        new_len++;

    goo = malloc(sizeof(list_t));
    if (!goo)
        return NULL;

    goo->str = strdup(yhl_str);
    goo->len = new_len;
    goo->next = NULL;

    if (*head_yhl == NULL)
    {
        *head_yhl = goo;
        return (goo);
    }

    while (temp->next)
        temp = temp->next;

    temp->next = goo;

    return (goo);
}
