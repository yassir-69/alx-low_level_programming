#include <stdio.h>
#include "lists.h"

size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

/**
 * looped_listint_len - Calculates the count of distinct nodes.
 * Within a circular listint_t linked list.
 * @head: A reference to the beginning of the listint_t list to examine.
 *
 * Return: If the list is not circular - 0.
 * Otherwise - The count of distinct nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow, *hare;
	size_t points = 1;

	    if (head == NULL || head->next == NULL)
		    return 0;

	slow = head->next;
	hare = (head->next)->next;

	    while (hare)
	    {
		    if (slow == hare)
		    {
			    slow = head;
			    while (slow != hare)
			    {
			    	points++;
			    	slow = slow->next;
			    	hare = hare->next;
			    }

			    slow = slow->next;
			    while (slow != hare)
			    {
			    	points++;
			    	slow = slow->next;
			    }

			    return points;
		    }

		    slow = slow->next;
		    hare = (hare->next)->next;
	    }

	        return 0;
}

/**
 * print_listint_safe - Safely displays a listint_t linked list.
 * @head: A reference to the beginning of the listint_t linked list.
 *
 * Return: The count of nodes present in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t points, in_dex = 0;

	points = looped_listint_len(head);

	    if (points == 0)
	    {
		    for (; head != NULL; points++)
		    {
		    	printf("[%p] %d\n", (void *)head, head->n);
		    	head = head->next;
		    }
	    }    

	    else
	    {
		    for (in_dex = 0; in_dex < points; in_dex++)
		    {
		    	printf("[%p] %d\n", (void *)head, head->n);
		    	head = head->next;
		    }

		    printf("-> [%p] %d\n", (void *)head, head->n);
	    }

	return points;
}
