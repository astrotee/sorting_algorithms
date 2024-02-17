#include "sort.h"

/**
* insertion_sort_list - sorting algorithm
* @list: the doubly linked list to sort
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *back;

	cur = (*list)->next;
	for (cur = (*list)->next; cur; cur = cur->next)
	{
		for (back = cur->prev; back && back->n > cur->n; back = back->prev)
		{
			cur->prev->next = cur->next;
			if (cur->next)
				cur->next->prev = cur->prev;
			cur->prev = back->prev;
			if (back->prev)
				back->prev->next = cur;
			else
				 *list = cur;
			cur->next = back;
			back->prev = cur;
			back = cur;
			print_list(*list);
		}
	}
}
