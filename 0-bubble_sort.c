#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * @array: An array
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t i = 0;
	size_t j;

	if (!array || !size)
		return;

	while (i < size)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
		i++;
	}
}

