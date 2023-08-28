#include "lists.h"

/**
 * sum_listint - Computes the total of all the data within a listint_t linked list.
 * @head: The initial node in the linked list.
 *
 * Return: The sum that is obtained as a result.
 */
int sum_listint(listint_t *head)
{
	int to_tal = 0;
	listint_t *go_o = head;

	    while (go_o)
	    {
		    to_tal += go_o->n;
		    go_o = go_o->next;
	    }

	    return to_tal;
}
