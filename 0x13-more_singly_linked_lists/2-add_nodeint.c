#include "lists.h"

/**
 * add_nodeint - Inserts a new node at the start of a linked list.
 * @head: Reference to the initial node in the list.
 * @n: Information to be placed within the new node during insertion.
 *
 * Return: A reference to the new node, or NULL if the operation is unsuccessful.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *crea_ted;

	    crea_ted = malloc(sizeof(listint_t));
	        if (!crea_ted)
		    return (NULL);

	    crea_ted->n = n;
	    crea_ted->next = *head;
	    *head = crea_ted;

	        return crea_ted;
}
