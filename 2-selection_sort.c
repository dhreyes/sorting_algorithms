#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *
 * @array: array of integers to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp = 0;
	int hold = 0, flag = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			hold = array[i];
			array[i] = array[temp];
			array[temp] = hold;
			print_array(array, size);
		}
	}
}
