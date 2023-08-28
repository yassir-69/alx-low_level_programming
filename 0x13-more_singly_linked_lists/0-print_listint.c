#include "lists.h"

/**
 * print_listint - Displaying all the elements of a linked list.
 * @h: Transform a linked list of type listint_t into a format that can be printed.
 *
 * Return: The number of nodes or the Quantity of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t number_nod = 0;

	    while (h)
	    {
		    printf("%d\n", h->n);
		    number_nod++;
		    h = h->next;
	    }

	return number_nod;
}
