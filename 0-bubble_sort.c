#include "sort.h"

/**
 * bubble_sort - sorst and array of integers in ascending order using the
 * bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, limit = 0;
	int temp = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		for (j = 0, limit = size - i - 1; j < limit; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
}
