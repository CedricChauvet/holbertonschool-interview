#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


/**
 * swap - Swaps the values of two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * This function swaps the values of the two integers pointed to by @a and @b.
 */

void swap(int *a, int *b)

{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * siftDown - Restores the heap property by sifting an element down.
 * @a: The array representing the heap.
 * @start: The index of the root of the subtree to sift down.
 * @end: The end index (exclusive) where the heap ends.
 * @length: The total length of the array (used for debugging).
 *
 * This function ensures that the subtree rooted at the index `start`
 * in the heap satisfies the max-heap property. It compares the element
 * at `start` with its children, and swaps it with the largest child if
 * necessary, repeating this process until the heap property is restored.
 *
 * It stops when the element at `start` is greater than both of its children
 * or when no more children exist. The length parameter is only used for
 * printing the array during debugging.
 */
void siftDown(int a[], int start, int end, int length)

{
	int root = start;

	while (2 * root + 1 < end)
	{
		int child = 2 * root + 1;

		if (child + 1 < end && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[root] < a[child])
		{
			swap(&a[root], &a[child]);
			print_array(a, length);
			root = child;
		}
		else
		{
			return;
		}
	}
}


/**
 * heapify - Builds a max-heap from an unordered array.
 * @a: The array of integers to be heapified.
 * @count: The number of elements in the array.
 *
 * This function transforms the input array into a max-heap, where each
 * parent node is greater than or equal to its children. The process starts
 * from the last non-leaf node and sifts down each element to ensure the
 * heap property is satisfied throughout the array.
 *
 * A max-heap is necessary for the heap sort algorithm, and it ensures
 * the largest element is always at the root of the heap.
 */
void heapify(int a[], int count)

{
	int start = (count / 2) - 1;

	while (start >= 0)
	{
		siftDown(a, start, count, count);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 * @a: The array of integers to sort.
 * @count: The number of elements in the array.
 *
 * This function sorts the input array in ascending order using the heap sort
 * algorithm. It first transforms the array into a max-heap by calling
 * `heapify`.
 * Then, it repeatedly swaps the root of the heap (the largest element)
 * with the
 * last unsorted element, reducing the size of the heap by
 * one after each iteration.
 * The heap property is restored after each swap using `siftDown`.
 *
 * This process continues until the entire array is sorted.
 */
void heap_sort(int a[], int count)
/*This sorts.*/
{
	heapify(a, count);
	int end = count;

	while (end > 1)
	{
		end--;
		swap(&a[0], &a[end]);
		print_array(a, count);
		siftDown(a, 0, end, count);
	}
}


void write_big_o_notations()
{
    FILE *file = fopen("0-O", "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "O(n log n)\n");   // Best case time complexity
    fprintf(file, "O(n log n)\n"); // Average case time complexity
    fprintf(file, "O(n log n)\n");   // Worst case time complexity
	fprintf(file, "\n");
    fclose(file);
}