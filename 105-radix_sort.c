#include "sort.h"
#include <stdlib.h>

/**
* radix_sort - sorting algorithm
* @array: the array to sort
* @size: the size of the array
* Return: Nothing
*/
void radix_sort(int *array, size_t size)
{
	size_t i = 0, b;
	int div, max = 0, count[10], *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = (int *)malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (div = 1; max / div > 0; div *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < size; i++)
		{
			b = (array[i] / div) % 10;
			count[b]++;
		}
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i < size; i--)
		{
			b = (array[i] / div) % 10;
			tmp[count[b] - 1] = array[i];
			count[b]--;
		}
		for (i = 0; i < size; i++)
			array[i] = tmp[i];
		print_array(array, size);
	}
	free(tmp);
}
