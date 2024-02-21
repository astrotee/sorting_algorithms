#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* merge_sort - sorting algorithm
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	tmp = (int *)malloc(sizeof(int *) * size);
	if (tmp == NULL)
		return;
	for (i = 0; i < size; i++)
		tmp[i] = array[i];
	split_merge(tmp, 0, size, array);
	free(tmp);
}

/**
* split_merge - split, sort and merge
* @a: the array to sort
* @begin: the begining of the range
* @end: the end of the range
* @b: temp array
* Return: Nothing
*/
void split_merge(int *a, int begin, int end, int *b)
{
	int mid;

	if (end - begin < 2)
		return;
	mid = (begin + end) / 2;
	split_merge(b, begin, mid, a);
	split_merge(b, mid, end, a);
	sort_merge(a, begin, mid, end, b);
}

/**
* sort_merge - sort and merge
* @a: the array to sort
* @begin: the begining of the range
* @mid: the middle of the range
* @end: the end of the range
* @b: temp array
* Return: Nothing
*/
void sort_merge(int *a, int begin, int mid, int end, int *b)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&a[begin], mid - begin);
	printf("[right]: ");
	print_array(&a[mid], end - mid);
	i = begin, j = mid;
	for (k = begin; k < end; k++)
	{
		if (i < mid && (j >= end || a[i] <= a[j]))
			b[k] = a[i++];
		else
			b[k] = a[j++];
	}

	printf("[Done]: ");
	print_array(&b[begin], end - begin);
}
