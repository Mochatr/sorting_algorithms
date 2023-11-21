#include "sort.h"

/**
 * selection_sort - Sorts an array in ascending order
 * @array: An array
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t sortIdx, currIdx, minIdx;

	for (sortIdx = 0; sortIdx < size - 1; sortIdx++)
	{
		minIdx = sortIdx;
		for (currIdx = sortIdx + 1; currIdx < size; currIdx++)
		{
			if (array[currIdx] < array[minIdx])
				minIdx = currIdx;
		}

		if (minIdx != sortIdx)
		{
			int tmp = array[sortIdx];

			array[sortIdx] = array[minIdx];
			array[minIdx] = tmp;

			print_array(array, size);
		}
	}
}
