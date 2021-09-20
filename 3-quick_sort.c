#include "sort.h"
int partition(int *array, int low_index, int high_index);
void quick_sort_recursive(int *array, int start_index, int end_index, size_t size);
/**
 * quick_sort - quickly sorts
 * @array: the array
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	size_t high_index = size - 1;
	size_t low_index = 0;
	int partition_index;

	partition_index = partition(array, low_index, high_index);
	quick_sort_recursive(array, low_index, partition_index - 1, size);
	quick_sort_recursive(array, partition_index + 1, high_index, size);
}

void swap_values(int *num1, int *num2)
{
	int tmp;

	printf("inside swap value, num1: %d, num2: %d\n", *num1, *num2);
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * partition - finds pivot
 * @array: array to sort
 * @low_index: first index of array
 * @high_index: last index of array
 * @size: number of elements in array
 *
 * Return: partition location
 */
int partition(int *array, int low_index, int high_index)
{
	int pivot;
	size_t i, j;

	pivot = high_index;
	i = low_index - 1;

	for (j = low_index; array[j] <= pivot; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_values(&array[i], &array[j]);
		}
	}
	swap_values(&array[i + 1], &pivot);
	return (i + 1);
}

/**
 * quick_sort_recursive - does the actual work
 * @array: array to sort
 * @start_index: where it starts each call
 * @end_index: where each part ends each call
 *
 * Return: void
 */
void quick_sort_recursive(int *array, int start_index, int end_index, size_t size)
{
	start_index = partition(array, end_index, start_index);
	print_array(array, size);
}
