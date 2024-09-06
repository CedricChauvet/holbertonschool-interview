#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int arr[], int n);
void siftDown(int arr[], int n, int i, int length);
void heapify(int a[], int count);
void swap(int *a, int *b);
void write_big_o_notations();
#endif