#include "sort.h"

void quickSort(int *array, size_t size, ssize_t low, ssize_t high);
void quick_sort(int *array, size_t size);
int partition(int *array, size_t size, int low, int high);


/**
 * swap - Function that swaps two integers
 * @array: Array
 * @size: Size of the array
 * @x: First value
 * @y: second value
 */
void swap(int *array, int size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * partition - Does the partition of the array
 * @array: Array
 * @size: size of the array
 * @low: low index
 * @high: high index
 *
 * Return: A value
 */
int partition(int *array, size_t size, int low, int high)
{
	int idx, j, pivot = array[high];

	for (idx = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[idx++]);

	swap(array, size, &array[idx], &array[high]);

	return (idx);
}

/**
 * quickSort - Quicksorts via partition
 * @array: Array
 * @size: the size of the array
 * @low: Low index
 * @high: high index
 */
void quickSort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = partition(array, size, low, high);

		quickSort(array, size, low, (p - 1));
		quickSort(array, size, (p + 1), high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: An array
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quickSort(array, size, 0, size - 1);
}
