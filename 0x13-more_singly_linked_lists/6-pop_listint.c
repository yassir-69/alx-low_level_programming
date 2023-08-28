#include "lists.h"

/**
 * pop_listint - Removes the initial node of a linked list.
 * @head: Reference to the initial element within the linked list.
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *go_o;
	    int number_nod;

	        if (!head || !*head)
		    return 0;

	    number_nod = (*head)->n;
	    go_o = (*head)->next;
	    free(*head);
	    *head = go_o;

	return number_nod;
}
