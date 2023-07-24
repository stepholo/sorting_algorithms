#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * shell sort algorithm wiht knuth sequence
 * @array: The array to be sorted
 * @size: number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = 1; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
