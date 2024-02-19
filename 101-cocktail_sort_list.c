#include "sort.h"


/**
* swap_nodes - swap two nodes in a doubly linked list
* @a: the first node
* @b: the second node
* Return: Nothing
*/
void swap_nodes(listint_t *a, listint_t *b)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	if (a->prev)
		a->prev->next = b;
	b->next = a;
	a->prev = b;
}

/**
* cocktail_sort_list - sorting algorithm
* @list: the doubly linked list to sort
* Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *back;
	short swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (back = *list, cur = back->next; cur; back = cur, cur = cur->next)
		{
			if (cur->n < back->n)
			{
				swapped = 1;
				if (back->prev == NULL)
					*list = cur;
				swap_nodes(back, cur);
				cur = back;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (cur = back, back = back->prev; back; cur = back, back = back->prev)
		{
			if (cur->n < back->n)
			{
				swapped = 1;
				if (back->prev == NULL)
					*list = cur;
				swap_nodes(back, cur);
				back = cur;
				print_list(*list);
			}
		}
	} while (swapped);
}
