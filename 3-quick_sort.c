#include "sort.h"

void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partition_function(int *array, int lo, int hi, size_t size);
void swap_element(int *array, int idx, int jdx, size_t size);

/**
 * quick_sort - sorts data with the quick sort algo
 * @array: array to sort
 * @size: size of array
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - assists main quick responsible for
 * moving pivot
 * @array: array to be sorted
 * @lo: first element of array
 * @hi: last element of array
 * @size: size of array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int partition = partition_function(array, lo, hi, size);

		quick_sort_helper(array, lo, partition - 1, size);
		quick_sort_helper(array, partition + 1, hi, size);
	}
}
/**
 * partition_function - takes array and lowest and highest index
 * then swaps elements in array until next place is in order
 * @array: array to be partitioned
 * @lo: smallest element in array
 * @hi: largest element in array
 * @size: size of array
 * Return: index for new partition
 */
int partition_function(int *array, int lo, int hi, size_t size)
{
	int i = lo, j;
	int pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			swap_element(array, i, j, size);
			i++;
		}
	}
	swap_element(array, i, hi, size);
	return (i);
}
/**
 * swap_element - swaps element in array
 * @array: array to be swapped
 * @idx: first index
 * @jdx: second index
 * @size: size of array
 * Return: none
 */
void swap_element(int *array, int idx, int jdx, size_t size)
{
	int temp;

	if (array[idx] != array[jdx])
	{
		temp = array[idx];
		array[idx] = array[jdx];
		array[jdx] = temp;
		print_array(array, size);
	}
}
