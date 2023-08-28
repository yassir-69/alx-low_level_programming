#include "lists.h"

/**
 * get_nodeint_at_index - Provides the node located at a specific index within a linked list.  
 * @head: Initial node within the linked list.
 * @index: Position of the node to retrieve.
 *
 * Return: Reference to the desired node, or NULL if it's not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int y = 0;
	listint_t *go_o = head;

	    while (go_o && y < index)
	    {
		    go_o = go_o->next;
		    y++;
	    }

	    return (go_o ? go_o : NULL);
}
