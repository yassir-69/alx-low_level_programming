#include "lists.h"

/**
 * add_nodeint_end - Appends a node to the end of a linked list.
 * @head: Reference to the initial element in the list.
 * @n: Information to be inserted into the new element.
 *
 * Return: A reference to the new node, or NULL if the process encounters failure.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *number_nod;
	listint_t *go_o = *head;

	    number_nod = malloc(sizeof(listint_t));
	        if (!number_nod)
		    return (NULL);

	    number_nod->n = n;
	    number_nod->next = NULL;

	        if (*head == NULL)
	        {
		*head = number_nod;
		    return number_nod;
	        }
         
            while (go_o->next)
		go_o = go_o->next;

	    go_o->next = number_nod;

	        return number_nod;
}
