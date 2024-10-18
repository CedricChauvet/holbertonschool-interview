#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void merge_sort(int *array, size_t size) {
    if (size <= 1) return;

    size_t mid = size / 2;
    merge_sort(array, mid);
    merge_sort(array + mid, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array, mid);
    printf("[right]: ");
    print_array(array + mid, size - mid);

    int *temp = malloc(size * sizeof(int));
    size_t i = 0, j = mid, k = 0;

    while (i < mid && j < size) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while (i < mid) temp[k++] = array[i++];
    while (j < size) temp[k++] = array[j++];

    for (i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    printf("[Done]: ");
    print_array(array, size);
    printf("\n");

    // free(temp);
}