#include "sort.h"


/**
 * swap_nodes - Swaps two nodes
 * @n1: first node
 * @n2: first node
 */

void swap_nodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;

	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * @list: Doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr)
	{
		tmp = curr;
		curr = curr->next;

		while (tmp && tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_nodes(tmp->prev, tmp);
				if (!tmp->prev)
					*list = tmp;
				/*Print list after swap*/
				print_list((const listint_t *)*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
