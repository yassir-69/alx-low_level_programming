#include "lists.h"

/**
 * delete_nodeint_at_index - Removes a node from a linked list at a specific index.
 * @head: Reference to the initial element within the list.
 * @index: Position of the node to be deleted.
 *
 * Return: if 1 (Success), or -1 (Fail).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *go_o = *head;
	listint_t *exis_ting = NULL;
	unsigned int y = 0;

	    if (*head == NULL)
		        return -1;

	    if (index == 0)
	    {
		    *head = (*head)->next;
		    free(go_o);
		        return 1;
	    }

	    while (y < index - 1)
	    {
		    if (!go_o || !(go_o->next))
			    return (-1);
		    go_o = go_o->next;
		    y++;
	    }


	exis_ting = go_o->next;
	go_o->next = exis_ting->next;
	free(exis_ting);

	return 1;
}
