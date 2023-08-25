#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Deallocates a linked list
 * @head: The list t list that needs to be deallocated.
 */
void free_list(list_t *head)
{
	list_t *yoo_list;

	while (head)
	{
		yoo_list = head->next;
		free(head->str);
		free(head);
		head = yoo_list;
	}
}
