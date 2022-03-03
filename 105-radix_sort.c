#include "sort.h"
/**
 * countingSort - sort countin'
 * @size: size
 * @wumbus: current position
 */
void countingSort(int *array, int size, int wumbus)
{
	int output[1024];
	int g;
    int counter[10] = { 0 };

	for (g = 0; g < size; g++)
		counter[(array[g] / wumbus) % 10]++;
	for (g = 1; g < 10; g++)
		counter[g] += counter[g - 1];
	for (g = size - 1; g >= 0; g--)
	{
		output[counter[(array[g] / wumbus) % 10] - 1] = array[g];
		counter[(array[g] / wumbus) % 10]--;
	}
	for (g = 0; g < size; g++)
		array[g] = output[g];
}
/**
 * radix_sort - radix sort
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int wumbus;
    int max;
    int g;

	if (!array || size < 2)
		return;
	max = array[0];
	for (g = 1; g < (int)size; g++)
	{
		if (array[g] > max)
			max = array[g];
	}
	for (wumbus = 1; max / wumbus > 0; wumbus *= 10)
	{
		countingSort(array, size, wumbus);
		print_array(array, size);
	}
}