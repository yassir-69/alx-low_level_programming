#include "lists.h"

/**
 * insert_nodeint_at_index - Adds a new node to a linked list.
 * At a specified position.
 * @head: Reference to the initial node within the list.
 * @idx: Position where the new node is inserted.
 * @n: Information to be placed within the new node during insertion.
 *
 * Return: Reference to the new node, or NULL if it doesn't exist.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int y;
	listint_t *crea_ted;
	listint_t *go_o = *head;

	    crea_ted = malloc(sizeof(listint_t));
	        if (!crea_ted || !head)
	        return (NULL);

	    crea_ted->n = n;
	    crea_ted->next = NULL;

	        if (idx == 0)
	        {
		        crea_ted->next = *head;
		        *head = crea_ted;
		            return (crea_ted);
	        }

	for (y = 0; go_o && y < idx; y++)
	{
		    if (y == idx - 1)
		    {
		        crea_ted->next = go_o->next;
		        go_o->next = crea_ted;
			        return (crea_ted);
		    }
		    else
		        go_o = go_o->next;
	}

	    return NULL;
}
