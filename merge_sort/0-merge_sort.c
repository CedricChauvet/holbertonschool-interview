#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * merge - merge the two halves of the array
 * @array: Pointer to the array
 * @left: Pointer to the left array
 * @right: Pointer to the right array
 * @mid: Pointer to the mid array
 * @temp: Pointer to the temp array
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}

	while (i < mid)
	{
		temp[k++] = array[i++];
	}

	while (j < right)
	{
		temp[k++] = array[j++];
	}

	for (i = 0; i < k; i++)
	{
		array[left + i] = temp[i];
	}

	printf("[Done]: ");
	print_array(array + left, right - left);

}

/**
 * merge_sort_recursive - recursive method
 * @array: Pointer to the array
 * @left: Pointer to the left array
 * @right: Pointer to the right array
 * @temp: Pointer to the temp array
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
	if (right - left <= 1)
	{
		return;
	}
	size_t mid = left + (right - left) / 2;

	merge_sort_recursive(array, left, mid, temp);
	merge_sort_recursive(array, mid, right, temp);
	merge(array, left, mid, right, temp);
}

/**
 * merge_sort - main method
 * @array: Pointer to the array
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int temp[1000];

	merge_sort_recursive(array, 0, size, temp);
}
