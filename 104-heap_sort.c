#include "sort.h"

void swap(int* a, int* b);
void heapify(int *array, int n, int i);

/**
 *
 *
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
		print_array(array, size);
	}
}
/**
 *
 *
 *
 */
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 *
 *
 *
 */
void heapify(int *array, int n, int i)
{
	int left, right, largest;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}
