#include "lists.h"

/**
 * free_listint - Deallocates or releases a linked list.
 * @head: Linked list of type listint_t that needs to be deallocated.
 */
void free_listint(listint_t *head)
{
	listint_t *go_o;

	    while (head)
	    {
		    go_o = head->next;
		    free(head);
		    head = go_o;
	    }
}
