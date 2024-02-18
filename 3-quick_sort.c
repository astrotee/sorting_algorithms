#include "sort.h"

/**
* quick_sort - sorting algorithm
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_qsort(array, size, 0, size - 1);
}


/**
* lomuto_qsort - quicksort with lomuto partitioning algorithm
* @array: the array to sort
* @size: the array size
* @low: the begining of the sub-range
* @high: the end of the sub-range
* Return: Nothing
*/
void lomuto_qsort(int *array, size_t size, size_t low, size_t high)
{
	int pivot, tmp;
	size_t i, j;

	if (low >= high || high > size)
		return;
	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}

	if (++i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	lomuto_qsort(array, size, low, i - 1);
	lomuto_qsort(array, size, i + 1, high);
}
