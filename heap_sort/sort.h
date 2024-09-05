#include <stddef.h>
// sort.h
#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void heap_sort(int arr[], int n);
void siftDown(int arr[], int n, int i);
#endif // SORT_H