#ifndef SORT_H_
#define SORT_H_
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t *a, listint_t *b);
void swap_values(int *a, int *b);
void split_merge(int *a, int begin, int end, int *b);
void sort_merge(int *a, int begin, int mid, int end, int *b);
void heapify(int *array, size_t size);
void siftdown(int *array, size_t root, size_t end, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lomuto_qsort(int *array, size_t size, size_t low, size_t high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif
