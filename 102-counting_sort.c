#include "sort.h"
#include <stdlib.h>

/**
* counting_sort - sorting algorithm
* @array: the array to sort
* @size: the array size
* Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *output, *cnt, k = 0, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > k)
			k = array[i];
	k++;
	cnt = (int *)malloc(sizeof(int *) * k);
	if (cnt == NULL)
		return;
	for (j = 0; j < k; j++)
		cnt[j] = 0;
	for (i = 0; i < size; i++)
		cnt[array[i]]++;
	for (j = 1; j < k; j++)
		cnt[j] += cnt[j - 1];
	print_array(cnt, k);
	i = 0;
	output = (int *)malloc(sizeof(int *) * size);
	if (output == NULL)
		return;
	for (i = 0; i < size; i++)
		output[--cnt[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(cnt);
	free(output);
}
