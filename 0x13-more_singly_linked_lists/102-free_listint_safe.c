#include "lists.h"

/**
 * free_listint_safe - Deallocates a linked list.
 * @h: Reference to the initial node in the linked list.
 *
 * Return: Count of elements within the deallocated list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	int varia;
	listint_t *go_o;

	    if (!h || !*h)
		    return 0;

	    while (*h)
	    {
	    	varia = *h - (*h)->next;
	    	if (varia > 0)
	    	{
	    		go_o = (*h)->next;
	    		free(*h);
	    		*h = go_o;
	    		size++;
	    	}
	    	else
	    	{
	    		free(*h);
	    		*h = NULL;
	    		size++;
	    		break;
	    	}
	    }

	*h = NULL;

	return size;
}
