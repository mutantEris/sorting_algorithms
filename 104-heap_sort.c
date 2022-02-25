#include "sort.h"

/**
 * downsift - downsift
 * @array: the array
 * @start: starting index
 * @stop: where to stop
 * @size: length
 * Return: void
 */

void downsift(int *array, int start, int stop, size_t size)
{
	int g = stop;
	int l = 2 * stop + 1;
	int r = 2 * stop + 2;
	int wumbo;

	if (l < start && array[l] > array[g])
		g = l;
	if (r < start && array[r] > array[g])
		g = r;

	if (g != stop)
	{
		wumbo = array[stop];
		array[stop] = array[g];
		array[g] = wumbo;
		print_array(array, size);
		downsift(array, start, g, size);
	}
}

/**
 * heap_sort - heaps
 * @array: array
 * @size: size
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int x;
	int wumbo;
	int s = size;

	if (!array || size < 2)
		return;
	for (x = (s - 2) / 2; x >= 0; x--)
		downsift(array, s, x, size);
	for (x = (s - 1); x >= 0; x--)
	{
		wumbo = array[0];
		array[0] = array[x];
		array[x] = wumbo;
		if (x != 0)
			print_array(array, size);
		downsift(array, x, 0, size);
	}
}
