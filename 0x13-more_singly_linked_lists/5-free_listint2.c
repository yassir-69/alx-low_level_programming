#include "lists.h"

/**
 * free_listint2 - Deallocates a linked list.
 * @head: Reference to the listint_t list that is intended to be deallocated.
 */
void free_listint2(listint_t **head)
{
	listint_t *go_o;

	    if (head == NULL)
		    return;

	    while (*head)
	    {
		    go_o = (*head)->next;
		    free(*head);
		    *head = go_o;
	    }

	    *head = NULL;
}
