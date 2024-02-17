#include "sort.h"

/**
* bubble_sort - sorting algorithm
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size, nn;
	int tmp;

	if (array == NULL || size == 1)
		return;

	do {
		nn = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i] > array[i - 1])
				continue;
			tmp = array[i];
			array[i] = array[i - 1];
			array[i - 1] = tmp;
			nn = i;
			print_array(array, size);
		}
		n = nn;
	} while (n > 0);
}
