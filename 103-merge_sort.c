/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges
 * @l: left arrat
 * @array: array
 * @r: index array right
 * @m: middle array index
 */
void merge(int array[], int l, int m, int r)
{
    int x, y, g;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
  
    printf("Merging...\n");
    for (x = 0; x < n1; x++)
        L[x] = array[l + x];
    printf("[left]: ");
    print_array(L, n1);
    for (y = 0; y < n2; y++)
        R[y] = array[m + 1 + y];
    printf("[right]: ");
    print_array(R, n2);

    x = 0;
    y = 0;
    g = l;
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) {
            array[g] = L[x];
            x++;
        }
        else {
            array[g] = R[y];
            y++;
        }
        g++;
    }
    while (x < n1) {
        array[g] = L[x];
        x++;
        g++;
    }
    while (y < n2) {
        array[g] = R[y];
        y++;
        g++;
    }
    printf("[Done]: ");
    print_array(&array[l], n1 + n2);
}

/**
 * merge_sort - merge sorts array
 * @array: array being sorted
 * @size: number of elements in array
 */

void mergeSort(int *array, int li, int ri)
{
	int mid = (ri + li - 1) / 2;

	if (li < ri)
	{
		mergeSort(array, li, mid);
		mergeSort(array, mid + 1, ri);

		merge(array, li, mid, ri);
	}
}

/**
 * merge_sort - performs a merge sort on an array
 * @array: the array to sort
 * @size: number of elements in the array
 */

void merge_sort(int *array, size_t size)
{
	if (size > 1)
		mergeSort(array, 0, size - 1);
}