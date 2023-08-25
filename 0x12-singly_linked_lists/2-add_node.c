#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - Inserts a fresh node at the start of a linked list
 * @str: This is a novel string to include within the node
 * @head: The pointer that points to another pointer, referencing the list t list.
 *
 * Return: The memory location of the new item, or NULL if unsuccessful.
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *hoo_list;
    unsigned int yoo = 0;

    while (str[yoo])
        yoo++;

    hoo_list = malloc(sizeof(list_t));
    if (!hoo_list)
        return NULL;

    hoo_list->str = strdup(str);
    hoo_list->len = yoo;
    hoo_list->next = (*head);
    (*head) = hoo_list;

    return (*head);
}
