#include "sort.h"

/**
* heap_sort - sorting algorithm
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void heap_sort(int *array, size_t size)
{
	size_t end = size;

	if (array == NULL || size == 1)
		return;

	heapify(array, size);

	while (end > 1)
	{
		end--;
		swap_values(&array[end], &array[0]);
		print_array(array, size);
		siftdown(array, 0, end, size);
	}
}

/**
* heapify - build a heap
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void heapify(int *array, size_t size)
{
	int i;

	i = size / 2;
	while (i > 0)
		siftdown(array, --i, size, size);
}

/**
* siftdown - swap down until it's in heap order
* @array: the array to sort
* @end: the end of the heap
* @root: the root of the (sub)tree to siftdown
* @size: the array size
* Return: Nothing
*/
void siftdown(int *array, size_t root, size_t end, size_t size)
{
	size_t mxc;

	while (2 * root + 1 < end)
	{
		mxc = 2 * root + 1;
		if (mxc + 1 < end && array[mxc] < array[mxc + 1])
			mxc++;
		if (array[root] < array[mxc])
		{
			swap_values(&array[root], &array[mxc]);
			print_array(array, size);
			root = mxc;
		}
		else
			return;
	}


}

/**
* swap_values - swap the values of two int pointers
* @a: the first pointer
* @b: the second pointer
* Return: Nothing
*/
void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
