#include "lists.h"

/**
 * listint_len - Gives back the count of elements in a linked list.
 * @h: Navigate through a linked list of type listint_t.
 *
 * Return: The number of nodes or the Quantity of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t number_nod = 0;

	    while (h)
	    {
		    number_nod++;
		    h = h->next;
	    }

	return number_nod;
}
