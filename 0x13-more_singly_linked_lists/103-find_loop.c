#include "lists.h"

/**
 * find_listint_loop - Detects the loop within a linked list.
 * @head: Linked list to be searched within.
 *
 * Return: Memory location of the node where the loop initiates, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slo_ow = head;
	listint_t *fas_st = head;

	if (!head)
		return NULL;

	while (slo_ow && fas_st && fas_st->next)
	{
		fas_st = fas_st->next->next;
		slo_ow = slo_ow->next;
		if (fas_st == slo_ow)
		{
			slo_ow = head;
			while (slo_ow != fas_st)
			{
				slo_ow = slo_ow->next;
				fas_st = fas_st->next;
			}
			return fas_st;
		}
	}

	return NULL;
}
